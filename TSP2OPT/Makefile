# Makefile для проекта TSP

all: tsp_solver

# Сборка исполняемого файла из объектных файлов
tsp_solver: parser.o solver.o main.o
	g++ parser.o solver.o main.o -o tsp_solver

# Компиляция main.cpp
main.o: main.cpp parser.h solver.h
	g++ -c main.cpp

# Компиляция parser.cpp
parser.o: parser.cpp parser.h
	g++ -c parser.cpp

# Компиляция solver.cpp
solver.o: solver.cpp solver.h
	g++ -c solver.cpp

# Очистка всех объектных файлов и исполняемого файла
clean:
	rm -rf tsp_solver *.o
