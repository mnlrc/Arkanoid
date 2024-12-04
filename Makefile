TOPDIR := ./
SRCDIR := $(TOPDIR)/src/
OBJDIR := $(TOPDIR)/obj/
BINDIR := $(TOPDIR)
NAME   := Arkanoid-game
EXE    := $(BINDIR)$(NAME)

# Extensions de fichiers
SFILES := cpp
OFILES := o

# Compilateur
CXX := g++

# Options de compilation
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2
CXXFLAGS += -std=c++2b
CXXFLAGS += -pedantic -Wall -Wextra -g
CXXFLAGS += -O2
CXXFLAGS += -Walloc-zero -Wcast-align -Wconversion -Wctad-maybe-unsupported -Wctor-dtor-privacy -Wdeprecated-copy-dtor -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wformat-signedness -Wformat=2 -Winit-self -Wlogical-op -Wmismatched-tags -Wnoexcept -Wnon-virtual-dtor -Wnull-dereference -Wold-style-cast -Woverloaded-virtual -Wredundant-tags -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wuseless-cast -Wvolatile -Wzero-as-null-pointer-constant -fmax-errors=2
CXXFLAGS += -Wno-unused-command-line-argument -Wno-unknown-warning-option
CXXFLAGS += $(shell pkg-config allegro-5 allegro_primitives-5 allegro_font-5 --cflags | sed 's/-I/-isystem/g')

# Flags de lien
LDFLAGS = $(shell pkg-config allegro-5 allegro_primitives-5 allegro_font-5 --libs)
LDFLAGS += -fsanitize=address,undefined

# Fichiers source et objets
SOURCES := $(shell find $(SRCDIR) \( -name "*.$(SFILES)" \) )
OBJECTS := $(patsubst $(SRCDIR)%.$(SFILES), $(OBJDIR)%.$(OFILES), $(SOURCES))

.PHONY: all clean

# Cible par défaut
all: $(EXE)

# Lien des fichiers objets pour créer l'exécutable
$(EXE): $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Compilation des fichiers objets
$(OBJDIR)%.$(OFILES): $(SRCDIR)%.$(SFILES)
	@mkdir -p $(OBJDIR) # Crée le dossier obj si nécessaire
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) $< -c -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	@rm -f $(OBJECTS) $(EXE)

