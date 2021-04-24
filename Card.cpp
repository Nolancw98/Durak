#include "Card.h"

Card::Card(int v, char s)
{
  value = v; 
  suit = s;
}
int Card::getSuit()
{
  return suit;
}

char Card::getValue()
{
  return value;
}

string Card::toString()
{
  return to_string(value) + suit;
}