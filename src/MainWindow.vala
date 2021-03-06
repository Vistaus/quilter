/*
* Copyright (c) 2017-2021 Lains
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
* Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
* Boston, MA 02110-1301 USA
*/

namespace Quilter {
    public class MainWindow : Hdy.ApplicationWindow {
        delegate void HookFunc ();
        public Gtk.Adjustment eadj;
        public Gtk.Box box;
        public Gtk.Box main_leaf;
        public Gtk.Overlay overlay_editor;
        public Gtk.Button focus_overlay_button;
        public Hdy.Leaflet grid;
        public Hdy.Leaflet header;
        public Hdy.TitleBar window_header;
        public Hdy.HeaderBar welcome_titlebar;
        public Gtk.Grid main_pane;
        public Gtk.Grid welcome_view;
        public Gtk.MenuButton set_font_menu;
        public Gtk.Paned paned;
        public Gtk.Revealer titlebar_revealer;
        public Gtk.Revealer overlay_button_revealer;
        public Gtk.ScrolledWindow edit_view;
        public Gtk.Stack main_stack;
        public Gtk.Stack stack;
        public Gtk.Stack titlebar_stack;
        public Gtk.Stack win_stack;
        public Gtk.Separator separator;
        public Gtk.Separator separator2;
        public SimpleActionGroup actions { get; construct; }
        public Widgets.EditView edit_view_content;
        public Widgets.Headerbar titlebar;
        public Widgets.Preview preview_view_content;
        public Widgets.SearchBar searchbar;
        public Widgets.SideBar sidebar;
        public Widgets.StatusBar statusbar;
        public const string ACTION_PREFIX = "win.";
        public const string ACTION_CHEATSHEET = "action_cheatsheet";
        public const string ACTION_EXPORT_HTML = "action_export_html";
        public const string ACTION_EXPORT_PDF = "action_export_pdf";
        public const string ACTION_FOCUS = "action_focus";
        public const string ACTION_TOGGLE_VIEW = "action_toggle_view";
        public const string ACTION_PREFS = "action_preferences";
        public const string ACTION_ABOUT = "action_about";
        public const string ACTION_KEYS = "action_keys";
        public static Gee.MultiMap<string, string> action_accelerators = new Gee.HashMultiMap<string, string> ();
        public weak Quilter.Application app { get; construct; }

        private const GLib.ActionEntry[] ACTION_ENTRIES = {
            { ACTION_CHEATSHEET, action_cheatsheet },
            { ACTION_PREFS, action_preferences },
            { ACTION_KEYS, action_keys },
            { ACTION_FOCUS, action_focus },
            { ACTION_TOGGLE_VIEW, action_toggle_view },
            { ACTION_EXPORT_PDF, action_export_pdf },
            { ACTION_EXPORT_HTML, action_export_html },
            { ACTION_ABOUT, action_about }
        };

        private GtkSpell.Checker spell = null;
        public bool spellcheck {
            set {
                if (value) {
                    try {
                        var last_language = Quilter.Application.gsettings.get_string ("spellcheck-language");
                        var language_list = GtkSpell.Checker.get_language_list ();

                        bool language_set = false;
                        foreach (var element in language_list) {
                            if (last_language == element) {
                                spell.set_language (last_language);
                                language_set = true;
                                break;
                            }
                        }

                        if (language_list.length () == 0) {
                            spell.set_language (null);
                        } else if (!language_set) {
                            last_language = language_list.first ().data;
                            spell.set_language (last_language);
                        }
                        spell.attach (edit_view_content);
                    } catch (Error e) {
                        warning (e.message);
                    }
                } else {
                    spell.detach ();
                }
            }
        }

        public bool is_fullscreen {
            get {
                return Quilter.Application.gsettings.get_boolean("fullscreen");
            }
            set {
                Quilter.Application.gsettings.set_boolean("fullscreen", value);
                if (value) {
                    fullscreen ();
                    if (Quilter.Application.gsettings.get_string("preview-type") != "full") {
                        Quilter.Application.gsettings.set_string("preview-type", "full");
                    }
                    var buffer_context = edit_view_content.get_style_context ();
                    buffer_context.add_class ("full-text");
                    buffer_context.remove_class ("small-text");
                    sidebar.reveal_child = false;
                } else {
                    unfullscreen ();
                    var buffer_context = edit_view_content.get_style_context ();
                    buffer_context.add_class ("small-text");
                    buffer_context.remove_class ("full-text");
                    sidebar.reveal_child = true;
                }
            }
        }

