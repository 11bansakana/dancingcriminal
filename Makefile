CC=g++
EXE=dc
OBJS=main.o game.o card.o playeri.o cardfactory.o
CPPFLAGS+=-std=c++11
all: $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CPPFLAGS)
playeri.o: playeri.cpp playeri.h
	$(CC) -c playeri.cpp $(CPPFLAGS)
clean:
	rm -rf *.o $(EXE)
