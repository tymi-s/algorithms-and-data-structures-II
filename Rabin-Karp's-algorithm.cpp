#include <iostream>
#include <string>
using namespace std;



int haszowanie_klucza(char tab[],int x)
{
	int h=10*tab[0]+ tab[1];
	for (int i=2; i <x;i++)
	{
		h = 10 * h + tab[i];
	}
	h = h % 13;
	return h;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int haszowanie_tekstu(char tab[], int x)
{
	int h = 10 * tab[0] + tab[1];
	for (int i = 2; i < x; i++)
	{
		h = 10 * h + tab[i];
	}
	h = h % 13;
	return h;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void podejrzane_ciagi_naiwny(char tab[],char wzorzec[], int x)
{
	cout << endl;
	int g = 0;
	for (int i =0; i<x;i++)
	{
		if (tab[i] == wzorzec[i])
		{
			g++;
		}
	}
	if (g==x)
	{
		cout << "ZNALEZIONO WZORZEC!!!:\n";

		for (int i = 0; i<x;i++)
		{
			cout << tab[i] << "->";
		}
	}
	cout << "\n\n";
}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	char tekst[13] = { 'a', 'b', 'c', 'a', 'b', 'a', 'a', 'b', 'c', 'a', 'b', 'a', 'c' };
	char wzorzec[4] = {'a','b','a','a'};
	
	int hasz_klucza = haszowanie_klucza(wzorzec, 4);
	cout << hasz_klucza<<endl<<endl;

	cout << "WZORZEC:\n";
	for (int i = 0; i < sizeof(wzorzec); i++)
	{
		cout << wzorzec[i] << "->";
	}

	cout << "\nTEKST:\n";
		for (int i = 0; i < sizeof(tekst); i++)
		{
			cout << tekst[i] << "->";
		}
		cout << "\n\n\n";

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// sprawdzanie hasza tekstu i porównywanie z haszem wzorca:
	char tmp[4];
	for (int i =0; i <= (sizeof(tekst)-sizeof(wzorzec));i++)
	{
		for (int j = 0; j<sizeof(wzorzec);j++)
		{
			tmp[j] = tekst[j+i];
			cout << tmp[j]<<"->";

		}
		cout << endl;
		if (haszowanie_tekstu(tmp, sizeof(tmp)) == hasz_klucza)
		{
			podejrzane_ciagi_naiwny(tmp,wzorzec, sizeof(tmp));
		}
	}


	return 0;
}