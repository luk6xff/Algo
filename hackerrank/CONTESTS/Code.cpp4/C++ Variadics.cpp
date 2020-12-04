#include <iostream>
using namespace std;

#include <sstream>
#include <bitset>
#include <algorithm>

template<bool... digits> int reversed_binary_value()
{
    std::bitset<sizeof...(digits)> bits;
    int idx= 0;
    for(const bool& b:{digits...})
    {
        bits.set(idx++,b); 
    }
    //cout<<bits<<endl;
    return bits.to_ulong();
}


template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}

/*
Sample Input

2
65 1
10 0
Sample Output

0100000000000000000000000000000000000000000000000000000000000000
0000000000100000000000000000000000000000000000000000000000000000
*/