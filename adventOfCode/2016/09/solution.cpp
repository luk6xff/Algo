//http://adventofcode.com/2016/day/9
//Day 9: Explosives in Cyberspace

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <tuple>

using namespace std;

//part1
static void solutionPart1()
{
    string inputLine;
    int a, b;
    char c;
    istringstream is;
    int posStart;
    while(getline(cin, inputLine))
    {
        bool found = false;
        for(size_t i = 0; i < inputLine.size(); ++i)
        {
            if(found && inputLine[i] == ')')
            {
                istringstream is(inputLine.substr(posStart+1, i-posStart-1));
                is>>a>>c>>b;
                found = false;
                string toBeInserted = inputLine.substr(i+1, a);

                for(int j = 0; j<b-1; ++j)
                {
                    inputLine.insert(i+1, toBeInserted);    
                }
                inputLine.erase(posStart, i+1-posStart);
                i = a*b + posStart;
                found = false;
            }
            if(inputLine[i] == '(')
            {
                posStart = i;
                found = true;    
            }
        }
        cout<<inputLine.size()<<endl;
    }
}

//part 2
static long long decompressFile(const string& input)
{
  int pos = 0;
  long long sizeOfFile = 0; 
  for(size_t i = 0; i < input.size(); ++i)
  {
    if(input[i] == '(')
    {
        pos = i;
        int a, b;
        char c;
        while(input[i] != ')')
        {
          i++;
        }
        istringstream is(input.substr(pos+1, i-pos));
        is>>a>>c>>b;
        string tempStr = input.substr(i+1, a);
        //cout<<tempStr<<endl;
        sizeOfFile += decompressFile(tempStr) * b;
        i += a;
    }  
    else
    {
      sizeOfFile++;
    }
  }
  return sizeOfFile;
}

static void solutionPart2()
{
    string inputLine;
    while(getline(cin, inputLine))
    {
        cout<<"SIZE OF FILE: "<<decompressFile(inputLine)<<endl;
    }
}

int main() 
{
    //solutionPart1();
    solutionPart2();
}