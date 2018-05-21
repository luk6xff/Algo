#include <stdio.h>

//
//INSERTION SORT Time Complexity: O(n*n)
//Auxiliary Space: O(1)

// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}


void insertionSort(int arr[], int n){

    if (n<=0) return;
    
    int temp=0; // temp variable
    
    for (int i= 1;i<n; i++){
        
        if(arr[i]<arr[i-1]){
            temp = arr[i];
            int j= i-1;
            while(temp<arr[j]&&j>=0){
                
                arr[j+1]= arr[j];
                arr[j]=temp;
               	j--;
            }
        }
    }
}

/* Driver program to test insertion sort */
int main()
{
    int arr[] = {12, 11, 13, 5,6,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("INPUT: ");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("OUTPUT: ");
    printArray(arr, n);
 
    return 0;
}
//Output:

//5 6 11 12 13