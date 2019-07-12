#!/bin/bash

CPP_FILES=`find . -name ''\*.cpp''`
HPP_FILES=`find . -name ''\*.hpp''`
SH_FILES=`find . -name ''\*.sh''`

FILES="$CPP_FILES $HPP_FILES $SH_FILES"

for file in $FILES
do
    expand -t4 $file > "$file.t2s123"
done

TMP_FILES=`find . -name ''\*.t2s123''`

for TMP_FILE in $TMP_FILES
do
    ORIG_FILE_NAME=${TMP_FILE:0: -7}
    if ! cmp --silent "$ORIG_FILE_NAME" "$TMP_FILE"
    then
        truncate -s0 "$ORIG_FILE_NAME"
        cat "$TMP_FILE" >> "$ORIG_FILE_NAME"
    fi
    rm "$TMP_FILE"
done

    
