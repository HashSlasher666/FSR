all: graph_coloring

graph_coloring: parser.o solver.o main.o
	g++ parser.o solver.o main.o -o graph_coloring

main.o: main.cpp parser.h solver.h
	g++ -c main.cpp

parser.o: parser.cpp parser.h
	g++ -c parser.cpp

solver.o: solver.cpp solver.h
	g++ -c solver.cpp

clean:
	rm -rf graph_coloring *.o
