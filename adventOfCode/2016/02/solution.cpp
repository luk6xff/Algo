//Day 2: Bathroom Security
//http://adventofcode.com/2016/day/2

//////////////////////////////1
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <limits>
#include <tuple>

//types            //U  //D  //R  //L 
typedef std::tuple<int, int, int, int> NextNum;

static const std::map<int, NextNum> DirectTransition= {
    {1, std::make_tuple(0, 4, 2, 0)},
    {2, std::make_tuple(0, 5, 3, 1)},
    {3, std::make_tuple(0, 6, 0, 2)},
    {4, std::make_tuple(1, 7, 5, 0)},
    {5, std::make_tuple(2, 8, 6, 4)},
    {6, std::make_tuple(3, 9, 0 ,5)},
    {7, std::make_tuple(4, 0, 8, 0)},
    {8, std::make_tuple(5, 0, 9, 7)},
    {9, std::make_tuple(6, 0, 0, 8)},
};

int main() {
    int currentPos = 5;
	std::vector<int> bathromCodeNums; 
	//read input and separate it into tokens
	std::string directions;
	while(getline(std::cin, directions))
	{
        int pos;
       	for( const auto& d: directions) 
       	{
            if(d == 'U')
            {
                pos = std::get<0>(DirectTransition.at(currentPos));        
            }
            else if(d == 'D')
            {
                pos = std::get<1>(DirectTransition.at(currentPos));      
            }
            else if(d == 'R')
            {
                pos = std::get<2>(DirectTransition.at(currentPos));            
            }
            else if(d == 'L')
            {
                pos = std::get<3>(DirectTransition.at(currentPos));             
            }
            
            if(pos != 0)
            {
                currentPos = pos;   
            }
       	}
        bathromCodeNums.push_back(currentPos);    
	}
   	for(const auto& code: bathromCodeNums)
   	{
	    std::cout<<code;
   	}
   	std::cout<<"\n";
	return 0;
}

//////////////////////////////2
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <limits>
#include <tuple>
using namespace std;

//types            //U  //D  //R  //L 
typedef std::tuple<char, char, char, char> NextNum;

static const std::map<int, NextNum> DirectTransition= {
    {'1', std::make_tuple('0', '3', '0', '0')},
    {'2', std::make_tuple('0', '6', '3', '0')},
    {'3', std::make_tuple('1', '7', '4', '2')},
    {'4', std::make_tuple('0', '8', '0', '3')},
    {'5', std::make_tuple('0', '0', '6', '0')},
    {'6', std::make_tuple('2', 'A', '7', '5')},
    {'7', std::make_tuple('3', 'B', '8', '6')},
    {'8', std::make_tuple('4', 'C', '9', '7')},
    {'9', std::make_tuple('0', '0', '0', '8')},
    {'A', std::make_tuple('6', '0', 'B', '0')},
    {'B', std::make_tuple('7', 'D', 'C', 'A')},
    {'C', std::make_tuple('8', '0', '0', 'B')},
    {'D', std::make_tuple('B', '0', '0', '0')},
};

int main() {
    char currentPos = '5';
	std::vector<char> bathromCodeNums; 
	//read input and separate it into tokens
	std::string directions;
	while(getline(std::cin, directions))
	{
        char pos;
       	for( const auto& d: directions) 
       	{
            if(d == 'U')
            {
                pos = std::get<0>(DirectTransition.at(currentPos));        
            }
            else if(d == 'D')
            {
                pos = std::get<1>(DirectTransition.at(currentPos));      
            }
            else if(d == 'R')
            {
                pos = std::get<2>(DirectTransition.at(currentPos));            
            }
            else if(d == 'L')
            {
                pos = std::get<3>(DirectTransition.at(currentPos));             
            }
            
            if(pos != '0')
            {
                currentPos = pos;   
            }
       	}
        bathromCodeNums.push_back(currentPos);    
	}
   	for(const auto& code: bathromCodeNums)
   	{
	    std::cout<<code;
   	}
   	std::cout<<"\n";
	return 0;
}