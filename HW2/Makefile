
CXX = g++
CXXFLAGS = -Wall -g


EXECS = least5 game prefixsubarray

LEAST5_SRC = least5.cpp minHeap.cpp
GAME_SRC = game.cpp AVL.cpp
PREFIXSUBARRAY_SRC = prefixsubarray.cpp AVL.cpp


LEAST5_OBJS = least5.o minHeap.o
GAME_OBJS = game.o AVL.o
PREFIXSUBARRAY_OBJS = prefixsubarray.o AVL.o


all: $(EXECS)


build: all


least5: $(LEAST5_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(LEAST5_OBJS)


game: $(GAME_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(GAME_OBJS)


prefixsubarray: $(PREFIXSUBARRAY_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(PREFIXSUBARRAY_OBJS)


least5.o: least5.cpp minHeap.h
	$(CXX) $(CXXFLAGS) -c least5.cpp

minHeap.o: minHeap.cpp minHeap.h
	$(CXX) $(CXXFLAGS) -c minHeap.cpp


game.o: game.cpp AVL.h
	$(CXX) $(CXXFLAGS) -c game.cpp

AVL.o: AVL.cpp AVL.h
	$(CXX) $(CXXFLAGS) -c AVL.cpp


prefixsubarray.o: prefixsubarray.cpp AVL.h
	$(CXX) $(CXXFLAGS) -c prefixsubarray.cpp


clean:
	rm -f $(EXECS) *.o
