/* Subscript.c generated by valac 0.50.2, the Vala compiler
 * generated from Subscript.vala, do not modify */

/*
* Copyright (c) 2019-2020 Lains
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc., 59 Temple Place - Suite 330,
* Boston, MA 02111-1307, USA.
*
* Co-authored by: Felipe Escoto <felescoto95@hotmail.com>
*/

#include <glib-object.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <glib/gi18n-lib.h>

#define QUILTER_PLUGINS_TYPE_PLUGIN (quilter_plugins_plugin_get_type ())
#define QUILTER_PLUGINS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), QUILTER_PLUGINS_TYPE_PLUGIN, QuilterPluginsPlugin))
#define QUILTER_PLUGINS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), QUILTER_PLUGINS_TYPE_PLUGIN, QuilterPluginsPluginClass))
#define QUILTER_PLUGINS_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QUILTER_PLUGINS_TYPE_PLUGIN))
#define QUILTER_PLUGINS_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), QUILTER_PLUGINS_TYPE_PLUGIN))
#define QUILTER_PLUGINS_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), QUILTER_PLUGINS_TYPE_PLUGIN, QuilterPluginsPluginClass))

typedef struct _QuilterPluginsPlugin QuilterPluginsPlugin;
typedef struct _QuilterPluginsPluginClass QuilterPluginsPluginClass;
typedef struct _QuilterPluginsPluginPrivate QuilterPluginsPluginPrivate;

#define QUILTER_TYPE_SUBSCRIPT (quilter_subscript_get_type ())
#define QUILTER_SUBSCRIPT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), QUILTER_TYPE_SUBSCRIPT, QuilterSubscript))
#define QUILTER_SUBSCRIPT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), QUILTER_TYPE_SUBSCRIPT, QuilterSubscriptClass))
#define QUILTER_IS_SUBSCRIPT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QUILTER_TYPE_SUBSCRIPT))
#define QUILTER_IS_SUBSCRIPT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), QUILTER_TYPE_SUBSCRIPT))
#define QUILTER_SUBSCRIPT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), QUILTER_TYPE_SUBSCRIPT, QuilterSubscriptClass))

typedef struct _QuilterSubscript QuilterSubscript;
typedef struct _QuilterSubscriptClass QuilterSubscriptClass;
typedef struct _QuilterSubscriptPrivate QuilterSubscriptPrivate;
enum  {
	QUILTER_SUBSCRIPT_0_PROPERTY,
	QUILTER_SUBSCRIPT_NUM_PROPERTIES
};
static GParamSpec* quilter_subscript_properties[QUILTER_SUBSCRIPT_NUM_PROPERTIES];
#define _g_pattern_spec_free0(var) ((var == NULL) ? NULL : (var = (g_pattern_spec_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))

struct _QuilterPluginsPlugin {
	GObject parent_instance;
	QuilterPluginsPluginPrivate * priv;
	GSettings* settings;
	gboolean state;
	gchar* code_name;
};

struct _QuilterPluginsPluginClass {
	GObjectClass parent_class;
	gboolean (*is_active) (QuilterPluginsPlugin* self);
	void (*set_active) (QuilterPluginsPlugin* self, gboolean active);
	gchar* (*get_desctiption) (QuilterPluginsPlugin* self);
	gchar* (*get_name) (QuilterPluginsPlugin* self);
	gboolean (*has_match) (QuilterPluginsPlugin* self, const gchar* text);
	gchar* (*convert) (QuilterPluginsPlugin* self, const gchar* line);
	GtkWidget* (*editor_button) (QuilterPluginsPlugin* self);
	gchar* (*get_button_desctiption) (QuilterPluginsPlugin* self);
	gchar* (*request_string) (QuilterPluginsPlugin* self, const gchar* selection);
};

struct _QuilterSubscript {
	QuilterPluginsPlugin parent_instance;
	QuilterSubscriptPrivate * priv;
};

struct _QuilterSubscriptClass {
	QuilterPluginsPluginClass parent_class;
};

