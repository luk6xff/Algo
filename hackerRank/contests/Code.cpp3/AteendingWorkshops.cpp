//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
typedef  struct Workshop_t
{
  int startingTime; 
  int durationTime; 
  int endingTime ;      
}Workshop;

typedef struct Available_Workshops_t
{
	 Available_Workshops_t(int n)
	{
		N=n;
		workshops= new Workshop[N];
	}
    int N;
    Workshop *workshops;
} Available_Workshops;

Available_Workshops* initialize(int start_time[], int duration[], int N)
{
  Available_Workshops *avWorkshops = new  Available_Workshops(N);
  for(int i=0; i<N;i++)
  {
      avWorkshops->workshops[i].startingTime =start_time[i];
      avWorkshops->workshops[i].durationTime=duration[i];
      avWorkshops->workshops[i].endingTime=avWorkshops->workshops[i].startingTime+avWorkshops->workshops[i].durationTime;
  }
    
  return avWorkshops;  
}
int CalculateMaxWorkshops(Available_Workshops*ptr)
{
    if(ptr==NULL)
           return 0;
    vector<pair<int,int>> data; 
    for(int i=0;i<ptr->N;i++)
        data.push_back(make_pair(ptr->workshops[i].startingTime,ptr->workshops[i].endingTime));
    
    

    std::sort(data.begin(),data.end(),[](pair<int,int> a, pair<int,int> b) {
        return b.first > a.first;   
    });
    
    int counter=1;
    int lastEndTime= data.at(0).second;
    for(int i=1;i<data.size();i++)
    {
        if(data.at(i).first==data.at(i).second){
            continue;
        }
        if(data.at(i).second<lastEndTime)
        {
            counter=counter;
            lastEndTime=data.at(i).second;
        }
        else if(data.at(i).first>=lastEndTime){
            
            counter++;  
            lastEndTime=data.at(i).second;
        }
        //cout<<data.at(i).first<<" "<<data.at(i).second<<" --- "<<lastEndTime<<endl;
    }
#if 0
   
    for(int i=0;i<data.size();i++)
    {
       cout<<data.at(i).first<<" "<<data.at(i).second<<" --- "<<lastEndTime<<endl;
    }
#endif
    return counter;
}
