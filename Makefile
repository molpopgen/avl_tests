CC=gcc
CXX=g++
CFLAGS=-O2 -Wall
CXXFLAGS=-O3 -Wall -std=c++11
LDFLAGS=-Wl,-rpath,$(HOME)/anaconda3/lib
GSL=-lgsl -lgslcblas
all: avl.o simple_avl_test.o simple_map_test.o simple_unordered_map_test.o flat_map_test.o avl_tuple.o
	$(CC) -o simple_avl_test simple_avl_test.o avl.o $(GSL) -lm $(LDFLAGS)
	$(CXX) -o avl_tuple avl_tuple.o avl.o $(GSL) $(LDFLAGS)
	$(CXX) -o simple_map_test simple_map_test.o $(GSL) $(LDFLAGS)
	$(CXX) -o simple_unordered_map_test simple_unordered_map_test.o $(GSL) $(LDFLAGS)
	$(CXX) -o flat_map_test flat_map_test.o $(GSL) $(LDFLAGS)

clean:
	rm -f *.o