struct _QuilterSubscriptPrivate {
	GPatternSpec* spec;
};

static gint QuilterSubscript_private_offset;
static gpointer quilter_subscript_parent_class = NULL;

GType quilter_plugins_plugin_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QuilterPluginsPlugin, g_object_unref)
GType quilter_subscript_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QuilterSubscript, g_object_unref)
gchar* quilter_plugins_plugin_get_desctiption (QuilterPluginsPlugin* self);
gchar* quilter_plugins_plugin_get_name (QuilterPluginsPlugin* self);
GtkWidget* quilter_plugins_plugin_editor_button (QuilterPluginsPlugin* self);
gchar* quilter_plugins_plugin_request_string (QuilterPluginsPlugin* self,
                                              const gchar* selection);
gchar* quilter_plugins_plugin_get_button_desctiption (QuilterPluginsPlugin* self);
gboolean quilter_plugins_plugin_has_match (QuilterPluginsPlugin* self,
                                           const gchar* text);
gchar* quilter_plugins_plugin_convert (QuilterPluginsPlugin* self,
                                       const gchar* line);
static gchar* quilter_subscript_real_get_desctiption (QuilterPluginsPlugin* base);
static gchar* quilter_subscript_real_get_name (QuilterPluginsPlugin* base);
static GtkWidget* quilter_subscript_real_editor_button (QuilterPluginsPlugin* base);
static gchar* quilter_subscript_real_request_string (QuilterPluginsPlugin* base,
                                              const gchar* selection);
static gchar* quilter_subscript_real_get_button_desctiption (QuilterPluginsPlugin* base);
static gboolean quilter_subscript_real_has_match (QuilterPluginsPlugin* base,
                                           const gchar* text);
static gchar* quilter_subscript_real_convert (QuilterPluginsPlugin* base,
                                       const gchar* line_);
QuilterSubscript* quilter_subscript_new (void);
QuilterSubscript* quilter_subscript_construct (GType object_type);
QuilterPluginsPlugin* quilter_plugins_plugin_construct (GType object_type);
static GObject * quilter_subscript_constructor (GType type,
                                         guint n_construct_properties,
                                         GObjectConstructParam * construct_properties);
static void quilter_subscript_finalize (GObject * obj);
static GType quilter_subscript_get_type_once (void);

static inline gpointer
quilter_subscript_get_instance_private (QuilterSubscript* self)
{
	return G_STRUCT_MEMBER_P (self, QuilterSubscript_private_offset);
}

static gchar*
quilter_subscript_real_get_desctiption (QuilterPluginsPlugin* base)
{
	QuilterSubscript * self;
	gchar* _tmp0_;
	gchar* result = NULL;
#line 27 "../src/Plugins/Subscript.vala"
	self = (QuilterSubscript*) base;
#line 28 "../src/Plugins/Subscript.vala"
	_tmp0_ = g_strdup (_ ("Make text on the bottom."));
#line 28 "../src/Plugins/Subscript.vala"
	result = _tmp0_;
#line 28 "../src/Plugins/Subscript.vala"
	return result;
#line 154 "Subscript.c"
}

static gchar*
quilter_subscript_real_get_name (QuilterPluginsPlugin* base)
{
	QuilterSubscript * self;
	gchar* _tmp0_;
	gchar* result = NULL;
#line 31 "../src/Plugins/Subscript.vala"
	self = (QuilterSubscript*) base;
#line 32 "../src/Plugins/Subscript.vala"
	_tmp0_ = g_strdup (_ ("Subscript"));
#line 32 "../src/Plugins/Subscript.vala"
	result = _tmp0_;
#line 32 "../src/Plugins/Subscript.vala"
	return result;
#line 171 "Subscript.c"
}

static GtkWidget*
quilter_subscript_real_editor_button (QuilterPluginsPlugin* base)
{
	QuilterSubscript * self;
	GtkWidget* result = NULL;
#line 35 "../src/Plugins/Subscript.vala"
	self = (QuilterSubscript*) base;
#line 36 "../src/Plugins/Subscript.vala"
	result = NULL;
#line 36 "../src/Plugins/Subscript.vala"
	return result;
#line 185 "Subscript.c"
}

