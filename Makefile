APP				= spacerogue

CXX				= clang
CXXFLAGS		= -std=c++17 -Isrc/

LIBS			=
DEFS			=

ifneq (DEBUG,)
	CXXFLAGS	+= -g
endif

SRC_FILES		= $(wildcard src/*.cpp) \
				  $(wildcard src/ui/*.cpp)

# determine graphics library
ifeq (GFX,sdl)
	LIBS		+= -lsdl
	DEFS		+= -DGFX_SDL
	SRC_FILES	+= src/video/sdl.cpp
else
	LIBS		+= -lncurses
	DEFS		+= -DGFX_CURSES
	SRC_FILES	+= src/video/curses.cpp
endif

#SRC_FILES		= $(shell find src/ -type f -name '*.cpp')
#HDR_FILES		= $(patsubst %.cpp,%.h,$(SRC_FILES))

OBJ_FILES		= $(patsubst %.cpp,%.o,$(SRC_FILES))


.PHONY: tags clean

$(APP): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c $<

tags:
	cd src/; ctags -R

clean:
	rm -f $(APP)
	rm -f src/tags
	rm -f `find src/ -type f -name '*.o'`

