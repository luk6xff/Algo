//Day 3: Squares With Three Sides
//http://adventofcode.com/2016/day/3

//////////////////////////////1
//1
#include <iostream>
#include <string>
#include <sstream>

bool isTriangle(int a, int b, int c)
{
    if((a+b <= c) || (a+c <= b) || (b+c <= a))
        return false;
    return true;
}

int main() {
    int numOfTriangles = 0;
    int a, b, c;
	std::string line;
	while(getline(std::cin, line))
	{
        std::istringstream iStr(line);
        iStr>>a>>b>>c;
        numOfTriangles += isTriangle(a, b, c);
	}
   	std::cout<<numOfTriangles<<"\n";
	return 0;
}






//////////////////////////////2
#include <iostream>
#include <string>
#include <sstream>

bool isTriangle(int a, int b, int c)
{
    if((a+b <= c) || (a+c <= b) || (b+c <= a))
        return false;
    return true;
}

int main() {
    int numOfTriangles = 0;
    int lineCounter = 1;
    std::string points[3];
    int a0, b0, c0, a1, b1, c1, a2, b2, c2;
	std::string line;
	while(getline(std::cin, line))
	{
	    points[(lineCounter -1) % 3] = line;
	    if(!(lineCounter % 3))
	    {
            std::istringstream iStrA(points[0]);
            std::istringstream iStrB(points[1]);
            std::istringstream iStrC(points[2]);
            iStrA>>a0>>a1>>a2;
            iStrB>>b0>>b1>>b2;
            iStrC>>c0>>c1>>c2;
            numOfTriangles += isTriangle(a0, b0, c0);
            numOfTriangles += isTriangle(a1, b1, c1);
            numOfTriangles += isTriangle(a2, b2, c2);
	    }
	    lineCounter++;
	}
   	std::cout<<numOfTriangles<<"\n";
	return 0;
}