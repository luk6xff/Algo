//https://www.hackerrank.com/challenges/ctci-recursive-staircase
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



static int countNumOfWays(const int maxSum)
{
    static std::unordered_map<int, int> cacheMap{{0,1}};
    int numOfWays = 0;
    auto cachedNumOfWays = cacheMap.find(maxSum);
  
    if(maxSum < 0)
    {
        return 0;
    } 
    if(cachedNumOfWays != cacheMap.end())
    {
        return cachedNumOfWays->second;
    }
    else
    {
        numOfWays+= countNumOfWays(maxSum - 1);
        numOfWays+= countNumOfWays(maxSum - 2);
        numOfWays+= countNumOfWays(maxSum - 3);
    }
    cacheMap.insert({maxSum, numOfWays});
    return numOfWays;
}


int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int sum = 0;
        int n;
        cin >> n;
        cout<<countNumOfWays(n)<<endl;
    }
    return 0;
}
