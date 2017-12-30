PROGRAM = 3pt
CC = gcc
CFLAGS  = -c -Wall -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL -lm

$(PROGRAM): main.o scene.o light.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) $^ $(LDLIBS)
	
.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) 

dist: clean
	-tar -czv -C .. -f ../$(PROGRAM).tar.gz RG014-basketball-3pt-

