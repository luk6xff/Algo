//https://www.hackerrank.com/challenges/ctci-making-anagrams
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

static const size_t charMapSize = 'z' - 'a' + 1;
static constexpr size_t idxConverter(char ch)
{
    return ch - 'a';
}

int numberNeeded(string a, string b) 
{

    size_t charNumToBeDeleted = 0;
    size_t charMapA[charMapSize];
    memset(charMapA, 0, charMapSize*sizeof(size_t));
    size_t charMapB[charMapSize];
    memset(charMapB, 0, charMapSize*sizeof(size_t));
    for(const auto& c: a)
    {
        charMapA[idxConverter(c)]++;    
    }
    for(const auto& c: b)
    {
        charMapB[idxConverter(c)]++;    
    }
    for(size_t i = 0; i < charMapSize; ++i)
    {
        //cout << charMapA[i] <<"  "<< charMapB[i] << endl;
        charNumToBeDeleted += std::abs(int(charMapA[i] - charMapB[i]));        
    }
    return charNumToBeDeleted;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << numberNeeded(a, b) << endl;
    return 0;
}
