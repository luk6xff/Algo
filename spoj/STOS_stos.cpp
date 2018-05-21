//Stos
//Kod zadania: STOS
#include <iostream>
#include <vector> 
using namespace std;

template <typename T> class MyStack{

public: 

	MyStack(){

		mStack = new std::vector<T>;
		counter= -1;

	}

	~MyStack(){
		delete mStack;
	}

	bool pushData(T data){

		bool status = false;
		if(counter<9){
			mStack->push_back(data); 
			counter++;
			status =true;	
		}

		return status; 
	}


	T popData(void){

		T lastElement =NULL;
		if(counter>=0){
			lastElement= (mStack->at(counter));
			mStack->pop_back();
			counter--;
		}
		return lastElement;
	}

private:
	std::vector<T>* mStack;
	int counter;
};


int main(void)
{
	MyStack<int> myStack; 	
	std::vector<int> inputData;
	char input;
	bool endOfInput= false;

	do{ 

		cin>>input;
		if(cin.eof())endOfInput=false;
		else if(input=='+' || input=='-' || input>='0'&&input<='9'){
			if(input>='0'&&input<='9'){
				if(!inputData.empty())
				{
					int i = inputData.back();
					if(i!='+') return 0;
				}
			}
			else if(input=='+'||input=='-'){
				if(!inputData.empty())
				{
					int i = inputData.back();
					if(i=='+') return 0;
				}
			}
			inputData.push_back((int)input);
			endOfInput= true;
		}
	
		else return 0;

	}while( endOfInput);

	for(std::vector<int>::iterator it = inputData.begin(); it!=inputData.end(); ++it){


		if(*it=='+'){
			if(myStack.pushData((*(++it)))){
				std::cout<<":)\n";
				//std::cout<<"---------"<<*(it);
			}

			else  std::cout<<":(\n"; 
		}

		else if(*it=='-'){
			int element=	myStack.popData();
			if(element!=NULL){
				std::cout<<static_cast<char>(element)<<"\n";

			}
			else std::cout<<":(\n";

		}



	}
	return 0;
}



