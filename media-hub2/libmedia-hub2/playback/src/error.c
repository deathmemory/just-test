/*
 * Generated by object-codegen.
 */
#include <glib.h>
#include "stmdefs.h"
#include "error.h"
#include "switching.h"
#include <mh_playlist.h>
#include <mh_dev.h>
#include <mh_pb.h>

typedef struct _MHStateErrorPrivate MHStateErrorPrivate;

struct _MHStateErrorPrivate
{
	gint dummy;
};

G_DEFINE_TYPE_WITH_PRIVATE( MHStateError, mh_state_error, MH_TYPE_STATE )

static GObject * errorObject;


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _action
 *  Description:
 * =====================================================================================
 */
static void _action( MHState * self, MHPb * pb, guint event, gpointer param1, gpointer param2 )
{
	MHPb * _pb = MH_PB( pb );

	if( pb->playlist != NULL )
	{
		 switch( event )
		 {
			 case EVENT_SWITCHING_NEXT:
				 g_message( "[Error] to [switching]" );			
				 mh_pb_dispatch( _pb, EVENT_CHANGE, GUINT_TO_POINTER( SWITCHING_STATUS ), NULL );
				 if( _pb->playlist->repeat != MH_PB_REPEAT_MODE_ONE )
				 {
					 mh_dev_next( _pb->mhDev, _pb );
				 }
				 break;
			 case EVENT_SWITCHING_PREVIOUS:
				 g_message( "[Error] to [switching]" );
				 mh_pb_dispatch( _pb, EVENT_CHANGE, GUINT_TO_POINTER( SWITCHING_STATUS ), NULL );
				 mh_dev_previous( _pb->mhDev, _pb );
				 break;
			 case EVENT_SWITCHING_SELECT:
				 g_message( "[Error] to [switching]" );
				 mh_dev_set_index( _pb->mhDev, _pb, ( uint32_t )_pb->playlist->index );
				 break;
			 default:
				 break;
		 }
	}else{
		g_message("error.c %s playlist is NULL!!",__func__);		
	}
	//Method default implement.
}      /* -----  end of static function action  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _open
 *  Description:
 * =====================================================================================
 */
static void _open( MHState * self, MHPb * pb )
{
	g_message( "Opening [Error]" );
	mh_pb_state_open( pb, MH_PB_STATE_ERROR, NULL );
}      /* -----  end of static function open  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _close
 *  Description:
 * =====================================================================================
 */
static void _close( MHState * self, MHPb * pb )
{
	g_message( "Closing [Error]" );
}      /* -----  end of static function close  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_error_constructor
 *  Description:  
 * =====================================================================================
 */
static GObject * mh_state_error_constructor( GType type, guint n_construct_params, 
									GObjectConstructParam * construct_params )
{
	if( errorObject == NULL )
	{
		errorObject	=	G_OBJECT_CLASS( mh_state_error_parent_class )->constructor( type, 
						n_construct_params,	construct_params );
	}

	return errorObject;
}		/* -----  end of static function mh_state_error_constructor  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_error_dispose
 *  Description:
 * =====================================================================================
 */
static void mh_state_error_dispose( GObject * object )
{
	MHStateError * _self	=	MH_STATE_ERROR( object );

	errorObject	=	NULL;

	G_OBJECT_CLASS( mh_state_error_parent_class )->dispose( object );
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_error_finalize
 *  Description:
 * =====================================================================================
 */
static void mh_state_error_finalize( GObject * object )
{
	MHStateError * _self	=	MH_STATE_ERROR( object );
	MHStateErrorPrivate * _priv	=	mh_state_error_get_instance_private( _self );

	G_OBJECT_CLASS( mh_state_error_parent_class )->finalize( object );
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_error_init
 *  Description:
 * =====================================================================================
 */
static void mh_state_error_init( MHStateError * self )
{
	MHStateErrorPrivate * _priv	=	mh_state_error_get_instance_private( self );
}       /* -----  end of static function mh_state_error_init  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_error_class_init
 *  Description:
 * =====================================================================================
 */
static void mh_state_error_class_init( MHStateErrorClass * klass )
{
	MHStateClass * _parentClass	=	MH_STATE_CLASS( klass );
	GObjectClass * _gobjectClass	=	G_OBJECT_CLASS( klass );

	_gobjectClass->constructor	=	mh_state_error_constructor;
	_gobjectClass->dispose	=	mh_state_error_dispose;
	_gobjectClass->finalize	=	mh_state_error_finalize;

	/* assemble ios of mh_state_error class */

	/* assemble methods of mh_state_error class */
	_parentClass->action	=	_action;
	_parentClass->open	=	_open;
	_parentClass->close	=	_close;

	/* Ios */
	/* Signals */
}       /* -----  end of static function mh_state_error_class_init  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_error_instance
 *  Description:  
 * =====================================================================================
 */
MHStateError * mh_state_error_instance()
{
	return g_object_new( MH_TYPE_STATE_ERROR, NULL );
}		/* -----  end of function mh_state_error_instance  ----- */