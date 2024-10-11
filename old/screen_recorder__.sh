#!/bin/bash

# Default output directory
OUTPUT_DIR="$HOME/ScreenRecordings"

# Create output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Generate a unique filename based on current date and time
FILENAME="$OUTPUT_DIR/recording_$(date +%Y%m%d_%H%M%S).mp4"

# Start the recording
wf-recorder -f "$FILENAME" -a &

# Store the PID of the wf-recorder process
PID=$!

echo "Recording started. Press Ctrl+C to stop."

# Wait for user to press Ctrl+C
trap "kill $PID" INT
wait $PID

echo "Recording stopped. Saved as $FILENAME"

# Copy the video file path to clipboard
if command -v wl-copy &> /dev/null; then
    echo -n "$FILENAME" | wl-copy
    echo "Video file path copied to clipboard."
else
    echo "wl-copy not found. Install it to enable clipboard functionality."
fi