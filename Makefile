

all:
	gcc -Wall -g -o main Main_Compactador.c Sources_Compactador/*.c -lm
clean:
	rm -f main