static gchar*
quilter_subscript_real_request_string (QuilterPluginsPlugin* base,
                                       const gchar* selection)
{
	QuilterSubscript * self;
	gchar* _tmp0_;
	gchar* result = NULL;
#line 39 "../src/Plugins/Subscript.vala"
	self = (QuilterSubscript*) base;
#line 39 "../src/Plugins/Subscript.vala"
	g_return_val_if_fail (selection != NULL, NULL);
#line 40 "../src/Plugins/Subscript.vala"
	_tmp0_ = g_strdup (selection);
#line 40 "../src/Plugins/Subscript.vala"
	result = _tmp0_;
#line 40 "../src/Plugins/Subscript.vala"
	return result;
#line 205 "Subscript.c"
}

static gchar*
quilter_subscript_real_get_button_desctiption (QuilterPluginsPlugin* base)
{
	QuilterSubscript * self;
	gchar* _tmp0_;
	gchar* result = NULL;
#line 43 "../src/Plugins/Subscript.vala"
	self = (QuilterSubscript*) base;
#line 44 "../src/Plugins/Subscript.vala"
	_tmp0_ = g_strdup ("");
#line 44 "../src/Plugins/Subscript.vala"
	result = _tmp0_;
#line 44 "../src/Plugins/Subscript.vala"
	return result;
#line 222 "Subscript.c"
}

static gboolean
quilter_subscript_real_has_match (QuilterPluginsPlugin* base,
                                  const gchar* text)
{
	QuilterSubscript * self;
	GPatternSpec* _tmp0_;
	gboolean result = FALSE;
#line 47 "../src/Plugins/Subscript.vala"
	self = (QuilterSubscript*) base;
#line 47 "../src/Plugins/Subscript.vala"
	g_return_val_if_fail (text != NULL, FALSE);
#line 48 "../src/Plugins/Subscript.vala"
	_tmp0_ = self->priv->spec;
#line 48 "../src/Plugins/Subscript.vala"
	result = g_pattern_match_string (_tmp0_, text);
#line 48 "../src/Plugins/Subscript.vala"
	return result;
#line 242 "Subscript.c"
}

static gint
string_index_of (const gchar* self,
                 const gchar* needle,
                 gint start_index)
{
	gchar* _result_ = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gint result = 0;
#line 1133 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, 0);
#line 1133 "glib-2.0.vapi"
	g_return_val_if_fail (needle != NULL, 0);
#line 1134 "glib-2.0.vapi"
	_tmp0_ = strstr (((gchar*) self) + start_index, (gchar*) needle);
#line 1134 "glib-2.0.vapi"
	_result_ = _tmp0_;
#line 1136 "glib-2.0.vapi"
	_tmp1_ = _result_;
#line 1136 "glib-2.0.vapi"
	if (_tmp1_ != NULL) {
#line 266 "Subscript.c"
		gchar* _tmp2_;
#line 1137 "glib-2.0.vapi"
		_tmp2_ = _result_;
#line 1137 "glib-2.0.vapi"
		result = (gint) (_tmp2_ - ((gchar*) self));
#line 1137 "glib-2.0.vapi"
		return result;
#line 274 "Subscript.c"
	} else {
#line 1139 "glib-2.0.vapi"
		result = -1;
#line 1139 "glib-2.0.vapi"
		return result;
#line 280 "Subscript.c"
	}
}

