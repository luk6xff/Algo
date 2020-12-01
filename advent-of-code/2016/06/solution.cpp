//http://adventofcode.com/2016/day/6
//Day 6: Signals and Noise

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;



int main() 
{
    
    int hashMap[256];
    memset(hashMap,0,sizeof(hashMap));
    string inputLine;
    string part1Response;
    string part2Response;
    
    getline(cin, inputLine); //first getline

    vector<string> inputContainer(inputLine.length());
    for(size_t i = 0; i < inputLine.length(); ++i)
    {
    inputContainer[i].push_back(inputLine[i]);  
    }
    
    while(getline(cin, inputLine))
    {
    for(size_t i = 0; i < inputLine.length(); ++i)
    {
      inputContainer[i].push_back(inputLine[i]);  
    }
    }
    for(const auto& str:inputContainer )
    {
      for(const auto& ch:str )
      {
        hashMap[ch]++;
      }
      char maxChar = '\0';
      char minChar = '\0';
      int maxVal = -1;
      int minVal = 256;
      for(int i = 0; i<256; ++i)
      {
          if(hashMap[i] > 0)
          {
            if(hashMap[i] > maxVal)
            {
                maxVal = hashMap[i];
                maxChar = static_cast<char>(i); 
            }
            if(hashMap[i] < minVal)
            {
                minVal = hashMap[i];
                minChar= static_cast<char>(i); 
            }
          }
      }
      part1Response.push_back(maxChar);
      part2Response.push_back(minChar);
      memset(hashMap,0,sizeof(hashMap));
    }
    cout<<part1Response<<endl<<part2Response;
}