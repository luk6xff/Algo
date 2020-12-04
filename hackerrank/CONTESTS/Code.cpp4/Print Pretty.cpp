#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        //#include <cstdio> 

        cout << resetiosflags(ios::uppercase) <<setw(0x0)<< showbase <<hex<<static_cast<long>(A)<<endl;
        //printf("%#x\n",static_cast<unsigned int>(A));
                
        char prev =cout.fill('_');
        cout.setf( ios::showpos |ios::fixed| std::ios_base::right );
        cout<<setw(15)<<std::setprecision(2)<<B<<endl;
        cout.unsetf( ios::showpos |ios::fixed| std::ios_base::right);
        std::cout.fill(prev);
        cout<<setw(0xf);      
        /*
            char buf[16]={'_'};
            char buffer[15]={'\0'};
            sprintf(buffer, "%+.2f",B);
            //printf( "%s\n", buffer );
            int len= 0;
            for (int i=0;buffer[i]!='\0';len++,i++);
                
            for(int i=0;i<len;i++){
               buf[15-len+i]= buffer[i];
            } 
            buf[15]='\0';
            for(int i=0;i<15-len;i++){
               buf[i]= '_';
            } 
            printf( "%s\n", buf );
         */
        

        cout<<setiosflags(ios::uppercase);
        cout << std::fixed << std::setprecision(9)<< std::scientific<< C<<endl;
        cout.unsetf( ios::showpos |ios::fixed|ios::scientific);
        //printf("%.9E\n",C);
        }
	return 0;
}

/*
Sample Input

1  
100.345 2006.008 2331.41592653498
Sample Output

0x64             
_______+2006.01  
2.331415927E+03
*/