/*
 * Generated by object-codegen.
 */
#ifndef __MH_COL_PRIVATE_H__
#define __MH_COL_PRIVATE_H__

#include <mh_api.h>
#include <glib-object.h>
#include <mh_playlist.h>
/*
 * Type Macros
 */

#define MH_TYPE_COL \
	(mh_col_get_type())
#define MH_COL(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), MH_TYPE_COL, MHCol))
#define MH_IS_COL(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), MH_TYPE_COL))
#define MH_COL_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), MH_TYPE_COL, MHColClass))
#define MH_IS_COL_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE((klass), MH_TYPE_COL))
#define MH_COL_GET_CLASS(obj) \
	(G_TYPE_INSTANCE_GET_CLASS((obj), MH_TYPE_COL, MHColClass))

typedef struct _MHColClass	MHColClass;

struct _MHColClass
{
	GObjectClass parent_class;

	/* Class Methods */

//	MHResult (* foreach)( MHCol * , MHFunc , void *);
//	int (* get_count)( MHCol *);
//	MHResult (* set_filter)( MHCol *, MHItemType, MHMediaType, MHColFilterType, const char *, va_list );
	char ** (* retrieve_data)( MHCol *, MHItemType, MHMediaType, int * , bool);
	MHPlaylist * (* create_playlist)( MHCol *, MHItemType, MHMediaType, bool );
	MHResult (* add_filter)( MHCol *, MHColFilterType, va_list);	
	MHResult (* filter_clear)( MHCol * );
	MHResult (* set_retrieve_key)( MHCol *, MHColFilterType);
	MHResult (* set_order_type)( MHCol *, MHItemOrderType );
	MHAlbumInfo * ( * retrieve_album)( MHCol *, MHItemType, MHMediaType, int *, bool);
	MHResult (* set_favorite)( MHCol *, MHItemType , bool);

};

typedef struct _MHColFilter 
{
	MHColFilterType type;
	gpointer value;
} MHColFilter;				/* ----------  end of struct MHColFilter  ---------- */

struct _MHCol
{
	GObject parent;

	/* Instance Members */
	MHDev * dev;
	MHItemOrderType order;
	GList * list;
	MHColFilterType retrieve_key;

};

/* used by MH_TYPE_COL */
GType mh_col_get_type( void );


#endif
