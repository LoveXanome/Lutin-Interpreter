#include "ExpressionMultiplication.hpp"

#include "SymboleEnum.hpp"

ExpressionMultiplication::ExpressionMultiplication() : ExpressionBinaire(MULTIPLIER)
{

}

ExpressionMultiplication::ExpressionMultiplication( Expression membreG , Expression membreD )
 : ExpressionBinaire(DIVISER, membreG, membreD) 
{
}

ExpressionMultiplication::~ExpressionMultiplication()
{

}
