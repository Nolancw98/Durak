#include <iostream>
#include <set>
#include <vector>
#include "Card.h"

#ifndef HAND_H
#define HAND_H
class Hand
{
  public:
    Hand();
    set<Card> getHand();
    void addCard(Card c);
    void addCards(vector<Card> c);
    Card removeCard(Card c);
    int getSize();
  private:
    set<Card> hand;
};
#endif