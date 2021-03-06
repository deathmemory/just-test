/*
 * Generated by object-codegen.
 */
#include <glib.h>
#include <mh_movie.h>

typedef struct _MHMoviePrivate MHMoviePrivate;

struct _MHMoviePrivate
{
	gint dummy;
};

G_DEFINE_TYPE_WITH_PRIVATE( MHMovie, mh_movie, MH_TYPE_ITEM )

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_movie_dispose
 *  Description:
 * =====================================================================================
 */
static void _dispose( GObject * object )
{
	MHMovie * _self	=	MH_MOVIE( object );
	if(_self->title !=	NULL)
	{
		g_free( _self->title );
	}
	if( _self->director !=	NULL)
	{
		g_free( _self->director );
	}
	if( _self->genre	!=	NULL )
	{
		g_free( _self->genre );
	}
	if( _self->language	!=	NULL)
	{
		g_free( _self->language );
	}
	G_OBJECT_CLASS( mh_movie_parent_class )->dispose( object );
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_movie_finalize
 *  Description:
 * =====================================================================================
 */
static void _finalize( GObject * object )
{
	MHMovie * _self	=	MH_MOVIE( object );
	MHMoviePrivate * _priv	=	mh_movie_get_instance_private( _self );

	G_OBJECT_CLASS( mh_movie_parent_class )->finalize( object );
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_movie_init
 *  Description:
 * =====================================================================================
 */
static void mh_movie_init( MHMovie * self )
{
	MHMoviePrivate * _priv	=	mh_movie_get_instance_private( self );
	self->title	=	NULL;
	self->director	=	NULL;
	self->genre	=	NULL;
	self->language	=	NULL;
}       /* -----  end of static function mh_movie_init  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_movie_class_init
 *  Description:
 * =====================================================================================
 */
static void mh_movie_class_init( MHMovieClass * klass )
{
	MHItemClass * _parentClass	=	MH_ITEM_CLASS( klass );
	GObjectClass * _gobjectClass	=	G_OBJECT_CLASS( klass );

	_gobjectClass->dispose	=	_dispose;
	_gobjectClass->finalize	=	_finalize;

	/* assemble ios of mh_movie class */

	/* assemble methods of mh_movie class */

	/* Ios */
	/* Signals */
}       /* -----  end of static function mh_movie_class_init  ----- */

