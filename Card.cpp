#include "Card.h"

Card::Card(int v, char s)
{
  value = v; 
  suit = s;
  trump = false;
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
  return to_string(value) + suit + ", isTrump?: " + to_string(isTrump());
}

/*
bool operator < (const Card c1, const Card c2)
{
  
  return false;
}
*/

void Card::setTrump()
{
  trump = true;
}

bool Card::isTrump()
{
  return trump;
}