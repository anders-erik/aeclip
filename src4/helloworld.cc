#include "helloworld.h"

#include <iostream>
#include <fstream>
#include <vector>

#include <string>

// gpt
#include <glibmm.h>

#include <gtkmm.h>
#include <giomm.h>

#include <gdk/gdk.h>
#include <giomm/liststore.h>
#include <giomm/file.h>

// #include <gtkmm.h>
// #include <giomm/file.h>
#include <glibmm/bytes.h>
#include <glibmm/variant.h>

#include "app.hh"


HelloWorld::HelloWorld()
    : m_button("Hello World") // creates a new button with label "Hello World".
{
    // Sets the margin around the button.
    m_button.set_margin(10);

    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    m_button.signal_clicked().connect(sigc::mem_fun(*this,
                                                    &HelloWorld::on_button_clicked));

    // This packs the button into the Window (a container).
    set_child(m_button);
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::on_button_clicked()
{
    std::cout << "Hello World" << std::endl;
    // Basic clipboard - text
    // Glib::RefPtr<Gtk::Clipboard> clipboard = Gtk::Clipboard::get();
    // clipboard->set_text("Hello from GTKmm!");



    // ATTEMPT  1
    // auto display = app->get_active_window()->get_display();
    // auto clipboard = display->get_clipboard();

    // auto file = Gio::File::create_for_path("/home/anders/Videos/withaudio/2024-10-11_08:42:29_output.mp4");

    // auto file_info = file->query_info(G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE);
    // auto mime_type = file_info->get_content_type();

    // auto content_provider = Gdk::ContentProvider::create_for_file(file);



    // ATTEMPT  2
    std::string file_path = "/home/anders/Videos/withaudio/2024-10-11_08:42:29_output.mp4";
    auto display = Gdk::Display::get_default();
    auto clipboard = display->get_clipboard();

    std::cout << "clipboard->get_formats()->to_string() = " << clipboard->get_formats()->to_string() << std::endl;

    // Create a file URI
    // auto file = Gio::File::create_for_path(file_path);
    // Glib::ustring uri = file->get_uri();

    // Create a content provider with the file URI
    // auto content_provider = Gdk::ContentProvider::create([uri]()
    //                                                      { return Glib::Variant<std::vector<Glib::ustring>>::create(std::vector<Glib::ustring>{uri}); });

    // Try to use 'create'
    // https: // gnome.pages.gitlab.gnome.org/gtkmm/classGdk_1_1ContentProvider.html
    // Glib::ustring mime_type = "application/octet-stream";
    Glib::ustring mime_type = "gchararray text/plain;charset=utf-8 chromium/x-web-custom-data text/html text/plain";

    // MANUAL DATA
    // const unsigned char data[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f}; // "Hello" in ASCII
    // Glib::RefPtr<const Glib::Bytes> bytes = Glib::Bytes::create(data, sizeof(data));

    // DATA FROM FILE
    std::ifstream file(file_path, std::ios::binary | std::ios::ate);
    if (!file)
    {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }
    // Get the file size
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    // Read the file into a vector
    std::vector<unsigned char> buffer(size);
    if (!file.read(reinterpret_cast<char *>(buffer.data()), size))
    {
        std::cerr << "Failed to read file" << std::endl;
        return;
    }
    // Create a Glib::Bytes object from the file data
    Glib::RefPtr<const Glib::Bytes> fileBytes = Glib::Bytes::create(buffer.data(), buffer.size());
    // Create Content provider
    auto file_content_provider = Gdk::ContentProvider::create(mime_type, fileBytes);


    // STRING PATH instead of file data
    std::string strBuffer = file_path ;
    Glib::RefPtr<const Glib::Bytes> stringBytes = Glib::Bytes::create(strBuffer.data(), strBuffer.size());
    // Create Content provider
    auto string_content_provider = Gdk::ContentProvider::create(mime_type, stringBytes);

    // content_provider->set_data()
    // content_provider->write_mime_type_async(mime_type, )

        // Set the clipboard content
    // clipboard->set_content(file_content_provider);
    clipboard->set_content(string_content_provider);
    // clipboard->set_text(file_path); // test with plain text.. THAT ALWAYS WORKS!

    


}

