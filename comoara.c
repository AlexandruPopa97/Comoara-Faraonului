//Popa Alexandru Gabriel 314AB
#include "comoara.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned int seed = 0;
/* valoarea de plecare pentru functia rand() */

int main(int argc,char* argv[])
{
	/* structura in care vom retine TOATE datele citite din fisier */
	structura_date_intrare input;
	int i,j;

	/* alocam spatiu pentru numele fisierelor pentru IN/OUT */
	char *numeInput = alocaSirCaractere(LUNGIME_NUME_FISIER);
	char *numeOutput = alocaSirCaractere(LUNGIME_NUME_FISIER);

	/* verificam si salvam numele fisierelor */
	verificaArgument(argc,argv,numeInput,numeOutput);
	/* citeste datele din fisierul de intrare */
	input = citesteInput(numeInput);
	/* rezolva si scrie in fisierul de iesire */
	rezolvaSiScrieOutput(input,numeOutput);

	/* eliberam memoria alocata anterior */
	eliberareSirCaractere(numeInput);
	eliberareSirCaractere(numeOutput);
	eliberareMatrice(input.m,input.n);
	return 0;
}
/**Functia eliberareMatrice
  * Primeste matricea M de dimensiune (n x n).
  */
void eliberareMatrice(long long int **m,int n)
{
	int i;
	for(i=0;i<n;i++)
		free(m[i]);
	free(m);
}
/**Functia eliberareSirCaractere
  * Primeste vectorul de caractere v.
  */
void eliberareSirCaractere(char *v)
{
	free(v);
}
/**Functia alocaMatrice
  * primeste ca parametru n = dimensiunea matricei
  * intoarce o matrice n x n (adresa pozitiei de inceput)
  */
long long int **alocaMatrice(int n)
{
	long long int **m = NULL,i;
	m = (long long int**)malloc(n*sizeof(long long int*));
	for(i=0;i<n;i++)
		m[i] = (long long int*)malloc(n*sizeof(long long int));
	return m;
}
/**Functia alocaSirCaractere
  * Primeste ca parametru n = lungimea sirului de caractere.
  *
  * Intoarce un vector de n caractere (adresa pozitiei de inceput).
  */
char* alocaSirCaractere(int n)
{
	char *v = NULL;
	v = (char*)malloc(n*sizeof(char));
	return v;
}
/**Functia citesteInput
  * Primeste numele fisierului de intrare.
  *
  * Intoarce un element de tip structura_date_intrare cu datele citite.
  */
structura_date_intrare citesteInput(char *numeFisier)
{
	structura_date_intrare in;
	int i,j;
	FILE *f;
	f = fopen(numeFisier,"rt");
	if(f == NULL)
	{
		printf("Fisierul de input nu a putut fi deschis! :( \n");
		exit(1);
	}
	for(i=0;i<4;i++)
		fscanf(f,"%d",&in.c[i]);
	fscanf(f,"%d",&in.n);
	fscanf(f,"%lli",&in.sumaMax);
	in.m = alocaMatrice(in.n);
	for(i=0;i<in.n;i++)
		for(j=0;j<in.n;j++)
			fscanf(f,"%lli",&in.m[i][j]);
	fscanf(f,"%d",&in.numarMaxIncercari);
	fclose(f);
	return in;
}

void verificaArgument(int argc,char *argv[],char *numeIntrare,char *numeIesire)
{
	if(argc == 3)
	{
		strcpy(numeIntrare,argv[1]);
		strcpy(numeIesire,argv[2]);
	}
}
/**Functia scrieOutput
  * Primeste
  *     -un element cu datele de intrare;
  *     -un vector cu rezultatele ce vor fi scrise in fisier;
  *     -numele fisierului de iesire in care vom scrie.
  */
void scrieOutput(structura_date_intrare in,long long int rezultatCerinta[],char* numeIesire)
{
	FILE *f;
	f = fopen(numeIesire,"wt");
	if(f == NULL)
	{
		printf("Fisierul de output nu a putut fi creat :( \n");
		exit(1);
	}
	fprintf(f,"%lli",rezultatCerinta[0]);
	if(in.c[1] == 1)
		fprintf(f,"\n%lli",rezultatCerinta[1]);
	if(in.c[2] == 1)
		fprintf(f,"\n%lli",rezultatCerinta[2]);
	if(in.c[3] == 1)
		fprintf(f,"\n%lli",rezultatCerinta[3]);
	fclose(f);
}
/**Functia rezolvareCerintaGreedy
  * Primeste ca parametru un element cu toate datele de intrare.
  *
  * Intoarce rezultatul pentru cerinta 1.
  */
