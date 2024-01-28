//
// Tomás Oliveira e Silva, AED, October 2021
//
// example of function overloading (same function name, different argument numbers and/or data types)
//

#include <iostream>

using std::cout; // make this symbol from the std namespace directly visible

void show(const int i)
{
  cout << "int: "
       << i
       << std::endl;
}

void show(const double d)
{
  cout << "double: "
       << d
       << std::endl;
}

void show(const char *s,const char *h = "string: ") // second argument with default value
{
  cout << h
       << s
       << std::endl;
}

void show(const char c)
{
  cout << "char: "
       << c
       << std::endl;
}

void show(const int *p)
{
  cout << "array: [" << p[0] << "," << p[1] << "," << p[2] << "]" << std::endl;
}

// another way, more cases
void show(const int *p, const int size)
{
  cout << "array: [";
  for(int i = 0; i < size; i++){
    cout << p[i];
    if( i != size-1){
      cout << ",";
    }
  }
  cout << "]\n";
}

int main(void)
{
  show(1.0);
  show("hello");
  show(-3);
  show("John","name: ");
  show('a');
  int a[3] = { 2,7,-1 };
  show(a);
  int b[5] = {1,2,3,4,5};
  show(b, 5);
  return 0;
}
