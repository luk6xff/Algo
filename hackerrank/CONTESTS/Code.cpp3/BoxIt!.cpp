class Box
{
    public:
        Box()
        {
            l=0;
            b=0;
            h=0;
            BoxesCreated++;
        }

        Box(int length, int breadth, int height)
        {
          
            l=length;
            b=breadth;
            h=height;
            BoxesCreated++;
        }
    
        Box(const Box& box)
        {
            l=box.l;
            b=box.b;
            h=box.h;
            BoxesCreated++;
        }
   
        Box& operator=(const Box &box)
        {
            if(this==&box)
                return *this;
            this->l=box.l;
            this->b=box.b;
            this->h=box.h;           
            return *this;
        }
   

        ~Box()
        {
            BoxesDestroyed++;
        }
     
        int getLength() const
        {
            return l;
        }
        
        int getBreadth () const
        {
            return b;
        }
        
        int getHeight () const
        {
            return h;
        }
        
        long long CalculateVolume() const
        {
            return 1ll*l*b*h;
        }
         // Mus be passed as a value to get right number of constructor calls ?? starnge
        friend ostream& operator<<(ostream& out, const Box/*&*/ box)
        {
            out<<box.l<<" "<<box.b<<" "<<box.h;
            return out;
        }

        bool operator<(Box &b)
        {
           if(this->l<b.l)
               return true;
           else if(this->b < b.b && this->l==b.l)
               return true;
           else if(this->h < b.h && this->b==b.b && this->l==b.l)
               return true;
           return false;
        }

    private:
        int l;
        int b;
        int h;
};

