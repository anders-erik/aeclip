
from gi.repository import Gio

def get_running_apps():
    bus = Gio.bus_get_sync(Gio.BusType.SESSION, None)
    proxy = Gio.DBusProxy.new_sync(
        bus,
        Gio.DBusProxyFlags.NONE,
        None,
        'org.gnome.Shell',
        '/org/gnome/Shell',
        'org.gnome.Shell.AppStore',
        None
    )
    apps = proxy.GetRunningApps()
    return apps

print(get_running_apps())