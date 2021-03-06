#ifndef FINANCIALAIDAWARD_H
#define FINANCIALAIDAWARD_H

#include <string>
#include <iostream>
/**
  * class FinancialAidAward
  * 
  */

class FinancialAidAward
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  FinancialAidAward ( );

  /**
   * Empty Destructor
   */
  virtual ~FinancialAidAward ( );


  /**
   * 获得奖学金数额
   * @return float
   */
  float getAmount ( );


  /**
   * 获得奖学金来源
   * @return std::string
   */
  std::string getSource ( );


  /**
   * 显示奖学金信息
   */
  void display ( );


  /**
   * 设置奖学金数额
   * @param  A
   */
  void setAmount (float A );


  /**
   * 设置奖学金名称
   * @param  S 奖学金来源
   */
  void setSource (std::string S );

private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  float amount;
  std::string source;
  void initAttributes ( ) ;

};

#endif // FINANCIALAIDAWARD_H
