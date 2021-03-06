import sys

import _types
import _utils

class CodeGenerator:
	def __init__( self, klass ):
		self.klass	=	klass

	def generate_h( self ):
		_header	=	self.klass.name + '.h'
		_guarder	=	'__' + _header.upper().replace('.', '_') + '__'
		h	=	open( 'gen/' + _header, 'w' )
		h.write('/*\n'
				' * Generated by plugin-codegen.\n'
				' */\n'
				'#ifndef %s\n'
				'#define %s\n'
				'\n'%(_guarder, _guarder) )

		h.write( '#include <gio/gio.h>\n' )
		h.write( '#include <%s>\n'%self.klass.parent_header )

		h.write('\n/*\n'
				' * Type Macros\n'
				' */\n' )

		h.write('\n#define %s \\\n\t(%s_get_type())\n'
				%( _utils.klass_type( self.klass.name ), self.klass.name ))
		h.write('#define %s(obj) \\\n\t(G_TYPE_CHECK_INSTANCE_CAST'
				'((obj), %s, %s))\n'
				%( _utils.obj_cast( self.klass.name ), _utils.klass_type( self.klass.name ),
				_utils.obj_name( self.klass.name )))
		h.write('#define %s(obj) \\\n\t(G_TYPE_CHECK_INSTANCE_TYPE'
				'((obj), %s))\n'
				%( _utils.obj_check( self.klass.name ), _utils.klass_type( self.klass.name ) ))
		h.write('#define %s(klass) \\\n\t(G_TYPE_CHECK_CLASS_CAST'
				'((klass), %s, %s))\n'
				%( _utils.klass_cast( self.klass.name ), _utils.klass_type( self.klass.name ),
				_utils.klass_name( self.klass.name ) ))
		h.write('#define %s(klass) \\\n\t(G_TYPE_CHECK_CLASS_TYPE'
				'((klass), %s))\n'
				%( _utils.klass_check( self.klass.name ), _utils.klass_type( self.klass.name ) ))
		h.write('#define %s(obj) \\\n\t(G_TYPE_INSTANCE_GET_CLASS'
				'((obj), %s, %s))\n'
				%( _utils.klass_get( self.klass.name ), _utils.klass_type( self.klass.name ),
				_utils.klass_name( self.klass.name ) ))

		h.write( '\n' )

		h.write( 'typedef struct _%s\t\t%s;\n'%( _utils.obj_name( self.klass.name ), _utils.obj_name( self.klass.name ) ))
		h.write( 'typedef struct _%s\t%s;\n'%( _utils.klass_name( self.klass.name ), _utils.klass_name( self.klass.name ) ))

		h.write( '\n' )

		h.write( 'struct _%s\n'%_utils.klass_name( self.klass.name ) )
		h.write( '{\n' )
		h.write( '\t%s parent_class;\n'%_utils.klass_name( self.klass.parent ) )

		h.write( '\n' )
		h.write( '\t/* Class Ios */\n' )

		for i in self.klass.ios:
			if i.override == None:
				h.write( '\tgboolean (* %s)( %s *, GTask *'
							%( i.name.lower(), _utils.obj_name( self.klass.name ) ))

				for a in i.in_args:
					h.write( ', %s'%( _types.arg_dic[ a.sig ][ a.direction ] ))

				h.write( ' );\n' )

		h.write( '\n' );
		h.write( '\t/* Class Methods */\n' )

		for m in self.klass.methods:
			if m.override == None:
				h.write( '\tvoid (* %s)( %s *'
							%( m.name.lower(), _utils.obj_name( self.klass.name ) ))

				for a in m.in_args:
					h.write( ', %s'%( _types.arg_dic[ a.sig ][ a.direction ] ))

				h.write( ' );\n' )

		h.write( '\n' );
		h.write( '\t/* Class Properties */\n' )

		for p in self.klass.properties:
			if p.scope == 'class':
				h.write( '\t%s %s;\n'%( p.ptype, p.name ))

		h.write( '};\n' )

		h.write( '\n' )

		h.write( 'struct _%s\n'%_utils.obj_name( self.klass.name ))
		h.write( '{\n' )
		h.write( '\t%s parent;\n'%_utils.obj_name( self.klass.parent ))

		h.write( '\n' )
		h.write( '\t/* Instance Members */\n' )
		h.write( '\n' )

		for p in self.klass.properties:
			if p.scope == 'object':
				h.write( '\t%s %s;\n'%( p.ptype, p.name ))

		h.write( '};\n' )

		h.write( '\n' )
		h.write( '/* used by %s */\n'%_utils.klass_type( self.klass.name ) )
		h.write( 'GType %s_get_type( void );\n'%self.klass.name )

		h.write( '\n' )
		h.write( '/* Ios List */\n' )
		h.write( '\n' )

		for i in self.klass.ios:
			if i.override == None:
				h.write( 'gboolean %s_%s( %s * self'%(self.klass.name,
						i.name, _utils.obj_name( self.klass.name ) ))

				for a in i.in_args:
					h.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

				for a in i.out_args:
					h.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

				#h.write( ',\n\tGCancellable * cancellable, GError ** error );\n' )
				h.write( ' );\n' )

				h.write( 'void %s_complete_%s( %s * self, GTask * task'%(self.klass.name,
						i.name, _utils.obj_name( self.klass.name ) ))

				for a in i.out_args:
					h.write( ', %s %s'%( _types.arg_dic[ a.sig ][ 'in' ], a.name ))

				h.write( ' );\n' )

				h.write( '\n' )

		h.write( '\n' )

		for e in self.klass.events:
			h.write( 'void %s_%s( %s * self'%(self.klass.name,
					e.name, _utils.obj_name( self.klass.name ) ))

			for a in e.in_args:
				h.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

			for a in e.out_args:
				h.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

			h.write( ' );\n' )

		for m in self.klass.methods:
			if m.override == None:
				h.write( 'void %s_%s( %s * self'%(self.klass.name,
						m.name, _utils.obj_name( self.klass.name ) ))

				for a in m.in_args:
					h.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

				for a in m.out_args:
					h.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

				h.write( ' );\n' )

		h.write( '\n' )
		h.write( '#endif /* %s */\n'%_guarder )

		h.close()

	def generate_c( self ):
		_source	=	self.klass.name + '.c'
		c	=	open( 'gen/' + _source, 'w' )

		c.write( '/*\n'
				' * Generated by object-codegen.\n'
				' */\n' )

		c.write( '#include <glib.h>\n' )
		c.write( '#include <%s.h>\n'%self.klass.name )

		c.write( '\n' )

		c.write( 'typedef struct _%sPrivate %sPrivate;\n'%(_utils.obj_name( self.klass.name ), _utils.obj_name( self.klass.name )))

		c.write( '\n' )

		c.write( 'struct _%sPrivate\n{\n\tgint dummy;\n};\n'%_utils.obj_name( self.klass.name ))

		c.write( '\n' );

		c.write( 'G_DEFINE_TYPE_WITH_PRIVATE( %s, %s, %s )\n'%(_utils.obj_name( self.klass.name ),
					self.klass.name, _utils.klass_type( self.klass.parent )))

		c.write( '\n' )

		c.write( 'enum {\n' )
		c.write( '\t/* Ios */\n' )
		for i in self.klass.ios:
			if i.override == None:
				c.write( '\t%s,\n'%i.name.upper() )

		c.write( '\n' )
		c.write( '\t/* Signals */\n' )
		for s in self.klass.signals:
			c.write( '\t%s,\n'%s.name.upper() )

		c.write( '\n' )
		c.write( '\tN_SIGNALS\n' )
		c.write( '};\n' )

		c.write( '\n' )

		c.write( 'static guint signals[ N_SIGNALS ] = {0};\n' )

		for i in self.klass.ios:
			c.write( '\n' )
			c.write( '/*\n' )
			c.write( ' * ===  FUNCTION  ======================================================================\n' )
			c.write( ' *         Name:  _%s\n'%i.name )
			c.write( ' *  Description:\n' )
			c.write( ' * =====================================================================================\n' )
			c.write( ' */\n' )
			if i.override != None:
				c.write( 'static gboolean _%s( %s * self, GTask * task'%( i.name, _utils.obj_name( i.override ) ))
			else:
				c.write( 'static gboolean _%s( %s * self, GTask * task'%( i.name, _utils.obj_name( self.klass.name ) ))

			for a in i.in_args:
				c.write( ', %s %s'%(_types.arg_dic[ a.sig ][ a.direction ], a.name ))

			c.write( ' )\n' )
			c.write( '{\n' )
			for a in i.out_args:
				c.write( '\t%s _%s\t=\t%s;\n'%( _types.arg_dic[ a.sig ][ 'in' ], a.name, _types.arg_dic[ a.sig ][ 'default'] ))

			c.write( '\n' )

			c.write( '\t//Io default implement.\n' )
			c.write( '\tg_assert_not_reached();\n' )
			c.write( '\n' )
			if i.override == None:
				c.write( '\t%s_complete_%s( self, task'%( self.klass.name, i.name ) )
			else:
				c.write( '\t%s_complete_%s( self, task'%( i.override, i.name ) )
			for a in i.out_args:
				c.write( ', _%s'%a.name )

			c.write( ' );\n' )
			c.write( '\n' )
			c.write( '\treturn TRUE;\n' )
			c.write( '}      /* -----  end of static function _%s  ----- */\n'%i.name )

		c.write( '\n' )

		for i in self.klass.events:
			c.write( '\n' )
			c.write( '/*\n' )
			c.write( ' * ===  FUNCTION  ======================================================================\n' )
			c.write( ' *         Name:  _%s\n'%i.name )
			c.write( ' *  Description:\n' )
			c.write( ' * =====================================================================================\n' )
			c.write( ' */\n' )
			c.write( 'static gboolean _%s( gpointer user_data )\n'%i.name )

			c.write( '{\n' )
			c.write( '\treturn G_SOURCE_REMOVE;\n' )
			c.write( '}      /* -----  end of static function _%s  ----- */\n'%i.name )

		c.write( '\n' )

		for m in self.klass.methods:
			c.write( '\n' )
			c.write( '/*\n' )
			c.write( ' * ===  FUNCTION  ======================================================================\n' )
			c.write( ' *         Name:  _%s\n'%m.name )
			c.write( ' *  Description:\n' )
			c.write( ' * =====================================================================================\n' )
			c.write( ' */\n' )
			if m.override != None:
				c.write( 'static void _%s( %s * self'%( m.name, _utils.obj_name( m.override ) ))
			else:
				c.write( 'static void _%s( %s * self'%( m.name, _utils.obj_name( self.klass.name ) ))

			for a in m.in_args:
				c.write( ', %s %s'%(_types.arg_dic[ a.sig ][ a.direction ], a.name ))

			c.write( ' )\n' )
			c.write( '{\n' )
			for a in m.out_args:
				c.write( '\t%s _%s\t=\t%s;\n'%( _types.arg_dic[ a.sig ][ 'in' ], a.name, _types.arg_dic[ a.sig ][ 'default'] ))
			c.write( '\n' )
			c.write( '\t//Method default implement.\n' )
			c.write( '\tg_assert_not_reached();\n' )
			c.write( '}      /* -----  end of static function _%s  ----- */\n'%m.name )

		c.write( '\n' )

		c.write( '/*\n' )
		c.write( ' * ===  FUNCTION  ======================================================================\n' )
		c.write( ' *         Name:  %s_dispose\n'%self.klass.name )
		c.write( ' *  Description:\n' )
		c.write( ' * =====================================================================================\n' )
		c.write( ' */\n' )
		c.write( 'static void %s_dispose( GObject * object )\n'%self.klass.name )
		c.write( '{\n' )
		c.write( '\t%s * _self\t=\t%s( object );\n'%( _utils.obj_name( self.klass.name ), _utils.obj_cast( self.klass.name )))
		c.write( '\n' )
		c.write( '\tG_OBJECT_CLASS( %s_parent_class )->dispose( object );\n'%self.klass.name )
		c.write( '}\n' )

		c.write( '\n' )

		c.write( '/*\n' )
		c.write( ' * ===  FUNCTION  ======================================================================\n' )
		c.write( ' *         Name:  %s_finalize\n'%self.klass.name )
		c.write( ' *  Description:\n' )
		c.write( ' * =====================================================================================\n' )
		c.write( ' */\n' )
		c.write( 'static void %s_finalize( GObject * object )\n'%self.klass.name )
		c.write( '{\n' )
		c.write( '\t%s * _self\t=\t%s( object );\n'%( _utils.obj_name( self.klass.name ), _utils.obj_cast( self.klass.name )))
		c.write( '\t%sPrivate * _priv\t=\t%s_get_instance_private( _self );\n'%( _utils.obj_name( self.klass.name ), self.klass.name ))
		c.write( '\n' )
		c.write( '\tG_OBJECT_CLASS( %s_parent_class )->finalize( object );\n'%self.klass.name )
		c.write( '}\n' )

		c.write( '\n' )

		c.write( '/*\n' )
		c.write( ' * ===  FUNCTION  ======================================================================\n' )
		c.write( ' *         Name:  %s_init\n'%self.klass.name )
		c.write( ' *  Description:\n' )
		c.write( ' * =====================================================================================\n' )
		c.write( ' */\n' )
		c.write( 'static void %s_init( %s * self )\n'%( self.klass.name,
					_utils.obj_name( self.klass.name ) ))
		c.write( '{\n' )
		c.write( '\t%sPrivate * _priv\t=\t%s_get_instance_private( self );\n'%( _utils.obj_name( self.klass.name ), self.klass.name ))
		c.write( '}       /* -----  end of static function %s_init  ----- */\n'%self.klass.name )

		c.write( '\n' )

		c.write( '/*\n' )
		c.write( ' * ===  FUNCTION  ======================================================================\n' )
		c.write( ' *         Name:  %s_class_init\n'%self.klass.name )
		c.write( ' *  Description:\n' )
		c.write( ' * =====================================================================================\n' )
		c.write( ' */\n' )
		c.write( 'static void %s_class_init( %s * klass )\n'%( self.klass.name,
					_utils.klass_name( self.klass.name ) ))
		c.write( '{\n' )
		c.write( '\t%s * _parentClass\t=\t%s( klass );\n'%( _utils.klass_name( self.klass.parent ),
					_utils.klass_cast( self.klass.parent )))
		c.write( '\tGObjectClass * _gobjectClass\t=\tG_OBJECT_CLASS( klass );\n' )

		c.write( '\n' )

		c.write( '\t_gobjectClass->dispose\t=\t%s_dispose;\n'%self.klass.name )
		c.write( '\t_gobjectClass->finalize\t=\t%s_finalize;\n'%self.klass.name )

		c.write( '\n' )

		c.write( '\t/* assemble ios of %s class */\n'%self.klass.name )
		for i in self.klass.ios:
			if i.override != None:
				c.write( '\t_parentClass->%s\t=\t_%s;\n'%( i.name, i.name ))
			else:
				c.write( '\tklass->%s\t=\t_%s;\n'%( i.name, i.name ))

		c.write( '\n' )

		c.write( '\t/* assemble methods of %s class */\n'%self.klass.name )
		for m in self.klass.methods:
			if m.override != None:
				c.write( '\t_parentClass->%s\t=\t_%s;\n'%( m.name, m.name ))
			else:
				c.write( '\tklass->%s\t=\t_%s;\n'%( m.name, m.name ))

		c.write( '\n' )
		c.write( '\t/* Ios */\n' )

		for i in self.klass.ios:
			if i.override == None:
				c.write( '\tsignals[ %s ]\t=\n'
						'\t\tg_signal_new( "%s",\n'
						'\t\t\t\tG_TYPE_FROM_CLASS( klass ),\n'
						'\t\t\t\tG_SIGNAL_RUN_LAST,\n'
						'\t\t\t\tG_STRUCT_OFFSET( %s, %s ),\n'
						'\t\t\t\tg_signal_accumulator_true_handled,\n'
						'\t\t\t\tNULL,\n'
						'\t\t\t\tg_cclosure_marshal_generic,\n'
						'\t\t\t\tG_TYPE_BOOLEAN,\n'
						'\t\t\t\t%d,\n'
						'\t\t\t\tG_TYPE_TASK'
						%( i.name.upper(), i.name, _utils.klass_name( self.klass.name ),
						i.name, len( i.in_args ) + 1 ))

				for a in i.in_args:
					c.write( ', %s'%_types.arg_dic[ a.sig ][ 'gtype' ] )

				c.write( ' );\n\n' )

		c.write( '\t/* Signals */\n' )

		for s in self.klass.signals:
			c.write( '\tsignals[ %s ]\t=\n'
					'\t\tg_signal_new( "%s",\n'
					'\t\t\t\tG_TYPE_FROM_CLASS( klass ),\n'
					'\t\t\t\tG_SIGNAL_RUN_LAST,\n'
					'\t\t\t\t0,\n'
					'\t\t\t\tNULL,\n'
					'\t\t\t\tNULL,\n'
					'\t\t\t\tg_cclosure_marshal_generic,\n'
					'\t\t\t\tG_TYPE_NONE,\n'
					'\t\t\t\t%d\n'
					'\t\t\t\t'
					%( s.name.upper(), s.name, len( s.in_args ) ))

			for a in s.in_args:
				c.write( ', %s'%_types.arg_dic[ a.sig ][ 'gtype' ] )

			c.write( ' );\n\n' )

		c.write( '}' )
		c.write( '       /* -----  end of static function %s_class_init  ----- */\n'%self.klass.name )

		for i in self.klass.ios:
			if i.override == None:
				c.write( '\n' )
				c.write( '/*\n' )
				c.write( ' * ===  FUNCTION  ======================================================================\n' )
				c.write( ' *         Name:  %s_%s\n'%( self.klass.name, i.name) )
				c.write( ' *  Description:\n' )
				c.write( ' * =====================================================================================\n' )
				c.write( ' */\n' )
				c.write( 'gboolean %s_%s( %s * self'%(self.klass.name,
						i.name, _utils.obj_name( self.klass.name ) ))

				for a in i.in_args:
					c.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))
				for a in i.out_args:
					c.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))


				#c.write( ',\n\tGCancellable * cancellable, GError ** error )\n' )
				c.write( ' )\n' )
				c.write( '{\n' )
				c.write( '\tGVariant * _ret;\n\n' )
				c.write( '\t_ret\t=\tmh_io_invoke_sync( MH_IO( self ), "%s", g_variant_new("('
						%i.name )

				for a in i.in_args:
					c.write( '%s'%_types.arg_dic[ a.sig ][ 'format' ] )

				c.write( ')"' )

				for a in i.in_args:
					c.write( ', %s'%a.name )

				#c.write( '), cancellable, error );\n' )
				c.write( '), NULL, NULL );\n' )

				c.write( '\n' )

				c.write( '\tif( _ret != NULL )\n' )
				c.write( '\t{\n' )
				c.write( '\t\tg_variant_get( _ret, "(' )

				for a in i.out_args:
					c.write( '%s'%_types.arg_dic[ a.sig ][ 'format' ] )

				c.write( ')"' )

				for a in i.out_args:
					c.write( ', %s'%a.name )

				c.write( ' );\n' )

				c.write( '\n\t\tg_variant_unref( _ret );\n' )

				c.write( '\t}\n' )

				c.write( '\n' )

				c.write( '\treturn _ret != NULL ;\n' )

				c.write( '}\t\t/* -----  end of function %s_%s  ----- */\n'%( self.klass.name, i.name) )

				c.write( '\n' )
				c.write( '/*\n' )
				c.write( ' * ===  FUNCTION  ======================================================================\n' )
				c.write( ' *         Name:  %s_complete_%s\n'%( self.klass.name, i.name) )
				c.write( ' *  Description:\n' )
				c.write( ' * =====================================================================================\n' )
				c.write( ' */\n' )
				c.write( 'void %s_complete_%s( %s * self, GTask * task'%(self.klass.name,
						i.name, _utils.obj_name( self.klass.name ) ))

				for a in i.out_args:
					c.write( ', %s %s'%( _types.arg_dic[ a.sig ][ 'in' ], a.name ))

				c.write( ' )\n' )
				c.write( '{\n' )
				c.write( '\tmh_io_invoke_return_value( task, g_variant_new("(' )

				for a in i.out_args:
					c.write( '%s'%_types.arg_dic[ a.sig ][ 'format' ] )

				c.write( ')"' )

				for a in i.out_args:
					c.write( ', %s'%a.name )

				c.write( ') );\n' )

				c.write( '}\t\t/* -----  end of function %s_complete_%s  ----- */\n'%( self.klass.name, i.name) )

		c.write( '\n' )

		for i in self.klass.events:
			c.write( '/*\n' )
			c.write( ' * ===  FUNCTION  ======================================================================\n' )
			c.write( ' *         Name:  %s_%s\n'%( self.klass.name, i.name) )
			c.write( ' *  Description:\n' )
			c.write( ' * =====================================================================================\n' )
			c.write( ' */\n' )
			c.write( 'void %s_%s( %s * self'%(self.klass.name,
					i.name, _utils.obj_name( self.klass.name ) ))

			for a in i.in_args:
				c.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))
			for a in i.out_args:
				c.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

			c.write( ' )\n' )
			c.write( '{\n' )

			c.write( '\tGSource * _source\t=\tg_idle_source_new();\n' )
			c.write( '\n' )
			c.write( '\tg_source_set_callback( _source, _%s, NULL, NULL );\n'%i.name )
			c.write( '\n' )
			c.write( '\tmh_io_dispatch( MH_IO( self ), _source );\n' )
			c.write( '\n' )
			c.write( '\tg_source_unref( _source );\n' )

			c.write( '}\t\t/* -----  end of function %s_%s  ----- */\n'%( self.klass.name, i.name) )

			c.write( '\n' )

		for m in self.klass.methods:
			if m.override == None:
				c.write( '/*\n' )
				c.write( ' * ===  FUNCTION  ======================================================================\n' )
				c.write( ' *         Name:  %s_%s\n'%( self.klass.name, m.name) )
				c.write( ' *  Description:\n' )
				c.write( ' * =====================================================================================\n' )
				c.write( ' */\n' )
				c.write( 'void %s_%s( %s * self'%(self.klass.name,
						m.name, _utils.obj_name( self.klass.name ) ))

				for a in m.in_args:
					c.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))
				for a in m.out_args:
					c.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

				c.write( ' )\n' )
				c.write( '{\n' )
				c.write( '\tg_return_if_fail( %s( self ));\n'%_utils.obj_check( self.klass.name ))
				c.write( '\n' )
				c.write( '\tif( %s( self )->%s != NULL )\n'%( _utils.klass_get( self.klass.name ), m.name ))
				c.write( '\t{\n' )
				c.write( '\t\t%s( self )->%s( self'%( _utils.klass_get( self.klass.name ), m.name ))

				for a in m.in_args:
					c.write( ', %s'%a.name )
				for a in m.out_args:
					c.write( ', %s'% a.name )
				c.write( ' );\n' )

				c.write( '\t}\n' )
				c.write( '\telse\n' )
				c.write( '\t{\n' )
				c.write( '\t\tg_warning( "Class \'%s\' does not implement the pure virtual function ' )
				c.write( '\'%s::%s()\'",\n'%( _utils.klass_name( self.klass.name ), m.name ))
				c.write( '\t\t\t\tG_OBJECT_TYPE_NAME( self ));\n' )
				c.write( '\t}\n' )
				c.write( '}\t\t/* -----  end of function %s_%s  ----- */\n'%( self.klass.name, m.name) )

				c.write( '\n' )
		c.close()

		e	=	open( 'gen/' + self.klass.name + '_ext.c', 'w' )

		for i in self.klass.ios:
			if i.override == None:
				e.write( 'gboolean %s_%s( %s * self'%(self.klass.name,
						i.name, _utils.obj_name( self.klass.name ) ))

				for a in i.in_args:
					e.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

				for a in i.out_args:
					e.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

				e.write( ',\n\tGCancellable * cancellable, GError ** error );\n' )

				e.write( '\n' )

		for i in self.klass.ios:
			if i.override == None:
				e.write( '\n' )
				e.write( '/*\n' )
				e.write( ' * ===  FUNCTION  ======================================================================\n' )
				e.write( ' *         Name:  %s_%s\n'%( self.klass.name, i.name) )
				e.write( ' *  Description:\n' )
				e.write( ' * =====================================================================================\n' )
				e.write( ' */\n' )
				e.write( 'gboolean %s_%s( %s * self'%(self.klass.name,
						i.name, _utils.obj_name( self.klass.name ) ))

				for a in i.in_args:
					e.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))
				for a in i.out_args:
					e.write( ', %s %s'%( _types.arg_dic[ a.sig ][ a.direction ], a.name ))

				e.write( ',\n\tGCancellable * cancellable, GError ** error )\n' )
				e.write( '{\n' )
				e.write( '\tGVariant * _result;\n' )
				e.write( '\tgboolean * _ret;\n' )
				e.write( '\t_ret\t=\tmediahub_invoke_mh_ext_io_sync( mh_proxy, plugin, "%s", g_variant_new("('
						%i.name )

				for a in i.in_args:
					e.write( '%s'%_types.arg_dic[ a.sig ][ 'format' ] )

				e.write( ')"' )

				for a in i.in_args:
					e.write( ', %s'%a.name )

				e.write( '), &_result, cancellable, error );\n' )

				e.write( '\n' )

				e.write( '\tif( _ret )\n' )
				e.write( '\t{\n' )
				e.write( '\t\tg_variant_get( _result, "(' )

				for a in i.out_args:
					e.write( '%s'%_types.arg_dic[ a.sig ][ 'format' ] )

				e.write( ')"' )

				for a in i.out_args:
					e.write( ', %s'%a.name )

				e.write( ' );\n' )

				e.write( '\n\t\tg_variant_unref( _result );\n' )

				e.write( '\t}\n' )

				e.write( '\n' )

				e.write( '\treturn _ret ;\n' )

				e.write( '}\t\t/* -----  end of function %s_%s  ----- */\n'%( self.klass.name, i.name) )

		e.close()

	def generate( self ):
		self.generate_h()
		self.generate_c()

