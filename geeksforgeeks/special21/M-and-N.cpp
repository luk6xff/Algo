// https://practice.geeksforgeeks.org/contest-problem/m-and-n5047

#include <bits/stdc++.h>
using namespace std;

// ver 1
void solution(int M, int N)
{
    string m_n = to_string(M+N);
    string n = to_string(N);
    if (n.size() == m_n.size())
    {
        cout << N;
    }
    else
    {
        cout << m_n;
    }
    cout << '\n';
}


// ver 2
int countdigit(long long int no)
{
    int count=0;
    while (no!=0)
    {
        count++;
        no /= 10;
    }
    return count;
}

int solution2(int M, int N)
{
    int m_n = M + N;

    if (countdigit(N) == countdigit(m_n))
        return N;
    else
        return m_n;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, M, N;
    cin >> T;
    while (T--)
    {
        cin >> M >> N;
        solution(M, N);
    }

    return 0;
}