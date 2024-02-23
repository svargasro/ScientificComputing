CXXFLAGS=-02 -std=c++17


all: sumupdown.pdf


sumupdown.x: sumupdown.cpp
	g++ ${CXXFLAGS} sumupdown.cpp -o sumupdown.x



# %.x: %.cpp
# 	g++ $^ -o $@
# 	Equivalente
#
#Si cambia sumupdown, entonces actualice data.txt
data.txt: sumupdown.x
	./sumupdown.x > data.txt


sumupdown.pdf: data.txt plot.gp
	gnuplot plot.gp

.PHONY: clean

clean:
rm -f *.x *.pdf
