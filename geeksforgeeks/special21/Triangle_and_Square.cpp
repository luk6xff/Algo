// https://practice.geeksforgeeks.org/contest-problem/triangle-and-square

#include <bits/stdc++.h>
using namespace std;

// ver 1
void solution(int b)
{
    // count num of squares
    int n = (b-2)/2;
    int num_squares = n;
    while (n--)
    {
        num_squares += n;
    }
    cout << num_squares << '\n';
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, B;
    cin >> T;
    while (T--)
    {
        cin >> B;
        solution(B);
    }

    return 0;
}