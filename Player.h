#include <iostream>
#include <set>
#include <vector>
#include "Card.h"
#include "Hand.h"

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H
class Player
{
  public:
    Player();
    Hand getHand();
    bool attack(vector<Card>& field);
    bool defend(vector<Card>& field);
    void addToHand(Card toAdd);
  private:
    Hand hand;
};
#endif