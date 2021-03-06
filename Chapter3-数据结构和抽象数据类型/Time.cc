#include "Time.h"
/**
 * 将时间设置一个给定的值
 * 
 * 接受：	Time对象t
 * 	hours，以标准时间衡量的小时数
 * 	minutes，以标准时间衡量的分钟数
 * 	AMPM，（'A' if AM,'P' if PM)
 * 回传：	将数据成员设置为给定值后的Time t
 * @param  &t
 * @param  hours
 * @param  minutes
 * @param  AMPM
 */
void set (Time &t, unsigned int hours, unsigned int minutes, char AMPM )
{
  if(hours >=1 && hours <=12 &&
     minutes >=0 && minutes <= 59 &&
     (AMPM == 'A' || AMPM == 'P'))
    {
      t.hour = hours;
      t.minute = minutes;
      t.AMorPM = AMPM;
      t.milTime = toMilitary(hours,minutes,AMPM);
    }
  else
    cerr<<"***Can't set time with these values ***\n"; // t未改变
}


/**
 * 使用输出流out显示标准或军用格式时间
 * 
 * 接受：	Time t和ostream out
 * 输出：	将t输出到out
 * 回传：	将t的表示插入到ostream，返回修改后的ostream out
 * @param  &t
 * @param  &out
 */
void display (Time &t, ostream &out )
{
  out << t.hour << ':'
      << (t.minute < 10 ? "0" : "") << t.minute
      << " " << t.AMorPM << "M. ("
      << t.milTime << " mil. Time)";
}


/**
 * 将时间前进到一个给定的值
 * 
 * 接受：	Time对象t
 * 	hours，要增加的小时数
 * 	minutes，要增加的分钟数
 * 回传：	数据成员被增加了给定值后的Time t
 * @param  &t
 * @param  hours
 * @param  minutes
 */
void advance (Time &t, unsigned int hours, unsigned int minutes )
{
  // 使用军用格式时间前进
  t.milTime += 100 * hours + minutes;
  unsigned milHours = t.milTime / 100;
  unsigned milMins = t.milTime % 100;

  // 调整为正确的格式
  milHours += milMins / 60;
  milMins %= 60;
  milHours %= 24;
  t.milTime = 100 * milHours + milMins;

  // 现在设置标准格式时间
  toStandard(t.milTime,t.hour,t.minute,t.AMorPM);
}


/**
 * 判断一个时间是否小于另一个时间
 * 
 * 接受：	Time t1，Time t2
 * 返回：	如果t1<t2返回true，否则返回false
 * @return bool
 * @param  &t1
 * @param  &t2
 */
bool lessThan (const Time &t1, const Time &t2 )
{
  return (t1.milTime < t2.milTime);
}


/**
 * 将标准时间转换为军用格式时间
 * @return int
 * @param  hours
 * @param  minutes
 * @param  AMPM
 */
int toMilitary (unsigned int hours, unsigned int minutes, char AMPM )
{
  if(hours == 12)
    hours = 0;
  return hours * 100 + minutes + (AMPM == 'P' ? 1200 : 0);
}


/**
 * 将军用时间转换为标准格式时间
 * @param  military
 * @param  &hours
 * @param  &minutes
 * @param  &AMPM
 */
void toStandard (unsigned int military, unsigned int &hours, unsigned int &minutes, char &AMPM )
{
  hours = (military / 100) % 12;
  if(hours == 0)
    hours = 12;
  minutes = military % 100;
  AMPM = (military/100) < 12 ? 'A' : 'P';
}
int main()
{
  Time mealTime,
    goToWorkTime;
  set(mealTime,11,30,'A');
  cout<<"We'll be eating at ";
  display(mealTime,cout);
  cout<<endl;
  set(goToWorkTime,11,30,'A');
  cout<<"You leave for work at ";
  display(goToWorkTime,cout);
  cout<<endl;
  if(lessThan(mealTime,goToWorkTime))
    cout<<"If you hurry,you can eat first.\n";
  else
    cout<<"Sorry you can't eat with us.\n";
  advance(goToWorkTime,0,30);	// 尝试其他的值:0->12
  cout<<"You boss called . You go in later at ";
  display(goToWorkTime,cout);
  cout<<endl;
  if(lessThan(mealTime,goToWorkTime))
    cout<<"If you hurry,you can eat first.\n";
  else
    cout<<"Sorry you can't eat with us.\n";
  cout<<endl;
}
