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

const ostream& operator <<(ostream& outputStream, const Card& c)
{
  outputStream << to_string(c.value) + c.suit;
  if(c.trump)
    outputStream << "*";
  return outputStream;
}

//DEPRECATED
/*
string Card::toString()
{
  return to_string(value) + suit + "\tT: " + to_string(isTrump());
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
const bool Card::constIsTrump()
{
  return trump;
}

const bool operator <(const Card &c1, const Card &c2)
{
  if((c1.trump && c2.trump) || (!c1.trump && !c2.trump))
  {
    return c1.value < c2.value;
  }
  else
    return c2.trump;
}

const bool operator >(const Card &c1, const Card &c2)
{
  if((c1.trump && c2.trump) || (!c1.trump && !c2.trump))
  {
    return c1.value > c2.value;
  }
  else
    return c1.trump;
}

const bool operator <=(const Card &c1, const Card &c2)
{
  if((c1.trump && c2.trump) || (!c1.trump && !c2.trump))
  {
    return c1.value <= c2.value;
  }
  else
    return c2.trump;
}

const bool operator >=(const Card &c1, const Card &c2)
{
  if((c1.trump && c2.trump) || (!c1.trump && !c2.trump))
  {
    return c1.value >= c2.value;
  }
  else
    return c1.trump;
}

const bool operator ==(const Card &c1, const Card &c2)
{
  if(c1.value == c2.value && c1.suit == c2.suit)
    return true;
  return false;  
}

const bool operator !=(const Card &c1, const Card &c2)
{
  if(c1.value != c2.value || c1.suit != c2.suit)
    return true;
  return false;
}