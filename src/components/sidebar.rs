use gtk::prelude::*;

pub struct Sidebar {
    pub container: gtk::Revealer,
    pub sideheader: libhandy::HeaderBar,
    pub stack: gtk::Stack,
    pub files_list: gtk::ListBox,
    pub viewswitcher: libhandy::ViewSwitcher,
    pub placeholder: gtk::Label,
    pub outline: gtk::TreeView,
}

impl Sidebar {
    pub fn new() -> Sidebar {
        let builder = gtk::Builder::from_resource("/com/github/lainsce/quilter/sidebar.ui");
        get_widget!(builder, gtk::Revealer, container);
        get_widget!(builder, libhandy::HeaderBar, sideheader);
        get_widget!(builder, gtk::Stack, stack);
        get_widget!(builder, gtk::ListBox, files_list);
        get_widget!(builder, libhandy::ViewSwitcher, viewswitcher);
        get_widget!(builder, gtk::Label, placeholder);
        get_widget!(builder, gtk::TreeView, outline);

        Sidebar {
            container,
            sideheader,
            stack,
            files_list,
            viewswitcher,
            placeholder,
            outline,
        }
    }
}
