#!/bin/bash


function ccd() {
   
    if [ -z "$1" ]; then
        echo "Usage: mcd <directory>"
        return 1
    fi

    # If the argument is '~', go to the home directory
    if [ "$1" == "~" ]; then
        cd ~
    # If the argument is '..', go to the parent directory
    elif [ "$1" == ".." ]; then
        cd ..
    
    elif [ -d "$1" ]; then
        cd "$1"
    else
        echo "Error: Directory '$1' does not exist."
        return 1
    fi

  
    echo "Current directory: $(pwd)"
}

