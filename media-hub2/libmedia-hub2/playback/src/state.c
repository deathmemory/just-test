/*
 * Generated by object-codegen.
 */
#include <glib.h>
#include "state.h"

typedef struct _MHStatePrivate MHStatePrivate;

struct _MHStatePrivate
{
	gint dummy;
};

G_DEFINE_TYPE_WITH_PRIVATE( MHState, mh_state, G_TYPE_OBJECT )

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _action
 *  Description:
 * =====================================================================================
 */
static void _action( MHState * self, MHPb * pb, guint event, gpointer param1, gpointer param2 )
{

	//Method default implement.
	g_critical( "implement the pure virtual function 'State::%s' is Failed!",
			__func__);

}      /* -----  end of static function action  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _open
 *  Description:
 * =====================================================================================
 */
static void _open( MHState * self, MHPb * pb )
{

	//Method default implement.
	g_critical( "implement the pure virtual function 'State::%s' is Failed!",
			__func__);

}      /* -----  end of static function open  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _close
 *  Description:
 * =====================================================================================
 */
static void _close( MHState * self, MHPb * pb )
{

	//Method default implement.
	g_critical( "implement the pure virtual function 'State::%s' is Failed!",
			__func__);

}      /* -----  end of static function close  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_dispose
 *  Description:
 * =====================================================================================
 */
static void mh_state_dispose( GObject * object )
{
	MHState * _self	=	MH_STATE( object );

	G_OBJECT_CLASS( mh_state_parent_class )->dispose( object );
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_finalize
 *  Description:
 * =====================================================================================
 */
static void mh_state_finalize( GObject * object )
{
	MHState * _self	=	MH_STATE( object );
	MHStatePrivate * _priv	=	mh_state_get_instance_private( _self );

	G_OBJECT_CLASS( mh_state_parent_class )->finalize( object );
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_init
 *  Description:
 * =====================================================================================
 */
static void mh_state_init( MHState * self )
{
	MHStatePrivate * _priv	=	mh_state_get_instance_private( self );
}       /* -----  end of static function mh_state_init  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_class_init
 *  Description:
 * =====================================================================================
 */
static void mh_state_class_init( MHStateClass * klass )
{
	GObjectClass * _parentClass	=	G_OBJECT_CLASS( klass );
	GObjectClass * _gobjectClass	=	G_OBJECT_CLASS( klass );

	_gobjectClass->dispose	=	mh_state_dispose;
	_gobjectClass->finalize	=	mh_state_finalize;

	/* assemble ios of mh_state class */

	/* assemble methods of mh_state class */
	klass->action	=	_action;
	klass->open	=	_open;
	klass->close	=	_close;

	/* Ios */
	/* Signals */
}       /* -----  end of static function mh_state_class_init  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_action
 *  Description:
 * =====================================================================================
 */
void mh_state_action( MHState * self, MHPb * pb, guint event, gpointer param1, gpointer param2 )
{
	g_return_if_fail( MH_IS_STATE( self ));

	if( MH_STATE_GET_CLASS( self )->action != NULL )
	{
		MH_STATE_GET_CLASS( self )->action( self, pb, event, param1, param2 );
	}
	else
	{
		g_warning( "Class '%s' does not implement the pure virtual function 'MHStateClass::action()'",
				G_OBJECT_TYPE_NAME( self ));
	}
}		/* -----  end of function mh_state_action  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_open
 *  Description:
 * =====================================================================================
 */
void mh_state_open( MHState * self, MHPb * pb )
{
	g_return_if_fail( MH_IS_STATE( self ));

	if( MH_STATE_GET_CLASS( self )->open != NULL )
	{
		MH_STATE_GET_CLASS( self )->open( self, pb );
	}
	else
	{
		g_warning( "Class '%s' does not implement the pure virtual function 'MHStateClass::open()'",
				G_OBJECT_TYPE_NAME( self ));
	}
}		/* -----  end of function mh_state_open  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_state_close
 *  Description:
 * =====================================================================================
 */
void mh_state_close( MHState * self, MHPb * pb )
{
	g_return_if_fail( MH_IS_STATE( self ));

	if( MH_STATE_GET_CLASS( self )->close != NULL )
	{
		MH_STATE_GET_CLASS( self )->close( self, pb );
	}
	else
	{
		g_warning( "Class '%s' does not implement the pure virtual function 'MHStateClass::close()'",
				G_OBJECT_TYPE_NAME( self ));
	}
}		/* -----  end of function mh_state_close  ----- */