static glong
string_strnlen (gchar* str,
                glong maxlen)
{
	gchar* end = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	glong result = 0L;
#line 1447 "glib-2.0.vapi"
	_tmp0_ = memchr (str, 0, (gsize) maxlen);
#line 1447 "glib-2.0.vapi"
	end = _tmp0_;
#line 1448 "glib-2.0.vapi"
	_tmp1_ = end;
#line 1448 "glib-2.0.vapi"
	if (_tmp1_ == NULL) {
#line 1449 "glib-2.0.vapi"
		result = maxlen;
#line 1449 "glib-2.0.vapi"
		return result;
#line 304 "Subscript.c"
	} else {
		gchar* _tmp2_;
#line 1451 "glib-2.0.vapi"
		_tmp2_ = end;
#line 1451 "glib-2.0.vapi"
		result = (glong) (_tmp2_ - str);
#line 1451 "glib-2.0.vapi"
		return result;
#line 313 "Subscript.c"
	}
}

static gchar*
string_substring (const gchar* self,
                  glong offset,
                  glong len)
{
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	gchar* _tmp3_;
	gchar* result = NULL;
#line 1458 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1460 "glib-2.0.vapi"
	if (offset >= ((glong) 0)) {
#line 1460 "glib-2.0.vapi"
		_tmp0_ = len >= ((glong) 0);
#line 332 "Subscript.c"
	} else {
#line 1460 "glib-2.0.vapi"
		_tmp0_ = FALSE;
#line 336 "Subscript.c"
	}
#line 1460 "glib-2.0.vapi"
	if (_tmp0_) {
#line 1462 "glib-2.0.vapi"
		string_length = string_strnlen ((gchar*) self, offset + len);
#line 342 "Subscript.c"
	} else {
		gint _tmp1_;
		gint _tmp2_;
#line 1464 "glib-2.0.vapi"
		_tmp1_ = strlen (self);
#line 1464 "glib-2.0.vapi"
		_tmp2_ = _tmp1_;
#line 1464 "glib-2.0.vapi"
		string_length = (glong) _tmp2_;
#line 352 "Subscript.c"
	}
#line 1467 "glib-2.0.vapi"
	if (offset < ((glong) 0)) {
#line 1468 "glib-2.0.vapi"
		offset = string_length + offset;
#line 1469 "glib-2.0.vapi"
		g_return_val_if_fail (offset >= ((glong) 0), NULL);
#line 360 "Subscript.c"
	} else {
#line 1471 "glib-2.0.vapi"
		g_return_val_if_fail (offset <= string_length, NULL);
#line 364 "Subscript.c"
	}
#line 1473 "glib-2.0.vapi"
	if (len < ((glong) 0)) {
#line 1474 "glib-2.0.vapi"
		len = string_length - offset;
#line 370 "Subscript.c"
	}
#line 1476 "glib-2.0.vapi"
	g_return_val_if_fail ((offset + len) <= string_length, NULL);
#line 1477 "glib-2.0.vapi"
	_tmp3_ = g_strndup (((gchar*) self) + offset, (gsize) len);
#line 1477 "glib-2.0.vapi"
	result = _tmp3_;
#line 1477 "glib-2.0.vapi"
	return result;
#line 380 "Subscript.c"
}

static gchar*
string_replace (const gchar* self,
                const gchar* old,
                const gchar* replacement)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	GError* _inner_error0_ = NULL;
	gchar* result = NULL;
#line 1534 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1534 "glib-2.0.vapi"
	g_return_val_if_fail (old != NULL, NULL);
#line 1534 "glib-2.0.vapi"
	g_return_val_if_fail (replacement != NULL, NULL);
#line 1535 "glib-2.0.vapi"
	if ((*((gchar*) self)) == '\0') {
#line 1535 "glib-2.0.vapi"
		_tmp1_ = TRUE;
#line 402 "Subscript.c"
	} else {
#line 1535 "glib-2.0.vapi"
		_tmp1_ = (*((gchar*) old)) == '\0';
#line 406 "Subscript.c"
	}
#line 1535 "glib-2.0.vapi"
	if (_tmp1_) {
#line 1535 "glib-2.0.vapi"
		_tmp0_ = TRUE;
#line 412 "Subscript.c"
	} else {
#line 1535 "glib-2.0.vapi"
		_tmp0_ = g_strcmp0 (old, replacement) == 0;
#line 416 "Subscript.c"
	}
