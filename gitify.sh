#!/bin/bash

# Ensure we're in a git repo
if [ ! -d ".git" ]; then
    echo "Run this in a git repository!"
    exit 1
fi

# Iterate over all files (recursively) sorted by last modified time
find . -type f ! -path './.git/*' -printf '%T@ %p\n' | sort -n | while read timestamp file; do
    # Convert timestamp to human-readable format
    commit_date=$(date -d @"$timestamp" --iso-8601=seconds)

    echo $file $timestamp $commit_date
    
    # Stage the file
    git add "$file"
    
    # Commit with the file’s last modified date
    GIT_AUTHOR_DATE="$commit_date" GIT_COMMITTER_DATE="$commit_date" git commit -m "Add $file"
done
