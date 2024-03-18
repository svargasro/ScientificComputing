SHELL:=/bin/bash

all: factorial_main.x

%.x: %.o factorial.o
	g++ $^ -o $@

%.o: %.cpp
g++ -c $<

clean:
    rm -f *.o *.x
