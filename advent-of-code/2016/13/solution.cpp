//http://adventofcode.com/2016/day/13
//Day 13: A Maze of Twisty Little Cubicles

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

using namespace std;



static int SolutionPartNum = 2;  // 1 or 2
static int magicNum = 0;

static int parseInput()
{
    string num;
    int numVal;
    getline(cin, num);
    istringstream is(num);
    is>>numVal;
    return numVal;
}

struct Point
{
    Point(int x, int y):x(x),y(y){}
    
    bool operator <(const Point& p) const
    {
        return ((x < p.x) || (x == p.x && y < p.y));
        
    }
    int x;
    int y;
};

bool isOpenSpace(const Point& p)
{
  uint32_t sum = p.x*p.x + 3*p.x + 2*p.x*p.y + p.y + p.y*p.y + magicNum;
  if(bitset<sizeof(int)*8>(sum).count()%2)
  {
      return false;
  }
  return true;
}

bool isValid(const Point& p)
{
  if((p.x > -1) && (p.y > -1))
  {
      return true;
  }
  return false;
}
struct QueueNode
{
  Point point; 
  int distance; //distance from the source cell
};


int bfs(const Point& src, const Point& dst)
{
    int INT_INVALID = 0xFFFFFFFF;
    if(!isOpenSpace(src) || !isOpenSpace(dst))
    {
        return INT_INVALID;
    }
    
    set<Point> visited;
    queue<QueueNode> q;  
   
    q.push({src, 0}); //init node
    visited.insert(src);
    
    while(!q.empty())
    {
        Point currPoint = q.front().point;
        //std::cout<<currPoint.x<<", "<<currPoint.y<<" %%% "<<endl; 
        int currDist = q.front().distance;

if(SolutionPartNum == 2)     
        if(currDist == 50)
        {
            return  visited.size();
        }
else        
        if(currPoint.x == dst.x && currPoint.y == dst.y)
        {
            return currDist;
        }
        
        q.pop(); //dequeue the front cell, push all of its adjacen cells
        
        vector<Point> adjacentPoints = 
        {
            {currPoint.x + 1, currPoint.y},
            {currPoint.x - 1, currPoint.y},
            {currPoint.x, currPoint.y + 1},
            {currPoint.x, currPoint.y - 1}
        };
        for (const auto& p : adjacentPoints)
        {
            if( isOpenSpace(p) && isValid(p) && (visited.find(p) == visited.end()))
            {
                visited.insert(p);
                q.push({p, currDist + 1 });    
            }
        }
    }
    return INT_INVALID; 
}

static void solutionPart1()
{
    magicNum = parseInput();
    SolutionPartNum =1;
    Point p1(1,1);
    Point p2(31,39);
    cout<<"Fewest number= "<<bfs(p1, p2)<<endl;
    
}

static void solutionPart2()
{
    SolutionPartNum = 2;
    Point p1(1,1);
    Point p2(31,39);
    cout<<"Locations visited at 50= "<<bfs(p1, p2)<<endl;
}

int main() 
{
    solutionPart1();
    solutionPart2();
}