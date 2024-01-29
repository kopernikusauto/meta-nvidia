#!/bin/bash

# Check if the user provided a directory as an argument
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <directory_path> <output_file>"
    exit 1
fi

# Get the directory and output file from the arguments
DIRECTORY="$1"
OUTPUT_FILE="$2"

# Recursively list all directories and files, excluding ones that start with .git or git
find "$DIRECTORY" -name '.git*' -prune -o -name 'git*' -prune -o -type d -print -o -type f -print > "$OUTPUT_FILE"

echo "Directories and files (excluding .git* and git*) have been written to $OUTPUT_FILE"
