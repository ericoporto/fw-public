TARGET := main

SOURCES := \
    main.cpp \
    FilmicCurve/FilmicColorGrading.cpp \
    FilmicCurve/FilmicToneCurve.cpp \
    Core/CoreHelpers.cpp \
    Core/Mat44.cpp \
    Core/Quat.cpp \
    Core/ShUtil.cpp

CXXFLAGS := -ICore -std=c++11 -Wall -Wno-unused-function -Wno-unknown-pragmas -Werror

OBJECTS := $(SOURCES:.cpp=.o)

all: $(TARGET)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJECTS)
