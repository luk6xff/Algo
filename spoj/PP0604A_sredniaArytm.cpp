//1102. Średnia arytmetyczna
//Kod zadania: PP0604A
#include <iostream>
#include <cmath>
using namespace std;

int main()

{
    double srednia_arytm=0;
    double min=0;
    int min_index=0;
    int t=0; // liczba testow
    int x=0; // liczba danych

        cin>>t;   // wczytuje liczbe testow
    if(t<=0||t>100) return 0;
    int *tab_testow=new int [t];  // alokuje pamiec na tablice testow -> tu te¿ bede zwracal wyniki

    for(int i=0; i<t; i++ )
    {
        cin>>x;
        if(x<=0||x>100)return 0;
        int *tab_danych= new int [x];
        srednia_arytm=0;
        for(int j=0; j<x; j++)
        {
            cin>> tab_danych[j]; // wczytuje posczególne liczby dla kazdego testu

            if(tab_danych[j]<0||tab_danych[j]>100)return 0;
            srednia_arytm +=tab_danych[j]; // w tej petli wyliczam sumuje wszystkie liczby z tablicy
            
        }
        srednia_arytm/=x;             //  tutaj wyliczam srednia

        min_index=0;
        min=fabs(srednia_arytm-tab_danych[0]);   // przyjmuje se pierwszy element jako minimum
        for(int k=0; k<x; k++)         // w tej petli sprawdzam która wartosc z tablicy jest najblizej sredniej i ta wpisuje to tab_testow
        {

            if((fabs(srednia_arytm-tab_danych[k]))<min) // fabs zwraca double
            {
                min=fabs(srednia_arytm-tab_danych[k]);
                min_index=k;
            }
        }
        tab_testow[i]=tab_danych[min_index]; // wypisuje wyniki w tablicę
        delete[] tab_danych; // tutaj usuwam tab_danych
    }
   
    for(int i=0; i<t; i++)
    {
        cout<<tab_testow[i]<<"\n";
    }

    delete[] tab_testow;
    return 0;
}



