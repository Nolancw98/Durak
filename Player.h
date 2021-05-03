#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "Card.h"
#include "Hand.h"


using namespace std;

#ifndef PLAYER_H
#define PLAYER_H
class Player
{
  public:
    Player();
    Player(string n);
    Hand getHand();
    string getName();
    bool attack(vector<Card>& field);
    bool defend(vector<Card>& field);
    void addToHand(Card toAdd);
  private:
    Hand hand;
    string name;
};
#endif