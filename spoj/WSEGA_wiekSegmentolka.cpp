#include <iostream>
//ZADANIE SPOJ : WIEK SEGMENTOLKA, WSEGA
using namespace std;

int main()

{
    int z=0;
    int sum=0;
    do
    {
        cin>>z;        //wczytaj liczbe zestawów
    }

    while(z<=0);
    int *tab1 =new int[z];
    int *tab_sum =new int[z]; // alokuje pamięć na tablię sum, poszczególnych lat każdego z segmentolków
    for(int i=0; i<z; i++)        //tworze tablice o rozmiarze takim jakim jaka podana liczba zestawów
    {
        cin>>tab1[i];
        if( tab1[i]<1||tab1[i]>10000)
        {
            i=0;
            continue;
        }
        int *tab2 =new int[tab1[i]];
        for(int j=0; j<tab1[i]; j++)    //tworze tablice o wielkości takiej ile podałem segmentów
        {
            cin>>tab2[j];
            if(tab2[j]<0||tab2[j]>100000)
            {
                j=0;
                continue;
            }
            sum+=tab2[j];
        }
        tab_sum[i]=(tab1[i]-1)+sum;    //zapisuje sumy do tablicy
     //   cout<<"sum"<<((tab1[i]-1)+sum)<<"\n";
        sum=0;
        delete[] tab2;   // kasuje ,a pozniej w kolejnym obiegu tworze nowa po

    }
   for(int i=0; i<z; i++){cout<<tab_sum[i]<<"\n";}
   delete[] tab1; //kasuje 1 tablicę
   delete[]tab_sum;
    return 0;
}

