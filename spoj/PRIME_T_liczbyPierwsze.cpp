//Liczby pierwsze
//Kod zadania: PRIME_T
#include <iostream>

using namespace std;
bool czy_liczba_pierwsza(int liczba);
int main()
{
    int n; //liczba testów
    cin>>n;

    int *tab = new int[n];  // tworze dynamicznie tablice na wartości po wpisaniu
    for(int i=0; i<n; i++)
    {
        cin>>tab[i];
        if(tab[i]<=0||tab[i]>10000){i=0; continue;} // coby spełnic warunki zadania
    }

    for(int i=0; i<n; i++)
    {
        switch (czy_liczba_pierwsza(tab[i]))
    {
    case true:  cout<<"TAK"<<"\n"; break;
    case false: cout<<"NIE"<<"\n"; break;
    }


}


}

bool czy_liczba_pierwsza(int liczba)
{if(liczba==1){return false;} // q nie jest ani pirwsza ani zlozona
    for(uint8_t i=2; i<100; i++)
    {
        if(!(liczba%i)&&liczba!=i)  // to co w komentach mi nie potrzebne bo itak wiadomo że przez siebie sie dzieli
    {
        return false;    // jesli liczba dzieli się przez ktoras z liczb w petli ale nie przez sama siebie to znaczy że nie jest pierwsza
    }
}
return true; // jesli nie dzieli sie to zwróc true;
}
