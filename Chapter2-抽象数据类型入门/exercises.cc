// 第 2 章 抽象数据类型入门
// 编程问题

#include <iostream>
#include <string>
using namespace std;
// 2.2 节
// 1.题 以二进制格式输出一个整数
void printBinary(int num)
{
  int _i = sizeof(num);
  int __i = _i<<3;
  unsigned int mask = 1<<(__i-1);
  int i;
  cout<<num<<"=";
  for(i = __i; i > 0; i--)
    {
      if(0 != (num&mask))
	cout<<1;
      else
	cout<<0;
      mask = mask>>1;
    }
  cout<<endl;
}
// 3.题 位运算
int bitoperation(char ch, int a, int b = 0)
{
  if(ch == '&')
    return a&b;
  else if(ch == '|')
    return a|b;
  else if(ch == '^')
    return a^b;
  else if(ch =='~')
    return ~a;
  else if(ch == '<')		// 为了方便<代表<<
    return a<<b;
  else if(ch == '>')
    return a>>b;
  else
    {
      printf("error!\n");
      exit(1);
    }

}
// 4.题 整数溢出时的"环绕"形为
void outRound()
{
  int i = -1;
  for(;;i++)
    {
      if(i == (-1))
	printBinary(i);
      else if(i == 0)
	printBinary(i);
      else if(i == 1)
	printBinary(i);
      else if(i == 2147483647)
	printBinary(i);
      else if(i == -2147483648)
	printBinary(i);
    }
}
//5.题
// a*(b+c) and a*b+b*c
// (a+b)+c and a+(b+c)
// a*(1/a) and 1,a!=0
// 两边不相等的情况
bool specialCondition(double a, double b, double c)
{
  cout<<"a="<<a<<",b="<<b<<",c="<<c<<endl;
  return a * (b + c) == a * b + b * c;
}
// 练习2.3 3
enum MonthAbbrev{Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
enum Digit{ONE=1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN};// 练习2.3 10

// 2.3节
// 6.题
ostream& operator<<(ostream &os,MonthAbbrev ma)
{
  const char *ch;
  switch(ma)
    {
    case 1:
      ch = "Jan";break;
    case 2:
      ch ="Feb";break;
    case 3:
      ch = "Mar";break;
    case 4:
      ch = "Apr";break;
    case 5:
      ch = "May";break;
    case 6:
      ch ="Jun";break;
    case 7:
      ch = "Jul";break;
    case 8:
      ch = "Aug";break;
    case 9:
      ch = "Sep";break;
    case 10:
      ch ="Oct";break;
    case 11:
      ch = "Nov";break;
    case 12:
      ch = "Dec";break;
    default:
      ch="error";
    }
  os<<ch;
  return os;
}
istream& operator>>(istream &is, MonthAbbrev &ma)
{
  string str="";
  is>>str;
  if(str=="Jan")
    ma = Jan;
  else if(str == "Feb")
    ma = Feb;
  else if(str == "Mar")
    ma = Mar;
  else if(str == "Apr")
    ma = Apr;
  else if(str == "May")
    ma =May;
  else if(str == "Jun")
    ma = Jun;
  else if(str == "Jul")
    ma = Jul;
  else if(str == "Aug")
    ma = Aug;
  else if(str == "Sep")
    ma = Sep;
  else if(str == "Oct")
    ma = Oct;
  else if(str == "Nov")
    ma = Nov;
  else if(str == "Dec")
    ma = Dec;
  else
    cout<<"error"<<endl;
  return is;
}
MonthAbbrev& operator++(MonthAbbrev &ma) // 重载前置++运算符
{
  if(ma == Jan)
    ma = Feb;
  else if(ma == Feb)
    ma = Mar;
  else if(ma == Mar)
    ma = Apr;
  else if(ma == Apr)
    ma = May;
  else if(ma == May)
    ma = Jun;
  else if(ma == Jun)
    ma = Jul;
  else if(ma == Jul)
    ma = Aug;
  else if(ma == Aug)
    ma = Sep;
  else if(ma == Sep)
    ma = Oct;
  else if(ma == Oct)
    ma = Nov;
  else if(ma == Nov)
    ma = Dec;
  else
    cout<<"error"<<endl;
  return ma;
}
void testMonthAbbrev()
{
  MonthAbbrev one = Jan,twelve = Dec;
  cout<<one<<","<<twelve<<endl;
  cin>>twelve;
  cout<<"twelve = "<<twelve<<endl;
  ++twelve;
  cout<<"twelve = "<<twelve<<endl;
}
// 9.
enum Currency{PENNY=1,NICKEL=5,DIME=10,QUARTER=25,HALFDOLLAR=50,DOLLAR=100}; // 练习2.3 11
ostream& operator<<(ostream &os,Currency c)
{
  const char *ch;
  switch(c)
    {
    case 1:
      ch = "PENNY";break;
    case 5:
      ch ="NICKEL";break;
    case 10:
      ch = "DIME";break;
    case 25:
      ch = "QUARTER";break;
    case 50:
      ch = "HALFDOLLAR";break;
    case 100:
      ch ="DOLLAR";break;
    default:
      ch="error";
    }
  os<<ch;
  return os;
}
istream& operator>>(istream &is, Currency &c)
{
  string str="";
  is>>str;
  if(str=="PENNY")
    c = PENNY;
  else if(str == "NICKEL")
    c = NICKEL;
  else if(str == "DIME")
    c = DIME;
  else if(str == "QUARTER")
    c = QUARTER;
  else if(str == "HALFDOOLAR")
    c = HALFDOLLAR;
  else if(str == "DOLLAR")
    c = DOLLAR;
  else
    cout<<"error";
  return is;
}
Currency& operator++(Currency &c) // 重载前置++运算符
{
  if(c == PENNY)
    c = NICKEL;
  else if(c == NICKEL)
    c = DIME;
  else if(c == DIME)
    c = QUARTER;
  else if(c == QUARTER)
    c = HALFDOLLAR;
  else if(c == HALFDOLLAR)
    c = DOLLAR;
  else if(c == DOLLAR)
    c = PENNY;
  else
    cout<<"error"<<endl;
  return c;
}
Currency& operator--(Currency &c) // 重载前置--运算符
{
  if(c == PENNY)
    c = DOLLAR;
  else if(c == NICKEL)
    c = PENNY;
  else if(c == DIME)
    c = NICKEL;
  else if(c == QUARTER)
    c = DIME;
  else if(c == HALFDOLLAR)
    c = QUARTER;
  else if(c == DOLLAR)
    c = HALFDOLLAR;
  else
    cout<<"error"<<endl;
  return c;
}
void bill(int buy,int pay)
{
  int num,quo,mod;		// chushu beichushu shang he yushu
  cout<<"result:";
  num = pay-buy;
  quo = num/100;
  mod = num%100;
  if(quo >0)
    cout<<quo<<"DOLLAR";
  num = mod;
  quo = num/50;
  mod = num%50;
  if(quo > 0)
    cout<<quo<<"HALFDOLLAR";
  num = mod;
  quo = num/25;
  mod = num%25;
  if(quo > 0)
    cout<<quo<<"QUARTER";
  num = mod;
  quo = num/10;
  mod = num%10;
  if(quo > 0)
    cout<<quo<<"DIME";
  num = mod;
  quo = num/5;
  mod = num%5;
  if(quo > 0)
    cout<<quo<<"NICKEL";
  if(mod > 0)
    cout<<mod<<"PENNY";
  cout<<endl;
}
void testBill()
{
  int p,b;
  cout<<"buy"<<endl;
  cin>>b;
  cout<<"pay"<<endl;
  cin>>p;
  bill(b,p);
}
// 2.4
// 10.
void showVarAddr()
{
  short int _si,__si;
  int _i,__i;
  long int _li,__li;
  bool _b,__b;
  char _c,__c;
  float _f,__f;
  double _d,__d;
  long double _ld,__ld;
  cout<<"short int addr:"<<&_si<<","<<&__si<<endl;
  cout<<"int addr:"<<&_i<<","<<&__i<<endl;
  cout<<"long int addr:"<<&_li<<","<<&__li<<endl;
  cout<<"bool addr:"<<&_b<<","<<&__b<<endl;
  cout<<"char addr:"<<&_c<<","<<&__c<<endl;
  cout<<"float addr:"<<&_f<<","<<&__f<<endl;
  cout<<"double addr:"<<&_d<<","<<&__d<<endl;
  cout<<"long double addr:"<<&_ld<<","<<&__ld<<endl;
  cout<<"-------------------------------"<<endl;
  cout<<"&__si-&_si:"<<&__si-&_si<<endl;
  cout<<"&_i-&__i:"<<&_i-&__i<<endl;
  cout<<"&_li-&__li:"<<&_li-&__li<<endl;
  cout<<"&_b-&__b="<<&_b-&__b<<endl;
  cout<<"&_c-&__c="<<&_c-&__c<<endl;
  cout<<"&_f-&__f="<<&_f-&__f<<endl;
  cout<<"&_d-&__d="<<&_d-&__d<<endl;
  cout<<"&_ld-&__ld="<<&_ld-&__ld<<endl;
  cout<<"--------------------------------"<<endl;
  cout<<"sizeof(short int):"<<sizeof(short int)<<endl;
  cout<<"sizeof(int):"<<sizeof(int)<<endl;
  cout<<"sizeof(long int):"<<sizeof(long int)<<endl;
  cout<<"sizeof(bool):"<<sizeof(bool)<<endl;
  cout<<"sizeof(char):"<<sizeof(char)<<endl;
  cout<<"sizeof(float):"<<sizeof(float)<<endl;
  cout<<"sizeof(double):"<<sizeof(double)<<endl;
  cout<<"sizeof(long double):"<<sizeof(long double)<<endl;
}
// 13.ti
double add(double a,double b)
{
  return a + b;
}
double minus_(double a,double b)
{
  return a - b;
}
double multipy(double a,double b)
{
  return a * b;
}
double devide(double a,double b)
{
  return a / b;
}
double pro(double a,double b,double(*fun)(double,double))
{
  return fun(a,b);
}
void testPro()
{
  cout<<"please input char:'+'or'-'or'*'or'/'"<<endl;
  char choose;
  cin>>choose;
  double a,b;
  cout<<"please input two real number:"<<endl;
  cin>>a;
  cin>>b;
  if(choose == '+')
    cout<<"result="<<pro(a,b,add)<<endl;
  else if(choose == '-')
    cout<<"result="<<pro(a,b,minus_)<<endl;
  else if(choose == '*')
      cout<<"result="<<pro(a,b,multipy)<<endl;
    else if(choose == '/')
      cout<<"result="<<pro(a,b,devide)<<endl;
}
int main()
{
  // int a;
  //  cout<<"Input Integer:"<<endl;	
  //  cin>>a;
  //  printBinary(a);
  /*cout<<"Input perational character and operand."<<endl;
  char ch;
  int num1,num2;
  cin>>ch>>num1>>num2;
  int res = bitoperation(ch,num1,num2);
  printBinary(res);
  */
  //outRound();
  //cout<<boolalpha<<specialCondition(0.11113,0.11112,0.11111)<<endl;
  //  testMonthAbbrev();
  // testBill();
  //  showVarAddr();
  //  testPro();
  MonthAbbrev a,b,c;		// meiju jisuan jieguo wei zhengxing
  a = Jan;
  b = Feb;
  int res = a * b;
  cout<<res<<endl;
}
