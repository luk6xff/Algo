//http://adventofcode.com/2016/day/8
//Day 8: Two-Factor Authentication

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <tuple>

using namespace std;


vector<bitset<50>> lcd(6);

static void displayLcd()
{
    for(const auto& row: lcd)
    {
        cout<<row<<endl;
    }
}


vector<tuple<char, int, int>> input;

static void parseInput()
{
    string inputLine;
    int x,y;
    char command;
    while(getline(cin, inputLine))
    {
        size_t pos;
        if((pos = inputLine.find("rect")) != string::npos)
        {
            istringstream is(inputLine.substr(pos + 5, pos + 5 + 3));
            char c;
            is>>x>>c>>y;
            command = 't';

        }
        else if((pos = inputLine.find("row")) != string::npos)
        {
            istringstream is(inputLine.substr(pos + 6, pos + 6 + 4));
            string c;
            is>>x>>c>>y;
            command = 'r';
        }
        
        else if((pos = inputLine.find("column")) != string::npos)
        {
            istringstream is(inputLine.substr(pos + 9, pos + 9 + 4));
            string c;
            is>>x>>c>>y;
            command = 'c';
        }
        input.push_back(std::make_tuple(command, x, y));
    }
}

static void solutionPart1()
{
    for(auto & cmd: input)
    {
        switch(std::get<0>(cmd))
        {
            case 't':
            {
                for(int i = 0; i < std::get<2>(cmd); ++i)
                {
                    for(int j = 0; j < std::get<1>(cmd); ++j)
                        lcd[i].set(j, 1);
                }
                //displayLcd();
            }
            break;
            
            case 'r':
            {
                int rotateNum = std::get<2>(cmd) % lcd[0].size();
                int rowNum = std::get<1>(cmd);
                bitset<50> row = lcd[rowNum];
                for(int i = 0; i < row.size(); ++i)
                {
                    int prevIdx = (i < rotateNum)?(row.size() - rotateNum +i ):(i - rotateNum);
                    int prevVal = row[prevIdx];
                    lcd[rowNum].set(i, prevVal);
                }
            }
            break;

            
            case 'c':
            {
                int rotateNum = std::get<2>(cmd) % lcd.size();
                int columnNum = std::get<1>(cmd);
                int col[lcd.size()];
                for(int i = 0; i < lcd.size(); ++i)
                {
                    col[i] = lcd[i][columnNum];
                }
                for(int i = 0; i < lcd.size(); ++i)
                {
                    int prevIdx = (i < rotateNum)?(lcd.size() - rotateNum + i ):(i - rotateNum);
                    int prevVal = col[prevIdx];
                    lcd[i].set(columnNum, prevVal);
                }
            }    
            break;

        }
    }
    int pixels = 0;
    for(auto & row: lcd)
    {
        pixels+=row.count();   
    }
    cout<<"NUM OF PIXELS= "<<pixels<<endl;
    //displayLcd();
}


static void solutionPart2()
{
    vector<string> decodedDisplay;
    for(auto & row: lcd)
    {
        decodedDisplay.push_back(row.to_string());   
    }
    for(auto & row: decodedDisplay)
    {
        std::replace(row.begin(), row.end(), '0', ' ');
        std::replace(row.begin(), row.end(), '1', '#');
        for(int i = 0; i < row.size()/2; ++i)
        {
            char tmp = row.at(i);
            row[i] = row.at(row.size()-1-i);
            row[row.size()-1-i] = tmp;
        }
        cout<<row<<endl;
    }
}

int main() 
{
    
    parseInput();
    solutionPart1();
    solutionPart2();
}