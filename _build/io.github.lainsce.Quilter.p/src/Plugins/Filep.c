/* Filep.c generated by valac 0.50.2, the Vala compiler
 * generated from Filep.vala, do not modify */

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
#include <glib/gstdio.h>
#include "mkdio.h"

#define QUILTER_PLUGINS_TYPE_PLUGIN (quilter_plugins_plugin_get_type ())
#define QUILTER_PLUGINS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), QUILTER_PLUGINS_TYPE_PLUGIN, QuilterPluginsPlugin))
#define QUILTER_PLUGINS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), QUILTER_PLUGINS_TYPE_PLUGIN, QuilterPluginsPluginClass))
#define QUILTER_PLUGINS_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QUILTER_PLUGINS_TYPE_PLUGIN))
#define QUILTER_PLUGINS_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), QUILTER_PLUGINS_TYPE_PLUGIN))
#define QUILTER_PLUGINS_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), QUILTER_PLUGINS_TYPE_PLUGIN, QuilterPluginsPluginClass))

typedef struct _QuilterPluginsPlugin QuilterPluginsPlugin;
typedef struct _QuilterPluginsPluginClass QuilterPluginsPluginClass;
typedef struct _QuilterPluginsPluginPrivate QuilterPluginsPluginPrivate;

#define QUILTER_TYPE_FILEP (quilter_filep_get_type ())
#define QUILTER_FILEP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), QUILTER_TYPE_FILEP, QuilterFilep))
#define QUILTER_FILEP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), QUILTER_TYPE_FILEP, QuilterFilepClass))
#define QUILTER_IS_FILEP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QUILTER_TYPE_FILEP))
#define QUILTER_IS_FILEP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), QUILTER_TYPE_FILEP))
#define QUILTER_FILEP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), QUILTER_TYPE_FILEP, QuilterFilepClass))

typedef struct _QuilterFilep QuilterFilep;
typedef struct _QuilterFilepClass QuilterFilepClass;
typedef struct _QuilterFilepPrivate QuilterFilepPrivate;
enum  {
	QUILTER_FILEP_0_PROPERTY,
	QUILTER_FILEP_NUM_PROPERTIES
};
static GParamSpec* quilter_filep_properties[QUILTER_FILEP_NUM_PROPERTIES];
#define _g_pattern_spec_free0(var) ((var == NULL) ? NULL : (var = (g_pattern_spec_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _mkd_cleanup0(var) ((var == NULL) ? NULL : (var = (mkd_cleanup (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

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

struct _QuilterFilep {
	QuilterPluginsPlugin parent_instance;
	QuilterFilepPrivate * priv;
};

struct _QuilterFilepClass {
	QuilterPluginsPluginClass parent_class;
};

struct _QuilterFilepPrivate {
	GPatternSpec* spec;
};

static gint QuilterFilep_private_offset;
static gpointer quilter_filep_parent_class = NULL;

GType quilter_plugins_plugin_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QuilterPluginsPlugin, g_object_unref)
GType quilter_filep_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QuilterFilep, g_object_unref)
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
static gchar* quilter_filep_real_get_desctiption (QuilterPluginsPlugin* base);
static gchar* quilter_filep_real_get_name (QuilterPluginsPlugin* base);
static GtkWidget* quilter_filep_real_editor_button (QuilterPluginsPlugin* base);
static gchar* quilter_filep_real_request_string (QuilterPluginsPlugin* base,
                                          const gchar* selection);
static gchar* quilter_filep_real_get_button_desctiption (QuilterPluginsPlugin* base);
static gboolean quilter_filep_real_has_match (QuilterPluginsPlugin* base,
                                       const gchar* text);
static gchar* quilter_filep_real_convert (QuilterPluginsPlugin* base,
                                   const gchar* line_);
QuilterFilep* quilter_filep_new (void);
QuilterFilep* quilter_filep_construct (GType object_type);
QuilterPluginsPlugin* quilter_plugins_plugin_construct (GType object_type);
static GObject * quilter_filep_constructor (GType type,
                                     guint n_construct_properties,
                                     GObjectConstructParam * construct_properties);
