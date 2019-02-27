//Popa Alexandru Gabriel 314AB
#ifndef COMOARA_H
#define COMOARA_H

#define VECTOR_CERINTE 4
#define LUNGIME_NUME_FISIER 32

#define MODULATOR 2147483647
#define MULTIP 1103515245
#define INCREMENT 12345

struct date_intrare
{
	int c[VECTOR_CERINTE];
	int n;
	long long int sumaMax;
	long long int **m;
	int numarMaxIncercari;
};
typedef struct date_intrare structura_date_intrare;


/* elibereaza memoria folosita de matrice*/
void eliberareMatrice(long long int **m,int n);

/* elibereaza memoria folosita de vector*/
void eliberareSirCaractere(char *v);

/* aloca spatiu pentru o matrice*/
long long int **alocaMatrice(int n);

/* citire date din fisier*/
structura_date_intrare citesteInput(char *numeFisier);

/* aloca spatiu pentru un vector de caractere*/
char* alocaSirCaractere(int n);
/* verifica argumentele date la executie*/

void verificaArgument(int argc,char *argv[],char *numeIntrare,char *numeIesire);

/* scrie rezultatele in fisier*/
void scrieOutput(structura_date_intrare in,long long int rezultatCerinta[],char* numeIesire);

/* rezolvare C1*/
long long int rezolvareCerintaGreedy(structura_date_intrare in);

/* rezolvare C2*/
long long int rezolvareCerintaPD(structura_date_intrare in);

/* rezolvare C3*/
long long int rezolvareCerintaSimulare(structura_date_intrare in);

/* rezolvare C4*/
void back(long long int suma,long long int sumaMax,long long int **m,int i,int j);
long long int rezolvareCerintaBacktracking(structura_date_intrare in);

/* genereaza un numar "la intamplare" */
int rand();

/* rezolvare C[i] si scriere*/
void rezolvaSiScrieOutput(structura_date_intrare in,char* fisierIesire);

#endif
