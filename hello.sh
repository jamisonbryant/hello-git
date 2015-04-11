if [ -f "bin/hello" ]; then
    export LD_LIBRARY_PATH=lib/libconfig/lib/.libs:/usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/server
    ./bin/hello
else
    echo "Please build the program first (hint: run make)"
fi