static void quilter_filep_finalize (GObject * obj);
static GType quilter_filep_get_type_once (void);

static inline gpointer
quilter_filep_get_instance_private (QuilterFilep* self)
{
	return G_STRUCT_MEMBER_P (self, QuilterFilep_private_offset);
}

static gchar*
quilter_filep_real_get_desctiption (QuilterPluginsPlugin* base)
{
	QuilterFilep * self;
	gchar* _tmp0_;
	gchar* result = NULL;
#line 27 "../src/Plugins/Filep.vala"
	self = (QuilterFilep*) base;
#line 28 "../src/Plugins/Filep.vala"
	_tmp0_ = g_strdup (_ ("Load an embeded file"));
#line 28 "../src/Plugins/Filep.vala"
	result = _tmp0_;
#line 28 "../src/Plugins/Filep.vala"
	return result;
#line 159 "Filep.c"
}

static gchar*
quilter_filep_real_get_name (QuilterPluginsPlugin* base)
{
	QuilterFilep * self;
	gchar* _tmp0_;
	gchar* result = NULL;
#line 31 "../src/Plugins/Filep.vala"
	self = (QuilterFilep*) base;
#line 32 "../src/Plugins/Filep.vala"
	_tmp0_ = g_strdup (_ ("File"));
#line 32 "../src/Plugins/Filep.vala"
	result = _tmp0_;
#line 32 "../src/Plugins/Filep.vala"
	return result;
#line 176 "Filep.c"
}

static GtkWidget*
quilter_filep_real_editor_button (QuilterPluginsPlugin* base)
{
	QuilterFilep * self;
	GtkWidget* result = NULL;
#line 35 "../src/Plugins/Filep.vala"
	self = (QuilterFilep*) base;
#line 36 "../src/Plugins/Filep.vala"
	result = NULL;
#line 36 "../src/Plugins/Filep.vala"
	return result;
#line 190 "Filep.c"
}

static gchar*
quilter_filep_real_request_string (QuilterPluginsPlugin* base,
                                   const gchar* selection)
{
	QuilterFilep * self;
	gchar* _tmp0_;
	gchar* result = NULL;
#line 39 "../src/Plugins/Filep.vala"
	self = (QuilterFilep*) base;
#line 39 "../src/Plugins/Filep.vala"
	g_return_val_if_fail (selection != NULL, NULL);
#line 40 "../src/Plugins/Filep.vala"
	_tmp0_ = g_strdup (selection);
#line 40 "../src/Plugins/Filep.vala"
	result = _tmp0_;
#line 40 "../src/Plugins/Filep.vala"
	return result;
#line 210 "Filep.c"
}

static gchar*
quilter_filep_real_get_button_desctiption (QuilterPluginsPlugin* base)
{
	QuilterFilep * self;
	gchar* _tmp0_;
	gchar* result = NULL;
#line 43 "../src/Plugins/Filep.vala"
	self = (QuilterFilep*) base;
#line 44 "../src/Plugins/Filep.vala"
	_tmp0_ = g_strdup ("");
#line 44 "../src/Plugins/Filep.vala"
	result = _tmp0_;
#line 44 "../src/Plugins/Filep.vala"
	return result;
#line 227 "Filep.c"
}

