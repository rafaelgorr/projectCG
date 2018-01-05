CXX         = g++
CXXFLAGS    = -lGL -lGLU -lglut  -lm -Wall -std=c++11
SOURCES    =  	./tinyxml/tinyxml.cpp \
				./tinyxml/tinystr.cpp \
				./tinyxml/tinyxmlerror.cpp \
				./tinyxml/tinyxmlparser.cpp \
				functions.cpp					 \
				Circle.cpp \
				globals.cpp \
				Reader.cpp \
				Player.cpp \
				Enemy.cpp \
				Body.cpp \
				Image.cpp \
				Mesh.cpp \
				Vertec.cpp \
 				client.cpp
OBJECTS    = $(SOURCES:.cpp=.o)
EXECUTABLE = trabalhocg

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o $@



clean:
	rm -f $(OBJECTS) $(EXECUTABLE)


run: ./$(EXECUTABLE)
	   ./$(EXECUTABLE) ./
