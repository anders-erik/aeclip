import dbus
import time
bus = dbus.SessionBus()
obj = bus.get_object("org.gnome.Shell", "/org/gnome/Shell/Screencast")

obj.Screencast("Auto %d %t.webm", [],
               dbus_interface="org.gnome.Shell.Screencast")
time.sleep(999999)