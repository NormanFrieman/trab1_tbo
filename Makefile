

all:
	gcc -Wall -g -o main Main.c Sources/*.c -lm
clean:
	rm -f main