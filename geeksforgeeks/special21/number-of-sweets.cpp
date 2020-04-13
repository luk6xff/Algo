// https://practice.geeksforgeeks.org/contest-problem/number-of-sweets

#include <bits/stdc++.h>
using namespace std;


vector<string>getDecision(int a , int b)
{
    vector<string> ans;
    while (a != b)
    {
        if (a > b)
        {
            a--;
            ans.push_back("eat ");
        }
        else
        {
            // even b's
            if (b%2 == 0)
            {
                if (a <= b/2)
                {
                    a *= 2;
                    ans.push_back("overflow ");
                }
                else
                {
                    a--;
                    ans.push_back("eat ");
                }
            }
            // odd b's
            else
            {
                if (a <= (b/2+1))
                {
                    a *= 2;
                    ans.push_back("overflow ");
                }
                else
                {
                    a--;
                    ans.push_back("eat ");
                }
            }
        }
    }
    return ans;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{

		int m , n;
		cin>>m>>n;
		vector<string>ans;
		ans = getDecision(m,n);
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
		cout<<endl;

	}
	return 0;
}
