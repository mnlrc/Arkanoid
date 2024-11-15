TOPDIR := ./
SRCDIR := $(TOPDIR)/src/
OBJDIR := $(TOPDIR)/obj/
BINDIR := $(TOPDIR)
NAME   := Arkanoid-game
EXE    := $(BINDIR)$(NAME)

# File extensions
SFILES := cpp
OFILES := o

# Compiler
CXX := g++

# Compilation flags
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2
CXXFLAGS += -std=c++2b
CXXFLAGS += -pedantic -Wall -Wextra -g
CXXFLAGS += -O2
CXXFLAGS += -Walloc-zero -Wcast-align -Wconversion -Wctad-maybe-unsupported -Wctor-dtor-privacy -Wdeprecated-copy-dtor -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wformat-signedness -Wformat=2 -Winit-self -Wlogical-op -Wmismatched-tags -Wnoexcept -Wnon-virtual-dtor -Wnull-dereference -Wold-style-cast -Woverloaded-virtual -Wredundant-tags -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wuseless-cast -Wvolatile -Wzero-as-null-pointer-constant -fmax-errors=2
CXXFLAGS += -Wno-unused-command-line-argument -Wno-unknown-warning-option
CXXFLAGS += $(shell pkg-config allegro-5 allegro_primitives-5 allegro_font-5 --cflags | sed 's/-I/-isystem/g')

# Link flags
LDFLAGS = $(shell pkg-config allegro-5 allegro_primitives-5 allegro_font-5 --libs)

# Source and object files
SOURCES := $(shell find $(SRCDIR) -name "*.$(SFILES)")
OBJECTS := $(patsubst $(SRCDIR)%.$(SFILES), $(OBJDIR)%.$(OFILES), $(SOURCES))

.PHONY: all clean

# Default target
all: $(EXE)

# Building executable
$(EXE): $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Building object files
$(OBJDIR)%$(OFILES): $(SRCDIR)%$(SFILES)
	$(CXX) $(CXXFLAGS) $< -c -o $@ 

# Cleaning
clean:
	@rm -f $(OBJECTS) $(EXE)
