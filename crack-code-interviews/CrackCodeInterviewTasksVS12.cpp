
// CrackCodeInterviewTasks.cpp :  tasks from the book "CrackCodeInterview"
//

#include "stdafx.h"
#include "string.h"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <utility> 
// you can also use includes, for example:
#include <algorithm>


#define CURRENT_TASKS 

#ifdef CURRENT_TASKS

#define TASK1_1x
#define TASK1_2x
#define TASK1_3x
#define TASK1_4x
#define TASK1_5x
#define TASK1_6x
#define TASK1_7x
#define TASK1_8x
#define TASK2_1
#define TASK2_2x
#define TASK2_3x
#define TASK2_4x
#define TASK2_5x
#define TASK3_1x
#define TASK3_2x
#define TASK3_3x
#define TASK3_4x
#define TASK3_5x
#define TASK3_6x

#endif


using namespace std;

/*1.2 Write code to reverse a C-Style String.
(C-String means that “abcd” is represented as five characters, including the null character.)*/
void reverseCStyleString(char* stringToReverse){
	char temp;
	char *tempStr;

	//TODO!!!
	while (stringToReverse);
}

/*1.3 Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer.
NOTE: One or two additional variables are fine.An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method.*/

void removeTheDuplicateCharactersInAString(char* stringToRemoveDuplicates){
	int length = strlen(stringToRemoveDuplicates);
	if (stringToRemoveDuplicates == nullptr || length < 2) return;
	char temp;
	for (int i = 0; i < length; i++){

		temp = *(stringToRemoveDuplicates + i);

		for (int j = i + 1; j < length; j++){
			if (temp == *(stringToRemoveDuplicates + j)){
				for (int k = j; k < length; k++){
					*(stringToRemoveDuplicates + j) = *(stringToRemoveDuplicates + j + 1);

				}
				///j--;//to check again the same position
			}
		}
	}
}

/*1.4 Write a method to decide if two strings are anagrams or not. */
bool areStringAnagrams(char* string1, char* string2){
	bool retValue = false;
	if (string1 == nullptr || string2 == nullptr || (strlen(string1) != strlen(string2))) return retValue;
	int length = strlen(string1);

	char tempTab[256];

	memcpy(tempTab, string1, length);


	for (int i = 0; i < length; i++){

		for (int j = 0; j < length; j++){

			if (string2[i] == tempTab[j]){
				tempTab[j] = 0; 
				retValue = true;
				break;
			}

			retValue = false;
		}

	}

	return retValue;
}

/*1.5 Write a method to replace all spaces in a string with ‘ % 20’.*/
void replaceAllSpacesInTheString(std::string& str){

	std::string::iterator it = str.begin();
	std::string strToReplace="%20";
	//1 way - not very good 
	std::vector<int> spaces;
	for (int i=0; i<str.length(); ++i){
		if (str.at(i) == ' ')spaces.push_back(i);
	}

	for(int i=0; i<spaces.size(); ++i){
		str.insert(spaces.at(i),strToReplace);
	}

	//2
	for (; it != str.end(); ++it){
		if (*it == ' ') {str.insert(it,strToReplace.begin(),strToReplace.end());continue;}
	}

}
/*1.6 Write a method to rotate the image Matrix [N]x[N] by 90 degrees.*/

void rotateImageBy90Degrees(std::vector<std::vector<int>> & image){




}

/*1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.*/
bool setColumnAndRowOf0elementTo0(vector<vector<int>>& matrix){

	if(matrix.empty()) return false ;

	int numOfRows= matrix.size();
	int numOfColumns= matrix[0].size();
	vector<pair<int,int>> colAndRowsToZero;

	for(auto itRow= matrix.begin(); itRow!=matrix.end(); ++itRow) {

		for(auto itCol= matrix[itRow-matrix.begin()].begin(); itCol!=matrix[itRow-matrix.begin()].end(); ++itCol) {

			if(*itCol==0){

				colAndRowsToZero.push_back(make_pair(distance(matrix.begin(),itRow),distance(matrix[itRow-matrix.begin()].begin(),itCol)));
			}
		}

	}

	int numberOfPosToZero = colAndRowsToZero.size();

	if(numberOfPosToZero==0) return true;

	else {

		for(int i =0; i<numberOfPosToZero;i++){

			matrix[colAndRowsToZero.at(i).first].assign(numOfColumns,0);   //rows is "0"ed

			for(int j =0; j<numOfRows;j++){

				matrix.at(j)[colAndRowsToZero.at(i).second]=0;
			}
		}
	}
	return true;
}


