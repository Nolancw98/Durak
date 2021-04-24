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
  private:
    char suit;
    int value;
};
#endif