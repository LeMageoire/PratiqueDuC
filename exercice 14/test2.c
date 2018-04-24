#include <stdio.h>
//------------------------------------------------------------------------------
/*
 * t1 est un tableau de 10 pointeurs pointant chacun sur un int constant
 * 
 */
const int * t1[10];
/* raisonnement inverse :
 * 1) t est un tableau de 10 pointeurs sur const int 
 * 
 */

/* test 1: */
int* const  p ;
/*
 * p est un pointeur (const) sur un entier
 */ 
 
/* 2) t est un tableau de 10 pointeurs constants pointant chacun sur un int
 * 
 * Règle Tableau : t[10] est un pointeur constant sur un int
 * 
 * int* const t[10] 
 */
int* const t[10];

//------------------------------------------------------------------------------
/* 3) p est un pointeur sur une fonction prenant en paramètre un pointeur sur une fonction (prenant en paramètre un double et livrant un double) et renvoyant un pointeur sur int
 * 
 *  int*(*p)(double(*p2)(double));
 */ 
int*(*p1)(double(*p2)(double));
/* Raisonnement inverse
 * 
 * affirmation initiale : (*p1)(double(*p2)(double)) est un pointeur sur un entier
 * Règle fonction : (*p1) est une fonction prenant un (double(*p2)(double)) et qui renvoit un pointeur sur un entier 
 * Règle parenthèse : *p1 est [...]
 * Règle pointeur   : p1 est un pointeur sur une fonction prenant (un pointeur de fonction qui prend un double en paramètre et retourne un double) et renvoie un pointeur sur un entier 
 * 
 */
//------------------------------------------------------------------------------ 
//------------------------------------------------------------------------------ 
/* 4) p est un pointeur constant sur un tableau de 10 pointeurs sur double 
 *
 *  (*const p) est un tableau de 10 pointeurs sur double
 *  (*const p)[10] est pointeur sur double
 *  double*(*const p)[10]  
 */
double*(*const p4)[10]; //compile !
/*
 * Raisonnement inverse : 
 * 1) affirmation initiale : (*const p4)[10] est un pointeur sur un double 
 * 2) Règle Tableau        : (*const p4) est un tableau de 10 pointeur sur double 
 * 3) Règle parenthèse     : *const p4 est [...]
 * 4) Règle pointeur       :  p4 est un pointeur [constant] sur un tableau de 10 pointeur sur double 
 */
//------------------------------------------------------------------------------ 
/* compléments Exercice 5: Tableau de pointeurs de fonctions (issus de :https://fr.wikiversity.org/wiki/C_pointeurs/Tableau_de_pointeurs_de_fonctions)
 * 
 * double (*TrigF[6])(double x) = {cos,sin,tan,atan,asin,acos};
 * exemple d'un appel : cos(.5) == TrigF[0](.5)
 * 
 * Raisonnement inverse
 * 1) règle pointeur : TrigF[6] est un pointeur sur une fonction qui prend un double en paramètre et qui renvoie un double 
 * 2) règle tableau  : TrigF est un tableau de de 6 pointeurs sur une fonction qui prend un double en paramètre et qui renvoie un double  
 */

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/* 5) t4 est un tableau de 10 pointeurs pointant chacun sur une fonction prenant un double comme paramètre et renvoyant un pointeur sur char
 *
 * t[10] est un pointeur sur une fonction prenant un double comme paramètre et renvoyant un pointeur sur char 
 *  char*(*t)[10](double)
 * 
 */
  char*(*t4[10])(double);
/*
 * Raisonnement inverse :
 * 
 * 1) affirmation générale : t4[10] est un (*fonction) qui prend un double 
 *    en paramètre et qui retourne un pointeur sur char
 * 2) règle t4 est un tableau de 10 pointeur sur fonction qui prend un double 
 *    en paramètre et qui retourne un pointeur sur char 
 * 
 * 
 */
//------------------------------------------------------------------------------  
//------------------------------------------------------------------------------
/* 6) f est une fonction prenant en paramètre un pointeur constant 
 *    sur char et renvoyant un pointeur constant 
 *    contenant l’adresse d’un pointeur sur char
 *
 *  Rappel : 
 *  char*(const)* p : 
 *  1) affirmation générale : **p est un char 
 *  2) règle pointeur :*p est un pointeur sur un char 
 *  3) règle pointeur : p est un pointeur sur un pointeur de char 
 *  
 *  char* const p : p est un pointeur [constant] sur un char   
 *  char* const char* f(char* const p)
 * 
 */
  char* const * f6(char* const p6);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/* 6) f est une fonction prenant en paramètre un pointeur constant 
 *    sur char et renvoyant un pointeur constant 
 *    contenant l’adresse d’un pointeur sur char
 *
 *  Rappel : 
 *  char*(const)* p : 
 *  1) affirmation générale : **p est un char 
 *  2) règle pointeur :*p est un pointeur sur un char 
 *  3) règle pointeur : p est un pointeur sur un pointeur de char 
 *  
 *  char* const p : p est un pointeur [constant] sur un char   
 *  char* const char* f(char* const p)
 * 
 */
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/* 7) f est une fonction sans paramètre renvoyant un pointeur 
 *    sur un tableau de 10 pointeurs constants sur char
 *
 *  char* const (*p)[10] : p est un pointeur sur un tableau de 10 pointeurs constants sur char  
 *  char* const (*p)[10]f7(void) NON!
 *  
 *  int (*p)[10] : p est un pointeur de tableau de 10 entier 
 *  
 * (f7)(void) renvoie un pointeur sur un tableau de 10 poointeurs constants sur char  
 * 
 */
// char* const (*p7)[10]; // OK


char texte[10] = "0123456789";
char* const  (*p7)[10] = &texte;

char* const (*f7(void))[10]; // Compile mais est-ce que je veux ?


/* 
 * Raisonnement Inverse  :
 * 1) règle fonction     : f(void) qui retourne  (*p)[10] qui est un char*const ;
 * 2) règle tableau      : (*p) est un tableau de 10 char * const ;
 * 3) règle parenthèse   : *p [...];
 * 4) règle pointeur     : f(void) qui retourne p qui est un tableau de 10 char * const;  
 */
        
int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
