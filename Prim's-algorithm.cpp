#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


struct lista {
	lista* nastepnik;
	int skad;
	int	doo;
	int dlugosc;
};


void dodaj_do_listy(lista*& tablica, int d, int l)
{


	lista* tmp = new lista;

	tmp->nastepnik = nullptr;
	tmp->doo = d;
	tmp->dlugosc = l;

	if (tablica == nullptr) {
		
		tablica = tmp;
	}
	else {


		//przejscie na koniec listy
		lista* obecny = tablica;
		while (obecny->nastepnik != nullptr) {
			obecny = obecny->nastepnik;
		}
		obecny->nastepnik = tmp;
	}



}
void dodaj_do_listy_prima(lista*& tablica, int s, int d, int l)
{


	lista* tmp = new lista;

	tmp->nastepnik = nullptr;
	tmp->skad = s;
	tmp->doo = d;
	tmp->dlugosc = l;

	if (tablica == nullptr) {

		tablica = tmp;
	}
	else {


		//przejscie na koniec listy
		lista* obecny = tablica;
		while (obecny->nastepnik != nullptr) {
			obecny = obecny->nastepnik;
		}
		obecny->nastepnik = tmp;
	}



}






void wypisujaca_graf(int **graf,int rozmiar)
{

	for (int i = 0; i < rozmiar;i++)
	{
		for (int j=0; j<rozmiar;j++)
		{
			cout << setw(4)<< graf[i][j] << "  ";
		}
		cout << "\n";
	}
}
void wypisz_tablica(lista** tab, int rozmiar) {

	for (int i = 0; i < rozmiar; i++)
	{
		cout << "[" << i + 1 << "]" << "->";
		lista* tmp = tab[i];
		while (tmp != nullptr)
		{
			cout << tmp->doo + 1 << "/" << tmp->dlugosc << "->";
			tmp = tmp->nastepnik;

		}
		cout << "nullptr" << endl;
	}

}
bool czy_same_jedynki(int* tab, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		if (tab[i] != 1)
		{
			return false;
		}
	}
	return true;
}

void wypisz_wynik(lista*& wynik)
{
	lista* tmp = wynik;
	while (tmp != nullptr)
	{
		cout << tmp->skad + 1 << "/" << tmp->doo + 1  <<"/"<< tmp->dlugosc<<"->";
		tmp = tmp->nastepnik;
	}
	cout << "nullptr\n";

}


lista* algorytm_prima(lista ** tab,int rozmiar,int start)
{

	int* tab_kolorow = new int [rozmiar];

	for (int i =0; i<rozmiar;i++)
	{
		tab_kolorow[i] = 0;
	}


	lista* wynik = nullptr;
	start--;
	tab_kolorow[start] = 1;


	while (czy_same_jedynki(tab_kolorow,rozmiar) == false)
	{
		int poprz = -1;
		int nast = -1;
		int min_l = 1000000;

		
		for (int i = 0; i < rozmiar; i++)
		{


			if (tab_kolorow[i] == 1)
			{
				lista* indeks = tab[i];


				while (indeks != nullptr)
				{
					if (tab_kolorow[indeks->doo] == 0  &&  indeks->dlugosc < min_l) // szukanie wieszcho³ka  nieodwiedzonego i najkrótszego
					{
						min_l = indeks->dlugosc;
						poprz = i;
						nast = indeks->doo;
					}
					indeks = indeks->nastepnik;	

				}
			}

		}
		if (nast != -1) // czyli jeœli znaleziono bia³y wierzcho³ek  nakrótsz¹ krawêdzi¹
		{
			dodaj_do_listy_prima(wynik,poprz, nast, min_l);
			tab_kolorow[nast] = 1;
			
		}
	}

	return wynik;
}

int main()
{

	int rozmiar;
	fstream odczyt;
	odczyt.open("graf.txt");
	odczyt >> rozmiar;

	int** graf = new int* [rozmiar];

	for (int i=0; i< rozmiar;i++)
	{
		graf[i] = new int[rozmiar];
	}
	for (int i=0 ; i < rozmiar; i ++)
	{
		for (int j=0;j<rozmiar;j++)
		{
			odczyt >> graf[i][j];
		}

	}

	odczyt.close();
	wypisujaca_graf(graf, rozmiar);




	lista** tab = new lista * [rozmiar];

	for (int i = 0; i < rozmiar; i++) ///////// pusta lista wskaŸników
	{
		tab[i] = nullptr;
	}

	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			if (graf[i][j] != 0)
			{
				dodaj_do_listy(tab[i], j, graf[i][j]);
			}
		}
	}

	cout << "\n\n";
	wypisz_tablica(tab, rozmiar);
	


	lista* prima = algorytm_prima(tab, rozmiar, 3);
	cout << "\n\n";
	wypisz_wynik(prima);
	return 0;
}