#line 1535 "glib-2.0.vapi"
	if (_tmp0_) {
#line 420 "Subscript.c"
		gchar* _tmp2_;
#line 1536 "glib-2.0.vapi"
		_tmp2_ = g_strdup (self);
#line 1536 "glib-2.0.vapi"
		result = _tmp2_;
#line 1536 "glib-2.0.vapi"
		return result;
#line 428 "Subscript.c"
	}
	{
		GRegex* regex = NULL;
		gchar* _tmp3_;
		gchar* _tmp4_;
		GRegex* _tmp5_;
		GRegex* _tmp6_;
		gchar* _tmp7_ = NULL;
		GRegex* _tmp8_;
		gchar* _tmp9_;
		gchar* _tmp10_;
#line 1539 "glib-2.0.vapi"
		_tmp3_ = g_regex_escape_string (old, -1);
#line 1539 "glib-2.0.vapi"
		_tmp4_ = _tmp3_;
#line 1539 "glib-2.0.vapi"
		_tmp5_ = g_regex_new (_tmp4_, 0, 0, &_inner_error0_);
#line 1539 "glib-2.0.vapi"
		_tmp6_ = _tmp5_;
#line 1539 "glib-2.0.vapi"
		_g_free0 (_tmp4_);
#line 1539 "glib-2.0.vapi"
		regex = _tmp6_;
#line 1539 "glib-2.0.vapi"
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 1539 "glib-2.0.vapi"
			_g_free0 (_tmp7_);
#line 1539 "glib-2.0.vapi"
			_g_regex_unref0 (regex);
#line 1539 "glib-2.0.vapi"
			if (_inner_error0_->domain == G_REGEX_ERROR) {
#line 460 "Subscript.c"
				goto __catch0_g_regex_error;
			}
#line 1539 "glib-2.0.vapi"
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 1539 "glib-2.0.vapi"
			g_clear_error (&_inner_error0_);
#line 1539 "glib-2.0.vapi"
			return NULL;
#line 469 "Subscript.c"
		}
#line 1540 "glib-2.0.vapi"
		_tmp8_ = regex;
#line 1540 "glib-2.0.vapi"
		_tmp9_ = g_regex_replace_literal (_tmp8_, self, (gssize) -1, 0, replacement, 0, &_inner_error0_);
#line 1540 "glib-2.0.vapi"
		_tmp7_ = _tmp9_;
#line 1540 "glib-2.0.vapi"
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 1540 "glib-2.0.vapi"
			_g_free0 (_tmp7_);
#line 1540 "glib-2.0.vapi"
			_g_regex_unref0 (regex);
#line 1540 "glib-2.0.vapi"
			if (_inner_error0_->domain == G_REGEX_ERROR) {
#line 485 "Subscript.c"
				goto __catch0_g_regex_error;
			}
#line 1540 "glib-2.0.vapi"
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 1540 "glib-2.0.vapi"
			g_clear_error (&_inner_error0_);
#line 1540 "glib-2.0.vapi"
			return NULL;
#line 494 "Subscript.c"
		}
#line 1540 "glib-2.0.vapi"
		_tmp10_ = _tmp7_;
#line 1540 "glib-2.0.vapi"
		_tmp7_ = NULL;
#line 1540 "glib-2.0.vapi"
		result = _tmp10_;
#line 1540 "glib-2.0.vapi"
		_g_free0 (_tmp7_);
#line 1540 "glib-2.0.vapi"
		_g_regex_unref0 (regex);
#line 1540 "glib-2.0.vapi"
		return result;
#line 508 "Subscript.c"
	}
	goto __finally0;
	__catch0_g_regex_error:
	{
#line 1538 "glib-2.0.vapi"
		g_clear_error (&_inner_error0_);
#line 1542 "glib-2.0.vapi"
		g_assert_not_reached ();
#line 517 "Subscript.c"
	}
	__finally0:
#line 1538 "glib-2.0.vapi"
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 1538 "glib-2.0.vapi"
	g_clear_error (&_inner_error0_);
