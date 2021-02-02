/* quilterdark.c generated by valac 0.50.2, the Vala compiler
 * generated from quilterdark.vala, do not modify */

/*
The MIT License (MIT)

Copyright (c) 2017-2020 Lains

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gobject/gvaluecollector.h>

#define QUILTER_STYLES_TYPE_QUILTERDARK (quilter_styles_quilterdark_get_type ())
#define QUILTER_STYLES_QUILTERDARK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), QUILTER_STYLES_TYPE_QUILTERDARK, QuilterStylesquilterdark))
#define QUILTER_STYLES_QUILTERDARK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), QUILTER_STYLES_TYPE_QUILTERDARK, QuilterStylesquilterdarkClass))
#define QUILTER_STYLES_IS_QUILTERDARK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QUILTER_STYLES_TYPE_QUILTERDARK))
#define QUILTER_STYLES_IS_QUILTERDARK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), QUILTER_STYLES_TYPE_QUILTERDARK))
#define QUILTER_STYLES_QUILTERDARK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), QUILTER_STYLES_TYPE_QUILTERDARK, QuilterStylesquilterdarkClass))

typedef struct _QuilterStylesquilterdark QuilterStylesquilterdark;
typedef struct _QuilterStylesquilterdarkClass QuilterStylesquilterdarkClass;
typedef struct _QuilterStylesquilterdarkPrivate QuilterStylesquilterdarkPrivate;
typedef struct _QuilterStylesParamSpecquilterdark QuilterStylesParamSpecquilterdark;

struct _QuilterStylesquilterdark {
	GTypeInstance parent_instance;
	volatile int ref_count;
	QuilterStylesquilterdarkPrivate * priv;
};

struct _QuilterStylesquilterdarkClass {
	GTypeClass parent_class;
	void (*finalize) (QuilterStylesquilterdark *self);
};

struct _QuilterStylesParamSpecquilterdark {
	GParamSpec parent_instance;
};

static gpointer quilter_styles_quilterdark_parent_class = NULL;

gpointer quilter_styles_quilterdark_ref (gpointer instance);
void quilter_styles_quilterdark_unref (gpointer instance);
GParamSpec* quilter_styles_param_spec_quilterdark (const gchar* name,
                                                   const gchar* nick,
                                                   const gchar* blurb,
                                                   GType object_type,
                                                   GParamFlags flags);
void quilter_styles_value_set_quilterdark (GValue* value,
                                           gpointer v_object);
void quilter_styles_value_take_quilterdark (GValue* value,
                                            gpointer v_object);
gpointer quilter_styles_value_get_quilterdark (const GValue* value);
GType quilter_styles_quilterdark_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QuilterStylesquilterdark, quilter_styles_quilterdark_unref)
#define QUILTER_STYLES_QUILTERDARK_css "\n" \
"    html {\n" \
"      font-size: 13pt;\n" \
"      width: 100%;\n" \
"      margin: 0 auto;\n" \
"    }\n" \
"\n" \
"    p {\n" \
"      font-size: 13pt;\n" \
"      line-height: 1.618rem;\n" \
"      color: #C3C3C1;\n" \
"    }\n" \
"\n" \
"    h1,\n" \
"    h2,\n" \
"    h3,\n" \
"    h4,\n" \
"    h5,\n" \
"    h6 {\n" \
"      font-style: bold;\n" \
"      margin-top: 1em;\n" \
"      line-height: 1.618rem;\n" \
"    }\n" \
"\n" \
"    h1 {\n" \
"      font-size: 2em;\n" \
"      text-transform: uppercase;\n" \
"    }\n" \
"\n" \
"    h2 {\n" \
"      font-size: 1.5em;\n" \
"    }\n" \
"\n" \
"    h3 {\n" \
"      font-size: 1.17em;\n" \
"    }\n" \
"\n" \
"    h4 {\n" \
"      font-size: 1.12em;\n" \
"    }\n" \
"\n" \
"    h5 {\n" \
"      font-size: .83em;\n" \
"    }\n" \
"\n" \
"    h6 {\n" \
"      font-size: .75em;\n" \
"    }\n" \
"\n" \
"    small {\n" \
"      font-size: .7em;\n" \
"    }\n" \
"\n" \
"    img,\n" \
"    canvas,\n" \
"    iframe,\n" \
"    video,\n" \
"    select,\n" \
"    textarea {\n" \
"      display: block;\n" \
"      max-width: 50%;\n" \
"    }\n" \
"\n" \
"    body {\n" \
"      color: #C3C3C3;\n" \
"      background-color: #111111;\n" \
"      font-weight: 400;\n" \
"      line-height: 1.618rem;\n" \
"      margin-left: 3rem;\n" \
"      margin-right: 3rem;\n" \
"      margin-top: 3rem;\n" \
"      margin-bottom: 3rem;\n" \
"      text-align: left;\n" \
"    }\n" \
"\n" \
"    table {\n" \
"      border-spacing: 0;\n" \
"      border-collapse: collapse;\n" \
"      margin-top: 0;\n" \
"      margin-bottom: 16px;\n" \
"    }\n" \
"\n" \
"    table th {\n" \
"      font-weight: bold;\n" \
"      background-color: #2b2b2b;\n" \
"    }\n" \
"\n" \
"    table th,\n" \
"    table td {\n" \
"      padding: 8px 13px;\n" \
"      border: 1px solid #2b2b2b;\n" \
"    }\n" \
"\n" \
"    table tr {\n" \
"      border-top: 1px solid #2b2b2b;\n" \
"    }\n" \
"\n" \
"    img {\n" \
"      height: auto;\n" \
"      margin: 0 auto;\n" \
"    }\n" \
"\n" \
"    a,\n" \
"    a:visited,\n" \
"    a:hover,\n" \
"    a:focus,\n" \
"    a:active {\n" \
"      color: #1d99f3;\n" \
"    }\n" \
"\n" \
"    code{\n" \
"      display: inline-block;\n" \
"      padding: 0 0.25rem;\n" \
"      background-color: #23241c;\n" \
"      border: 1px solid #23241c;\n" \
"      border-radius: 4px;\n" \
"      font-family: 'Quilt Mono', monospace;\n" \
"      font-weight: normal;\n" \
"    }\n" \
"\n" \
"    pre code{\n" \
"      display: block;\n" \
"      margin: 1rem auto;\n" \
"      overflow-x: scroll;\n" \
"      padding: 0.5em;\n" \
"    }\n" \
"\n" \
"    blockquote {\n" \
"      margin: 0;\n" \
"      border-left: 5px solid #7E8087;\n" \
"      font-style: italic;\n" \
"      padding-left: .8rem;\n" \
"      margin-left: .8rem;\n" \
"      text-align: left;\n" \
"    }\n" \
"\n" \
"    blockquote > p {\n" \
"      color: inherit;\n" \
"      margin-top: 20px;\n" \
"      margin-bottom: 20px;\n" \
"      padding-top: 20px;\n" \
"      padding-bottom: 20px;\n" \
"    }\n" \
"\n" \
"    ul {\n" \
"      list-style: disc;\n" \
"    }\n" \
"\n" \
"    ul>li {\n" \
"      font-size: 18px;\n" \
"    }\n" \
"\n" \
"    hr {\n" \
"      overflow: visible;\n" \
"      padding: 0;\n" \
"      border: none;\n" \
"      color: inherit;\n" \
"      text-align: center;\n" \
"    }\n" \
"    hr:after {\n" \
"      content: \"...\";\n" \
"      letter-spacing: .6em;\n" \
"      display: inline-block;\n" \
"      position: relative;\n" \
"      top: -0.3rem;\n" \
"      font-size: 1.65em;\n" \
"      padding: 0 0.25em;\n" \
"      background: inherit;\n" \
"    }\n" \
"  "
QuilterStylesquilterdark* quilter_styles_quilterdark_new (void);
QuilterStylesquilterdark* quilter_styles_quilterdark_construct (GType object_type);
static void quilter_styles_quilterdark_finalize (QuilterStylesquilterdark * obj);
static GType quilter_styles_quilterdark_get_type_once (void);

QuilterStylesquilterdark*
quilter_styles_quilterdark_construct (GType object_type)
{
	QuilterStylesquilterdark* self = NULL;
#line 25 "../src/Styles/quilterdark.vala"
	self = (QuilterStylesquilterdark*) g_type_create_instance (object_type);
#line 25 "../src/Styles/quilterdark.vala"
	return self;
#line 92 "quilterdark.c"
}

QuilterStylesquilterdark*
quilter_styles_quilterdark_new (void)
{
#line 25 "../src/Styles/quilterdark.vala"
	return quilter_styles_quilterdark_construct (QUILTER_STYLES_TYPE_QUILTERDARK);
#line 100 "quilterdark.c"
}

static void
quilter_styles_value_quilterdark_init (GValue* value)
{
#line 25 "../src/Styles/quilterdark.vala"
	value->data[0].v_pointer = NULL;
#line 108 "quilterdark.c"
}

static void
quilter_styles_value_quilterdark_free_value (GValue* value)
{
#line 25 "../src/Styles/quilterdark.vala"
	if (value->data[0].v_pointer) {
#line 25 "../src/Styles/quilterdark.vala"
		quilter_styles_quilterdark_unref (value->data[0].v_pointer);
#line 118 "quilterdark.c"
	}
}

static void
quilter_styles_value_quilterdark_copy_value (const GValue* src_value,
                                             GValue* dest_value)
{
#line 25 "../src/Styles/quilterdark.vala"
	if (src_value->data[0].v_pointer) {
#line 25 "../src/Styles/quilterdark.vala"
		dest_value->data[0].v_pointer = quilter_styles_quilterdark_ref (src_value->data[0].v_pointer);
#line 130 "quilterdark.c"
	} else {
#line 25 "../src/Styles/quilterdark.vala"
		dest_value->data[0].v_pointer = NULL;
#line 134 "quilterdark.c"
	}
}

static gpointer
quilter_styles_value_quilterdark_peek_pointer (const GValue* value)
{
#line 25 "../src/Styles/quilterdark.vala"
	return value->data[0].v_pointer;
#line 143 "quilterdark.c"
}

static gchar*
quilter_styles_value_quilterdark_collect_value (GValue* value,
                                                guint n_collect_values,
                                                GTypeCValue* collect_values,
                                                guint collect_flags)
{
#line 25 "../src/Styles/quilterdark.vala"
	if (collect_values[0].v_pointer) {
#line 154 "quilterdark.c"
		QuilterStylesquilterdark * object;
		object = collect_values[0].v_pointer;
#line 25 "../src/Styles/quilterdark.vala"
		if (object->parent_instance.g_class == NULL) {
#line 25 "../src/Styles/quilterdark.vala"
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 161 "quilterdark.c"
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
#line 25 "../src/Styles/quilterdark.vala"
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 165 "quilterdark.c"
		}
#line 25 "../src/Styles/quilterdark.vala"
		value->data[0].v_pointer = quilter_styles_quilterdark_ref (object);
#line 169 "quilterdark.c"
	} else {
#line 25 "../src/Styles/quilterdark.vala"
		value->data[0].v_pointer = NULL;
#line 173 "quilterdark.c"
	}
#line 25 "../src/Styles/quilterdark.vala"
	return NULL;
#line 177 "quilterdark.c"
}

static gchar*
quilter_styles_value_quilterdark_lcopy_value (const GValue* value,
                                              guint n_collect_values,
                                              GTypeCValue* collect_values,
                                              guint collect_flags)
{
	QuilterStylesquilterdark ** object_p;
	object_p = collect_values[0].v_pointer;
#line 25 "../src/Styles/quilterdark.vala"
	if (!object_p) {
#line 25 "../src/Styles/quilterdark.vala"
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
#line 192 "quilterdark.c"
	}
#line 25 "../src/Styles/quilterdark.vala"
	if (!value->data[0].v_pointer) {
#line 25 "../src/Styles/quilterdark.vala"
		*object_p = NULL;
#line 198 "quilterdark.c"
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
#line 25 "../src/Styles/quilterdark.vala"
		*object_p = value->data[0].v_pointer;
#line 202 "quilterdark.c"
	} else {
#line 25 "../src/Styles/quilterdark.vala"
		*object_p = quilter_styles_quilterdark_ref (value->data[0].v_pointer);
#line 206 "quilterdark.c"
	}
#line 25 "../src/Styles/quilterdark.vala"
	return NULL;
#line 210 "quilterdark.c"
}

GParamSpec*
quilter_styles_param_spec_quilterdark (const gchar* name,
                                       const gchar* nick,
                                       const gchar* blurb,
                                       GType object_type,
                                       GParamFlags flags)
{
	QuilterStylesParamSpecquilterdark* spec;
#line 25 "../src/Styles/quilterdark.vala"
	g_return_val_if_fail (g_type_is_a (object_type, QUILTER_STYLES_TYPE_QUILTERDARK), NULL);
#line 25 "../src/Styles/quilterdark.vala"
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
#line 25 "../src/Styles/quilterdark.vala"
	G_PARAM_SPEC (spec)->value_type = object_type;
#line 25 "../src/Styles/quilterdark.vala"
	return G_PARAM_SPEC (spec);
#line 229 "quilterdark.c"
}

gpointer
quilter_styles_value_get_quilterdark (const GValue* value)
{
#line 25 "../src/Styles/quilterdark.vala"
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, QUILTER_STYLES_TYPE_QUILTERDARK), NULL);
#line 25 "../src/Styles/quilterdark.vala"
	return value->data[0].v_pointer;
#line 239 "quilterdark.c"
}

void
quilter_styles_value_set_quilterdark (GValue* value,
                                      gpointer v_object)
{
	QuilterStylesquilterdark * old;
#line 25 "../src/Styles/quilterdark.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, QUILTER_STYLES_TYPE_QUILTERDARK));
#line 25 "../src/Styles/quilterdark.vala"
	old = value->data[0].v_pointer;
#line 25 "../src/Styles/quilterdark.vala"
	if (v_object) {
#line 25 "../src/Styles/quilterdark.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, QUILTER_STYLES_TYPE_QUILTERDARK));
#line 25 "../src/Styles/quilterdark.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 25 "../src/Styles/quilterdark.vala"
		value->data[0].v_pointer = v_object;
#line 25 "../src/Styles/quilterdark.vala"
		quilter_styles_quilterdark_ref (value->data[0].v_pointer);
#line 261 "quilterdark.c"
	} else {
#line 25 "../src/Styles/quilterdark.vala"
		value->data[0].v_pointer = NULL;
#line 265 "quilterdark.c"
	}
#line 25 "../src/Styles/quilterdark.vala"
	if (old) {
#line 25 "../src/Styles/quilterdark.vala"
		quilter_styles_quilterdark_unref (old);
#line 271 "quilterdark.c"
	}
}

void
quilter_styles_value_take_quilterdark (GValue* value,
                                       gpointer v_object)
{
	QuilterStylesquilterdark * old;
#line 25 "../src/Styles/quilterdark.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, QUILTER_STYLES_TYPE_QUILTERDARK));
#line 25 "../src/Styles/quilterdark.vala"
	old = value->data[0].v_pointer;
#line 25 "../src/Styles/quilterdark.vala"
	if (v_object) {
#line 25 "../src/Styles/quilterdark.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, QUILTER_STYLES_TYPE_QUILTERDARK));
#line 25 "../src/Styles/quilterdark.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 25 "../src/Styles/quilterdark.vala"
		value->data[0].v_pointer = v_object;
#line 292 "quilterdark.c"
	} else {
#line 25 "../src/Styles/quilterdark.vala"
		value->data[0].v_pointer = NULL;
#line 296 "quilterdark.c"
	}
#line 25 "../src/Styles/quilterdark.vala"
	if (old) {
#line 25 "../src/Styles/quilterdark.vala"
		quilter_styles_quilterdark_unref (old);
#line 302 "quilterdark.c"
	}
}

static void
quilter_styles_quilterdark_class_init (QuilterStylesquilterdarkClass * klass,
                                       gpointer klass_data)
{
#line 25 "../src/Styles/quilterdark.vala"
	quilter_styles_quilterdark_parent_class = g_type_class_peek_parent (klass);
#line 25 "../src/Styles/quilterdark.vala"
	((QuilterStylesquilterdarkClass *) klass)->finalize = quilter_styles_quilterdark_finalize;
#line 314 "quilterdark.c"
}

static void
quilter_styles_quilterdark_instance_init (QuilterStylesquilterdark * self,
                                          gpointer klass)
{
#line 25 "../src/Styles/quilterdark.vala"
	self->ref_count = 1;
#line 323 "quilterdark.c"
}

static void
quilter_styles_quilterdark_finalize (QuilterStylesquilterdark * obj)
{
	QuilterStylesquilterdark * self;
#line 25 "../src/Styles/quilterdark.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, QUILTER_STYLES_TYPE_QUILTERDARK, QuilterStylesquilterdark);
#line 25 "../src/Styles/quilterdark.vala"
	g_signal_handlers_destroy (self);
#line 334 "quilterdark.c"
}

static GType
quilter_styles_quilterdark_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { quilter_styles_value_quilterdark_init, quilter_styles_value_quilterdark_free_value, quilter_styles_value_quilterdark_copy_value, quilter_styles_value_quilterdark_peek_pointer, "p", quilter_styles_value_quilterdark_collect_value, "p", quilter_styles_value_quilterdark_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (QuilterStylesquilterdarkClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) quilter_styles_quilterdark_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (QuilterStylesquilterdark), 0, (GInstanceInitFunc) quilter_styles_quilterdark_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType quilter_styles_quilterdark_type_id;
	quilter_styles_quilterdark_type_id = g_type_register_fundamental (g_type_fundamental_next (), "QuilterStylesquilterdark", &g_define_type_info, &g_define_type_fundamental_info, 0);
	return quilter_styles_quilterdark_type_id;
}

GType
quilter_styles_quilterdark_get_type (void)
{
	static volatile gsize quilter_styles_quilterdark_type_id__volatile = 0;
	if (g_once_init_enter (&quilter_styles_quilterdark_type_id__volatile)) {
		GType quilter_styles_quilterdark_type_id;
		quilter_styles_quilterdark_type_id = quilter_styles_quilterdark_get_type_once ();
		g_once_init_leave (&quilter_styles_quilterdark_type_id__volatile, quilter_styles_quilterdark_type_id);
	}
	return quilter_styles_quilterdark_type_id__volatile;
}

gpointer
quilter_styles_quilterdark_ref (gpointer instance)
{
	QuilterStylesquilterdark * self;
	self = instance;
#line 25 "../src/Styles/quilterdark.vala"
	g_atomic_int_inc (&self->ref_count);
#line 25 "../src/Styles/quilterdark.vala"
	return instance;
#line 369 "quilterdark.c"
}

void
quilter_styles_quilterdark_unref (gpointer instance)
{
	QuilterStylesquilterdark * self;
	self = instance;
#line 25 "../src/Styles/quilterdark.vala"
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
#line 25 "../src/Styles/quilterdark.vala"
		QUILTER_STYLES_QUILTERDARK_GET_CLASS (self)->finalize (self);
#line 25 "../src/Styles/quilterdark.vala"
		g_type_free_instance ((GTypeInstance *) self);
#line 383 "quilterdark.c"
	}
}

