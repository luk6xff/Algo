//In the following C++ program, struct variable st1 contains pointer to dynamically allocated memory. When we assign st1 to st2, str pointer of st2 also start pointing to same memory location. This kind of copying is called Shallow Copy.

# include <iostream>
# include <string.h>
 
using namespace std;
 
struct test
{
  char *str;
};
 
int main()
{
  struct test st1, st2;
 
  st1.str = new char[20];
  strcpy(st1.str, "GeeksforGeeks");
 
  st2 = st1;
 
  st1.str[0] = 'X';
  st1.str[1] = 'Y';
 
  /* Since copy was shallow, both strings are same */
  cout << "st1's str = " << st1.str << endl;
  cout << "st2's str = " << st2.str << endl;
 
  return 0;
}
//Output:
//st1’s str = XYeksforGeeks
//st2’s str = XYeksforGeeks

//Now, what about arrays? The point to note is that the array members are not shallow copied, compiler automatically 
//performs Deep Copy for array members.. In the following program, struct test contains array member str[]. 
//When we assign st1 to st2, st2 has a new copy of the array. So st2 is not changed when we change str[] of st1.

# include <iostream>
# include <string.h>
 
using namespace std;
 
struct test
{
  char str[20];
};
 
int main()
{
  struct test st1, st2;
 
  strcpy(st1.str, "GeeksforGeeks");
 
  st2 = st1;
 
  st1.str[0] = 'X';
  st1.str[1] = 'Y';
 
  /* Since copy was Deep, both arrays are different */
  cout << "st1's str = " << st1.str << endl;
  cout << "st2's str = " << st2.str << endl;
 
  return 0;
}
//Output:
//st1’s str = XYeksforGeeks
//st2’s str = GeeksforGeeks