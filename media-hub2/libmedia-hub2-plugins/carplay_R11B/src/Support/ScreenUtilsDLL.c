/*
	File:    	ScreenUtilsDLL.c
	Package: 	Apple CarPlay Communication Plug-in.
	Abstract: 	n/a 
	Version: 	210.81
	
	Disclaimer: IMPORTANT: This Apple software is supplied to you, by Apple Inc. ("Apple"), in your
	capacity as a current, and in good standing, Licensee in the MFi Licensing Program. Use of this
	Apple software is governed by and subject to the terms and conditions of your MFi License,
	including, but not limited to, the restrictions specified in the provision entitled ”Public 
	Software”, and is further subject to your agreement to the following additional terms, and your 
	agreement that the use, installation, modification or redistribution of this Apple software
	constitutes acceptance of these additional terms. If you do not agree with these additional terms,
	please do not use, install, modify or redistribute this Apple software.
	
	Subject to all of these terms and in consideration of your agreement to abide by them, Apple grants
	you, for as long as you are a current and in good-standing MFi Licensee, a personal, non-exclusive 
	license, under Apple's copyrights in this original Apple software (the "Apple Software"), to use, 
	reproduce, and modify the Apple Software in source form, and to use, reproduce, modify, and 
	redistribute the Apple Software, with or without modifications, in binary form. While you may not 
	redistribute the Apple Software in source form, should you redistribute the Apple Software in binary
	form, you must retain this notice and the following text and disclaimers in all such redistributions
	of the Apple Software. Neither the name, trademarks, service marks, or logos of Apple Inc. may be
	used to endorse or promote products derived from the Apple Software without specific prior written
	permission from Apple. Except as expressly stated in this notice, no other rights or licenses, 
	express or implied, are granted by Apple herein, including but not limited to any patent rights that
	may be infringed by your derivative works or by other works in which the Apple Software may be 
	incorporated.  
	
	Unless you explicitly state otherwise, if you provide any ideas, suggestions, recommendations, bug 
	fixes or enhancements to Apple in connection with this software (“Feedback”), you hereby grant to
	Apple a non-exclusive, fully paid-up, perpetual, irrevocable, worldwide license to make, use, 
	reproduce, incorporate, modify, display, perform, sell, make or have made derivative works of,
	distribute (directly or indirectly) and sublicense, such Feedback in connection with Apple products 
	and services. Providing this Feedback is voluntary, but if you do provide Feedback to Apple, you 
	acknowledge and agree that Apple may exercise the license granted above without the payment of 
	royalties or further consideration to Participant.
	
	The Apple Software is provided by Apple on an "AS IS" basis. APPLE MAKES NO WARRANTIES, EXPRESS OR 
	IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY 
	AND FITNESS FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR
	IN COMBINATION WITH YOUR PRODUCTS.
	
	IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR CONSEQUENTIAL DAMAGES 
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
	PROFITS; OR BUSINESS INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION 
	AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT
	(INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE 
	POSSIBILITY OF SUCH DAMAGE.
	
	Copyright (C) 2013-2014 Apple Inc. All Rights Reserved.
	
	ScreenStream adapter that delegates functionality to a DLL.
	
	This defaults to loading the DLL from "libScreenStream.so".
	These can be overridden in the makefile with the following:
	
	CFLAGS += -DSCREEN_STREAM_DLL_PATH\"/some/other/path/libScreenStream.so\"
*/

#include "ScreenUtils.h"

#include <dlfcn.h>

#include "APSCommonServices.h"
#include "APSDebugServices.h"

#include CF_HEADER
#include CF_RUNTIME_HEADER
#include LIBDISPATCH_HEADER

//===========================================================================================================================
//	ScreenUtils DLL
//===========================================================================================================================

#if( defined( SCREEN_STREAM_DLL_PATH ) )
	#define kScreenStreamDLLPath		SCREEN_STREAM_DLL_PATH
#else
	#define kScreenStreamDLLPath		"libScreenStream.so"
#endif

#define FIND_SYM_HANDLE( HANDLE, NAME )		(NAME ## _f)(uintptr_t) dlsym( HANDLE, # NAME );

static void	_ScreenUtilsDLLInitialize( void *inContext );

static dispatch_once_t	gScreenUtilsDLLInitOnce = 0;

//===========================================================================================================================
//	ScreenStream
//===========================================================================================================================

struct ScreenStreamPrivate
{
	CFRuntimeBase					base;		// CF type info. Must be first.
	void *							context;	// Context for DLLs.
};

static void	_ScreenStreamGetTypeID( void *inContext );
static void	_ScreenStreamFinalize( CFTypeRef inCF );

static dispatch_once_t			gScreenStreamInitOnce = 0;
static CFTypeID					gScreenStreamTypeID = _kCFRuntimeNotATypeID;
static const CFRuntimeClass		kScreenStreamClass = 
{
	0,						// version
	"ScreenStream",			// className
	NULL,					// init
	NULL,					// copy
	_ScreenStreamFinalize,	// finalize
	NULL,					// equal -- NULL means pointer equality.
	NULL,					// hash  -- NULL means pointer hash.
	NULL,					// copyFormattingDesc
	NULL,					// copyDebugDesc
	NULL,					// reclaim
	NULL					// refcount
};

