//Day 4: Security Through Obscurity
//http://adventofcode.com/2016/day/4


//////////////////////////////1
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <regex>
#include <utility>
#include <algorithm>    // std::sort

bool checkIfRealRoom(const std::string& data, int& sum)
{
    std::map<char, int> nameCharMap;
    std::vector<std::pair<char, int>> sortVec;
    std::string name;
    std::string id = "0";
    std::string checkSum;
    //retrieve all params
    std::regex reName ("([a-z]+*[-])*");
    std::regex reID ("(\\-)(\\d{3})");
    std::regex reCheckSum ("(\\[)([a-z]+)(\\])$");
    std::smatch m;
    if (std::regex_search(data, m, reName))
    {
        name = m[0];
        //std::cout<<name<<std::endl;
    }
    if (std::regex_search(data, m, reID))
    {
        id = m[2];
    }
    //increment sum
    int idNum;
    std::istringstream iStrId(id);
    iStrId>>idNum;
    sum = idNum;
    
    if (std::regex_search(data, m, reCheckSum))
    {
        checkSum = m[2];
    }
    for(const auto& letter: name)
    {
        if(letter != '-')
        {
            nameCharMap[letter]++;
        }
    }
    //sort all the data
    for(auto it = nameCharMap.begin(); it != nameCharMap.end(); ++it)
    {
        sortVec.push_back(*it);       
    }
    //by key
    std::sort(sortVec.begin(), sortVec.end(), 
            [=](const std::pair<char,int>& a, const std::pair<char,int>& b)
            {
             return (a.first < b.first);   
            });

    //by value
    std::stable_sort(sortVec.begin(), sortVec.end(), 
            [=](const std::pair<char,int>& a, const std::pair<char,int>& b)
            {
             return (a.second > b.second);   
            });

    std::string mostCommons;
    int count =5;
    for(const auto& val: sortVec)
    {
        mostCommons.push_back(val.first);
        count--;
        if(count == 0)
            break;
    }
    //check if checkSum contains the mostCommons
    if(mostCommons == checkSum)
    {
        //std::cout<<"here:  "<<mostCommons<<std::endl;
        return true;    
    }
    return false;

   
}

int main() {
    int sum = 0;
	std::string line;
    std::string name;
    std::string checkSum;
	while(getline(std::cin, line))
	{
        int tmpSum;
        if(checkIfRealRoom(line, tmpSum))
        {
            sum+=tmpSum;    
        }
	}
   	std::cout<<sum<<"\n";
	return 0;
}







//////////////////////////////2
#include <iostream>
#include <string>
#include <sstream>
#include <regex>


class NameDecrypter
{
private:
    int m_shift;

public:
    NameDecrypter(int shift):m_shift(shift)
    {
        
    }
        
    char operator( )(char c)
    {
        char shiftedChar;
        if (isspace(c) || c == '-')
        {
            return ' ';
        }
        else
        {
            const std::string letters( "abcdefghijklmnopqrstuvwxyz" );
            size_t pos = letters.find(tolower(c));
            shiftedChar = letters[(pos + m_shift)%letters.length()];
        }
        return shiftedChar;
    }
};

//returns sector ID
int encryptName(const std::string& data)
{
    std::string name;
    std::string id = "0";
    std::string checkSum;
    //retrieve all params
    std::regex reName ("([a-z]+*[-])*");
    std::regex reID ("(\\-)(\\d{3})");
    std::regex reCheckSum ("(\\[)([a-z]+)(\\])$");
    std::smatch m;
    if (std::regex_search(data, m, reName))
    {
        name = m[0];
        //std::cout<<name<<std::endl;
    }
    if (std::regex_search(data, m, reID))
    {
        id = m[2];
    }
    //increment sum
    int idNum;
    std::istringstream iStrId(id);
    iStrId>>idNum;
    
    if (std::regex_search(data, m, reCheckSum))
    {
        checkSum = m[2];
    }
    std::transform(name.begin(), name.end(), name.begin(), NameDecrypter(idNum));
    //std::cout<<"NAME: "<<name<<std::endl;
    if(name.find("northpole") != std::string::npos)
    {
        return idNum;    
    }
    return -1;  
}

int main() {
    int northPoleID = 0;
	std::string line;
    std::string name;
    std::string checkSum;
	while(getline(std::cin, line))
	{
	    northPoleID = encryptName(line);
        if(northPoleID != -1)
        {
            std::cout<<northPoleID<<"\n";   
        }
	}
   	
	return 0;
}