static gboolean
quilter_filep_real_has_match (QuilterPluginsPlugin* base,
                              const gchar* text)
{
	QuilterFilep * self;
	GPatternSpec* _tmp0_;
	gboolean result = FALSE;
#line 47 "../src/Plugins/Filep.vala"
	self = (QuilterFilep*) base;
#line 47 "../src/Plugins/Filep.vala"
	g_return_val_if_fail (text != NULL, FALSE);
#line 48 "../src/Plugins/Filep.vala"
	_tmp0_ = self->priv->spec;
#line 48 "../src/Plugins/Filep.vala"
	result = g_pattern_match_string (_tmp0_, text);
#line 48 "../src/Plugins/Filep.vala"
	return result;
#line 247 "Filep.c"
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
#line 271 "Filep.c"
		gchar* _tmp2_;
#line 1137 "glib-2.0.vapi"
		_tmp2_ = _result_;
#line 1137 "glib-2.0.vapi"
		result = (gint) (_tmp2_ - ((gchar*) self));
#line 1137 "glib-2.0.vapi"
		return result;
#line 279 "Filep.c"
	} else {
#line 1139 "glib-2.0.vapi"
		result = -1;
#line 1139 "glib-2.0.vapi"
		return result;
#line 285 "Filep.c"
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
#line 309 "Filep.c"
	} else {
		gchar* _tmp2_;
#line 1451 "glib-2.0.vapi"
		_tmp2_ = end;
#line 1451 "glib-2.0.vapi"
		result = (glong) (_tmp2_ - str);
#line 1451 "glib-2.0.vapi"
		return result;
#line 318 "Filep.c"
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
#line 337 "Filep.c"
	} else {
#line 1460 "glib-2.0.vapi"
		_tmp0_ = FALSE;
#line 341 "Filep.c"
	}
#line 1460 "glib-2.0.vapi"
	if (_tmp0_) {
#line 1462 "glib-2.0.vapi"
		string_length = string_strnlen ((gchar*) self, offset + len);
#line 347 "Filep.c"
	} else {
		gint _tmp1_;
		gint _tmp2_;
#line 1464 "glib-2.0.vapi"
		_tmp1_ = strlen (self);
#line 1464 "glib-2.0.vapi"
		_tmp2_ = _tmp1_;
#line 1464 "glib-2.0.vapi"
		string_length = (glong) _tmp2_;
#line 357 "Filep.c"
	}
#line 1467 "glib-2.0.vapi"
	if (offset < ((glong) 0)) {
#line 1468 "glib-2.0.vapi"
		offset = string_length + offset;
#line 1469 "glib-2.0.vapi"
		g_return_val_if_fail (offset >= ((glong) 0), NULL);
#line 365 "Filep.c"
	} else {
#line 1471 "glib-2.0.vapi"
		g_return_val_if_fail (offset <= string_length, NULL);
#line 369 "Filep.c"
	}
#line 1473 "glib-2.0.vapi"
	if (len < ((glong) 0)) {
#line 1474 "glib-2.0.vapi"
		len = string_length - offset;
#line 375 "Filep.c"
	}
#line 1476 "glib-2.0.vapi"
	g_return_val_if_fail ((offset + len) <= string_length, NULL);
#line 1477 "glib-2.0.vapi"
	_tmp3_ = g_strndup (((gchar*) self) + offset, (gsize) len);
#line 1477 "glib-2.0.vapi"
	result = _tmp3_;
#line 1477 "glib-2.0.vapi"
	return result;
#line 385 "Filep.c"
}

static guint8*
string_get_data (const gchar* self,
                 gint* result_length1)
{
	guint8* result;
	guint8* res = NULL;
	gint res_length1;
	gint _res_size_;
	gint _tmp0_;
	gint _tmp1_;
	guint8* _tmp2_;
	gint _tmp2__length1;
#line 1555 "glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1556 "glib-2.0.vapi"
	res = (guint8*) self;
#line 1556 "glib-2.0.vapi"
	res_length1 = -1;
#line 1556 "glib-2.0.vapi"
	_res_size_ = res_length1;
#line 1557 "glib-2.0.vapi"
	_tmp0_ = strlen (self);
#line 1557 "glib-2.0.vapi"
	_tmp1_ = _tmp0_;
#line 1557 "glib-2.0.vapi"
	res_length1 = (gint) _tmp1_;
#line 1558 "glib-2.0.vapi"
	_tmp2_ = res;
#line 1558 "glib-2.0.vapi"
	_tmp2__length1 = res_length1;
#line 1558 "glib-2.0.vapi"
	if (result_length1) {
#line 1558 "glib-2.0.vapi"
		*result_length1 = _tmp2__length1;
#line 422 "Filep.c"
	}
#line 1558 "glib-2.0.vapi"
	result = _tmp2_;
#line 1558 "glib-2.0.vapi"
	return result;
#line 428 "Filep.c"
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
#line 450 "Filep.c"
	} else {
#line 1535 "glib-2.0.vapi"
		_tmp1_ = (*((gchar*) old)) == '\0';
#line 454 "Filep.c"
	}
