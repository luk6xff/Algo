//KC015
//1941. Porównywanie dużych liczb

#include <stdio.h>

int main(void) {
	
	char num1[1001];
	char num2[1001];
	char sign[5];
	
	int res,len1,len2;
	while(scanf("%s %s %s" , num1,sign,num2)!=EOF){
		
		len1=strlen(num1);
		len2=strlen(num2);
		if(len1==len2){
			res= strcmp(num1,num2);
		}
		else{
		 res = len1-len2;
		 
		}
		
		switch(sign[0]){
		
		case '=':
		      res= !res;
		break;
		
		case '<':
		     res =res<=0?1:0;
		break;
		
		case '>':
		     res =res>=0?1:0;
		break;
		
		case '!':
		     res=res!=0?1:0;
		break;
			
			
		}
	//printf("%s %s %s\n" , num1,sign,num2);	
	printf("%d\n" , res);	
	}
	
	
	
	
	
	return 0;
}
