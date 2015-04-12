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
OUTPUT    := $(BINDIR)/hello

LIBRARIES := -L$(LIBDIR)/libconfig/lib/.libs -lconfig++ \
		-L/usr/local/lib -lpocketsphinx -lsphinxbase -lsphinxad \
			-lpulse -lpulse-simple -lpthread -lm

INCLUDES  := -I/usr/local/include \
		-I$(LIBDIR)/libconfig/lib \
		-I$(LIBDIR)/sphinxbase/include \
		-I$(LIBDIR)/pocketsphinx/include

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
