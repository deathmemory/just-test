/*
 * Generated by object-codegen.
 */
#include <glib.h>
#include <mh_item.h>
#include <stdio.h>
#include <string.h>
#include <mh_dev.h>
typedef struct _MHItemPrivate MHItemPrivate;

struct _MHItemPrivate
{
	int dummy;
};

G_DEFINE_TYPE_WITH_PRIVATE( MHItem, mh_item, G_TYPE_OBJECT )

enum
{
	PROP_0,

	PROP_ITEM_UNIQUE_ID,
	PROP_ITEM_NAME,
	PROP_ITEM_SIZE,
	PROP_ITEM_TYPE,
	PROP_ITEM_DEV,
	PROP_ITEM_URI,
	PROP_ITEM_PARENT,

	N_PROPERTIES
};

static GParamSpec *itemProperties[ N_PROPERTIES ] = { NULL, };
/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _get_parent
 *  Description:
 * =====================================================================================
 */
static MHFolder * _get_parent( MHItem * self )
{
	g_return_val_if_fail( MH_IS_ITEM( self ), NULL );

	GNode * _node	=	self->node;
	GNode * _parent	=	_node->parent;

	return _parent ? _parent->data : NULL ;
}      /* -----  end of static function _get_parent  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _get_uri
 *  Description:  
 * =====================================================================================
 */
static char * _get_uri( MHItem * self )
{
	GNode * _node;
	gchar * _uri	=	g_strdup( self->name );
	gchar * _tmpUri;

	for( _node = self->node->parent; _node != NULL; _node = _node->parent )
	{
		MHItem * _parent	=	MH_ITEM( _node->data );

		_tmpUri	=	g_strdup_printf( "%s/%s", _parent->name, _uri );

		g_free( _uri );

		_uri	=	_tmpUri;
	}

	return _uri;
}		/* -----  end of static function _get_uri  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _get_property
 *  Description:  
 * =====================================================================================
 */
static void _get_property( GObject * object, guint property_id, GValue * value,
		GParamSpec * spec)
{
	MHItem * _self	=	MH_ITEM( object );
//	MHItemPrivate * _priv	=	mh_item_get_instance_private( _self );

	switch( property_id )
	{
	case PROP_ITEM_UNIQUE_ID:
		g_value_set_uint64( value, _self->uniqueId );
		break;
	case PROP_ITEM_NAME:
		g_value_set_string( value, _self->name );
		break;
	case PROP_ITEM_SIZE:
		g_value_set_uint( value, _self->size );
		break;
	case PROP_ITEM_TYPE:
		g_value_set_uint( value, _self->type );
		break;
	case PROP_ITEM_DEV:
		g_value_set_pointer( value, _self->dev );
		break;
	case PROP_ITEM_URI:
		g_value_set_string( value, _self->uri );
		break;
	case PROP_ITEM_PARENT:
		if( _self->node->parent != NULL )
			g_value_set_pointer( value, _self->node->parent->data );
		else
			g_value_set_pointer( value, NULL );
		break;
	default:
		break;
	}
}		/* -----  end of static function _get_property  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _set_property
 *  Description:  
 * =====================================================================================
 */
static void _set_property( GObject * object, guint property_id, const GValue * value,
		GParamSpec * spec)
{
	MHItem * _self	=	MH_ITEM( object );
//	MHItemPrivate * _priv	=	mh_item_get_instance_private( _self );

	switch( property_id )
	{
	case PROP_ITEM_UNIQUE_ID:
		_self->uniqueId	=	g_value_get_uint64( value );
		break;
	case PROP_ITEM_NAME:
		g_strlcpy( _self->name, g_value_get_string( value ), MH_STRING_LONG );
		break;
	case PROP_ITEM_SIZE:
		_self->size		=	g_value_get_uint( value );
		break;

	case PROP_ITEM_TYPE:
		_self->type		=	g_value_get_uint( value );
		break;
	case PROP_ITEM_DEV:
		_self->dev		=	g_value_get_pointer( value );
		break;
	default:
		break;
	}
}		/* -----  end of static function _set_property  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _dispose
 *  Description:
 * =====================================================================================
 */
