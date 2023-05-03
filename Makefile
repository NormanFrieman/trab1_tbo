

all:
	gcc -Wall -g -o trab1 Main.c Sources/*.c -lm
clean:
	rm -f main