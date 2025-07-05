#include <iostream>
#include <array>
using namespace std;


void algorytm_naiwny(int tablica[],int klucz[])
{
	int i = sizeof(klucz)/4;
	int k[i];
	int s = 0;
	for (int j = 0; j<14;j++)
	{
		if (tablica[j] == klucz[j])
		{
			k[s] = tablica[j];
			s++;
		}
	}
}


int main()
{
	int tablica[14] = { 1,7,4,7,3,8,3,9,0,2,4,7,3,3 };

	int klucz1[4] = { 9,0,2,4 };
	int klucz2[3] = { 1,1,1 };
	
	

	return 0;
}