#arquivo Makefile
aGame: main.o Tcreature.o mix.o fight.o user.o
	gcc main.o user.o Tcreature.o mix.o fight.o -o aGame
 
main.o: main.c Tcreature.h mix.h fight.h
	gcc -c main.c
 
Tcreature.o: Tcreature.c Tcreature.h 
	gcc -c Tcreature.c

mix.o: mix.c mix.h 
	gcc -c mix.c

fight.o: fight.c fight.h mix.h Tcreature.h
	gcc -c fight.c

user.o: user.c user.h
	gcc -c user.c
 
clean:  
	rm *.o	
 
install:
	mv aGame ../