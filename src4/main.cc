#include "helloworld.h"
#include <gtkmm/application.h>

#include "app.hh"

Glib::RefPtr<Gtk::Application> app;

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create("org.gtkmm.example");

    // Shows the window and returns when it is closed.
    return app->make_window_and_run<HelloWorld>(argc, argv);
}