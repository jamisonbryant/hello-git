#!/bin/bash

if [ -f "bin/hello" ]; then
    export LD_LIBRARY_PATH=/usr/local/lib
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:lib/libconfig/lib/.libs
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/server
    export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig

    ./bin/hello
else
    echo "Please build the program first (hint: run make)"
fi
