# aeclip - clipboard utility 

## Supported platforms
- Ubuntu 22.04 - GNOME/Wayland
    - src3 = gtkmm 3.0
    - src4 = gtkmm 4.0

## Current functionality

### screencast with audio
- by running the script in `./screencast`, any screencast using the built-in app in ubuntu/GNOME triggers default-audio recording using ffmpeg and combines them into one .mp4-file in ~/Videos/withaudio. 
- Many attempts have been made to have the outputted video with audio add to the system clipboard, but without success.
    - wl-copy (part of wl-clipboard)
    - copyq
    - It appears that the clipboard access is restricted to GNOME-windows using the official gtk-bindings. Meaning I need to set the clipboard from the currently active window!
        - https://discourse.nixos.org/t/wl-copy-not-working/44557/2
        - https://stackoverflow.com/questions/39616066/wayland-clipboard-api
        - 
- The recommended approach seemes to be OBS, which has better functionality than e..g ffmpeg
    - https://www.gamingonlinux.com/forum/topic/5345/
        - simplescreenrecorder ony has x-lib dependencies on their github
            - https://github.com/MaartenBaert/ssr

### Hello World - src-folder - GNOME/GTK+
- gtkmm-3.0 app for clipboard access!


## TODO: Resolve the following issues on the GNOME/Wayland platform
- Stopping screencast with ANY  shortcut
    - https://gitlab.gnome.org/GNOME/gnome-shell/-/issues/5386

