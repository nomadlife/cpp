CC=gcc
CXX=g++
CFLAGS=-I.
SRC = main.cpp telphonebook.cpp array.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(SRC)
	$(CXX) -c -o $@ $< $(CFLAGS)

tel2.out : $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)
	rm -f *.o *~