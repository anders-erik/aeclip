#include <gtkmm.h>
#include <giomm.h>

#include "app.hh"

#include "helloworld.hh"


Glib::RefPtr<Gtk::Application> app;


int main(int argc, char *argv[])
{
    app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    HelloWorld helloworld;

    // Shows the window and returns when it is closed.
    return app->run(helloworld);
}

// void copy_video_to_clipboard(const Glib::RefPtr<Gtk::Application> &app, const std::string &file_path)
// {
//     auto display = app->get_active_window()->get_display();
//     auto clipboard = display->get_clipboard();

//     // Create a file object
//     auto file = Gio::File::create_for_path(file_path);

//     // Get the file's content type
//     auto file_info = file->query_info(G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE);
//     auto mime_type = file_info->get_content_type();

//     // Create a GdkContentProvider
//     auto content_provider = Gdk::ContentProvider::create_for_file(file);

//     // Set the content on the clipboard
//     clipboard->set_content(content_provider);
// }

// copy_video_to_clipboard(app, "/path/to/your/video.mp4");