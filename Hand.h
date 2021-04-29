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
    
    //To-Do: Add overload for [] to make life easier
    friend const ostream& operator <<(ostream& outputStream, const Hand& h);
    const Card& operator [](const int& index);
  private:
    set<Card> hand;
};
#endif