static ScreenStreamInitialize_f		gInitialize_f	= NULL;
static ScreenStreamFinalize_f		gFinalize_f		= NULL;
static _ScreenStreamSetProperty_f	gSetProperty_f	= NULL;
static ScreenStreamStart_f			gStart_f		= NULL;
static ScreenStreamStop_f			gStop_f			= NULL;
static ScreenStreamProcessData_f	gProcessData_f	= NULL;

//===========================================================================================================================
//	ScreenStreamGetTypeID
//===========================================================================================================================

CFTypeID	ScreenStreamGetTypeID( void )
{
	dispatch_once_f( &gScreenStreamInitOnce, NULL, _ScreenStreamGetTypeID );
	return( gScreenStreamTypeID );
}

static void _ScreenStreamGetTypeID( void *inContext )
{
	(void) inContext;
	
	gScreenStreamTypeID = _CFRuntimeRegisterClass( &kScreenStreamClass );
	check( gScreenStreamTypeID != _kCFRuntimeNotATypeID );
}

//===========================================================================================================================
//	ScreenStreamCreate
//===========================================================================================================================

OSStatus	ScreenStreamCreate( CFDictionaryRef inOptions, ScreenStreamRef *outStream )
{
	OSStatus			err;
	ScreenStreamRef		me;
	size_t				extraLen;
	
	extraLen = sizeof( *me ) - sizeof( me->base );
	me = (ScreenStreamRef) _CFRuntimeCreateInstance( NULL, ScreenStreamGetTypeID(), (CFIndex) extraLen, NULL );
	require_action( me, exit, err = kNoMemoryErr );
	memset( ( (uint8_t *) me ) + sizeof( me->base ), 0, extraLen );
	
	dispatch_once_f( &gScreenUtilsDLLInitOnce, NULL, _ScreenUtilsDLLInitialize );
	
	if( gInitialize_f )
	{
		err = gInitialize_f( me, inOptions );
		require_noerr( err, exit );
	}
	
	*outStream = me;
	me = NULL;
	err = kNoErr;
	
exit:
	CFReleaseNullSafe( me );
	return( err );
}

//===========================================================================================================================
//	_ScreenStreamFinalize
//===========================================================================================================================

static void	_ScreenStreamFinalize( CFTypeRef inCF )
{
	ScreenStreamRef const		me = (ScreenStreamRef) inCF;
	
	if( gFinalize_f ) gFinalize_f( me );
}

//===========================================================================================================================
//	ScreenStreamGetContext
//===========================================================================================================================

void *	ScreenStreamGetContext( ScreenStreamRef me )
{
	return( me->context );
}

//===========================================================================================================================
//	ScreenStreamSetContext
//===========================================================================================================================

void	ScreenStreamSetContext( ScreenStreamRef me, void *inContext )
{
	me->context = inContext;
}

//===========================================================================================================================
//	_ScreenStreamSetProperty
//===========================================================================================================================

OSStatus
	_ScreenStreamSetProperty( 
		CFTypeRef		inObject, 
		CFObjectFlags	inFlags, 
		CFStringRef		inProperty, 
		CFTypeRef		inQualifier, 
		CFTypeRef		inValue )
{
	return( gSetProperty_f ? gSetProperty_f( inObject, inFlags, inProperty, inQualifier, inValue ) : kUnsupportedErr );
}

//===========================================================================================================================
//	ScreenStreamStart
//===========================================================================================================================

OSStatus	ScreenStreamStart( ScreenStreamRef me )
{
	return( gStart_f ? gStart_f( me ) : kUnsupportedErr );
}

//===========================================================================================================================
//	ScreenStreamStop
//===========================================================================================================================

void	ScreenStreamStop( ScreenStreamRef me )
{
	if( gStop_f ) gStop_f( me );
}

//===========================================================================================================================
//	ScreenStreamProcessData
//===========================================================================================================================

OSStatus
	ScreenStreamProcessData( 
		ScreenStreamRef				me, 
		uint8_t *					inData, 
		size_t						inLen, 
		uint64_t					inDisplayTicks, 
		CFDictionaryRef				inOptions, 
		ScreenStreamCompletion_f	inCompletion, 
		void *						inContext )
{
	return( gProcessData_f ?
		gProcessData_f( me, inData, inLen, inDisplayTicks, inOptions, inCompletion, inContext ) :
		kUnsupportedErr );
}

//===========================================================================================================================
//	_ScreenUtilsDLLInitialize
//===========================================================================================================================

static void _ScreenUtilsDLLInitialize( void *inContext )
{
	void *		dllHandle;
	
	(void) inContext;
	
	dllHandle = dlopen( kScreenStreamDLLPath, RTLD_LAZY | RTLD_LOCAL );
	if( dllHandle )
	{
		gInitialize_f	= FIND_SYM_HANDLE( dllHandle, ScreenStreamInitialize );
		gFinalize_f		= FIND_SYM_HANDLE( dllHandle, ScreenStreamFinalize );
		gSetProperty_f	= FIND_SYM_HANDLE( dllHandle, _ScreenStreamSetProperty );
		gStart_f		= FIND_SYM_HANDLE( dllHandle, ScreenStreamStart );
		gStop_f			= FIND_SYM_HANDLE( dllHandle, ScreenStreamStop );
		gProcessData_f	= FIND_SYM_HANDLE( dllHandle, ScreenStreamProcessData );
	}
}

