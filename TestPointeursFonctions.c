#include <stdio.h>
#include <math.h>
int main(void)
{
	double (*pt)(double),x,y; 
	/*
	 * 1) (*pt)(double) est un double 
	 * 2) règle fonction : (*pt) est une fonction prenant un double comme argument et qui retourne un double
	 * 3) règle parenthèse : *pt est une fonction prenant un double comme argument et qui retourne un double
	 * 4) règle pointeur : pt est un pointeur sur une fonction prenant un double comme argument et qui retourne un double
	 * 
	 * END : pt est un pointeur sur une fonction prenant un double comme argument et qui retourne un double
	 * 
	 */
	/* RAPPEL : Le nom d'une fonction est un pointeur constant */
	x = M_PI/4;    		 // travail en radian !
	pt = cos ;    		 // pt contient l'adresse de la fonction cosinus ;
	y = (*pt)(x);  		 // y (double) contient la valeur de cos(45°) = 1/sqrt(2) ~ 0.707	(voir ligne 2 ci-dessus) ! les parenthèse de (*pt) sont obligatoires
	printf("%lf", y); 
	return 0;
}