#line 1535 "glib-2.0.vapi"
	if (_tmp1_) {
#line 1535 "glib-2.0.vapi"
		_tmp0_ = TRUE;
#line 460 "Filep.c"
	} else {
#line 1535 "glib-2.0.vapi"
		_tmp0_ = g_strcmp0 (old, replacement) == 0;
#line 464 "Filep.c"
	}
#line 1535 "glib-2.0.vapi"
	if (_tmp0_) {
#line 468 "Filep.c"
		gchar* _tmp2_;
#line 1536 "glib-2.0.vapi"
		_tmp2_ = g_strdup (self);
#line 1536 "glib-2.0.vapi"
		result = _tmp2_;
#line 1536 "glib-2.0.vapi"
		return result;
#line 476 "Filep.c"
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
#line 508 "Filep.c"
				goto __catch0_g_regex_error;
			}
#line 1539 "glib-2.0.vapi"
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 1539 "glib-2.0.vapi"
			g_clear_error (&_inner_error0_);
#line 1539 "glib-2.0.vapi"
			return NULL;
#line 517 "Filep.c"
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
#line 533 "Filep.c"
				goto __catch0_g_regex_error;
			}
#line 1540 "glib-2.0.vapi"
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 1540 "glib-2.0.vapi"
			g_clear_error (&_inner_error0_);
#line 1540 "glib-2.0.vapi"
			return NULL;
#line 542 "Filep.c"
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
#line 556 "Filep.c"
	}
	goto __finally0;
	__catch0_g_regex_error:
	{
#line 1538 "glib-2.0.vapi"
		g_clear_error (&_inner_error0_);
#line 1542 "glib-2.0.vapi"
		g_assert_not_reached ();
#line 565 "Filep.c"
	}
	__finally0:
#line 1538 "glib-2.0.vapi"
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 1538 "glib-2.0.vapi"
	g_clear_error (&_inner_error0_);
#line 1538 "glib-2.0.vapi"
	return NULL;
#line 574 "Filep.c"
}