/*1.8 Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, 
write code to check if s2 is a rotation of s1 using only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).*/
bool checkIfs2IsARotationOfS1(const string& s1,const string& s2){

	if(s1.empty()||s2.empty()||(s1.length()!=s2.length()))return false;
	int lengthOfString= s1.length();
	vector<char> lettersOfString(lengthOfString);

	for(int i=0;i<lengthOfString;i++)
		lettersOfString.push_back(lettersOfString.at(i));
	for(int i=0;i<lengthOfString;i++){

		for(int j=0;j<lettersOfString.size();j++){
			if(lettersOfString.at(j)==s2.at(i)){
				lettersOfString.erase(lettersOfString.begin()+i);
				break;}

		}

	}
	if(lettersOfString.empty()) return false;
	else
		return true;
}


/*2.1 Write code to remove duplicates from an unsorted linked list.
How would you solve this problem if a temporary buffer is not allowed? */

//////////////implementaton of THE simple Single Linked List///////////
/*
template<typename T> 
class SNode{
private: 

	T data;
	SNode<typename T> *next;
    friend class SingleLinkedList<T>; // provide StringLinkedList access
};

template <typename T>
class SingleLinkedList{

public:
	SingleLinkedList();
	~SingleLinkedList();
	bool empty() const;         // is list empty ?
	const T& getFront()const;   // get front element
	void addFront(const T& t);  // add to front of list
	void removeFront();         // remove front item list

private: SNode<T> * head;
};

template<typename T> SingleLinkedList<T>::SingleLinkedList():head(NULL){

};

template <typename T> bool SingleLinkedList<T>::empty() const {
	
	return head == NULL;
}

template <typename T> const T& SingleLinkedList<T>::getFront() const { 

	return head->data;
}


template <typename T> SingleLinkedList<T>::~SingleLinkedList() {

	while(!empty()){removeFront();} 
}


template <typename T> void SingleLinkedList<T>::addFront(const T& t){    
	
	SNode<T>* v = new SNode<T>;
	v->data=t;
	v->next=head;
	head=v;
}

template <typename T> void SingleLinkedList<T>:: removeFront(){

	SNode<T>* old =head;
	head=old->next;
	delete old;


}
*/
////////////////////////////////////////////////////////////////////




