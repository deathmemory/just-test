/*
 * Generated by plugin-codegen.
 */
#ifndef __MH_PLAYLIST_H__
#define __MH_PLAYLIST_H__

#include <gio/gio.h>
#include <glib-object.h>
#include <mh_api.h>

/*
 * Type Macros
 */

#define MH_TYPE_PLAYLIST \
	(mh_playlist_get_type())
#define MH_PLAYLIST(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), MH_TYPE_PLAYLIST, MHPlaylist))
#define MH_IS_PLAYLIST(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), MH_TYPE_PLAYLIST))
#define MH_PLAYLIST_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), MH_TYPE_PLAYLIST, MHPlaylistClass))
#define MH_IS_PLAYLIST_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE((klass), MH_TYPE_PLAYLIST))
#define MH_PLAYLIST_GET_CLASS(obj) \
	(G_TYPE_INSTANCE_GET_CLASS((obj), MH_TYPE_PLAYLIST, MHPlaylistClass))

typedef struct _MHPlaylistClass	MHPlaylistClass;

struct _MHPlaylistClass
{
	GObjectClass parent_class;

	/* Class Ios */

	/* Class Methods */
	void (* insert)( MHPlaylist *, uint32_t, MHItem **, uint32_t );
	MHResult (* remove)( MHPlaylist *, uint32_t, uint32_t );
	void (* sort)( MHPlaylist *, MHSortType, MHItemOrderType );
	void (* append)( MHPlaylist *, MHItem **, int );
	void (* append_playlist)( MHPlaylist *, MHPlaylist *);
	void (* foreach)( MHPlaylist *, int32_t, int32_t, MHFunc, void * );
	/* Class Properties */
};

struct _MHPlaylist
{
	GObject parent;

	/* Instance Members */
	GArray * array;
	guint * seq;
	gint index;
	guint ptime;
	MHPbShuffleMode shuffle;
	MHPbRepeatMode repeat;
	guint error_count;
	gint64 tag_id;
	MHDev * dev;
};

/* used by MH_TYPE_PLAYLIST */
GType mh_playlist_get_type( void );

/* Ios List */

#endif /* __MH_PLAYLIST_H__ */
