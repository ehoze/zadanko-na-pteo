#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct kolejka
{
        int liczba;
};

class zadanie
{
                vector <struct kolejka> spis;
       
        public:
                void wczytaj();
                void sasiedzi();
               	void odkonca();
               	void sortuj0();
               	void sortuj9();
			    void zapiszDoPliku(const char *);
              	void wczytajZPliku(const char *);                
};

int compvar(const void * a, const void * b)
{
	struct kolejka * samochod1=(struct kolejka*)a;
	struct kolejka * samochod2=(struct kolejka*)b;
   return (samochod1->liczba-samochod2->liczba);
 
}



void zadanie::sasiedzi()
{
	int poprzednia;
    for (vector<struct kolejka>::iterator it = spis.begin(); it != spis.end(); ++it)
		{	
		if(it != spis.begin()-1 && it != spis.end())
		{
			if(it->liczba == poprzednia - 1 || it->liczba == poprzednia + 1 || it->liczba == poprzednia)
			{
				cout<<poprzednia<<",";
				cout << it->liczba << "\n";
				
			}
			poprzednia = it->liczba;
		}
		}
}


void zadanie::wczytajZPliku(const char *nazwa)
{
        struct kolejka dane;
ifstream plik1;
plik1.open(nazwa);  
 
   if(plik1.good())  
            while(!plik1.eof())  
                 {
                plik1  >> dane.liczba;
 
                         spis.push_back(dane); 
                 }
                   plik1.close();  
               }

void zadanie::wczytaj()
{
       
	vector <int> liczby;
	ifstream plik("C:\\3PI eryk kucharski\\pteo\\zad 1\\x.txt");
	if (plik.good()) 
	{
		int liczba = 0;
		while (plik >> liczba)
		{
			liczby.push_back(liczba);
		}	
		plik.close();
		for (int ilosc = 0; ilosc < liczby.size(); ilosc++)
		{
			cout << liczby[ilosc] << " ";
		}
		cout << endl;
	}

}

void zadanie::odkonca()
{
	ifstream plik("C:\\3PI eryk kucharski\\pteo\\zad 1\\x.txt");
	string liczby;
	getline (plik,liczby);
	reverse(liczby.begin(), liczby.end());
	cout << liczby;
	cout << "\n";
}

void zadanie::sortuj0()
{
	ifstream plik("C:\\3PI eryk kucharski\\pteo\\zad 1\\x.txt");
	if (plik.good()) 
	{
		qsort(&spis[0],spis.size(), sizeof(struct kolejka), compvar);
		for (vector<struct kolejka>::iterator it = spis.begin(); it != spis.end(); ++it)
		{	
		cout << "!";
		cout << "Posortowane liczby: " << it->liczba << "\n";
		}
	}
}

void zadanie::sortuj9()
{
	ifstream plik("C:\\3PI eryk kucharski\\pteo\\zad 1\\x.txt");
	if (plik.good()) 
	{
		qsort(&spis[0],spis.size(), sizeof(struct kolejka), compvar);
		for (vector<struct kolejka>::iterator it = spis.end()-1; it != spis.begin()-1; --it)
		{	
		cout << "!";
		cout << "Posortowane liczby: " << it->liczba << "\n";
		}
	}
}

void zadanie::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct kolejka>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                plik << it->liczba << " \n";
        }
        plik.close();  
}


int main(int argc, char** argv) {
    zadanie xli;
    xli.wczytajZPliku("C:\\3PI eryk kucharski\\pteo\\zad 1\\x.txt");
	int wybor;
	cout << "Wybierz opcje\n";
	do
	{
		cout << "1. Wyswietl dane z x.txt\n2. Zapisz sasiadow o 1 w y.txt\n3. Wyswietl dane od konca\n4. Sortuj 0-9\n5. Sortuj 9-0\n0. Wyjdz\n";
		cin >> wybor;
		switch( wybor )
		{
		case 1:
    		xli.wczytaj();
		break;
   
		case 2:
    		xli.sasiedzi();
		break;
   
		case 3:
    		xli.odkonca();
		break;
   		
		case 4:
    		xli.sortuj0();
		break;
		   	
		case 5:
    		xli.sortuj9();
		break;
		   	
		   	
   		case 0:
			cout << "Do widzenia!\n";
		break;
		}
	}while(wybor != 0);
        xli.zapiszDoPliku("C:\\3PI eryk kucharski\\pteo\\zad 1\\y.txt");
        return 0;
}

