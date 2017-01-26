all: helloWorld.o
	g++ -g helloWorld.o -o helloWorld

helloWorld.o: helloWorld.cpp
	g++ -g -c helloWorld.cpp -o helloWorld.o

clean:
	rm -f *.o helloWorld

run: HelloWorld
	./helloWorld

