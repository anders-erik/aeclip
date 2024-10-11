#!/bin/bash

# DIRS
WATCH_DIR=~/Videos/Screencasts
DEST_DIR=~/Videos/withaudio

# FULL FILE PATHS
SRC_VIDEO_FILE=""
VIDEO_FILE=""
AUDIO_FILE=""
OUTPUT_FILE=""
FFMPEG_PID=""

# Watch for new files created and wait until they are closed (writing complete)
inotifywait -m "$WATCH_DIR" -e create -e close_write |
while read path action file; do

    if [[ "$action" == "CREATE" ]]; then
    
        # File Names
        SRC_VIDEO_FILE="$path$file"
        VIDEO_FILE="$DEST_DIR/$(date +%Y-%m-%d_%H:%M:%S)_video.webm"
        OUTPUT_FILE="$DEST_DIR/$(date +%Y-%m-%d_%H:%M:%S)_output.mp4"
        AUDIO_FILE="$DEST_DIR/$(date +%Y-%m-%d_%H:%M:%S)_audio.wav";

        # Start audio recording in the background
        ffmpeg -f pulse -i default -acodec pcm_s16le -ar 44100 "$AUDIO_FILE" &
        FFMPEG_PID=$!  # Store the process ID of ffmpeg

    elif [[ "$action" == "CLOSE_WRITE,CLOSE" ]]; then
        echo "Screencast write completed: $file"
        
        if [[ ! -z "$FFMPEG_PID" ]]; then
            sleep 1 # Delay to prevent audio from getting cut 1 second short
            kill -INT "$FFMPEG_PID"
        fi
        
        # 
        mv "$SRC_VIDEO_FILE" "$VIDEO_FILE"

        # ffmpeg -i "$DEST_DIR/$VIDEO_FILE" -i "$DEST_DIR/$AUDIO_FILE" -c:v copy -c:a aac -filter_complex "[1:a]adelay=1000|1000[aud]" -map 0:v -map "[aud]" "$DEST_DIR/$OUTPUT_FILE"
        # ffmpeg -i "$DEST_DIR/$VIDEO_FILE" -i "$DEST_DIR/$AUDIO_FILE" -c:v copy -c:a aac -filter_complex "[1:a]adelay=1000|1000[aud]" -map 0:v -map "[aud]" "$DEST_DIR/$OUTPUT_FILE"
        ffmpeg -i "$VIDEO_FILE" -i "$AUDIO_FILE" -vf "scale=trunc(iw/2)*2:trunc(ih/2)*2" -c:v libx264 -c:a aac -strict experimental "$OUTPUT_FILE"

        rm "$VIDEO_FILE" "$AUDIO_FILE"

        copyq add --type text/uri-list "$OUTPUT_FILE"

        aplay sound-done.wav
    fi
done
