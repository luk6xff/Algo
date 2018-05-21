class Person {

    public:
        string name;
        int age;
        int currentId;
        virtual void getdata() =0;
        virtual void putdata()=0;
        
};


class Professor: public Person{
  
    public:
        
        static int cur_id;
        Professor(){
           Professor::cur_id++;
           Person::currentId =Professor::cur_id;
        }

        int publications;
    
        virtual void getdata()
        {
            cin>>Person::name>>Person::age>>publications;
        }
    
        virtual void putdata()
        {
            cout<<Person::name<<" "<<Person::age<<" "<<publications<<" "<<Person::currentId<<endl;
        }
    
};


class Student: public Person{
  
    public:
        
        static int cur_id;
        
        Student(){
           Student::cur_id++; 
           Person::currentId =Student::cur_id;
        }
    
        vector<int> marks;
        virtual void getdata()
        {
            cin>>Person::name>>Person::age;
            int mark;
            for(int i=0;i<6;i++){
                cin>>mark;
                marks.push_back(mark);
            }
        }
    
        virtual void putdata()
        {
            cout<<Person::name<<" "<<Person::age;
            cout<<" "<<std::accumulate(marks.begin(),marks.end(),0)<<" "<<Person::currentId<<endl;
        }
};
int Student::cur_id=0;
int Professor::cur_id=0;

