#include "ExpressionAddition.hpp"

#include "SymboleEnum.hpp"

ExpressionAddition::ExpressionAddition() : ExpressionBinaire(PLUS)
{

}


ExpressionAddition::ExpressionAddition( Expression membreG , Expression membreD )
 : ExpressionBinaire(PLUS, membreG, membreD) 
{
}

ExpressionAddition::~ExpressionAddition()
{

}