#line 1538 "glib-2.0.vapi"
	return NULL;
#line 526 "Subscript.c"
}

static gchar*
quilter_subscript_real_convert (QuilterPluginsPlugin* base,
                                const gchar* line_)
{
	QuilterSubscript * self;
	gint initial = 0;
	gint last = 0;
	gchar* subline = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* result = NULL;
#line 51 "../src/Plugins/Subscript.vala"
	self = (QuilterSubscript*) base;
#line 51 "../src/Plugins/Subscript.vala"
	g_return_val_if_fail (line_ != NULL, NULL);
#line 52 "../src/Plugins/Subscript.vala"
	initial = string_index_of (line_, "~", 0) + 1;
#line 53 "../src/Plugins/Subscript.vala"
	last = string_index_of (line_, "~", initial);
#line 54 "../src/Plugins/Subscript.vala"
	_tmp0_ = string_substring (line_, (glong) initial, (glong) (last - initial));
#line 54 "../src/Plugins/Subscript.vala"
	subline = _tmp0_;
#line 56 "../src/Plugins/Subscript.vala"
	_tmp1_ = g_strdup_printf ("~%s~", subline);
#line 56 "../src/Plugins/Subscript.vala"
	_tmp2_ = _tmp1_;
#line 56 "../src/Plugins/Subscript.vala"
	_tmp3_ = g_strdup_printf ("<sub>%s</sub>", subline);
#line 56 "../src/Plugins/Subscript.vala"
	_tmp4_ = _tmp3_;
#line 56 "../src/Plugins/Subscript.vala"
	_tmp5_ = string_replace (line_, _tmp2_, _tmp4_);
#line 56 "../src/Plugins/Subscript.vala"
	_tmp6_ = _tmp5_;
#line 56 "../src/Plugins/Subscript.vala"
	_g_free0 (_tmp4_);
#line 56 "../src/Plugins/Subscript.vala"
	_g_free0 (_tmp2_);
#line 56 "../src/Plugins/Subscript.vala"
	result = _tmp6_;
#line 56 "../src/Plugins/Subscript.vala"
	_g_free0 (subline);
#line 56 "../src/Plugins/Subscript.vala"
	return result;
#line 579 "Subscript.c"
}

QuilterSubscript*
quilter_subscript_construct (GType object_type)
{
	QuilterSubscript * self = NULL;
#line 22 "../src/Plugins/Subscript.vala"
	self = (QuilterSubscript*) quilter_plugins_plugin_construct (object_type);
#line 22 "../src/Plugins/Subscript.vala"
	return self;
#line 590 "Subscript.c"
}

QuilterSubscript*
quilter_subscript_new (void)
{
#line 22 "../src/Plugins/Subscript.vala"
	return quilter_subscript_construct (QUILTER_TYPE_SUBSCRIPT);
#line 598 "Subscript.c"
}

static GObject *
quilter_subscript_constructor (GType type,
                               guint n_construct_properties,
                               GObjectConstructParam * construct_properties)
{
	GObject * obj;
	GObjectClass * parent_class;
	QuilterSubscript * self;
#line 25 "../src/Plugins/Subscript.vala"
	parent_class = G_OBJECT_CLASS (quilter_subscript_parent_class);
#line 25 "../src/Plugins/Subscript.vala"
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
#line 25 "../src/Plugins/Subscript.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, QUILTER_TYPE_SUBSCRIPT, QuilterSubscript);
#line 25 "../src/Plugins/Subscript.vala"
	return obj;
#line 617 "Subscript.c"
}

