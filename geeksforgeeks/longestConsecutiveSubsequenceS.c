//http://www.geeksforgeeks.org/longest-consecutive-subsequence/

//https://ideone.com/in5Dog
/*
Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Examples:

Input: arr[] = {1, 9, 3, 10, 4, 20, 2};
Output: 4
The subsequence 1, 3, 4, 2 is the longest subsequence
of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
The subsequence 36, 35, 33, 34, 32 is the longest subsequence
of consecutive elements. 

*/
#include <bits/stdc++.h>
using namespace std;

void doAlgorithm(vector<int>& arr){
	
	int size= arr.size();
	
	if(size<1)
		return;
	unordered_set<int> hashSet;
	int retVal=0;
	for (int i = 0; i < size; i++) 
		hashSet.insert(arr[i]);   //hashing
	
	for(int i=0;i<size; i++){
		
		if(hashSet.find(arr.at(i)-1)==hashSet.end()){ //first element of consecutive subsequence
			
			int x= arr.at(i);
			
			while(hashSet.find(x)!=hashSet.end())
				x++;
			
			retVal= (retVal>(x-arr.at(i)))?retVal:(x-arr.at(i));
		}
	}
	
	std::cout<<"the longest subsequenceof consecutive elements is : "<<retVal<<endl<<endl;
	
}


int main() {
   vector<int> arr1= {1, 9, 3, 10, 4, 20, 2};
   doAlgorithm(arr1);
   
   vector<int> arr2= {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42};
   doAlgorithm(arr2);
		
   return 0;
}