        public MainWindow (Quilter.Application application) {
            Object (
                application: application,
                app: application,
                title: "Quilter"
            );

            weak Gtk.IconTheme default_theme = Gtk.IconTheme.get_default ();
            default_theme.add_resource_path ("/io/github/lainsce/Quilter");

            // Ensure the file used in the init is cache and exists
            Services.FileManager.get_cache_path ();
            var path = Quilter.Application.gsettings.get_string("current-file");

            if (path == Services.FileManager.get_cache_path ()) {
                titlebar.samenu_button.title = (_("New Document"));
                titlebar.samenu_button.subtitle = (_("Not Saved Yet"));
            } else {
                titlebar.samenu_button.title = Path.get_basename(path);
                titlebar.samenu_button.subtitle = path.replace(GLib.Environment.get_home_dir (), "~")
                                                      .replace(Path.get_basename (path), "");
            }

            on_settings_changed.begin ();
            Quilter.Application.gsettings.changed.connect (() => {
                on_settings_changed.begin ();
            });
            
            if (sidebar.column.get_children () == null) {
                sidebar.reveal_child = false;
                Quilter.Application.gsettings.set_boolean("sidebar", false);
                on_create_new ();
                sidebar.store.clear ();
                sidebar.outline_populate ();
                sidebar.view.expand_all ();
            } else {
                sidebar.reveal_child = true;
                Quilter.Application.gsettings.set_boolean("sidebar", true);
                sidebar.store.clear ();
                sidebar.outline_populate ();
                sidebar.view.expand_all ();
            }

            spell = new GtkSpell.Checker ();
            spell.decode_language_codes = true;
            spellcheck = Quilter.Application.gsettings.get_boolean ("spellcheck");
            spell.language_changed.connect (() => {
                Quilter.Application.gsettings.set_string ("spellcheck-language", spell.get_language ());
            });

            eadj = edit_view.get_vadjustment ();
            eadj.notify["value"].connect (() => {
                scroll_to ();
            });

            key_press_event.connect ((e) => {
                uint keycode = e.hardware_keycode;
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.q, keycode)) {
                        this.destroy ();
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.n, keycode)) {
                        on_create_new ();
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.s, keycode)) {
                        on_save ();
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if ((e.state & Gdk.ModifierType.SHIFT_MASK) != 0) {
                        if (match_keycode (Gdk.Key.s, keycode)) {
                            on_save_as ();
                        }
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.o, keycode)) {
                        on_open ();
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.f, keycode)) {
                        show_searchbar ();
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.h, keycode)) {
                        action_cheatsheet ();
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.z, keycode)) {
                        edit_view_content.buffer.undo ();
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.g, keycode)) {
                        action_export_html ();
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.j, keycode)) {
                        action_export_pdf ();
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK + Gdk.ModifierType.SHIFT_MASK) != 0) {
                    if (match_keycode (Gdk.Key.z, keycode)) {
                        edit_view_content.buffer.redo ();
                    }
                }
                if (match_keycode (Gdk.Key.F11, keycode)) {
                        is_fullscreen = !is_fullscreen;
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.@1, keycode)) {
                        action_toggle_view ();
                        return true;
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.@2, keycode)) {
                        if (Quilter.Application.gsettings.get_boolean("sidebar")) {
                            Quilter.Application.gsettings.set_boolean("sidebar", false);
                        } else {
                            Quilter.Application.gsettings.set_boolean("sidebar", true);
                        }
                        return true;
                    }
                }
                if ((e.state & Gdk.ModifierType.CONTROL_MASK) != 0) {
                    if (match_keycode (Gdk.Key.@3, keycode)) {
                        if (Quilter.Application.gsettings.get_boolean("focus-mode")) {
                            Quilter.Application.gsettings.set_boolean("focus-mode", false);
                        } else {
                            Quilter.Application.gsettings.set_boolean("focus-mode", true);
                        }
                        return true;
                    }
                }
                return false;
            });

            overlay_button_revealer.visible = false;
        }

        static construct {
            action_accelerators.set (ACTION_CHEATSHEET, "<Control>h");
            action_accelerators.set (ACTION_EXPORT_HTML, "<Control>g");
            action_accelerators.set (ACTION_EXPORT_PDF, "<Control>p");
            action_accelerators.set (ACTION_TOGGLE_VIEW, "<Control>1");
            action_accelerators.set (ACTION_FOCUS, "<Control>3");
        }

        construct {
            Hdy.init ();
            int window_x, window_y, width, height;
            Quilter.Application.gsettings.get ("window-position", "(ii)", out window_x, out window_y);
            Quilter.Application.gsettings.get ("window-size", "(ii)", out width, out height);
            if (window_x != -1 || window_y != -1) {
                this.move (window_x, window_y);
            }
            this.resize (width, height);

            try {
                this.icon = Gtk.IconTheme.get_default ().load_icon ("io.github.lainsce.Quilter", Gtk.IconSize.DIALOG, 0);
            } catch (Error e) {
            }

            actions = new SimpleActionGroup ();
            actions.add_action_entries (ACTION_ENTRIES, this);
            insert_action_group ("win", actions);

            foreach (var action in action_accelerators.get_keys ()) {
                var accels_array = action_accelerators[action].to_array ();
                accels_array += null;

                app.set_accels_for_action (ACTION_PREFIX + action, accels_array);
            }

            Gtk.StyleContext style = get_style_context ();
            if (Config.PROFILE == "Devel") {
                style.add_class ("devel");
            }

            var provider = new Gtk.CssProvider ();
            provider.load_from_resource ("/io/github/lainsce/Quilter/app-main-stylesheet.css");
            Gtk.StyleContext.add_provider_for_screen (Gdk.Screen.get_default (), provider, Gtk.STYLE_PROVIDER_PRIORITY_APPLICATION);
            var provider3 = new Gtk.CssProvider ();

            titlebar = new Widgets.Headerbar (this);
            titlebar.open.connect (on_open);
            titlebar.save.connect (on_save);
            titlebar.save_as.connect (on_save_as);
            titlebar.create_new.connect (on_create_new);

            titlebar_stack = new Gtk.Stack ();
            titlebar_stack.set_transition_type (Gtk.StackTransitionType.CROSSFADE);
            titlebar_stack.add_named (titlebar, "title");

            titlebar_revealer = new Gtk.Revealer ();
            titlebar_revealer.reveal_child = Quilter.Application.gsettings.get_boolean("sidebar");
            titlebar_revealer.add (titlebar_stack);
            titlebar_revealer.transition_type = Gtk.RevealerTransitionType.SLIDE_DOWN;

            edit_view = new Gtk.ScrolledWindow (null, null);
            edit_view_content = new Widgets.EditView (this);
            edit_view.vexpand = true;
            edit_view_content.save.connect (on_save);
            edit_view.add (edit_view_content);

            edit_view_content.buffer.changed.connect (() => {
                edit_view_content.modified = true;
                if (Quilter.Application.gsettings.get_boolean("pos")) {
                    edit_view_content.pos_syntax_start ();
                }
                render_func ();
                update_count ();
                scroll_to ();
                sidebar.store.clear ();
                sidebar.outline_populate ();
                sidebar.view.expand_all ();
            });

            preview_view_content = new Widgets.Preview (this, edit_view_content);
            preview_view_content.vexpand = true;

            stack = new Gtk.Stack ();

            box = new Gtk.Box (Gtk.Orientation.HORIZONTAL, 0);
            box.homogeneous = true;

            statusbar = new Widgets.StatusBar (edit_view_content.buffer);

            main_stack = new Gtk.Stack ();
            main_stack.add_named (stack, "stack");
            main_stack.add_named (box, "paned");

            sidebar = new Widgets.SideBar (this, edit_view_content);
            sidebar.hexpand = false;
            sidebar.save_as.connect (() => on_save_as ());

            win_stack = new Gtk.Stack ();
            win_stack.get_style_context ().add_class ("quilter-normal-view");
            win_stack.add_named (main_stack, "doc");

            actions = new SimpleActionGroup ();
            actions.add_action_entries (ACTION_ENTRIES, this);
            insert_action_group ("win", actions);

            searchbar = new Widgets.SearchBar (this);

            overlay_button_revealer = new Gtk.Revealer ();
            overlay_button_revealer.transition_type = Gtk.RevealerTransitionType.SLIDE_UP;
            overlay_button_revealer.halign = Gtk.Align.END;
            overlay_button_revealer.valign = Gtk.Align.END;

            focus_overlay_button = new Gtk.Button ();
            focus_overlay_button.margin = 12;
            focus_overlay_button.set_image (new Gtk.Image.from_icon_name ("zoom-fit-best-symbolic", Gtk.IconSize.BUTTON));
            focus_overlay_button.set_always_show_image (true);
            focus_overlay_button.tooltip_text = _("Exit focus mode");
            var focus_overlay_button_context = focus_overlay_button.get_style_context ();
            focus_overlay_button_context.add_class ("quilter-focus-button");
            focus_overlay_button_context.add_class ("osd");

            focus_overlay_button.clicked.connect (() => {
                Quilter.Application.gsettings.set_boolean("focus-mode", false);
            });

            var overlay_button_dragger = new Hdy.WindowHandle ();
            overlay_button_dragger.add(focus_overlay_button);
            overlay_button_revealer.add (overlay_button_dragger);

            var sep = new Gtk.Separator (Gtk.Orientation.VERTICAL);
            sep.get_style_context ().add_class ("sidebar");

            var main_view = new Gtk.Grid ();
            main_view.attach (sidebar, 0, 0, 1, 2);
            main_view.attach (sep, 1, 0, 1, 2);
            main_view.attach (searchbar, 2, 0, 1, 1);
            main_view.attach (win_stack, 2, 1, 1, 1);
            main_view.attach (statusbar, 0, 3, 3, 1);

            main_leaf = new Gtk.Box (Gtk.Orientation.VERTICAL, 0);
            main_leaf.add (titlebar_revealer);
            main_leaf.add (main_view);

            change_layout.begin ();

            var main_overlay = new Gtk.Overlay ();
            main_overlay.add_overlay (overlay_button_revealer);
            main_overlay.add (main_leaf);

            var window_grid = new Gtk.Grid ();
            window_grid.orientation = Gtk.Orientation.VERTICAL;
            window_grid.add (main_overlay);

            add (window_grid);

            this.set_size_request (360, 400);
        }

