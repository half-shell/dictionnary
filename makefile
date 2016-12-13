build:
	gcc -g src/*.c -o dict.exe
test:
	gcc -g src/dict.c test.c -o test.exe
	./test.exe

clean:
	rm test.exe dict.exe
