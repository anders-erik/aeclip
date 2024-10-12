// #include <gdkmm/atom.h>
#include <gtkmm.h>
#include <gtkmm/clipboard.h>
#include <giomm.h>

#include "helloworld.hh"
#include <iostream>


HelloWorld::HelloWorld()
    : m_button("Hello World") // creates a new button with label "Hello World".
{
    // Sets the border width of the window.
    set_border_width(10);

    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    m_button.signal_clicked().connect(sigc::mem_fun(*this,
                                                    &HelloWorld::on_button_clicked));

    // This packs the button into the Window (a container).
    add(m_button);

    // The final step is to display this newly created widget...
    m_button.show();
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::on_button_clicked()
{
    std::cout << "Hello World" << std::endl;

    Glib::RefPtr<Gtk::Clipboard> clipboard = Gtk::Clipboard::get();
    
    // Setting text works!
    clipboard->set_text("Hello from GTKmm!");

    // Image to clipboard works!
    // Glib::RefPtr<Gdk::Pixbuf> pixbuf = Gdk::Pixbuf::create_from_file("/home/anders/Desktop/number_line.jpg");
    // clipboard->set_image(pixbuf);

    /* 
        VIDEO
    */
    // Attempt 1
    // std::string video_file_uri = "file:///path/to/video.mp4";
    // std::vector<Glib::ustring> uris;
    // uris.push_back(video_file_uri);
    // clipboard->set_uris(uris);

    // Attempt 2
    // std::string video_file_uri = "/home/anders/Videos/withaudio/2024-10-11_08:42:29_output.mp4";
    // clipboard->set_text(video_file_uri);

    // // Attempt 3
    // // Define the video file path (replace with actual path)
    // std::string video_file_path = "/path/to/video.mp4"; // Use the path without "file://"

    // // Define a target for the clipboard
    // Gdk::Atom target = Gdk::Atom::intern("text/uri-list");

    // // Set the data with a callback function
    // clipboard->set_with_data(target, [video_file_path](const Glib::RefPtr<Gtk::Clipboard> &clipboard, const Gdk::Atom &selection, Gtk::Clipboard::SetWithDataFuncData data)
    //                          {
    //             std::string uri = "file://" + video_file_path + "\n"; // Add newline for multiple URIs
    //             clipboard->set_text(uri); }, [](const Glib::RefPtr<Gtk::Clipboard> &clipboard, const Gdk::Atom &selection)
    //                          {
    //                              // No cleanup needed
    //                          });

    // Attempt 4
    // std::string video_file_path = "/home/anders/Videos/withaudio/2024-10-11_08:42:29_output.mp4"; 
    // std::string uri = "file://" + video_file_path + "\n";
    // clipboard->set_text(uri);

    // Attempt 5 -
    // Glib::ustring uri = Glib::filename_to_uri("/home/anders/Videos/withaudio/2024-10-11_08:42:29_output.mp4");

    // // Set up the target entry for URI lists
    // std::vector<Gtk::TargetEntry> targets;
    // targets.push_back(Gtk::TargetEntry("text/uri-list"));

    // // Set the clipboard content
    // clipboard->set_with_data(
    //     targets,
    //     [uri](Gtk::SelectionData &selection_data, guint /*info*/)
    //     {
    //         selection_data.set_uris({uri});
    //     },
    //     []() {});

    // Attempt 6 -- just writes text
    // Glib::ustring uri = Glib::filename_to_uri("/home/anders/Videos/withaudio/2024-10-11_08:42:29_output.mp4");
    // Glib::ustring clipboard_content = "text/uri-list\n" + uri;
    // clipboard->set_text(clipboard_content);

    // Attempt 7
    // Glib::ustring uri = Glib::filename_to_uri("/home/anders/Videos/withaudio/2024-10-11_08:42:29_output.mp4");

    // // Format the URI list as Firefox expects
    // // Each URI should be on a new line, and the list should end with a newline
    // Glib::ustring clipboard_content = uri + "\r\n";

    // // Set the clipboard content with the correct MIME type
    // clipboard->set_text(clipboard_content);

    // // We also need to set the targets to indicate that this is a URI list
    // std::vector<Gtk::TargetEntry> targets;
    // targets.push_back(Gtk::TargetEntry("text/uri-list"));
    // clipboard->set_with_owner(targets, sigc::ptr_fun(&HelloWorld::on_button_clicked));
}