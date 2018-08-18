#include <iostream>
using namespace std;
// 练习3.2
char a[10];
double ad[10];
struct T
{
  char c[10];
};
T at[7];
int ai[26];
enum Day{SUN,MON,TUE,WED,THU,FRI,SAT,NUM_DAYS};
Day aday[NUM_DAYS];
int in;
int im = 1;
static int io;
static int ip = 1;
void sDiffArr()
{
  /*
    char a[10];
    double ad[10];
    struct T
    {
    char c[10];
    };
    T at[7];
    int ai[26];
    enum Day{SUN,MON,TUE,WED,THU,FRI,SAT,NUM_DAYS};
    Day aday[NUM_DAYS];
*/
  
  cout<<"sizeof(char) = "<<sizeof(char)<<",sizeof(a) = "<<sizeof(a)<<",a[3]'addr = "<<(void *)(a+3)<<",a[9]'addr = "<<(void *)(a+9)<<endl;
  cout<<"sizeof(double) = "<<sizeof(double)<<",sizeof(ad) = "<<sizeof(ad)<<",ad[3]'addr = "<<ad+3<<",ad[9]'addr = "<<ad+9<<endl;
  cout<<"sizeof(T) = "<<sizeof(T)<<",sizeof(at) = "<<sizeof(at)<<",at[4]'addr = "<<at+4<<",at[6]'addr = "<<at+6<<endl;
  cout<<"sizeof(int) = "<<sizeof(int)<<",sizeof(ai) = "<<sizeof(ai)<<",ai[1]'addr = "<<ai+1<<",ai[2]'addr = "<<ai+2<<endl;
  cout<<"sizeof(Day) = "<<sizeof(Day)<<",sizeof(aday) = "<<sizeof(aday)<<",aday[TUE]'addr = "<<&aday[TUE]<<",aday[SAT]'addr = "<<&aday[SAT]<<endl;
  /*
    当以上变量为局部变量是输出结果：
    sizeof(char)=1,sizeof(a)=10,a[3]'addr=0x7ffe005c4af3,a[9]'addr=0x7ffe005c4af9
    sizeof(double)=8,sizeof(ad)=80,ad[3]'addr=0x7ffe005c4a28,ad[9]'addr=0x7ffe005c4a58
    sizeof(T)=10,sizeof(at)=70,at[4]'addr=0x7ffe005c49e8,at[6]'addr=0x7ffe005c49fc
    sizeof(int)=4,sizeof(ai)=104,ai[1]'addr=0x7ffe005c4a64,ai[2]'addr=0x7ffe005c4a68
    sizeof(Day)=4,sizeof(aday)=28,aday[TUE]'addr=0x7ffe005c4ad8,aday[SAT]'addr=0x7ffe005c4ae8
    当以上变量作为全局变量输出的结果：
    sizeof(char)=1,sizeof(a)=10,a[3]'addr=0x6021a3,a[9]'addr=0x6021a9
    sizeof(double)=8,sizeof(ad)=80,ad[3]'addr=0x6021d8,ad[9]'addr=0x602208
    sizeof(T)=10,sizeof(at)=70,at[4]'addr=0x602248,at[6]'addr=0x60225c
    sizeof(int)=4,sizeof(ai)=104,ai[1]'addr=0x602284,ai[2]'addr=0x602288
    sizeof(Day)=4,sizeof(aday)=28,aday[TUE]'addr=0x6022f8,aday[SAT]'addr=0x602308
  */
  //对于以上数组，如果数组a的基地址是b，则a[i]的地址为b+i*a的数据类型所占字节数
  static int iq;
  int ir;
  cout<<"static int iq's addr = "<<&iq<<endl;
  cout<<"int ir's addr = "<<&ir<<endl;
}
// 练习3.3
void sVarMemAddr()
{
  char tc[5][5];
  double td[4][10];
  int ti[8][7];
  T tT[7][6];
  T tTE[TUE][3];
  cout<<"tc'addr = "<<tc<<", tc[4][4]'addr = "<<(void *)(&tc[4][4])<<endl;
  cout<<"td'addr = "<<td<<", td[3][9]'addr = "<<&td[3][9]<<endl;
  cout<<"ti'addr = "<<ti<<", ti[7][6]'addr = "<<&ti[7][6]<<endl;
  cout<<"tT'addr = "<<tT<<", tT[6][5]'addr = "<<&tT[6][5]<<endl;
  cout<<"tTE'addr = "<<tTE<<", tTE[MON][2]'addr = "<<&tTE[MON][2]<<endl;
  /*n  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
    cout<<(void *)(&tc[i][j])<<endl;*/
  // 按照列序存储，就是把行列的位置调换一下
  // 11.假设f是可一个定义为：
  // double f[N1][N2][N3][N4];的四维数组，通过将f看成一个具有N1个元素的一维数组，其中每个元素都是一个三维double型的N2*N3*N4数组，并且假设三维数组每个元素需要w个字节内存空间来存储，推导出f[i][j][k][l]的通用地址翻译公式。
  // i*j*k*l*w+j*k*l*w+k*l*w+l*w=w(l-1)(i*j*k+j*k+k+1)
}
// 练习 3.4
void ex1to6()
{
  // 1.输入数组的大小
  int n;
  cout<<"Please input one Integer:"<<endl;
  cin>>n;
  double * doublePtr = new double[n];
  // 2.为数组每个元素赋值
  for(int i = 0; i < n; i++)
    cin>>(*(doublePtr+i));
  // 3.计算数组的平均值
  double sum = 0;
  for(int i = 0; i < n; i++)
    sum+=*(doublePtr+i);
  cout<<"avg = "<<(sum / n)<<endl;
  // 4.释放分配的内存
  delete []doublePtr;
  // 5.如果doublePtr的值为1000,double类型占8个字节，画出每个元素的内存映像图来显示匿名数组前几个元素的地址
  // 6.查看下列程序的输出
  double dubValues[] = {1.1,2.2,3.3,4.4,5.5};
  double * dubPtr = dubValues;
  for(int i = 0; i < 5; i++)
    cout<<sizeof(dubPtr + i)<<" "<<sizeof(*(dubPtr + i))<<" "<<*(dubPtr + i)<<endl;
}
void testlianxi()
{
  sDiffArr();
  cout<<"int in'addr = "<<&in<<endl;
  cout<<"int im = 1'addr="<<&im<<endl;
  cout<<"static int io'addr = "<<&io<<endl;
  cout<<"static int ip'addr = 1"<<&ip<<endl;
  cout<<"--------------------------------------------------------------"<<endl;
  sVarMemAddr();
  bool flag[4][4][4][4];
  cout<<flag<<endl;
  cout<<&flag[0][0][0][1]<<endl;
  cout<<&flag[3][3][3][3]<<endl;
  cout<<4*(5*5*5+5*5+5+1)<<endl;
  cout<<"--------------------------------------------------------------"<<endl;
  ex1to6();
}
// 编程问题
// 3.2节
// 1.
// 读取分数的一个数值列表
void sArr(double arr[], int num)
{
  cout<<"为数组设值:"<<endl;
  for(int i = 0; i < num; i++)
    cin>>arr[i];
}
// 计算平均值
double avg(double arr[], int num)
{
  double sum = 0;
  for(int i = 0;i < num; i++)
    sum += arr[i];
  return sum / num;
}
#include <cmath>
// 计算标准方差
double stdDev(double arr[], int num)
{
  double dsum = 0,avgv,variance;
  avgv = avg(arr,num);
  for(int i = 0; i < num; i++)
    dsum += (arr[i] - avgv) * (arr[i] - avgv);
  variance = dsum/num;
  return sqrt(variance);
}
// 显示相应成绩对应的字母成绩
void sSc(double arr[],int num)
{
  double m,q;			// m平均值，q标准差
  m = avg(arr,num);
  q = stdDev(arr,num);
  for(int i = 0; i < num; i++)
    {
      if(arr[i] < 0 || arr[i] > 100)
	cerr<<arr[i]<<"***value error***"<<endl;
      else if(arr[i] < m - 3 / 2 * q)
	cout<<arr[i]<<" F"<<endl;
      else if(arr[i] < m - 1 / 2 * q)
	cout<<arr[i]<<" D"<<endl;
      else if(arr[i] < m + 1 / 2 *q)
	cout<<arr[i]<<" C"<<endl;
      else if(arr[i] < m + 3 / 2 *q)
	cout<<arr[i]<<" B"<<endl;
      else
	cout<<arr[i]<<" A"<<endl;
    }
}
// 测试编程问题1
void t1()
{
  cout<<"Enter number:"<<endl;
  int num;
  cin>>num;
  double arr[num];
  sArr(arr,num);
  sSc(arr,num);
}
// 2.
void sOpen()
{
  int arr[151],f[151]={0};
  for(int i = 1; i < 151; i++)
    arr[i] = i;

  for(int i = 2; i < 6; i++)
    for(int j = i; j < 151; j += i)
      {
	if(j % i == 0)
	  {
	    if(f[j] == 0)
	      f[j] = 1;
	    else
	      f[j] = 0;
	  }
      }
  for(int i = 1; i < 151; i++)
    {
      if(i < 10)
	cout<<arr[i]<<"----"<<f[i]<<" ";
      else if(i < 100)
	cout<<arr[i]<<"---"<<f[i]<<" ";
      else
	cout<<arr[i]<<"--"<<f[i]<<" ";
      if(i % 10 == 0)
	cout<<endl;
    }
  cout<<endl;
  for(int i = 1; i < 151; i++)
    if(f[i] == 0)
      cout<<arr[i]<<" ";
  cout<<endl;
}
// 3.埃拉托色尼筛选法
  // 2是素数，2的倍数排除
  // 递增到下一个没有被排除的数3，即素数，它的倍数排除
  // 直到列表中的数的平方大于n，但是又没有被排除的数
  // 列表中剩余的数即为2-n之间的数
void initArr(int f[],int n)	// intit arr
{
  f[0] = 1;
  f[1] =1;
  for(int i = 2; i < n; i++)
    f[i] = 0;
}
void cPrimeNumber(int f[], int n,int sv) // sv step value
{
  for(int i = 2 * sv; i < n; i += sv)
    f[i] = 1;
}
void csv(int f[],int n,int max)			// compute step value
{
  for(int i = 2; i <= max; i++)
    if(f[i] == 0)
      cPrimeNumber(f,n,i);
}
void sPrimeNumber(int f[],int n)
{
  int count = 0;
  for(int i = 0; i < n; i++)
    {
      if(f[i] == 0)
	{
	  cout<<i<<",";
	  count++;
	  if(count % 20 == 0)
	    cout<<"\n";
	}
    }
  cout<<"sushu number:"<<count<<endl;
}
void res()
{
  int n = 0;
  cin>>n;
  int f[n];
  initArr(f,n);
  int max = sqrt(n)+1;
  cout<<"max = "<<max<<endl;
  csv(f,n,max);
  sPrimeNumber(f,n);
}
// 4.large number addition(300bit)

int main()
{
  //  t1();
  //sOpen();
  res();
}
