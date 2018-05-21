//1299. Stefan
//Kod zadania: FZI_STEF

#include <iostream>
#include <vector>
using namespace std;


static void doAlgorithm(vector<int>& dataset){
 
 long long  result=0;
 long long maxResult=0;
 	for(int i = 0; i<dataset.size(); i++){
        if(result > 0)
            result += dataset.at(i);
        else
            result = dataset.at(i);
        if(result > maxResult)
            maxResult = result;
    }

 	cout<<maxResult<<endl;
   
 
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int n, data;
	vector<int> dataset;
	cin>>n;
	if(n<1||n>100000) return 0;
	while(n--){
		cin>>data;
		if(data<-100000||data>100000)return 0;
	 	dataset.push_back(data);
	}
    doAlgorithm(dataset);
	return 0;
}



