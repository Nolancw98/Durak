#include <iostream>
#include <string>

using namespace std;

#ifndef CARD_H
#define CARD_H
class Card
{
  public:
    Card(int v, char s);
    int getSuit();
    char getValue();
    string toString();
    //friend bool operator< (const Card &c1, const Card &c2);
    void setTrump();
    bool isTrump();
  private:
    char suit;
    int value;
    bool trump;
};
#endif