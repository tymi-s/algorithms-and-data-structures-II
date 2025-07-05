#include <iostream>
#include <string>
using namespace std;

int* najdlzszy_prefix_safix(char wzrorzec[], int x)
{

	int* PS = new int[x];

	for (int i = 0; i < x; i++)
	{
		PS[i] = 0;
	}

	int j = 0; int i = 1;

	while (i < x)
	{
		if (wzrorzec[i] == wzrorzec[j])
		{
			j ++;
			PS[i] = j;
			i ++;

		}
		else if (j != 0)
		{
			
			j = PS[j - 1];// do najwiêkszego prefiksa bêd¹cego sufixem

		}
		else
		{
			PS[i] = 0;
			i ++;
		}
	}

	return PS;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void KMP(char tekst[], char wzorzec[], int prefix_safix[], int x)
{
	int j = 0; // przechodzi przez wzorzec
	int i = 0; // przechodzi przez tekst

	int tekst_len = sizeof(tekst)/sizeof(tekst[0]);

	while (i < tekst_len)
	{
		if (tekst[i] == wzorzec[j])
		{
			i++;
			j++;

			
			if (j == x) // gdy znaleziono wzorzec :D , x to dlugosc wzorca
			{
				cout << "\nZNALENIONO WZORZEC I ZACZYNA SIE ON NA POZYCJI NUMER: " << i - j << endl;
				return;
			}
		}
		else
		{
			if (j != 0)
			{
				j = prefix_safix[j - 1];
			}
			else
			{
				i++;
			}
		}
	}

	cout << "\nNIE ZNALEZIONO WZORCA :(\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	char tekst[] = { 'b','a','c','b','a','b','a','b','a','a','b','a','b' };
	char wzorzec[] = { 'a','b','a','b','a','b','a','b','c','a' };
	


	int x = sizeof(wzorzec)/sizeof(wzorzec[0]);

	int* prefix_safix = najdlzszy_prefix_safix(wzorzec,x);


	for (int i = 0; i < x; i++)
	{
		cout << prefix_safix[i] << " ";
	}

	KMP(tekst, wzorzec, prefix_safix,x);

	delete[] prefix_safix;

	return 0;	
}