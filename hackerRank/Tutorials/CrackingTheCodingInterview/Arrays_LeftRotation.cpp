//https://www.hackerrank.com/challenges/ctci-array-left-rotation
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

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    int temp;
    int nrMoves = k%n;
    vector<int> ar(n);
    if(!(nrMoves))
    {
        return a;
    }

    for(int a_i = n - 1; a_i >= 0; --a_i)
    {
        int idx = a_i - nrMoves; //left side
        if(idx < 0)
        {
            idx = n + idx;
        }
        ar[idx] = a[a_i];
    } 
    return ar;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
