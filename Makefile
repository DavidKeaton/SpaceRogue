APP				= spacerogue

CXX				= clang
CXXFLAGS		= -std=c++17

LIBS			= -lsdl -lncurses


SRC_FILES		= $(shell find src/ -type f -name '*.cpp')
#CPP_FILES		= $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))
HDR_FILES		= $(patsubst %.cpp,%.h,$(SRC_FILES))
OBJ_FILES		= $(patsubst %.cpp,%.o,$(SRC_FILES))


.PHONY: clean

$(APP): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f `find src/ -type f -name '*.o'`

