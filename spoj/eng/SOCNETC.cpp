//SOCNETC - Social Network Community
 
//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <iterator>     // std::istream_iterator
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>
#include <numeric>
#include <chrono>
#include <list>
 
using namespace std;

 
typedef struct {
	int id;
	vector<int>* ptrToCommunity;
}User_t;


static void printCommunityForGivenUser(int userId, User_t* buf, int bufSize){
	if(userId>bufSize){
		std::cout<<"Such user does not exist"<<std::endl;
		return;
	}
	std::cout<<"UserId:"<<userId<<" community: ";
	
	if((buf[userId].ptrToCommunity)==nullptr)
	{
		std::cout<<userId<<"->";
	}
	else
	{
		for(auto val:*(buf[userId].ptrToCommunity))
		{
			std::cout<<val<<"->";
		}
	}
	std::cout<<std::endl;
}


 
int main() {
	int n,m,q;
	scanf("%d %d",&n,&m);
	scanf("%d",&q);
	User_t users[n+1];
	for (int i =1; i<n+1;i++){
		users[i].id=i;
		users[i].ptrToCommunity=nullptr;
	}
	while(q--){
		int x,y;
		char option;
		scanf(" %c %d %d",&option,&x,&y);
		if(option=='S'){
			if(users[x].ptrToCommunity==nullptr)
			{
				cout<<"1"<<endl;
			}
			else
			{
				std::cout<<users[x].ptrToCommunity->size()<<endl;	
			}
		}
		else if(option=='A'){
			if(users[x].ptrToCommunity==nullptr&&users[y].ptrToCommunity==nullptr)
			{
				users[x].ptrToCommunity=users[y].ptrToCommunity= new vector<int>{x,y};
			}
			else if(users[x].ptrToCommunity!=nullptr&&users[y].ptrToCommunity!=nullptr)
			{
				if(users[y].ptrToCommunity->size()+users[x].ptrToCommunity->size()<=m)
				{
					/*
					users[y].ptrToCommunity->insert(std::end(*users[y].ptrToCommunity),std::begin(*users[x].ptrToCommunity),std::end(*users[x].ptrToCommunity));
					delete users[x].ptrToCommunity;
					for(auto i:*(users[y].ptrToCommunity))
					{
						users[i].ptrToCommunity=users[y].ptrToCommunity;
					}
					*/
					for(auto i:*(users[x].ptrToCommunity))
					{
						users[i].ptrToCommunity=users[y].ptrToCommunity;
						users[y].ptrToCommunity->push_back(i);
					}
				}
			}
			else if(users[x].ptrToCommunity==nullptr)
			{
				if(users[y].ptrToCommunity->size()<m)
				{
					users[y].ptrToCommunity->push_back(x);
					users[x].ptrToCommunity=users[y].ptrToCommunity;
				}
			}
			else if(users[y].ptrToCommunity==nullptr)
			{
				if(users[x].ptrToCommunity->size()<m)
				{
					users[x].ptrToCommunity->push_back(y);
					users[y].ptrToCommunity=users[x].ptrToCommunity;
				}
			}
		}
		else if(option=='E'){
			if(users[x].ptrToCommunity==users[y].ptrToCommunity&&(users[x].ptrToCommunity!=nullptr&&users[y].ptrToCommunity!=nullptr))
			{
				std::cout<<"Yes"<<endl;
			}
			else
			{
				std::cout<<"No"<<endl;
			}
		}
		else
			break;
 
	}
	//printCommunityForGivenUser(1, users, n);
	//printCommunityForGivenUser(2, users, n);
	//printCommunityForGivenUser(3, users, n);
	//printCommunityForGivenUser(4, users, n);
	return 0;
}
















#if 0   // FOR THIS GETTING TLE
	while(q--){
		string str;
		std::getline(std::cin, str);
    	stringstream ss(str); // insert the string into stream
		string bufStr;
		vector<string> tokens;
		while(ss>>bufStr){
			tokens.push_back(bufStr);
		}
		if(tokens.at(0)=="S"){
			if(users[std::stoi (tokens[1],nullptr,0)].ptrToCommunity==nullptr)
			{
				cout<<"1"<<endl;
			}
			else
			{
				std::cout<<users[std::stoi (tokens[1],nullptr,0)].ptrToCommunity->size()<<endl;	
			}
		}
		else if(tokens.at(0)=="A"){
			int x=std::stoi (tokens[1],nullptr,0);
			int y=std::stoi (tokens[2],nullptr,0);
			if(users[x].ptrToCommunity==nullptr&&users[y].ptrToCommunity==nullptr)
			{
				users[x].ptrToCommunity=users[y].ptrToCommunity= new vector<int>{x,y};
			}
			else if(users[x].ptrToCommunity!=nullptr&&users[y].ptrToCommunity!=nullptr)
			{
				if(users[y].ptrToCommunity->size()+users[x].ptrToCommunity->size()<=m)
				{
					/*
					users[y].ptrToCommunity->insert(std::end(*users[y].ptrToCommunity),std::begin(*users[x].ptrToCommunity),std::end(*users[x].ptrToCommunity));
					delete users[x].ptrToCommunity;
					for(auto i:*(users[y].ptrToCommunity))
					{
						users[i].ptrToCommunity=users[y].ptrToCommunity;
					}
					*/
					for(auto i:*(users[x].ptrToCommunity))
					{
						users[i].ptrToCommunity=users[y].ptrToCommunity;
						users[y].ptrToCommunity->push_back(i);
					}
				}
			}
			else if(users[x].ptrToCommunity==nullptr)
			{
				if(users[y].ptrToCommunity->size()<m)
				{
					users[y].ptrToCommunity->push_back(x);
					users[x].ptrToCommunity=users[y].ptrToCommunity;
				}
			}
			else if(users[y].ptrToCommunity==nullptr)
			{
				if(users[x].ptrToCommunity->size()<m)
				{
					users[x].ptrToCommunity->push_back(y);
					users[y].ptrToCommunity=users[x].ptrToCommunity;
				}
			}
		}
		else if(tokens.at(0)=="E"){
			int x=std::stoi (tokens[1],nullptr,0);
			int y=std::stoi (tokens[2],nullptr,0);
			if(users[x].ptrToCommunity==users[y].ptrToCommunity&&(users[x].ptrToCommunity!=nullptr&&users[y].ptrToCommunity!=nullptr))
			{
				std::cout<<"Yes"<<endl;
			}
			else
			{
				std::cout<<"No"<<endl;
			}
		}
		else
			break;
 
	}
	#endif
 