static gchar*
quilter_filep_real_convert (QuilterPluginsPlugin* base,
                            const gchar* line_)
{
	QuilterFilep * self;
	gchar* text = NULL;
	gchar* _tmp0_;
	gint initial = 0;
	gint last = 0;
	gchar* subline = NULL;
	gchar* _tmp1_;
	GFile* file = NULL;
	const gchar* _tmp2_;
	GFile* _tmp3_;
	gchar* _tmp26_;
	GError* _inner_error0_ = NULL;
	gchar* result = NULL;
#line 51 "../src/Plugins/Filep.vala"
	self = (QuilterFilep*) base;
#line 51 "../src/Plugins/Filep.vala"
	g_return_val_if_fail (line_ != NULL, NULL);
#line 52 "../src/Plugins/Filep.vala"
	_tmp0_ = g_strdup ("");
#line 52 "../src/Plugins/Filep.vala"
	text = _tmp0_;
#line 53 "../src/Plugins/Filep.vala"
	initial = string_index_of (line_, "/", 0) + 1;
#line 54 "../src/Plugins/Filep.vala"
	last = string_index_of (line_, " :file", initial);
#line 55 "../src/Plugins/Filep.vala"
	_tmp1_ = string_substring (line_, (glong) initial, (glong) (last - initial));
#line 55 "../src/Plugins/Filep.vala"
	subline = _tmp1_;
#line 57 "../src/Plugins/Filep.vala"
	_tmp2_ = subline;
#line 57 "../src/Plugins/Filep.vala"
	_tmp3_ = g_file_new_for_path (_tmp2_);
#line 57 "../src/Plugins/Filep.vala"
	file = _tmp3_;
#line 616 "Filep.c"
	{
		GFile* _tmp4_;
#line 60 "../src/Plugins/Filep.vala"
		_tmp4_ = file;
#line 60 "../src/Plugins/Filep.vala"
		if (g_file_query_exists (_tmp4_, NULL)) {
#line 623 "Filep.c"
			const gchar* _tmp5_;
			gchar* _tmp6_ = NULL;
			MMIOT* mkd = NULL;
			const gchar* _tmp7_;
			guint8* _tmp8_;
			gint _tmp8__length1;
			gint _tmp9_ = 0;
			guint8* _tmp10_;
			gint _tmp10__length1;
			MMIOT* _tmp11_;
			MMIOT* _tmp12_;
			gchar* _result_ = NULL;
			MMIOT* _tmp13_;
			const gchar* _tmp14_ = NULL;
			gchar* _tmp15_;
			const gchar* _tmp16_;
			gchar* _tmp17_;
			gchar* _tmp18_;
			const gchar* _tmp19_;
			gchar* _tmp20_;
			gchar* _tmp21_;
			gchar* _tmp22_;
			gchar* _tmp23_;
#line 61 "../src/Plugins/Filep.vala"
			_tmp5_ = subline;
#line 61 "../src/Plugins/Filep.vala"
			g_file_get_contents (_tmp5_, &_tmp6_, NULL, &_inner_error0_);
#line 61 "../src/Plugins/Filep.vala"
			_g_free0 (text);
#line 61 "../src/Plugins/Filep.vala"
			text = _tmp6_;
#line 61 "../src/Plugins/Filep.vala"
			if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 657 "Filep.c"
				goto __catch0_g_error;
			}
#line 62 "../src/Plugins/Filep.vala"
			_tmp7_ = text;
#line 62 "../src/Plugins/Filep.vala"
			_tmp8_ = string_get_data (_tmp7_, &_tmp9_);
#line 62 "../src/Plugins/Filep.vala"
			_tmp8__length1 = _tmp9_;
#line 62 "../src/Plugins/Filep.vala"
			_tmp10_ = _tmp8_;
#line 62 "../src/Plugins/Filep.vala"
			_tmp10__length1 = _tmp8__length1;
#line 62 "../src/Plugins/Filep.vala"
			_tmp11_ = mkd_string (_tmp10_, _tmp10__length1, ((0x00000100 + 0x00001000) + 0x00040000) + 0x00200000);
#line 62 "../src/Plugins/Filep.vala"
			mkd = _tmp11_;
#line 68 "../src/Plugins/Filep.vala"
			_tmp12_ = mkd;
#line 68 "../src/Plugins/Filep.vala"
			mkd_compile (_tmp12_, ((0x00000100 + 0x00001000) + 0x00040000) + 0x00200000);
#line 74 "../src/Plugins/Filep.vala"
			_tmp13_ = mkd;
#line 74 "../src/Plugins/Filep.vala"
			mkd_document (_tmp13_, &_tmp14_);
#line 74 "../src/Plugins/Filep.vala"
			_g_free0 (_result_);
#line 74 "../src/Plugins/Filep.vala"
			_tmp15_ = g_strdup (_tmp14_);
#line 74 "../src/Plugins/Filep.vala"
			_result_ = _tmp15_;
#line 76 "../src/Plugins/Filep.vala"
			_tmp16_ = subline;
#line 76 "../src/Plugins/Filep.vala"
			_tmp17_ = g_strdup_printf ("/%s :file", _tmp16_);
#line 76 "../src/Plugins/Filep.vala"
			_tmp18_ = _tmp17_;
#line 76 "../src/Plugins/Filep.vala"
			_tmp19_ = _result_;
#line 76 "../src/Plugins/Filep.vala"
			_tmp20_ = g_strdup_printf ("%s", _tmp19_);
#line 76 "../src/Plugins/Filep.vala"
			_tmp21_ = _tmp20_;
#line 76 "../src/Plugins/Filep.vala"
			_tmp22_ = string_replace (line_, _tmp18_, _tmp21_);
#line 76 "../src/Plugins/Filep.vala"
			_tmp23_ = _tmp22_;
#line 76 "../src/Plugins/Filep.vala"
			_g_free0 (_tmp21_);
#line 76 "../src/Plugins/Filep.vala"
			_g_free0 (_tmp18_);
#line 76 "../src/Plugins/Filep.vala"
			result = _tmp23_;
#line 76 "../src/Plugins/Filep.vala"
			_g_free0 (_result_);
#line 76 "../src/Plugins/Filep.vala"
			_mkd_cleanup0 (mkd);
#line 76 "../src/Plugins/Filep.vala"
			_g_object_unref0 (file);
#line 76 "../src/Plugins/Filep.vala"
			_g_free0 (subline);
#line 76 "../src/Plugins/Filep.vala"
			_g_free0 (text);
#line 76 "../src/Plugins/Filep.vala"
			return result;
#line 722 "Filep.c"
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		GError* _tmp24_;
		const gchar* _tmp25_;
#line 59 "../src/Plugins/Filep.vala"
		e = _inner_error0_;
#line 59 "../src/Plugins/Filep.vala"
		_inner_error0_ = NULL;
#line 79 "../src/Plugins/Filep.vala"
		_tmp24_ = e;
#line 79 "../src/Plugins/Filep.vala"
		_tmp25_ = _tmp24_->message;
#line 79 "../src/Plugins/Filep.vala"
		g_warning ("Filep.vala:79: Error: %s", _tmp25_);
#line 59 "../src/Plugins/Filep.vala"
		_g_error_free0 (e);
#line 743 "Filep.c"
	}
	__finally0:
#line 59 "../src/Plugins/Filep.vala"
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 59 "../src/Plugins/Filep.vala"
		_g_object_unref0 (file);
#line 59 "../src/Plugins/Filep.vala"
		_g_free0 (subline);
#line 59 "../src/Plugins/Filep.vala"
		_g_free0 (text);
#line 59 "../src/Plugins/Filep.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 59 "../src/Plugins/Filep.vala"
		g_clear_error (&_inner_error0_);
#line 59 "../src/Plugins/Filep.vala"
		return NULL;
#line 760 "Filep.c"
	}
