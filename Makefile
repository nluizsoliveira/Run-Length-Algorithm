BINARY=trab5
SOURCES=functions.c main.c
INCLUDES=.

all: clean compile clean

compile:
	@gcc -o $(BINARY) $(SOURCES) -I$(INCLUDES)

clean:
	@clear
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./trab5 < ./testes/1.in

zip:
	zip -r trab5.zip *.c *.h Makefile
