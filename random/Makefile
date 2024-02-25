all: random_pdf.pdf

random_pdf.x: random_pdf.cpp
	g++ random_pdf.cpp -o random_pdf.x

data1.txt data2.txt data5.txt: random_pdf.x
	./random_pdf.x 1 5000 3.5 0.4 2.7 4.6 50
	./random_pdf.x 2 5000 3.5 0.4 2.7 4.6 50
	./random_pdf.x 5 5000 3.5 0.4 2.7 4.6 50

random_pdf.pdf: data1.txt data2.txt data5.txt
	python3 Graphics.py
