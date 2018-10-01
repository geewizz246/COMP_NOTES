CFLAGS= -std=c++1y -c -Wall

fraction: Main.o Fraction.o
	@printf "\033[33mCreating Fraction ADT...\n\033[0m"
	g++ Main.o Fraction.o -o fract.out
	@printf "\nRun by typing 'make run'\n"

Main.o: Main.cpp
	@printf "\033[36mCompiling Fraction ADT...\n\033[0m"
	g++ $(CFLAGS) Main.cpp

Fraction.o: Fraction.h Fraction.cpp
	g++ $(CFLAGS) Fraction.cpp

# To run program
run:
	./fract.out


# Remove non-source files
clean:
	rm -f *.out *.o
