#include <stdio.h>

//
//QUICKSORT Time Complexity: O(n*n)
//Auxiliary Space: O(1)
//Divide and conquer algorithm 

//----------------VERSION 1: Last element picked as pivot----------------//


// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int l, int h){
	
	int x = arr[h]; //pivot as a last element
	int i =(l-1); //index of smaller element
	
	for(int j=l;j<=h-1;j++)
	{
		if(arr[j]<=x){
			i++;
			swap(&arr[i],&arr[j]); //swap current element with index
		}
	}
	swap(&arr[i + 1], &arr[h]);  
    return (i + 1);
}

void quickSort1(int arr[], int l, int h){
	if (l < h)
    {
        int p = partition(arr, l, h); /* Partitioning index */
        quickSort1(arr, l, p - 1);
        quickSort1(arr, p + 1, h);
    }
  
}

//----------------VERSION 2: medium element picked as pivot----------------//


static void quickSort2(int arr[], int left, int right) {
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






// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

/* Driver program to test quick sort algorithm */
int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort1(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);  
	//1 5 7 8 9 10 
	
    quickSort2(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);  
 
    return 0;
}


