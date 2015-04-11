if [ -f "bin/hello" ]; then
    export LD_LIBRARY_PATH=lib/libconfig/lib/.libs
    ./bin/hello
else
    echo "Please build the program first (hint: run make)"
fi
