#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;




void wypisz_macierz(int** macierz,int rozmiar)
{
	for (int i =0;i <rozmiar;i++)
	{
		for (int j=0; j<rozmiar;j++)
		{
			cout << setw(4) << macierz[i][j]<<"  ";
		}
		cout << "\n";
	}
}

int main()
{
	int rozmiar;


	fstream odczyt;


	odczyt.open("graf.txt");
	
	odczyt >> rozmiar;

	int ** graf = new int * [rozmiar];
	for (int i =0; i<rozmiar;i++)
	{
		graf[i] = new int[rozmiar];
	}

	for (int i=0;i<rozmiar;i++)
	{
		for (int j=0;j<rozmiar;j++)
		{
			odczyt>>graf[i][j];
		}
	}
	odczyt.close();

	wypisz_macierz(graf, rozmiar);

	int** tab_kolorow = new int* [rozmiar];
	int** tab_lasow = new int* [rozmiar];
	int iteraror = 1;
	return 0;
}