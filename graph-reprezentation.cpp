#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
/////////////////////////////////////////////// LISTA S¥SIEDZTWA GRAFU ///////////////////////////////////////////////////////
struct lista {
	lista* nastepnik;
	int	doo;
	int dlugosc;
};


void dodaj_do_listy(lista *& tablica, int d, int l)
{
	
	
		lista* tmp = new lista;
		tmp->nastepnik = tablica;
		tmp->doo = d;
		tmp->dlugosc = l;

		tablica = tmp;
		

	
	
}

void wypisz_tablica(lista** tab, int rozmiar) {

	for ( int i =0 ; i <rozmiar; i++)
	{
		cout << "[" << i+1 << "]" << "->";
		lista* tmp = tab[i];
		while (tmp != nullptr)
		{
			cout << tmp->doo +1<< "/" << tmp->dlugosc<<"->";
			tmp = tmp->nastepnik;

		}
		cout << "nullptr" << endl;
	}

}
///////////////////////////////////////////// MACIE¯ S¥SIEDZTWA ////////////////////////////////////////////////////////////////////////////////////////
void wypisujaca_graf(int**  graf,int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			cout << setw(4) << graf[i][j]<<"   "; // wyrównanie do 4 znaków
		}
		cout << "\n";
	}

}


///////////////////////////////////////////////////////////// LISTA KRAWÊDZI//////////////////////////////////////////////////////

struct lista_krawedzi
{
	int from;
	int to;
	int dlugosc;
	lista_krawedzi* nastepnik;
};

void tworzenie_listy_krawedzi(lista** tab,int rozmiar,lista_krawedzi*& listak )
{
	

	for (int i =0; i < rozmiar;i++)
	{
		lista* tmp = tab[i];

		while (tmp != nullptr)
		{
			lista_krawedzi* nowa = new lista_krawedzi;
			nowa->from = i +1;
			nowa->to = tmp->doo +1;
			nowa->dlugosc = tmp->dlugosc;
			nowa->nastepnik = listak;

			listak = nowa;

			tmp = tmp->nastepnik;
		}
	}
}

void tworzenie_listy_krawedzi_z_macierzy_sasiedztwa(int** macierz, int rozmiar,lista_krawedzi*& list)
{
	cout << "\n\n";
	
	for (int i=0; i <rozmiar;i++)
	{
		for (int j=0; j<rozmiar;j++)
		{
			if (macierz[i][j] != 0)
			{
				lista_krawedzi* tmp = new lista_krawedzi;
				tmp->from = i+ 1;
				tmp->to = j + 1;
				tmp->dlugosc = macierz[i][j];
				tmp->nastepnik = list;
				list = tmp;
			}
		}
	}
}

void lista_sasiedztwa_z_listy_krawedzi(lista** listaS, lista_krawedzi* listaK)
{
	while (listaK != nullptr)
	{
		lista* tmp = new lista;
		tmp->doo = listaK->to -1;
		tmp->dlugosc = listaK->dlugosc;
		tmp->nastepnik = listaS[listaK->from-1];
		listaS[listaK->from-1] = tmp;

		listaK = listaK->nastepnik;
	}

}

void wypisz_liste_krawedzi(lista_krawedzi*& listak)
{
	cout << "\n\n\nLISTA KRAWEDZI: ";
	lista_krawedzi* tmp = listak;
	while (tmp!= nullptr)
	{
		cout << tmp->from << "/" << tmp->to << "/" << tmp->dlugosc << "->->";

		tmp = tmp->nastepnik;
	}
	cout << "\n\n";
}
int main()
{

	///////////////////////////////////////////// MACIE¯ S¥SIEDZTWA ////////////////////////////////////////////////////////////////////////////////////////
	fstream odczyt;
	int rozmiar;


	odczyt.open("graf0.txt");
	

	odczyt >> rozmiar;

	int ** graf = new int*[rozmiar];

	for (int i = 0; i <rozmiar; i++)// tworzenie tablicy dwuwymiarowej z jednowymiarowej
	{ 
		graf[i] = new int[rozmiar];
	}

	for (int i =0; i <rozmiar ; i++)
	{
		for (int j =0;j<rozmiar;j++)
		{
			odczyt >> graf[i][j];
		}

	}
	odczyt.close();

	wypisujaca_graf(graf, rozmiar);
	
	


	////////////////////// LISTA S¥SIEDZTWA GRAFU/////////////////////////////////////////////////////
	


	lista** tab_ze_wskaznikiem_na_liste = new lista* [rozmiar];

	for (int i =0; i <rozmiar;i++) ///////// pusta lista wskaŸników
	{
		tab_ze_wskaznikiem_na_liste[i] = nullptr;
	}

	for (int i =0; i<rozmiar;i++)
	{
		for (int j=0;j<rozmiar ; j++)
		{
			if (graf[i][j] != 0)
			{
				dodaj_do_listy(tab_ze_wskaznikiem_na_liste[i], j, graf[i][j]);
			}
		}
	}
	cout << endl << endl;
	wypisz_tablica(tab_ze_wskaznikiem_na_liste, rozmiar);

	

	lista_krawedzi* list = nullptr;
	tworzenie_listy_krawedzi(tab_ze_wskaznikiem_na_liste, rozmiar, list);
	cout << "\n\nLISTA KRAWEDZI Z LISTY SASIEDZTWA:";
	wypisz_liste_krawedzi(list);


	lista_krawedzi* lk = nullptr;
	tworzenie_listy_krawedzi_z_macierzy_sasiedztwa(graf,rozmiar,lk);
	cout << "\nLISTA KRAWEDZI Z MACIERZY SASIEDZTWA:";
	wypisz_liste_krawedzi(lk);

	lista** listaS = new lista * [rozmiar]; // to bedzie lista sasiedztwa stworzona z listy krawedzi
	for (int i=0; i <rozmiar;i++)
	{
		listaS[i] = nullptr;
	}

	cout << "\nLISTA SASIEDZTWA Z LISTY KRAWEDZI:\n";
	lista_sasiedztwa_z_listy_krawedzi(listaS, lk);
	wypisz_tablica(listaS, rozmiar);

	return 0;
}