#line 82 "../src/Plugins/Filep.vala"
	_tmp26_ = g_strdup ("No file.");
#line 82 "../src/Plugins/Filep.vala"
	result = _tmp26_;
#line 82 "../src/Plugins/Filep.vala"
	_g_object_unref0 (file);
#line 82 "../src/Plugins/Filep.vala"
	_g_free0 (subline);
#line 82 "../src/Plugins/Filep.vala"
	_g_free0 (text);
#line 82 "../src/Plugins/Filep.vala"
	return result;
#line 774 "Filep.c"
}

QuilterFilep*
quilter_filep_construct (GType object_type)
{
	QuilterFilep * self = NULL;
#line 22 "../src/Plugins/Filep.vala"
	self = (QuilterFilep*) quilter_plugins_plugin_construct (object_type);
#line 22 "../src/Plugins/Filep.vala"
	return self;
#line 785 "Filep.c"
}

QuilterFilep*
quilter_filep_new (void)
{
#line 22 "../src/Plugins/Filep.vala"
	return quilter_filep_construct (QUILTER_TYPE_FILEP);
#line 793 "Filep.c"
}

static GObject *
quilter_filep_constructor (GType type,
                           guint n_construct_properties,
                           GObjectConstructParam * construct_properties)
{
	GObject * obj;
	GObjectClass * parent_class;
	QuilterFilep * self;
#line 25 "../src/Plugins/Filep.vala"
	parent_class = G_OBJECT_CLASS (quilter_filep_parent_class);
#line 25 "../src/Plugins/Filep.vala"
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
#line 25 "../src/Plugins/Filep.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, QUILTER_TYPE_FILEP, QuilterFilep);
#line 25 "../src/Plugins/Filep.vala"
	return obj;
#line 812 "Filep.c"
}