int _tmain(int argc, _TCHAR* argv[])
{


#ifdef TASK1_2
	//1.2_TEST 
	std::cout <<"\n\n*****************"<<"1.2_TEST"<<"****************"<< std::endl;
	char str[] = { "aaabdeed" };
	//reverseCStyleString(str);
	for (int i = 0; str[i] != NULL; i++) std::cout << str[i];
	std::cout << std::endl;
#endif 
#ifdef TASK1_3
	//1.3_TEST
	std::cout <<"\n\n*****************"<<"1.3_TEST"<<"****************"<< std::endl;
	removeTheDuplicateCharactersInAString(str);
	for (int i = 0; str[i] != NULL; i++) std::cout << str[i];
	std::cout << std::endl;
#endif
#ifdef TASK1_4
	//1.4_TEST
	std::cout <<"\n\n*****************"<<"1.4_TEST"<<"****************"<< std::endl;
	bool respond;
	char str1[] = { "bcda" };
	char str2[] = { "acbd" };
	respond = areStringAnagrams(str1, str2);
	std::cout << (respond ? "TAK" : "NIE") << std::endl;
#endif
#ifdef TASK1_5
	//1.5_TEST

	std::cout <<"\n\n*****************"<<"1.5_TEST"<<"****************"<< std::endl;
	std::string strToChangeSpaces =  "aaabbb ccc";
	replaceAllSpacesInTheString(strToChangeSpaces);
	std::string::iterator it = strToChangeSpaces.begin();
	for(;it!=strToChangeSpaces.end();it++){
		std::cout<<*it;
	}
	std::cout << '\n';
#endif	
#ifdef TASK1_6
	//1.6_TEST
	std::cout <<"\n\n*****************"<<"1.6_TEST"<<"****************"<< std::endl;
#endif

#ifdef TASK1_7
	//1.7_TEST
	std::cout <<"\n\n*****************"<<"1.7_TEST"<<"****************"<< std::endl;

	vector<vector<int>> matrix (10);
	vector<int> data;
	int tab[]= {1,1,2,3,4,5,6,7,8,9};
	for(auto it= begin(tab); it!=end(tab); ++it) data.push_back(*it);
	fill(matrix.begin(),matrix.end(),data);


	matrix[3][3]=0;


	cout<<"------BEFORE-------\n";
	for(auto itRow= matrix.begin(); itRow!=matrix.end(); ++itRow) {

		for(auto itCol= matrix[itRow-matrix.begin()].begin(); itCol!=matrix[itRow-matrix.begin()].end(); ++itCol) {

			cout<<*itCol<<" ";
		}
		cout<<"\n";
	}

	setColumnAndRowOf0elementTo0(matrix);
	cout<<"------AFTER-------\n";
	for(auto itRow= matrix.begin(); itRow!=matrix.end(); ++itRow) {

		for(auto itCol= matrix[itRow-matrix.begin()].begin(); itCol!=matrix[itRow-matrix.begin()].end(); ++itCol) {

			cout<<*itCol<<" ";
		}
		cout<<"\n";
	}
#endif
#ifdef TASK1_8
	//1.8_TEST
	std::cout <<"\n\n*****************"<<"1.8_TEST"<<"****************"<< std::endl;
	const string s1= "watterbottle";
	const string s2= "botletwatter";
	bool result=checkIfs2IsARotationOfS1(s1,s2);

	if(!result)	cout<< "S2 is NOT a rotation of S1";
	else cout<< "S2 is a rotation of S1";

#endif
#ifdef TASK2_1
	//2.1_TEST
	std::cout <<"\n\n*****************"<<"2.1_TEST"<<"****************"<< std::endl;
/*	SingleLinkedList<int> SingleList;
	for(int i =0;i<10;i++){
		cout<<SingleList.getFront();
		SingleList.addFront(i);
	}
	cout<<endl;
	cout<<SingleList.getFront();

	char a[3];
     
	char b[2]={'A','B'};

	a[0]='C';
	a[1]=b;
	*/
	int xzzz=0x70;

	int c= xzzz&0xF0;
	cout<<"CCCCCCC"<<c<<endl;
	c=c>>4;
	cout<<"CCCCCCC"<<c<<endl;

#endif
#ifdef TASK2_2
	//2.2_TEST
	std::cout <<"\n\n*****************"<<"2.2_TEST"<<"****************"<< std::endl;
#endif
#ifdef TASK2_3
	//2.3_TEST
	std::cout <<"\n\n*****************"<<"2.3_TEST"<<"****************"<< std::endl;
#endif
#ifdef TASK2_4
	//2.4_TEST
	std::cout <<"\n\n*****************"<<"2.4_TEST"<<"****************"<< std::endl;
#endif
#ifdef TASK2_5
	//2.5_TEST
	std::cout <<"\n\n*****************"<<"2.5_TEST"<<"****************"<< std::endl;
#endif
#ifdef TASK3_1
	//3.1_TEST
	std::cout <<"\n\n*****************"<<"3.1_TEST"<<"****************"<< std::endl;
#endif
#ifdef TASK3_2
	//3.2_TEST
	std::cout <<"\n\n*****************"<<"3.2_TEST"<<"****************"<< std::endl;
#endif
#ifdef TASK3_3
	//3.3_TEST
	std::cout <<"\n\n*****************"<<"3.3_TEST"<<"****************"<< std::endl;
#endif
#ifdef TASK3_4
	//3.4_TEST
	std::cout <<"\n\n*****************"<<"3.4_TEST"<<"****************"<< std::endl;
#endif
#ifdef TASK3_5
	//3.5_TEST
	std::cout <<"\n\n*****************"<<"3.5_TEST"<<"****************"<< std::endl;

#endif
#ifdef TASK3_6
	//3.6_TEST
	std::cout <<"\n\n*****************"<<"3.6_TEST"<<"****************"<< std::endl;
#endif






	while (1);
	return 0;
}


