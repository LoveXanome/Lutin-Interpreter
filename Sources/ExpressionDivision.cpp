#include "ExpressionDivision.hpp"

#include "SymboleEnum.hpp"

ExpressionDivision::ExpressionDivision() : ExpressionBinaire(DIVISER)
{

}

ExpressionDivision::ExpressionDivision( Expression membreG , Expression membreD )
 : ExpressionBinaire(DIVISER, membreG, membreD) 
{
}

ExpressionDivision::~ExpressionDivision()
{

}
