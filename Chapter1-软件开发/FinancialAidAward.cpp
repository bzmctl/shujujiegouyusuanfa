#include "FinancialAidAward.h"
// Constructors/Destructors
//  

FinancialAidAward::FinancialAidAward ( ) {
initAttributes();
}

FinancialAidAward::~FinancialAidAward ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  


/**
 * 获得奖学金数额
 * @return float
 */
float FinancialAidAward::getAmount ( )
{
  return this->amount;
}


/**
 * 获得奖学金来源
 * @return std::string
 */
std::string FinancialAidAward::getSource ( )
{
  return this->source;
}


/**
 * 显示奖学金信息
 */
void FinancialAidAward::display ( )
{
  std::cout<<"奖项："<<this->source<<",数额："<<this->amount<<std::endl;
}


/**
 * 设置奖学金数额
 * @param  A
 */
void FinancialAidAward::setAmount (float A )
{
  this->amount = A;
}


/**
 * 设置奖学金名称
 * @param  S 奖学金来源
 */
void FinancialAidAward::setSource (std::string S )
{
  this->source = S;
}

void FinancialAidAward::initAttributes ( ) {
  amount = 0;
}

