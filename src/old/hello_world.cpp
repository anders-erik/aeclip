#include <gtkmm.h>

class HelloWorld : public Gtk::Window
{
public:
    HelloWorld()
    {
        set_title("Hello, Worlds!");
        set_default_size(400, 200);
        show_all();
    }
};

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "com.example.helloworld");
    HelloWorld hw;
    return app->run(hw);
}