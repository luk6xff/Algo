//http://qa.geeksforgeeks.org/1905/c-program-to-find-the-smallest-missing-integer-value

//https://ideone.com/EMs2uT
/*
Given two arrays of integers output the smallest number in the first array not present in the second one.

Input Specification:

The first line contains the size N1 of the first array.

Next N1 lines give the contents of the first array. 

Next line contains the size N2 of the second array.

Next N2 lines give the contents of the second array.

Output Format: 

Output must be a single number which is the smallest number occurring in the first array that does not occur in the second. In case there is no such number, output NO.

Variable Constraints: The sizes of the arrays are smaller than 20.

Each array entry is an integer which fits an int data type.


//INPUT 4 3 2 4 1 7 3 5
//OUTPUT 2
*/
#include <bits/stdc++.h>
using namespace std;

static void quickSort(int arr[], int left, int right) {
      int i = left, j = right;                  
      int tmp;
      int pivot = arr[(left + right) / 2];      
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;                          
            while (arr[j] > pivot)
                  j--;                          
            if (i <= j) {            
                  tmp = arr[i];                 
                  arr[i] = arr[j];             
                  arr[j] = tmp;                 
                  i++;                          
                  j--;                          
            }
      };
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


static bool binarySearch(int n, int arr[], int arrLength){
	
	int start=0;
	int end= arrLength-1;
	
	while(start<=end){
		int mid =start+(end-start)/2;
		if(n==arr[mid])return true;
		if(n<arr[mid]){
			end=mid-1;
		}
		if(n>arr[mid]){
			start=mid+1;
		}
	}
	return false;
	
}

void doAlgorithm(int tab1[], int tab1Length, int tab2[],int tab2Length){
	
	quickSort(tab1, 0, tab1Length-1);
	quickSort(tab2, 0, tab2Length-1);
	
	for(int i =0; i<tab1Length; i++){
		if(!binarySearch(tab1[i], tab2, tab2Length)){
			printf("%d\n",tab1[i] );
			return;
		}
	}
	
	printf("NO\n");
	
}


int main() {

int length1, length2;
int *tab1;
int *tab2;
  
  try
  {
   	scanf("%d",&length1);
	if(length1<1) return 0;
	tab1= (int*)malloc(length1*sizeof(int));
	for(int i=0; i<length1;i++)
	{
		scanf("%d",&tab1[i]);
	}
	scanf("%d",&length2);
	if(length2<1) return 0;
	tab2= (int*)malloc(length2*sizeof(int));
	for(int i=0; i<length2;i++)
	{
		scanf("%d",&tab2[i]);
	}
  }	
  catch (exception& e)
  {
    printf("Standard exception: %d",e.what());
  }
    
   doAlgorithm(tab1, length1,tab2, length2);
		
   return 0;
}