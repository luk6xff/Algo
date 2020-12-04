//https://www.hackerrank.com/challenges/ctci-balanced-brackets
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

bool is_balanced(const string& expression) {
    std::stack<char> st;
    
    if(expression.length()== 0 || expression.length() ==1)
        return false;
    
    for(auto it = expression.begin(); it != expression.end(); ++it)
    {
        if(*it == '(' || *it == '{' || *it == '[')
        {
            st.push(*it);
        }
        else if(st.empty())
        {
            return false;
        }
        else if(*it == ')')
        {
            if(st.top() != '(')
            {
                return false;    
            }
            st.pop();
        }
        else if(*it == '}')
        {
            if(st.top() != '{')
            {
                return false;    
            }
            st.pop();
        }
        else if(*it == ']')
        {
            if(st.top() != '[')
            {
                return false;    
            }
            st.pop();
        }
        else
        {
            return false;
        }
    }
    
    return st.empty() == true;
  
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

