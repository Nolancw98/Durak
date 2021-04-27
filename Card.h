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
    void setTrump();
    bool isTrump();

    //std::less<Card>::operator lessThan();
    friend bool operator< (Card &c1, Card &c2);
    friend bool operator> (Card &c1, Card &c2);
    friend bool operator<= (Card &c1, Card &c2);
    friend bool operator>= (Card &c1, Card &c2);

  private:
    char suit;
    int value;
    bool trump;
};
#endif