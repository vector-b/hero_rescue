# Makefile
OBJS =  main.c
TARG = hero
TO_C = hero hero.o 
CFLAG = -g
CC = gcc
INCLUDE = class/hero_class.c
LIBS = -lm $$(pkg-config --libs allegro-5 allegro_image-5 allegro_font-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5)

all: hello

hello:${OBJS}
	${CC} -o ${TARG} ${OBJS} ${INCLUDE} ${LIBS} ${CFLAG}

mosaico.o:   main.c class/hero_class.h
mosaic_class.o: class/hero_class.c class/hero_class.h

clean:
	-rm -f *~ *.o

purge: clean
	-rm -f ${TO_C}