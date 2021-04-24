#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "Card.h"

using namespace std;

#ifndef DECK_H
#define DECK_H

class Deck
{
  public:
    Deck();
    void shuffle();
    Card draw(int index);
    Card draw();
    char getTrump();
    int getSize();
    vector<Card> getDeck();
    Card peekCard(int index);
    void setTrump();
  private:
    int size;
    char trumpSuit;
    vector<Card> deck;
};
#endif