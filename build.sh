#!/bin/bash

BIN_NAME="selaeditor"
OBJ_FOLDER=obj
CFLAGS="-g -I. `pkg-config --cflags gtk+-3.0`"
LFLAGS="-g `pkg-config --libs gtk+-3.0`"

CPPS=`find . -name '*.cpp'`


function get_obj_file_name {
    local CPP_FILE_NAME=$1
    local BASENAME=${CPP_FILE_NAME%.cpp}
    echo "$OBJ_FOLDER/$BASENAME.o"
}

function compile {
    local CPP_FILE_NAME=$1
    echo "Compiling $CPP_FILE_NAME"
    local OBJ_FILE_NAME=$(get_obj_file_name $CPP_FILE_NAME)
    mkdir -p $(dirname $OBJ_FILE_NAME)
    g++ -c $CFLAGS $CPP_FILE_NAME -o $OBJ_FILE_NAME
}

for F in $CPPS
do
    tools/need_compile $F $(get_obj_file_name $F)
    if [ $? -eq 0 ]
    then
        compile $F
        RET_VAL=$?
        if [ $RET_VAL -ne 0 ]
        then
            echo "Compilation of $F failed."
            exit $RET_VAL
        fi
    else
        echo "Skipping $F" 
    fi
done

NEED_LINK=false
if [ ! -f $BIN_NAME ]
then
    NEED_LINK=true
fi

OBJS=`find $OBJ_FOLDER -name '*.o'`

if ! $NEED_LINK
then
    for F in $OBJS
    do
        if [ $F -nt $BIN_NAME ]
        then
            NEED_LINK=true
            echo "$F is newer than $BIN_NAME"
            break
        fi
    done
fi

if $NEED_LINK
then
    echo "Linking..."
    g++ $OBJS $LFLAGS -o $BIN_NAME
else
    echo "$BIN_NAME is up to date." 
fi



