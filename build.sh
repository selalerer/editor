#!/bin/bash

BIN_NAME=editor
OBJ_FOLDER=obj
CFLAGS="-I. `pkg-config --cflags gtk+-3.0`"
LFLAGS="`pkg-config --libs gtk+-3.0`"

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

echo "Linking..."
OBJS=`find $OBJ_FOLDER -name '*.o'`
g++ $OBJS $LFLAGS -o $BIN_NAME



