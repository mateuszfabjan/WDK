#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>



void quicksort_gmp(int left, int right,mpz_t *tab,long long int *nr);

int main()
{
	mpz_t p,g,h; //zmienne odpowiadajaca int gmp
	mpz_init_set_str(p,"13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084171",10);
	mpz_init_set_str(g,"7986892892644964809678573127386712039532852301584169807905118050675340956203921770492145296166905084126855959303199420887184894225814618909287510943703491",10);
	mpz_init_set_str(h,"10353923830460929735328496784361539060361238653685678824483529175983950553832878320450730127803739628395851941601331144145295269915794187037493934868513335",10);
	unsigned long long int koniec=1048576;
	mpz_t inwersja;
	mpz_init(inwersja);
	mpz_t temporary;
	mpz_init(temporary);
	long long int *nrL=malloc(sizeof(long int)*koniec);//tablica x0
	long long int *nrP=malloc(sizeof(long int)*koniec);//tablica x1
	mpz_t *L=malloc(sizeof(mpz_t)*koniec);// g^x1*Y
  mpz_t *P=malloc(sizeof(mpz_t)*koniec);// h/g^x0
	int unsigned long long i=0;
	mpz_init(P[0]);
	mpz_set_ui(P[0],1);
	nrP[0]=0;
	for(i=1;i<koniec;i++){
	   mpz_init(P[i]);
	   mpz_powm_ui(P[i],g,i*koniec,p);
	   nrP[i]=i;
	}
	quicksort_gmp(0,koniec-1,P,nrP);
	printf("SORT 1 KONIEC\n");
	for(i=0;i<koniec;i++){
	   mpz_powm_ui(temporary,g,i,p);//analogicznie jak wyzej, temporary=g^i(mod p)
	   mpz_invert(inwersja,temporary,p);
	   mpz_mul(L[i],inwersja,h);
     mpz_mod(L[i],L[i],p);
	   nrL[i]=i;
	}
	quicksort_gmp(0,koniec-1,L,nrL);
	printf("SORT 2 KONIEC\n");
	int flag=1;
	int unsigned long long j=0;
	i=0;
	printf("Porownywanie tablic...\n"); //if (L = P) to znaleziono X
	int last;
		while(flag && i!=koniec-1){
			while(flag && j!=koniec-1){
        last=j;
				if(mpz_cmp(L[i],P[j])==0){
						printf("Szukane x to: %d\n",nrP[j]*koniec+nrL[i]);
						flag=0;
						break;
				}
				if(mpz_cmp(L[i],P[j])<0)
						break;
				j++;
			}
			j=last;
			i++;
		}
	return 0;
}


void quicksort_gmp(int left, int right,mpz_t *tab,long long int *nr){
	int i,j,pnr;
	int temp;
	mpz_t p;
	mpz_init(p);
	i=(left+right)/2;
	mpz_set(p,tab[i]);
	pnr=nr[i];
	nr[i]=nr[right];
	mpz_set(tab[i],tab[right]);
	for(j=i=left;i<right;i++){
		if(mpz_cmp(tab[i],piwot)<0){
		    temp=nr[j];
		    nr[j]=nr[i];
		    nr[i]=temp;
		    mpz_swap(tab[i],tab[j]);
		    j++;
		}
	}
	nr[right]=nr[j];
	nr[j]=pnr;
	mpz_set(tab[right],tab[j]);
	mpz_set(tab[j],p);
	if(left<j-1) quicksort_gmp(left,j-1,tab,nr);
	if(right>j+1) quicksort_gmp(j+1,right,tab,nr);
}
