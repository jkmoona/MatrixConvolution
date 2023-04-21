
output: mainProject.o matrixoperations.o
	gcc mainProject.c matrixoperations.c -o test

mainProject.o: mainProject.c
	gcc -c mainProject.c

matrixoperations.o: matrixoperations.c matrixoperations.h
	gcc -c matrixoperations.c

clean:
	rm *.o test