static void _dispose( GObject * object )
{
//	g_message("item.c:dispose");

	G_OBJECT_CLASS( mh_item_parent_class )->dispose( object );
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _finalize
 *  Description:
 * =====================================================================================
 */
static void _finalize( GObject * object )
{
//	g_message("item.c:_finalize");
	MHItem * _self	=	MH_ITEM( object );
	
	if( _self->name != NULL )
		g_free( _self->name );

	g_free( _self->uri );

	if( _self->collateKey != NULL )
		g_free( _self->collateKey );

	G_OBJECT_CLASS( mh_item_parent_class )->finalize( object );
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_item_init
 *  Description:
 * =====================================================================================
 */
static void mh_item_init( MHItem * self )
{
	MHItemPrivate * _priv	=	mh_item_get_instance_private( self );
	//g_message("%s self = %p",__func__,self);
	self->dev	=	NULL;
	self->node	=	NULL;
	self->size	=	0;
	self->collateKey	=	NULL;
	self->uniqueId	=	0;
	self->valid 	=	MH_ITEM_UNKNOWN;
	self->tagId	=	0;
	self->mediaId	=	0;
	self->favorite	=	false;
}       /* -----  end of static function mh_item_init  ----- */

/*
 * ===  FUNCTION  =============:=========================================================
 *         Name:  mh_item_class_init
 *  Description:
 * =====================================================================================
 */
static void mh_item_class_init( MHItemClass * klass )
{
	GObjectClass * _parentClass	=	G_OBJECT_CLASS( klass );
	GObjectClass * _gobjectClass	=	G_OBJECT_CLASS( klass );

	_gobjectClass->dispose	=	_dispose;
	_gobjectClass->finalize	=	_finalize;
	_gobjectClass->set_property	=	_set_property;
	_gobjectClass->get_property	=	_get_property;
	klass->get_parent	=	_get_parent;
	klass->get_uri		=	_get_uri;
	itemProperties[ PROP_ITEM_UNIQUE_ID ]	=	
		g_param_spec_uint64( "unique-id", "MHItem property", "Unique id of item",
				0, G_MAXUINT64, 0, G_PARAM_READABLE );

	itemProperties[ PROP_ITEM_NAME ]	=	
		g_param_spec_string( "name", "MHItem property", "Name of item",
				"", G_PARAM_READABLE );

	itemProperties[ PROP_ITEM_SIZE ]	=
		g_param_spec_uint( "size", "MHItem property", "Size of item",
				0, G_MAXUINT, 0, G_PARAM_READABLE );

	itemProperties[ PROP_ITEM_TYPE ]	=	
		g_param_spec_uint( "type", "MHItem property", "Type of item",
				0, G_MAXUINT, 0, G_PARAM_READABLE );

	itemProperties[ PROP_ITEM_DEV ]	=	
		g_param_spec_pointer( "plugin", "MHItem property", "Plugin of item",
				 G_PARAM_READABLE );

	itemProperties[ PROP_ITEM_URI ]	=	
		g_param_spec_string( "uri", "MHItem property", "URI of item",
				"", G_PARAM_READABLE );

	itemProperties[ PROP_ITEM_PARENT ]	=	
		g_param_spec_pointer( "parent", "MHItem property", "Parent of item",
				 G_PARAM_READABLE );

	g_object_class_install_properties( _gobjectClass, N_PROPERTIES, itemProperties );
	/* assemble ios of mh_item class */

	/* assemble methods of mh_item class */

	/* Ios */
	/* Signals */
}       /* -----  end of static function mh_item_class_init  ----- */
 /*
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_item_get_parent
 *  Description:
 * =====================================================================================
 */
MHFolder *  mh_item_get_parent( MHItem * self )
{
	g_return_val_if_fail( MH_IS_ITEM( self ), NULL);

	if( MH_ITEM_GET_CLASS( self )->get_parent != NULL )
	{
		return MH_ITEM_GET_CLASS( self )->get_parent( self );
	}

	else
	{
		g_warning( "Class '%s' does not implement the pure virtual function 'MHFolderClass::get_parent()'",
				G_OBJECT_TYPE_NAME( self ));
		return NULL;
	}
}		/* -----  end of function mh_item_get_parent  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_item_get_properties
 *  Description:  
 * =====================================================================================
 */
bool mh_item_get_properties(MHItem * self, const char * first_property_name, ... )
{
	va_list _varArgs;

	g_return_val_if_fail( MH_IS_ITEM( self ), false );
	va_start( _varArgs, first_property_name );

	g_object_get_valist( G_OBJECT( self ), first_property_name, _varArgs );

	va_end( _varArgs );

	return true;

}		/* -----  end of function mh_item_get_properties  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_item_set_properties
 *  Description:  
 * =====================================================================================
 */
bool mh_item_set_properties( MHItem * self, const char * first_property_name, ... )
{
	va_list _varArgs;

	g_return_val_if_fail( MH_IS_ITEM( self ), false );

	va_start( _varArgs, first_property_name );

	g_object_set_valist( G_OBJECT( self ), first_property_name, _varArgs );

	va_end( _varArgs );

	return true;

}		/* -----  end of function mh_item_set_properties  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_item_get_uri
 *  Description:  
 * =====================================================================================
 */
char * mh_item_get_uri( MHItem * self )
{
	g_return_val_if_fail( MH_IS_ITEM( self ), NULL);
	char * path	=	NULL;
	if( MH_ITEM_GET_CLASS( self )->get_uri != NULL )
	{
		path	=	MH_ITEM_GET_CLASS( self )->get_uri( self );
	}

	else
	{
		g_warning( "Class '%s' does not implement the pure virtual function 'MHFolderClass::get_uri()'",
				G_OBJECT_TYPE_NAME( self ));
	}
	return path;
}		/* -----  end of function mh_item_get_uri  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mh_item_foreach
 *  Description:  
 * =====================================================================================
 */
MHResult mh_item_foreach( MHItem ** items, int32_t count, MHItemFunc func, void * user_data )
{
	g_return_val_if_fail(( func != NULL ) && ( items != NULL ) && ( count > 0 ), MH_INVALID_PARAM);

	MHResult	_res	=	MH_OK;

	int i; 

	for( i = 0; i < count; i ++ )
	{
		if( items[ i ]	==	NULL)
		{
			break;
		}
		if( MH_IS_ITEM( items[ i ]))
		{
			ITEM_TO_DATA( items[ i ]);

			if( func( items[ i ], _data, user_data ))
			{
				g_free( _data->name );
				g_free( _data->uri );

				g_slice_free( MHItemData, _data );

				break;
			}

			g_free( _data->name );
			g_free( _data->uri );

			g_slice_free( MHItemData, _data );
		}
	}
	return _res;
}		/* -----  end of function mh_item_foreach  ----- */

