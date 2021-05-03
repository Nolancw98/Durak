#include "Hand.h"

Hand::Hand()
{
  vector<Card> hand = {};
}

//To Do - make construcrtor that takes in a vector
//For creating the inital hand

vector<Card> Hand::getHand()
{
  return hand;
}

void Hand::addCard(Card c)
{
  hand.push_back(c);
  sort(hand.begin(), hand.end());
}

void Hand::removeCard(Card card)
{
  vector<Card>::iterator i;
  for(i = hand.begin(); i < hand.end(); i++)
  {
    if(*i == card)
    {
      hand.erase(i);
    }
  }
}

int Hand::getSize()
{
  return hand.size();
}

const Card& Hand::operator [](const int& index)
{
  return *(hand.begin() + index);
}

const ostream& operator <<(ostream& outputStream, const Hand& h)
{
  outputStream << "Hand: [";
  vector<Card>::const_iterator i;
  int count = 0;
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