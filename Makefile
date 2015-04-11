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
LIBPATHS  := $(LIBDIR)/libconfig/lib/.libs
LIBNAMES  := config++
INCLUDES  := $(LIBDIR)/libconfig/lib
OUTPUT    := $(BINDIR)/hello

# Flags
CFLAGS := -Wall
LDFLAGS := -L$(LIBPATHS) -l$(LIBNAMES)
INCFLAGS := -I$(INCLUDES)

all: clean init compile

init:
	$(MKDIR) $(OBJDIR)
	$(MKDIR) $(BINDIR)

compile: $(OBJECTS)
	$(COMPILE) $(CFLAGS) -o $(OUTPUT) $(OBJECTS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(COMPILE) $(INCFLAGS) -c $< -o $@

clean:
	$(RMDIR) $(OBJDIR)
	$(RMDIR) $(BINDIR)
