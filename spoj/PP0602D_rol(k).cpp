//ROL(K)
//Kod zadania: PP0602D

#include <iostream>

using namespace std;

int main()
{
    int n, k;
//input
       do
        {
            cin>>n;
        }
        while(n<1||n>100);
        do
        {
            cin>>k;
        }
        while(k>100000||k<0);

/*
        LUB TAK
    cin>>n;
    if(n<1||n>100)
    {
        return 0;
    }
    cin>>k;
    if(k>100000||k<0)
    {
        return 0;
    }
*/
    int*tablica=new int[n]; // now table

    for(int i=0; i<n; i++)
    {
        cin>>tablica[i];
    }
//output

    for(int i=0; i<k; i++)
    {
        int z;
        for(int j=0 ; j<n; j++)
        {
            if(j==0)
            {
                z= tablica[j];
            }
            else
            {
                tablica[j-1]=tablica[j];
            }
        }
        tablica[n-1]=z;
    }

    for(int j=0 ; j<n; j++)
    {
        cout<<tablica[j]<<" ";

    }

    delete[] tablica;
    return 0;
}
