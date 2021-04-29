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
    const Card& operator [](const int& index);
    Card peekCard(int index); //To-Do Overload [] to make life easier
    void setTrump();
  private:
    //int size;
    char trumpSuit;
    vector<Card> deck;
};
#endif