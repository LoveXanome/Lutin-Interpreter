#include "ExpressionSoustraction.hpp"

#include "SymboleEnum.hpp"

ExpressionSoustraction::ExpressionSoustraction() : ExpressionBinaire(MOINS)
{

}

ExpressionSoustraction::ExpressionSoustraction( Expression membreG , Expression membreD )
 : ExpressionBinaire(DIVISER, membreG, membreD) 
{
}

ExpressionSoustraction::~ExpressionSoustraction()
{

}
