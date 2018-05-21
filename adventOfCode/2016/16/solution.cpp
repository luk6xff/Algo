//http://adventofcode.com/2016/day/16
//Day 16: Dragon Checksum

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <chrono>

using namespace std;



static int SolutionPartNum = 2;  // 1 or 2

static string parseInput()
{
    string num;
    getline(cin, num);
    return num;
}

static string solutionPart1(int length)
{
    auto start = std::chrono::high_resolution_clock::now();
    string initState = "10111011111001111"; //parseinput()
    SolutionPartNum =1;
    while(initState.length() < length)
    {
        string b = initState;
        std:reverse(b.begin(), b.end());
        for(char&c : b)
        {
            if(c == '0')
            {
                c = '1';
            }
            else if(c == '1')
            {
                c = '0';
            }
        };
        initState.append("0");    
        initState.append(b);
    }
    initState = initState.substr(0, length);

    while(!(initState.length()%2))
    {
        string checkSum;
        for(unsigned int i = 0; i<initState.size(); i+=2)
        {
            if(initState[i] == initState[i+1])
            {
                checkSum.push_back('1');   
            }
            else
            {
                checkSum.push_back('0');     
            }
        }
        initState =  checkSum;
    }
    auto stop = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(stop - start).count() << "[us]" << endl;
    return initState;
}

static void solutionPart2()
{
    cout<<"Part2: "<<solutionPart1(35651584)<<endl;    
}

int main() 
{
    cout<<"Part1: "<<solutionPart1(272)<<endl;
    solutionPart2();
}