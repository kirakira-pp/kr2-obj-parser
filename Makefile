all: compile
	
compile:
	clang++ main.cpp parser.cpp -std=c++11 -o main

run:
	./main bunny.obj

clean:
	rm ./main
