//Day 1: 
//http://adventofcode.com/2016/day/1
//1
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;

enum Direction
{
	E,
	W,
	N,
	S
};

int main() {
	long long x = 0; 
	long long y = 0;
	long val;
	char direction;
	long stepsAway = 0;
	Direction lastDirection = N;
	std::string line;
	getline(std::cin, line);
	std::istringstream split(line);
	std::vector<std::string> tokens;
   	for (std::string each; std::getline(split, each, ','); tokens.push_back(each));
   	for( auto& token: tokens)
   	{

   	   	if(token[0] == ' ')
   	   	{
   	   		direction = token[1];
   	   		token.erase(token.begin(), token.begin()+2);
   	   	}
   	   	else
   	   	{
   	   		direction = token[0];
   	   		token.erase(token.begin(), token.begin()+1);
   	   	}
   	   	   	   	
   	   	std::istringstream isstr(token);
   	   	isstr >> val;
   	   	
   	   	if(lastDirection == N)
   	   	{
  		   	if(direction =='R')
	   	   	{
	   	   		x+=val;
	   	   		lastDirection = E;
	   	   	}
	   	   	else //'L'
	   	   	{
	   	   		x-=val;
	   	   		lastDirection = W;	   	   		
	   	   	}
   	   	}
   	   	else if(lastDirection == S)
   	   	{
  		   	if(direction =='R')
	   	   	{
	   	   		x-=val;
	   	   		lastDirection = W;	
	   	   	}
	   	   	else //'L'
	   	   	{
	   	   		x+=val;
	   	   		lastDirection = E;
	   	   	}
   	   	}
   	   	else if(lastDirection == W)
   	   	{
  		   	if(direction =='R')
	   	   	{
	   	   		y+=val;
	   	   		lastDirection = N;
	   	   	}
	   	   	else //'L'
	   	   	{
	   	   		y-=val;	
	   	   		lastDirection = S; 		
	   	   	}   	   		
   	   	}
   	   	else  //E
   	   	{
  		   	if(direction =='R')
	   	   	{
	   	   		y-=val;	
	   	   		lastDirection = S; 		
	   	   	}
	   	   	else //'L'
	   	   	{
	   	   		y+=val;
	   	   		lastDirection = N;
	   	   	}  	
   	   	}
   	}
	stepsAway = abs(x)+abs(y);
	std::cout<<stepsAway<<"\n";
	return 0;
}

//2
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <limits>
using namespace std;

//types
typedef std::pair<int,int> Coords;

enum Direction
{
	E,
	W,
	N,
	S
};
//funcs
static std::set<Coords> coords;

bool addAndCheckIfCoordExist(int x, int y)
{
    //std::cout<<"CORD: "<<x<<" "<<y<<std::endl;
   	if(coords.find(Coords(x,y)) != coords.end() )
   	{
   		return true;
   	}
   	coords.insert(Coords(x,y));
   	return false;
}
static const std::map<Direction, Coords> DirectMap= {
    {E, {1,0} },
    {W, {-1,0}},
    {N, {0,1} },
    {S, {0,-1}}
};

int main() {
	int x = 0; 
	int y = 0;
	long val;
	char direction;
	long stepsAway = 0;
	Direction lastDirection = N;
	
	//read input and separate it into tokens
	std::vector<std::string> tokens;
	std::string data;
	getline(std::cin, data);
	std::string delimeter = ", ";
	size_t pos;
	do
	{
	    pos = data.find(delimeter);
		tokens.push_back(data.substr(0, pos));
		data.erase(0, pos+delimeter.length());
	}while(pos != std::string::npos);
	
   	addAndCheckIfCoordExist(x, y);

   	for( auto& token: tokens)
   	{
  		direction = token[0];
  		token.erase(token.begin(), token.begin()+1);

   	   	std::istringstream isstr(token);
   	   	isstr >> val;
   	   	
   	   	if(lastDirection == N)
   	   	{
  		   	if(direction =='R')
	   	   	{
	   	   		lastDirection = E;
	   	   	}
	   	   	else //'L'
	   	   	{
	   	   		lastDirection = W;	   	   		
	   	   	}
   	   	}
   	   	else if(lastDirection == S)
   	   	{
  		   	if(direction =='R')
	   	   	{
	   	   		lastDirection = W;	
	   	   	}
	   	   	else //'L'
	   	   	{
	   	   		lastDirection = E;
	   	   	}
   	   	}
   	   	else if(lastDirection == W)
   	   	{
  		   	if(direction =='R')
	   	   	{
	   	   		lastDirection = N;
	   	   	}
	   	   	else //'L'
	   	   	{
	   	   		lastDirection = S; 		
	   	   	}   	   		
   	   	}
   	   	else  //E
   	   	{
  		   	if(direction =='R')
	   	   	{
	   	   		lastDirection = S; 		
	   	   	}
	   	   	else //'L'
	   	   	{
	   	   		lastDirection = N;
	   	   	}  	
   	   	}
  	   	for(int i = 1; i<=val; i++)
  		{
  		    x+=DirectMap.at(lastDirection).first;
  		    y+=DirectMap.at(lastDirection).second;
  		    if(addAndCheckIfCoordExist(x, y))
  		    {
  		    	stepsAway = abs(x)+abs(y);
  		    	std::cout<<stepsAway<<"\n";
  		    	return 0;
  		    }
  		}
   	}
	std::cout<<0<<"\n";
	return 0;
}