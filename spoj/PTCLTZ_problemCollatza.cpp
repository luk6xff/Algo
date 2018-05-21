//Problem Collatza
//Kod zadania: PTCLTZ


#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int i;
	int datatoProced;
	vector<int> testData;

	cin >> i;

	if (i <= 0) return 0;

	while (i--){
		cin >> datatoProced;
		testData.push_back(datatoProced);

		if (testData.back()<1 || testData.back()>10000) return 0;
	}

	for (vector<int>::iterator it = testData.begin(); it != testData.end(); it++)
	{
		int n = 0;
		int num = *it;
		while (1){
			if (!(num % 2)){
				if (num == 1){
					cout << n << "\n";
					break;
				}
				else{
					num = num / 2;
					n++;
				}
			}
			else{
				if (num == 1){
					cout << n << "\n";
					break;
				}
				else{
					num = (3 * num) + 1;
					n++;
				}
			}
		}
	}

	return 0;
}
