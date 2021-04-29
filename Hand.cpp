#include "Hand.h"

Hand::Hand()
{
  set<Card> hand = {};
}

//To Do - make construcrtor that takes in a vector
//For creating the inital hand

set<Card> Hand::getHand()
{
  return hand;
}

void Hand::addCard(Card c)
{
  hand.insert(c);
}

void Hand::addCards(vector<Card> c)
{
  hand.insert(c.begin(), c.begin() + c.size());
}

Card Hand::removeCard(Card c)
{
  set<Card>::iterator i;
  i = hand.find(c);
  hand.erase(i);
  return *i;
}

int Hand::getSize()
{
  return hand.size();
}

const Card& Hand::operator [](const int& index)
{
  set<Card>::iterator i;
  set<Card>::iterator toReturn;
  int count = 0;
  for(i = hand.begin(); i != hand.end(); i++)
  {
    if(count == index)
      toReturn = i;
    count++;
  }
  return *toReturn;
}

const ostream& operator <<(ostream& outputStream, const Hand& h)
{
  set<Card>::iterator i;
  int count = 0;
  outputStream << "Hand: [";
  for(i = h.hand.begin(); i != h.hand.end(); i++)
  {
    outputStream << *i;
    if(count < h.hand.size() - 1)
      outputStream << ", ";
    count++;
  }
  outputStream << "]\n";
  return outputStream;
}