long long int rezolvareCerintaGreedy(structura_date_intrare in)
{
	int n = in.n;
	long long int **m = in.m;
	int i,j;
	long long int suma = 0;
	i = n-1;
	j = n-1;
	suma = suma + m[i][j];
	while(i != 0 || j!= 0)
	{
		if(i == 0)
			j--;
		else if(j == 0)
			i--;
		else if(m[i][j-1] < m[i-1][j])
			j--;
		else if(m[i][j-1] >= m[i-1][j])
			i--;
		suma = suma + m[i][j];
	}
	return suma;
}
/**Functia rezolvareCerintaPD
  * Primeste ca parametru un element cu toate datele de intrare.
  *
  * Intoarce rezultatul pentru cerinta 2.
  */
long long int rezolvareCerintaPD(structura_date_intrare in)
{
	int n = in.n;
	long long int **m = in.m;
	long long int rezultatFinal = 0;
	long long int **pd;
	pd = alocaMatrice(n);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			pd[i][j] = 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(pd[i][j] == 0)
			{
				if(i == 0 && j == 0)
				{
					pd[i][j] = m[i][j];
				}
				else if(i == 0)
					pd[i][j] = m[i][j] + pd[i][j-1];
				else if(j == 0)
					pd[i][j] = m[i][j] + pd[i-1][j];
				else if(pd[i][j-1] < pd[i-1][j])
					pd[i][j] = m[i][j] + pd[i][j-1];
				else if(pd[i][j-1] >= pd[i-1][j])
					pd[i][j] = m[i][j] + pd[i-1][j];
			}
		}
	rezultatFinal = pd[n-1][n-1];
	eliberareMatrice(pd,n);
	return rezultatFinal;
}

int rand() 
{
    seed = (MULTIP * seed + INCREMENT) % MODULATOR;
    return seed;
}
/**Functia rezolvareCerintaSimulare
  * Primeste ca parametru un element cu toate datele de intrare.
  *
  * Intoarce rezultatul pentru cerinta 3.
  */
long long int rezolvareCerintaSimulare(structura_date_intrare in)
{
	int nrMaxIncercari = in.numarMaxIncercari;
	int n = in.n;
	long long int **m = in.m;
	long long int sumaMax = in.sumaMax;
	long long int suma,rezultatFinal,nrIncercari = 0;
	int i,j;

	while(nrIncercari <= nrMaxIncercari)
	{
		nrIncercari++;
		suma = 0;
		i = n-1;
		j = n-1;
		suma = suma + m[i][j];
		while(i != 0 && j != 0)
		{
			if(rand() % 2)
				i--;
			else j--;
			suma = suma + m[i][j];
		}
		if(i == 0)
			while(j != 0)
			{
				j--;
				suma = suma + m[i][j];
			}
		if(j == 0)
			while(i != 0)
			{
				i--;
				suma = suma + m[i][j];
			}
		if(suma <= sumaMax)
			break;
	}

	rezultatFinal = nrIncercari;
	if(nrIncercari >= nrMaxIncercari)
	{
		rezultatFinal = 0;
	}
	return rezultatFinal;
}
/*Functia back contorizeaza drumurile sigure gasite
*/
long long int contorC4 = 0;
void back(long long int suma,long long int sumaMax,long long int **m,int i,int j)
{
	suma = suma + m[i][j];
	if(j > 0)
		back(suma,sumaMax,m,i,j-1);
	if(i > 0)
		back(suma,sumaMax,m,i-1,j);
	if(i == 0 && j == 0)
		if(suma <= sumaMax)
			contorC4++;
}
/**Functia rezolvareCerintaBacktracking
  * Primeste ca parametru un element cu toate datele de intrare.
  * Intoarce rezultatul pentru cerinta 4.
  */
long long int rezolvareCerintaBacktracking(structura_date_intrare in)
{
	long long int **m = in.m;
	int n = in.n;
	long long int sumaMax = in.sumaMax;
	int startLinie = n-1;
	int startColoana = n-1;
	long long int suma = 0;
	back(suma,sumaMax,m,startLinie,startColoana);
	return contorC4;
}

void rezolvaSiScrieOutput(structura_date_intrare in,char* fisierIesire)
{
	long long int rezultatCerinta[VECTOR_CERINTE];
	if(in.c[0])
		rezultatCerinta[0] = rezolvareCerintaGreedy(in);
	if(in.c[1])
        rezultatCerinta[1] = rezolvareCerintaPD(in);
    if(in.c[2])
    	rezultatCerinta[2] = rezolvareCerintaSimulare(in);
    if(in.c[3]) 
        rezultatCerinta[3] = rezolvareCerintaBacktracking(in);
    scrieOutput(in,rezultatCerinta,fisierIesire);
}
