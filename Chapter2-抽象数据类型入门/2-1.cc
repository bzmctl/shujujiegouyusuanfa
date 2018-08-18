#include <iostream>
#include <climits>
using namespace std;

void print()
{
    int number = 2;
    for(int i =1; i <= 15; i++)
      {
	cout<<number<<endl;
	number *= 10;
      }
}

void _print()
{
  int number = INT_MAX - 3;
  cout<<"INT_MAX = "<<INT_MAX<<endl;
  for(int i = 1; i <= 7; i++)
    {
      cout<<number<<endl;
      number++;
    }
}

void _print_()
{
  int number = 2000000000;
  for(int i = 1; i <= 10; i++)
    cout<<i<<" * "<<number<<" = "<<i*number<<endl;
}
void _print__()
{
  double y = 1.0;
  for(double x = 0; x <= 5.0; x += 0.1)
    cout<<"x = "<<x<<",y ="<<x*y<<endl;
}
void _print___()
{
  float a=125.5;
  char *p=(char *)&a;
  printf("%d\n",*p);
  printf("%d\n",*(p+1));
  printf("%d\n",*(p+2));
  printf("%d\n",*(p+3));
}
int main()
{
  int a = -2;
  const char *b ="hello";
  float c = 6.625;
  double d = 123.1;
  print();
  _print();
  _print_();
  _print__();
  _print___();
  typedef float Real,SinglePrecision;
  Real e = 2.1;
  SinglePrecision f = 3.0;
}


