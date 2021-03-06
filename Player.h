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
    bool virtual attack(vector<Card>& field);
    bool virtual defend(vector<Card>& field);
    void addToHand(Card toAdd);
    void removeFromHand(Card toRemove);
    void setName(string n);
  private:
    Hand hand;
    string name;
};
#endif