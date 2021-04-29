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
  //hand.insert(c);
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

