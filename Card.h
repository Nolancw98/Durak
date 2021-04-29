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
    friend const ostream& operator <<(ostream& outputStream, const Card& c);
    string toString(); //DEPRECATED
    void setTrump();
    bool isTrump();

    friend const bool operator <(const Card &c1, const Card &c2);
    friend const bool operator >(const Card &c1, const Card &c2);
    friend const bool operator <=(const Card &c1, const Card &c2);
    friend const bool operator >=(const Card &c1, const Card &c2);

  private:
    char suit;
    int value;
    bool trump;
};
#endif