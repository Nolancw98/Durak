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
  return to_string(value) + suit + "\tT: " + to_string(isTrump());
}

void Card::setTrump()
{
  trump = true;
}

bool Card::isTrump()
{
  return trump;
}

/*
std::less<Card>::operator (Card c1, Card c2); 
{
  if((c1.isTrump() && c2.isTrump()) || (!c1.isTrump() && !c2.isTrump()))
    {
      return c1.getValue() < c2.getValue();
    }
    else
      return c2.isTrump();
}
*/

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
