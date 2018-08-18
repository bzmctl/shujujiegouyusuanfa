#include <iostream>
using namespace std;
struct Time{
  unsigned hour,
    minute;
  char AMorPM;
  unsigned milTime;
};
  /**
   * 将时间设置一个给定的值
   * 
   * 接受：	Time对象t
   * 	hours，以标准时间衡量的小时数
   * 	mintues，以标准时间衡量的分钟数
   * 	AMPM，（'A' if AM,'P' if PM)
   * 回传：	将数据成员设置为给定值后的Time t
   * @param  &t
   * @param  hours
   * @param  mintues
   * @param  AMPM
   */
  void set (Time &t, unsigned int hours, unsigned int minutes, char AMPM );


  /**
   * 使用输出流out显示标准或军用格式时间
   * 
   * 接受：	Time t和ostream out
   * 输出：	将t输出到out
   * 回传：	将t的表示插入到ostream，返回修改后的ostream out
   * @param  &t
   * @param  &out
   */
  void display (Time &t, ostream &out );


  /**
   * 将时间前进到一个给定的值
   * 
   * 接受：	Time对象t
   * 	hours，要增加的小时数
   * 	mintues，要增加的分钟数
   * 回传：	数据成员被增加了给定值后的Time t
   * @param  &t
   * @param  hours
   * @param  mintues
   */
  void advance (Time &t, unsigned int hours, unsigned int mintues );


  /**
   * 判断一个时间是否小于另一个时间
   * 
   * 接受：	Time t1，Time t2
   * 返回：	如果t1<t2返回true，否则返回false
   * @return bool
   * @param  &t1
   * @param  &t2
   */
  bool lessThan (const Time &t1, const Time &t2 );


  /**
   * 将标准时间转换为军用格式时间
   * @return int
   * @param  hours
   * @param  mintues
   * @param  AMPM
   */
  int toMilitary (unsigned int hours, unsigned int mintues, char AMPM );


  /**
   * 将军用时间转换为标准格式时间
   * @param  military
   * @param  &hours
   * @param  &mintues
   * @param  &AMPM
   */
  void toStandard (unsigned int military, unsigned int &hours, unsigned int &mintues, char &AMPM );
