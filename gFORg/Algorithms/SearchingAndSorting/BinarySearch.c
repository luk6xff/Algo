//geeks for geeks
//Binary Search O(logn)- recursion O(1) - iterative 

#include <stdio.h>

// a recursive binary search, given array arr[l...r] is present, otherwise -1
int binarySearchRecursive(int arr[], int l, int r, int x){

    if(r>=1)
    {
        int mid = l +(r-l)/2 ; 
        // if the element is present at the middle itself    
        if(arr[mid] ==x){ return mid; }
    
        //If element is smaller than mid , then it can only be present in left subarray
        if(arr[mid] > x){ return binarySearchRecursive(arr, l, mid-1, x); } 
    
        // Else the element can only be prsent in the right subarray
        return binarySearchRecursive(arr, mid+1, r, x);    
    }
    //element is no present in array
    return -1;
}



//an iterative binary search, given array arr[l...r] is present, otherwise -1
int binarySearchIterative(int arr[], int l, int r, int x){

    
while(l<=r){
    int mid =  l+(r- l)/2;
        if(arr[mid] ==x) return mid;
        if(arr[mid]>x) r= mid-1;   // go to left subarray
        else l = mid+1;            // go to right subarray
}
return -1;
}



int main(void) {
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearchIterative(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;

}


int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearchIterative(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;
}