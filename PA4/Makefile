BINARY=pathfinder

lib_objects= \
ActorGraph.o \
ActorNode.o \
GraphNode.o \
MovieEdge.o \
pathfinder.o

all: pathfinder

pathfinder: $(lib_objects)
	clang++ -o pathfinder $(lib_objects)

clean:
	rm -f $(lib_objects) pathfinder

.cpp.o:
	clang++ -std=c++11 -c $< -o $@

