PROGRAM = 3pt
CC = gcc
CFLAGS  = -O3 -c -Wall -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL -lm

$(PROGRAM): main.o scene.o light.o callback_functions.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) $^ $(LDLIBS)

main.o: main.c callback_functions.h 
	$(CC) $(CFLAGS) -o $@ $<

scene.o: scene.c scene.h variables.h
	$(CC) $(CFLAGS) -o $@ $<

callback_functions.o: callback_functions.c callback_functions.h variables.h
	$(CC) $(CFLAGS) -o $@ $<

light.o: light.c light.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean dist 

clean:
	-rm *.o $(PROGRAM) 

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)	
