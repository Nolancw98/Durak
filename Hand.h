#include <iostream>
#include <vector>
#include <algorithm>
#include "Card.h"


using namespace std;

#ifndef HAND_H
#define HAND_H
class Hand
{
  public:
    Hand();
    vector<Card> getHand();
    void addCard(Card c);
    //void addCards(vector<Card> c);
    void removeCard(Card card);
    int getSize();
    friend const ostream& operator <<(ostream& outputStream, const Hand& h);
    const Card& operator [](const int& index);
  private:
    vector<Card> hand;
};
#endif