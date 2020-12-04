//https://www.hackerrank.com/challenges/ctci-comparator-sorting
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
}; 

vector<Player> comparator(vector<Player> players) 
{
   vector<Player> copy_players;
   std::copy(players.begin(), players.end(), std::back_inserter(copy_players));
   auto cmp = [](const Player& p1, const Player& p2)
   {
       return p1.score == p2.score ? p1.name.compare(p2.name) < 0 : p1.score > p2.score;
   };
   std::sort(copy_players.begin(), copy_players.end(), cmp);
   return copy_players;
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) 
    {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}