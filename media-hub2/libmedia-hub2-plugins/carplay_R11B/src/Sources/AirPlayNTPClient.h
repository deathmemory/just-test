/*
	File:    	AirPlayNTPClient.h
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
	
	Copyright (C) 2011-2014 Apple Inc. All Rights Reserved.
*/

#ifndef __AirPlayNTPClient_h__
#define __AirPlayNTPClient_h__

#include "AirPlayCommon.h"
#include "APSCommonServices.h"

//===========================================================================================================================
//	Prototypes
//===========================================================================================================================

typedef struct AirPlayNTPClient *		AirPlayNTPClientRef;

OSStatus	AirPlayNTPClient_Create( AirPlayNTPClientRef *outClient, const void *inServerAddr );
void		AirPlayNTPClient_Delete( AirPlayNTPClientRef inClient );
#define		AirPlayNTPClient_Forget( X )	do { if( *(X) ) { AirPlayNTPClient_Delete( *(X) ); *(X) = NULL; } } while( 0 )
void		AirPlayNTPClient_SetQoSDisabled( AirPlayNTPClientRef inClient, Boolean inQoSDisabled );
OSStatus	AirPlayNTPClient_Start( AirPlayNTPClientRef inClient );

uint64_t	AirPlayNTPClient_GetSynchronizedNTPTime( AirPlayNTPClientRef inClient );
void		AirPlayNTPClient_GetSynchronizedTime( AirPlayNTPClientRef inClient, Time96 *outTime );
void		AirPlayNTPClient_GetSynchronizedTimeNearUpTicks( AirPlayNTPClientRef inClient, Time96 *outTime, uint64_t inTicks );
uint64_t	AirPlayNTPClient_GetUpTicksNearSynchronizedNTPTime( AirPlayNTPClientRef inClient, uint64_t inNTPTime );

#endif // __AirPlayNTPClient_h__
