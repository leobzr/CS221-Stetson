.PHONY: all clean

all: CaesarCipher

CaesarCipher: main.o CaesarCipher.o
	g++ main.o CaesarCipher.o -o CaesarCipher

main.o: main.cpp CaesarCipher.h
	g++ -c main.cpp

CaesarCipher.o: CaesarCipher.cpp CaesarCipher.h
	g++ -c CaesarCipher.cpp

clean:
	rm -f CaesarCipher *.o
