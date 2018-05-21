//c++ implementation of  my own memcpy()
#include<iostream>
#include<string>
 
template<typename T>class SmartPointer{

public:
    
SmartPointer(T* p=NULL):ptr(p),refCount(new int(1)){
 std::cout<<"CONSTRUCTOR invoked\n";
}


~SmartPointer(){
    std::cout<<"DESTRUCTOR invoked\n";
    decrementRefCount();
    

}

//copy constructor copies the fields and increment the reference count
SmartPointer(const SmartPointer<T>& other): ptr(other.ptr),refCount(other.refCount){

    this->incrementRefCount();
    std::cout<<"COPY CONSTRUCTOR invoked\n";
}

SmartPointer<T>& operator=(const SmartPointer<T>&obj){

    if(this->ptr!= obj.ptr){

        decrementRefCount();
        ptr=obj.ptr;
        refCount= obj.refCount;
        //incrementRefCount();
        std::cout<<"OPERATOR = invoked, refCount="<<*this->refCount<<"\n";
    }

    return *this;
}

    T& operator *(){return *ptr;}
    T* operator ->(){return ptr;}
    T* getPtr(){return ptr;}

 
    
private:
    
    inline void incrementRefCount(){
        (*refCount)++;
    }
    
    
    inline void decrementRefCount(){
        (*refCount)--;
        
        if(*refCount<=0){
        	std::cout<<"DECREMENT deleting, refCount="<<*this->refCount<<"\n";
            delete ptr;
            delete refCount;
    
        }   
    }
    T* ptr;
    int *refCount;
    
    
};
 

int main()
{
    int a= 5;
  SmartPointer<int> spInteger = SmartPointer<int>(new int(1));
  SmartPointer<int> spInteger2 = SmartPointer<int>(new int(2));
  std::cout<<*spInteger<<std::endl;
  spInteger=spInteger2;
  std::cout<<*spInteger<<std::endl;
  SmartPointer<int> spInteger3(spInteger);
   return 0;
}