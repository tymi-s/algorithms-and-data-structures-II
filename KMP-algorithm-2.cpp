#include <iostream>
using namespace std;

// Funkcja do obliczania najd³u¿szego prefiksu bêd¹cego sufiksem
int* najdluzszy_prefix_sufix(const char wzorzec[], int x)
{
    int* PS = new int[x];
    PS[0] = 0; // Pierwszy element zawsze 0

    int j = 0;
    for (int i = 1; i < x; i++)
    {
        if (wzorzec[i] == wzorzec[j])
        {
            j++;
            PS[i] = j;
        }
        else if (j != 0)
        {
            j = PS[j - 1];
            i--; // Pozostajemy na tym samym `i` w kolejnej iteracji
        }
        else
        {
            PS[i] = 0;
        }
    }

    return PS;
}


void KMP(const char tekst[], int tekstRozmiar, char wzorzec[], int wzorzecRozmiar)
{
    int* PS = najdluzszy_prefix_sufix(wzorzec, wzorzecRozmiar);

    for (int i=0; i <sizeof(PS);i++)
    {
        cout << PS[i] << " ";
    }

    int i = 0; // Indeks w tekœcie
    int j = 0; // Indeks we wzorcu

    while (i < tekstRozmiar)
    {
        if (tekst[i] == wzorzec[j])
        {
            i++;
            j++;
        }

        if (j == wzorzecRozmiar)
        {
            cout << "Znaleziono wzorzec na pozycji: " << i - j << endl;
            delete[] PS;
            return;
        }
        else if (i < tekstRozmiar && tekst[i] != wzorzec[j])
        {
            if (j != 0)
                j = PS[j - 1];
            else
                i++;
        }
    }

    cout << "Nie znaleziono wzorca" << endl;
    delete[] PS;
}

int main()
{
    
    char tekst[] = { 'b', 'a', 'c', 'b', 'a', 'b', 'a', 'b', 'a', 'a', 'b', 'a', 'b' };
    char wzorzec[] = { 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'c', 'a' };

    
    int tekstRozmiar = sizeof(tekst) / sizeof(tekst[0]);
    

    
    KMP(tekst, tekstRozmiar, wzorzec, sizeof(wzorzec));

    return 0;
}
