/*
 * Generated by plugin-codegen.
 */
#ifndef __MH_IO_H__
#define __MH_IO_H__

#include <gio/gio.h>
#include "glib-object.h"
#include <mh_api.h>

/*
 * Type Macros
 */

typedef enum _IOErrorCode
{
	MH_IO_NO_ERROR	=	0,
	MH_IO_METHOD_ERROR,

	MH_IO_GENERIC_ERROR,
	MH_IO_ERROR_NUM
} IOErrorCode;				/* ----------  end of enum IOErrorCode  ---------- */

#define MH_TYPE_IO \
	(mh_io_get_type())
#define MH_IO(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), MH_TYPE_IO, MHIo))
#define MH_IS_IO(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), MH_TYPE_IO))
#define MH_IO_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), MH_TYPE_IO, MHIoClass))
#define MH_IS_IO_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE((klass), MH_TYPE_IO))
#define MH_IO_GET_CLASS(obj) \
	(G_TYPE_INSTANCE_GET_CLASS((obj), MH_TYPE_IO, MHIoClass))

typedef struct _MHIo		MHIo;
typedef struct _MHIoClass	MHIoClass;

struct _MHIoClass
{
	GObjectClass parent_class;

	/* Class Methods */
};

struct _MHIo
{
	GObject parent;

	/* Instance Members */
};

/* used by MH_TYPE_IO */
GType mh_io_get_type( void );

/* Methods List */
GVariant * mh_io_invoke_sync( MHIo * self, const gchar * method_name, GVariant * parameters, 
		GCancellable * cancellable, GError ** error );
void mh_io_invoke( MHIo * self, const gchar * method_name, GVariant * parameters,
		GCancellable * cancellable, GAsyncReadyCallback callback, gpointer user_data );
GVariant * mh_io_invoke_finish( MHIo * self, GTask * res, GError ** error );
void mh_io_invoke_return_value( GTask * task, GVariant * result );
void mh_io_dispatch( MHIo * self, GSource * source );

#endif /* __MH_IO_H__ */