static void
quilter_filep_class_init (QuilterFilepClass * klass,
                          gpointer klass_data)
{
#line 22 "../src/Plugins/Filep.vala"
	quilter_filep_parent_class = g_type_class_peek_parent (klass);
#line 22 "../src/Plugins/Filep.vala"
	g_type_class_adjust_private_offset (klass, &QuilterFilep_private_offset);
#line 22 "../src/Plugins/Filep.vala"
	((QuilterPluginsPluginClass *) klass)->get_desctiption = (gchar* (*) (QuilterPluginsPlugin*)) quilter_filep_real_get_desctiption;
#line 22 "../src/Plugins/Filep.vala"
	((QuilterPluginsPluginClass *) klass)->get_name = (gchar* (*) (QuilterPluginsPlugin*)) quilter_filep_real_get_name;
#line 22 "../src/Plugins/Filep.vala"
	((QuilterPluginsPluginClass *) klass)->editor_button = (GtkWidget* (*) (QuilterPluginsPlugin*)) quilter_filep_real_editor_button;
#line 22 "../src/Plugins/Filep.vala"
	((QuilterPluginsPluginClass *) klass)->request_string = (gchar* (*) (QuilterPluginsPlugin*, const gchar*)) quilter_filep_real_request_string;
#line 22 "../src/Plugins/Filep.vala"
	((QuilterPluginsPluginClass *) klass)->get_button_desctiption = (gchar* (*) (QuilterPluginsPlugin*)) quilter_filep_real_get_button_desctiption;
#line 22 "../src/Plugins/Filep.vala"
	((QuilterPluginsPluginClass *) klass)->has_match = (gboolean (*) (QuilterPluginsPlugin*, const gchar*)) quilter_filep_real_has_match;
#line 22 "../src/Plugins/Filep.vala"
	((QuilterPluginsPluginClass *) klass)->convert = (gchar* (*) (QuilterPluginsPlugin*, const gchar*)) quilter_filep_real_convert;
#line 22 "../src/Plugins/Filep.vala"
	G_OBJECT_CLASS (klass)->constructor = quilter_filep_constructor;
#line 22 "../src/Plugins/Filep.vala"
	G_OBJECT_CLASS (klass)->finalize = quilter_filep_finalize;
#line 841 "Filep.c"
}

static void
quilter_filep_instance_init (QuilterFilep * self,
                             gpointer klass)
{
	GPatternSpec* _tmp0_;
#line 22 "../src/Plugins/Filep.vala"
	self->priv = quilter_filep_get_instance_private (self);
#line 23 "../src/Plugins/Filep.vala"
	_tmp0_ = g_pattern_spec_new ("*/*:file*");
#line 23 "../src/Plugins/Filep.vala"
	self->priv->spec = _tmp0_;
#line 855 "Filep.c"
}

static void
quilter_filep_finalize (GObject * obj)
{
	QuilterFilep * self;
#line 22 "../src/Plugins/Filep.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, QUILTER_TYPE_FILEP, QuilterFilep);
#line 23 "../src/Plugins/Filep.vala"
	_g_pattern_spec_free0 (self->priv->spec);
#line 22 "../src/Plugins/Filep.vala"
	G_OBJECT_CLASS (quilter_filep_parent_class)->finalize (obj);
#line 868 "Filep.c"
}

static GType
quilter_filep_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (QuilterFilepClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) quilter_filep_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (QuilterFilep), 0, (GInstanceInitFunc) quilter_filep_instance_init, NULL };
	GType quilter_filep_type_id;
	quilter_filep_type_id = g_type_register_static (QUILTER_PLUGINS_TYPE_PLUGIN, "QuilterFilep", &g_define_type_info, 0);
	QuilterFilep_private_offset = g_type_add_instance_private (quilter_filep_type_id, sizeof (QuilterFilepPrivate));
	return quilter_filep_type_id;
}

GType
quilter_filep_get_type (void)
{
	static volatile gsize quilter_filep_type_id__volatile = 0;
	if (g_once_init_enter (&quilter_filep_type_id__volatile)) {
		GType quilter_filep_type_id;
		quilter_filep_type_id = quilter_filep_get_type_once ();
		g_once_init_leave (&quilter_filep_type_id__volatile, quilter_filep_type_id);
	}
	return quilter_filep_type_id__volatile;
}

