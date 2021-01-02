#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[] ){
	execvp ("echo", /* program yang dimuat - PATH dicari */
	&argv[0] ) ;
	printf ("EXEC Failed\n") ;
	/* Baris di atas akan dicetak saat terdapat kesalahan */
}