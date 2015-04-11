# Commands
COMPILE=g++
MKDIR=mkdir -p
RMDIR=rm -rf

# Directories
SRCDIR := src
LIBDIR := lib
OBJDIR := obj
BINDIR := bin

# Resources
SOURCES   := $(wildcard src/*.cpp)
OBJECTS   := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
LIBRARIES := -L$(LIBDIR)/libconfig/lib/.libs -lconfig++ -L$(LIBDIR)/voce/lib
INCLUDES  := -I$(LIBDIR)/libconfig/lib -I$(LIBDIR)/voce/src/c++ -I/usr/lib/jvm/java-7-openjdk-amd64/include
OUTPUT    := $(BINDIR)/hello

# Flags
CFLAGS := -Wall
LDFLAGS := -L$(LIBPATHS) -l$(LIBNAMES)

all: clean init compile

init:
	$(MKDIR) $(OBJDIR)
	$(MKDIR) $(BINDIR)

compile: $(OBJECTS)
	$(COMPILE) $(CFLAGS) -o $(OUTPUT) $(OBJECTS) $(LIBRARIES)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(COMPILE) $(INCLUDES) -c $< -o $@

clean:
	$(RMDIR) $(OBJDIR)
	$(RMDIR) $(BINDIR)
