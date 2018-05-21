/*
http://www.geeksforgeeks.org/find-memory-conflicts-among-multiple-threads/
Find memory conflicts among multiple threads
Consider a RAM organized in blocks. There are multiple processes running on the system. Every application gets below information.

(Thread T, Memory Block M, time t, R/W) which essentially tells that the thread T was using memory block M at time t and operation could be read or write.

Memory conflict is defined as –
– Multiple read operations at the same location are not cause of conflict.
– One write operation between x+5 to x-5 to location M, will be cause of conflict for a thread accessing location M at time x where x is some time in standard unit of time measurement.
– Example – If thread T1 accessed memory location M at time x+1 and if a thread T2 accesses location M before time x+6, then T1 and T2 are candidate of conflict given one of them does write operation.

You are given with the list of threads accessing memory locations, you have to find all conflicts.


Example–

Input:
  (1, 512, 1, R)
  (2, 432, 2, W)
  (3, 512, 3, R)
  (4, 932, 4, R)
  (5, 512, 5, W)
  (6, 932, 6, R)
  (7, 835, 7, R)
  (8, 432, 8, R)

Output:
Thread 1 & 3 conflict with thread 5
All other operations are safe.
*/


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;
class Thread{
	
	public:
	int nrOfThread;
	int memoryBlock;
	int time;
	char privilege;
	
	bool operator<(const Thread& thread2){
		if(this->memoryBlock==thread2.memoryBlock){
			return this->time < thread2.time;
		}
		else{
			return this->memoryBlock<thread2.memoryBlock;	
		}
	}
	
};

static bool compareThreads(const Thread& thread1, const Thread& thread2){
	
	if(thread1.memoryBlock==thread2.memoryBlock){
		
		return thread1.time < thread2.time;
	}
	
	else 
	
	return thread1.memoryBlock<thread2.memoryBlock;
	
	
}

static void doAlgorithm(vector<Thread>& threads){

	sort(threads.begin(),threads.end(),compareThreads);
	
	
	
	for(auto it =threads.begin()+1;it!=threads.end();it++){
		
		if(it->memoryBlock==(it-1)->memoryBlock){
			auto it2= it-1;
			
			while(it2!=threads.begin()&&it2->memoryBlock==it->memoryBlock){
			
				if(!(it->privilege=='R' && (it2)->privilege=='R')){
					if(abs((it->time-(it2)->time))<=5){
						cout<<"CONFLICT BETWEEN THREAD: "<<(it2)->nrOfThread<<" AND THREAD: "<<it->nrOfThread<<endl;
					}
				}
				it2--;
			}

		}
		
	}
}


int main(void) {


vector<Thread> threads = { {1, 512, 1, 'R'}, {2, 432, 2, 'W'},
                     {3, 512, 3, 'R'}, {4, 932, 4, 'R'},
                     {5, 512, 5, 'W'}, {6, 932, 6, 'R'},
                     {7, 835, 7, 'R'}, {8, 432, 8, 'R'}
                   };
 
 /*
 for(int n=0; n<(sizeof(arr)/sizeof(arr[0]));n++ ){
 	threads.push_back(arr[n]);
 	
 }
 
 */
    doAlgorithm(threads);
   
	return 0;
}



//https://ideone.com/H7MbhZ
