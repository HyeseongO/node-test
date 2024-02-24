
default:
	g++ -std=c++11 -g main.cpp -o main

build-tests:
	g++ -std=c++11 tester.cpp -o tester

run-tests:
	./tester