#if VALA_0_42
        protected bool match_keycode (uint keyval, uint code) {
#else
        protected bool match_keycode (int keyval, uint code) {
#endif
            Gdk.KeymapKey [] keys;
            Gdk.Keymap keymap = Gdk.Keymap.get_for_display (Gdk.Display.get_default ());
            if (keymap.get_entries_for_keyval (keyval, out keys)) {
                foreach (var key in keys) {
                    if (code == key.keycode)
                        return true;
                    }
                }

            return false;
        }

        public override bool delete_event (Gdk.EventAny event) {
            int w, h;
            get_size (out w, out h);
            Quilter.Application.gsettings.set ("window-size", "(ii)", w, h);
            int root_x, root_y;
            this.get_position (out root_x, out root_y);
            Quilter.Application.gsettings.set ("window-position", "(ii)", root_x, root_y);

            save_last_files ();
            if (sidebar.column.get_children () == null) {
                Quilter.Application.gsettings.set_string("current-file", "");
            }

            set_prev_workfile ();
            if (edit_view_content.modified) {
                on_save ();
            }

            return false;
        }

        public void scroll_to () {
            Gtk.Adjustment vap = edit_view.get_vadjustment ();
            var upper = vap.get_upper();
            var value = vap.get_value();
            preview_view_content.scroll_value = value/upper;
        }

        private static void widget_unparent (Gtk.Widget widget) {
            unowned Gtk.Container parent = widget.get_parent ();
            if (parent != null) {
                parent.remove (widget);
                widget.unparent ();
            } else {
                return;
            }
        }

        private void update_count () {
            if (Quilter.Application.gsettings.get_string("track-type") == "words") {
                statusbar.update_wordcount ();
            } else if (Quilter.Application.gsettings.get_string("track-type") == "lines") {
                statusbar.update_linecount ();
            } else if (Quilter.Application.gsettings.get_string("track-type") == "rtc") {
                statusbar.update_readtimecount ();
            }
        }

        private void action_preferences () {
            var prefs = new Widgets.Preferences (this);
            prefs.show_all ();
        }
        private void action_cheatsheet () {
            try {
                var build = new Gtk.Builder ();
                build.add_from_resource ("/io/github/lainsce/Quilter/cheatsheet.ui");
                var window =  (Hdy.PreferencesWindow) build.get_object ("cheatsheet");
                window.set_transient_for (this);
                window.show_all ();
            } catch (Error e) {
                warning ("Failed to open md_cheatsheet window: %s\n", e.message);
            }
        }
        private void action_toggle_view () {
            if (!Quilter.Application.gsettings.get_boolean ("full-width-changed")) {
                stack.set_visible_child (preview_view_content);
                Quilter.Application.gsettings.set_boolean ("full-width-changed", true);
            } else {
                stack.set_visible_child (edit_view);
                Quilter.Application.gsettings.set_boolean ("full-width-changed", false);
            }
        }
        private void action_focus () {
            Quilter.Application.gsettings.set_boolean("focus-mode", true);
        }

        private void action_export_pdf () {
            Services.ExportUtils.export_pdf ();
        }

        private void action_export_html () {
            Services.ExportUtils.export_html ();
        }

        public void render_func () {
            preview_view_content.update_html_view ();
            if (edit_view_content.buffer.get_modified () == true) {
                preview_view_content.update_html_view ();
                edit_view_content.buffer.set_modified (false);
            }
        }

        public void show_searchbar () {
            searchbar.set_search_mode (Quilter.Application.gsettings.get_boolean("searchbar"));
        }

        public void show_sidebar () {
            if (Quilter.Application.gsettings.get_boolean("sidebar")) {
                sidebar.reveal_child = true;
                sidebar.get_style_context ().add_class ("quilter-sidebar");
            } else {
                sidebar.reveal_child = false;
                sidebar.get_style_context ().remove_class ("quilter-sidebar");
            }
        }

        public void show_statusbar () {
            statusbar.reveal_child = Quilter.Application.gsettings.get_boolean("statusbar");
        }

        private void set_prev_workfile () {
            if (((Widgets.SideBarBox)sidebar.column.get_selected_row ()) != null) {
                Quilter.Application.gsettings.set_string("current-file", ((Widgets.SideBarBox)sidebar.column.get_selected_row ()).path);
            }
        }

        private async void on_settings_changed () {
            show_searchbar ();
            update_count ();
            edit_view_content.dynamic_margins ();
            change_layout.begin ();

            if (Quilter.Application.gsettings.get_boolean("focus-mode")) {
                overlay_button_revealer.reveal_child = true;
                sidebar.reveal_child = false;
                statusbar.reveal_child = false;
                titlebar_revealer.reveal_child = false;
                focus_overlay_button.button_press_event.connect ((e) => {
                    if (e.button == Gdk.BUTTON_SECONDARY) {
                        begin_move_drag ((int) e.button, (int) e.x_root, (int) e.y_root, e.time);
                        return true;
                    }
                    return false;
                });
            } else {
                overlay_button_revealer.reveal_child = false;
                titlebar_revealer.reveal_child = true;
                show_statusbar ();
                show_sidebar ();
            }

            if (Quilter.Application.gsettings.get_boolean ("full-width-changed") == false) {
                stack.set_visible_child (preview_view_content);
            } else if (Quilter.Application.gsettings.get_boolean ("full-width-changed") == true) {
                stack.set_visible_child (edit_view);
            }

            var edit_view_context = edit_view.get_style_context ();
            if (Quilter.Application.gsettings.get_string("preview-type") == "half") {
                edit_view_context.add_class ("edit-view-paned");
            } else {
                edit_view_context.remove_class ("edit-view-paned");
            }

            render_func ();
        }

        private async void change_layout () {
            if (Quilter.Application.gsettings.get_string("preview-type") == "full") {
                widget_unparent (edit_view);
                widget_unparent (preview_view_content);

                stack.add_titled (edit_view, "overlay_editor", _("Edit"));
                stack.add_titled (preview_view_content, "preview_view", _("Preview"));
                stack.set_visible_child (edit_view);
                stack.transition_type = Gtk.StackTransitionType.SLIDE_LEFT_RIGHT;
                main_stack.set_visible_child (stack);
            } else {
                widget_unparent (edit_view);
                widget_unparent (preview_view_content);

                box.add (edit_view);
                box.add (preview_view_content);
                main_stack.set_visible_child (box);
            }
        }

        public void save_last_files () {
          string[] rows = {};
          foreach (var child in sidebar.column.get_children ()) {
            rows += ((Widgets.SideBarBox)child).path;
          }
          Quilter.Application.gsettings.set_strv ("last-files", rows);
        }

        private void on_create_new () {
            var dialog = new Services.DialogUtils.Dialog ();
            dialog.transient_for = this;

            dialog.response.connect ((response_id) => {
                switch (response_id) {
                    case Gtk.ResponseType.OK:
                        unowned Widgets.SideBarBox? row = sidebar.get_selected_row ();
                        if (row != null && row.path != null) {
                            on_save ();
                        } else {
                            on_save_as ();
                        }

                        edit_view_content.modified = false;
                        sidebar.is_modified = false;
                        dialog.close ();
                        break;
                    case Gtk.ResponseType.NO:
                        edit_view_content.modified = false;
                        sidebar.is_modified = false;
                        dialog.close ();
                        break;
                    case Gtk.ResponseType.CANCEL:
                    case Gtk.ResponseType.CLOSE:
                    case Gtk.ResponseType.DELETE_EVENT:
                        dialog.close ();
                        return;
                    default:
                        assert_not_reached ();
                }
            });

            on_save ();
            edit_view_content.modified = false;
            sidebar.is_modified = false;
            save_last_files ();
            edit_view_content.text = "";
            var row = sidebar.add_file (Services.FileManager.get_cache_path ());
            sidebar.store.clear ();
            sidebar.outline_populate ();
            sidebar.view.expand_all ();
            win_stack.set_visible_child_name ("doc");
            titlebar_stack.set_visible_child_name ("title");
            titlebar.samenu_button.title = (_("New Document"));
            titlebar.samenu_button.subtitle = (_("Not Saved Yet"));
            row.path = (_("Document-%d.md".printf(row.uid)));
            row.header = (_("Not Saved Yet"));
            sidebar.reveal_child = true;
            Quilter.Application.gsettings.set_boolean("sidebar", true);
            if (edit_view_content.modified) {
                dialog.run ();
            }
        }

        private void on_open () {
            string contents;
            string path = Services.FileManager.open (out contents);

            if (sidebar.column.get_children () != null) {
                foreach (var child in sidebar.column.get_children ()) {
                    if (((Widgets.SideBarBox)child).path == path) {
                        sidebar.column.select_row (((Widgets.SideBarBox)child));
                        break;
                    } else {
                        sidebar.add_file (path);
                        sidebar.is_modified = true;
                        break;
                    }
                }
            } else {
                sidebar.add_file (path);
                sidebar.is_modified = true;
            }
            edit_view_content.text = contents;
            save_last_files ();
            win_stack.set_visible_child_name ("doc");
            titlebar_stack.set_visible_child_name ("title");
            Quilter.Application.gsettings.set_boolean("sidebar", true);
            sidebar.store.clear ();
            sidebar.outline_populate ();
            sidebar.view.expand_all ();
        }

        public void on_save () {
            unowned Widgets.SideBarBox? row = sidebar.get_selected_row ();
            if (row != null) {
                try {
                    Services.FileManager.save_file (row.path, edit_view_content.text);
                    edit_view_content.modified = false;
                } catch (Error e) {
                    warning ("Unexpected error during save: " + e.message);
                }
            }
        }

        private void on_save_as () {
            unowned Widgets.SideBarBox? row = sidebar.get_selected_row ();
            if (row != null) {
                try {
                    string fpath;
                    Services.FileManager.save_as (edit_view_content.text, out fpath);
                    edit_view_content.modified = false;
                    ((Widgets.SideBarBox) sidebar.column.get_selected_row ()).destroy ();
                    sidebar.add_file (fpath);
                } catch (Error e) {
                    warning ("Unexpected error during save: " + e.message);
                }
            }
        }

        public void action_keys () {
            try {
                var build = new Gtk.Builder ();
                build.add_from_resource ("/io/github/lainsce/Quilter/shortcuts.ui");
                var window =  (Gtk.ApplicationWindow) build.get_object ("shortcuts-quilter");
                window.set_transient_for (this);
                window.show_all ();
            } catch (Error e) {
                warning ("Failed to open shortcuts window: %s\n", e.message);
            }
        }

        public void action_about () {
            const string COPYRIGHT = "Copyright \xc2\xa9 2017-2021 Paulo \"Lains\" Galardi\n";

            const string? AUTHORS[] = {
                "Paulo \"Lains\" Galardi"
            };

            var program_name = Config.NAME_PREFIX + _("Quilter");
            Gtk.show_about_dialog (this,
                                   "program-name", program_name,
                                   "logo-icon-name", Config.APP_ID,
                                   "version", Config.VERSION,
                                   "comments", _("Focus on your writing."),
                                   "copyright", COPYRIGHT,
                                   "authors", AUTHORS,
                                   "artists", null,
                                   "license-type", Gtk.License.GPL_3_0,
                                   "wrap-license", false,
                                   "translator-credits", _("translator-credits"),
                                   null);
        }
    }
}
