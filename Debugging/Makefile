CXXFLAGS= -g -fsanitize=leak,address,undefined

all: codigoFuente.x

codigoFuente.x: codigoFuente.cpp
#	Sanitizers:

	g++ ${CXXFLAGS} codigoFuente.cpp -o x.codigoFuente
	./codigoFuente.x

# 	Valgrind:

	g++ -g codigoFuente.cpp -o codigoFuente.x
	valgrind --tool=memcheck --track-origins=yes --leak-check=full ./codigoFuente.x

# 	Wall:

	g++ -g -Wall codigoFuente.cpp -o codigoFuente.x
	./codigoFuente.x
