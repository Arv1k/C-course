CPP_FLAGS = -Wall

SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system




all: main.o
	g++ main.o $(CPP_FLAGS) $(SFML_FLAGS) -o sfml-app

main.o:
	g++ -c main.cpp

start: all clean
	./sfml-app

clean:
	rm -rf *.o
