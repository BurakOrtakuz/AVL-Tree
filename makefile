derlebaglacalistir: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/QueueNode.cpp -o ./lib/QueueNode.o
	g++ -c -I "./include" ./src/AvlNode.cpp -o ./lib/AvlNode.o
	g++ -c -I "./include" ./src/AvlTree.cpp -o ./lib/AvlTree.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o

bagla:
	g++  ./lib/Queue.o ./lib/QueueNode.o ./lib/AvlNode.o ./lib/AvlTree.o ./lib/main.o -o ./bin/program.exe
calistir:
	./bin/program.exe