static void
quilter_subscript_class_init (QuilterSubscriptClass * klass,
                              gpointer klass_data)
{
#line 22 "../src/Plugins/Subscript.vala"
	quilter_subscript_parent_class = g_type_class_peek_parent (klass);
#line 22 "../src/Plugins/Subscript.vala"
	g_type_class_adjust_private_offset (klass, &QuilterSubscript_private_offset);
#line 22 "../src/Plugins/Subscript.vala"
	((QuilterPluginsPluginClass *) klass)->get_desctiption = (gchar* (*) (QuilterPluginsPlugin*)) quilter_subscript_real_get_desctiption;
#line 22 "../src/Plugins/Subscript.vala"
	((QuilterPluginsPluginClass *) klass)->get_name = (gchar* (*) (QuilterPluginsPlugin*)) quilter_subscript_real_get_name;
#line 22 "../src/Plugins/Subscript.vala"
	((QuilterPluginsPluginClass *) klass)->editor_button = (GtkWidget* (*) (QuilterPluginsPlugin*)) quilter_subscript_real_editor_button;
#line 22 "../src/Plugins/Subscript.vala"
	((QuilterPluginsPluginClass *) klass)->request_string = (gchar* (*) (QuilterPluginsPlugin*, const gchar*)) quilter_subscript_real_request_string;
#line 22 "../src/Plugins/Subscript.vala"
	((QuilterPluginsPluginClass *) klass)->get_button_desctiption = (gchar* (*) (QuilterPluginsPlugin*)) quilter_subscript_real_get_button_desctiption;
#line 22 "../src/Plugins/Subscript.vala"
	((QuilterPluginsPluginClass *) klass)->has_match = (gboolean (*) (QuilterPluginsPlugin*, const gchar*)) quilter_subscript_real_has_match;
#line 22 "../src/Plugins/Subscript.vala"
	((QuilterPluginsPluginClass *) klass)->convert = (gchar* (*) (QuilterPluginsPlugin*, const gchar*)) quilter_subscript_real_convert;
#line 22 "../src/Plugins/Subscript.vala"
	G_OBJECT_CLASS (klass)->constructor = quilter_subscript_constructor;
#line 22 "../src/Plugins/Subscript.vala"
	G_OBJECT_CLASS (klass)->finalize = quilter_subscript_finalize;
#line 646 "Subscript.c"
}

static void
quilter_subscript_instance_init (QuilterSubscript * self,
                                 gpointer klass)
{
	GPatternSpec* _tmp0_;
#line 22 "../src/Plugins/Subscript.vala"
	self->priv = quilter_subscript_get_instance_private (self);
#line 23 "../src/Plugins/Subscript.vala"
	_tmp0_ = g_pattern_spec_new ("*~*~*");
#line 23 "../src/Plugins/Subscript.vala"
	self->priv->spec = _tmp0_;
#line 660 "Subscript.c"
}

static void
quilter_subscript_finalize (GObject * obj)
{
	QuilterSubscript * self;
#line 22 "../src/Plugins/Subscript.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, QUILTER_TYPE_SUBSCRIPT, QuilterSubscript);
#line 23 "../src/Plugins/Subscript.vala"
	_g_pattern_spec_free0 (self->priv->spec);
#line 22 "../src/Plugins/Subscript.vala"
	G_OBJECT_CLASS (quilter_subscript_parent_class)->finalize (obj);
#line 673 "Subscript.c"
}

static GType
quilter_subscript_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (QuilterSubscriptClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) quilter_subscript_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (QuilterSubscript), 0, (GInstanceInitFunc) quilter_subscript_instance_init, NULL };
	GType quilter_subscript_type_id;
	quilter_subscript_type_id = g_type_register_static (QUILTER_PLUGINS_TYPE_PLUGIN, "QuilterSubscript", &g_define_type_info, 0);
	QuilterSubscript_private_offset = g_type_add_instance_private (quilter_subscript_type_id, sizeof (QuilterSubscriptPrivate));
	return quilter_subscript_type_id;
}

GType
quilter_subscript_get_type (void)
{
	static volatile gsize quilter_subscript_type_id__volatile = 0;
	if (g_once_init_enter (&quilter_subscript_type_id__volatile)) {
		GType quilter_subscript_type_id;
		quilter_subscript_type_id = quilter_subscript_get_type_once ();
		g_once_init_leave (&quilter_subscript_type_id__volatile, quilter_subscript_type_id);
	}
	return quilter_subscript_type_id__volatile;
}

