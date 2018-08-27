//1////////////////////////////////////////////////////////////////
#include <stdio.h>

char *c[] = {"GeksQuiz", "MCQ", "TEST", "QUIZ"};
char **cp[] = {c+3, c+2, c+1, c};
char ***cpp = cp;

int main()
{
    printf("%s ", **++cpp);     //1st statement
    printf("%s ", *--*++cpp+3);  //2nd statement
    printf("%s ", *cpp[-2]+3);    //3rd statement
    printf("%s ", cpp[-1][-1]+1);  //4th statement

    return 0;
}

//OUTPUT : TEST sQuiz Z CQ
/////////////////////////////////////////////////////////////////////////////


//2////////////////////////////////////////////////////////////////
#include <stdio.h>
int main()
{
    int a[][3] = {1, 2, 3, 4, 5, 6};
    int (*ptr)[3] = a;
    printf("%d %d ", (*ptr)[1], (*ptr)[2]);
    ++ptr;
    printf("%d %d\n", (*ptr)[1], (*ptr)[2]);
    return 0;
}

//OUTPUT : 2 3 5 6
/////////////////////////////////////////////////////////////////////////////


//3////////////////////////////////////////////////////////////////
#include <stdio.h>
 
int main(void)
{
    int i;
    int *ptr = (int *) malloc(5 * sizeof(int));
 
    for (i=0; i<5; i++)
        *(ptr + i) = i;
 
    printf("%d ", *ptr++);
    printf("%d ", (*ptr)++);
    printf("%d ", *ptr);
    printf("%d ", *++ptr);
    printf("%d ", ++*ptr);
}

//OUTPUT : 0 1 2 2 3
/////////////////////////////////////////////////////////////////////////////



//4////////////////////////////////////////////////////////////////
int f(int x, int *py, int **ppz)
{
  int y, z;
  **ppz += 1; 
   z  = **ppz;
  *py += 2;
   y = *py;
   x += 3;
   return x + y + z;
}
  
void main()
{
   int c, *b, **a;
   c = 4;
   b = &c;
   a = &b; 
   printf( "%d", f(c,b,a));
   getchar();
}

//OUTPUT : 19
/////////////////////////////////////////////////////////////////////////////

//5////////////////////////////////////////////////////////////////
int main()
{ 
   unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6}, 
                           {7, 8, 9}, {10, 11, 12}};
   printf("%u, %u, %u", x+3, *(x+3), *(x+2)+3);
}

//OUTPUT : 2036, 2036, 2036

/*
x = 2000

Since x is considered as a pointer to an 
array of 3 integers and an integer takes 4
bytes, value of x + 3 = 2000 + 3*3*4 = 2036

The expression, *(x + 3) also prints same 
address as x is 2D array.


The expression *(x + 2) + 3 = 2000 + 2*3*4 + 3*4
                            = 2036
*/
/////////////////////////////////////////////////////////////////////////////



//6////////////////////////////////////////////////////////////////
# include <stdio.h>
int main( )
{
  static int a[] = {10, 20, 30, 40, 50};
  static int *p[] = {a, a+3, a+4, a+1, a+2};
  int **ptr = p;
  ptr++;
  printf("%d%d", ptr-p, **ptr);
  return 0;
}
//OUTPUT : 140
/////////////////////////////////////////////////////////////////////////////



/////7////////////////////////////////////////////////////////
