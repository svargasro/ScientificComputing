all: distributedUnitMatrix.cpp.x


distributedUnitMatrix.cpp.x: distributedUnitMatrix.cpp
	mpic++ distributedUnitMatrix.cpp -o distributedUnitMatrix.x
	mpirun -np 3 --oversubscribe distributedUnitMatrix.x 6



# data.txt: sumupdown.x
# 	./sumupdown.x > data.txt


# sumupdown.pdf: data.txt plot.gp
# 	gnuplot plot.gp

.PHONY: clean

clean:
	rm -f *.x *.pdf
