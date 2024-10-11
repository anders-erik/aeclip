from gi.repository import Gio

def get_window_titles():
    bus = Gio.bus_get_sync(Gio.BusType.SESSION, None)
    shell = Gio.DBusProxy.new_sync(bus, Gio.DBusProxyFlags.NONE, None,
                                   'org.gnome.Shell', '/org/gnome/Shell',
                                   'org.gnome.Shell', None)
    result = shell.Eval('(s)', 'JSON.stringify(global.get_window_actors().map(w => w.meta_window.get_title()))')
    return result

print(get_window_titles())