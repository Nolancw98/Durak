/*#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "Card.h"
#include "Hand.h"
#include "Player.h"


using namespace std;

#ifndef COMPUTER_H
#define COMPUTER_H
class Computer: public Player
{
  public:
    Computer();
    Hand getHand();
    string getName();
    bool attack(vector<Card>& field);
    bool defend(vector<Card>& field);
    void addToHand(Card toAdd);
    void setName(string n);
  private:
    Hand hand;
    string name;
};
#endif
*/