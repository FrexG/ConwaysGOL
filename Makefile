CC := gcc 
CFLAGS := -Wall -Wextra -std=c11

LIBS := `pkg-config --libs --cflags raylib` -lm

SRC := gol.c
OBJS := gol.o
MAIN := gol 

$(MAIN):$(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LIBS)

$(OBJS):$(SRC)
	$(CC) $(CFLAGS) -o $(OBJS) -c $(SRC) $(LIBS)

clean:
	rm *.o && rm gol 

