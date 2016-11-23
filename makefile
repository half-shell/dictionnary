build:
	gcc -g src/*.c -o dict.exe
test:
	gcc -g src/dict.c test.c -o test
	./test.exe
