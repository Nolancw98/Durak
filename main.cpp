#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

using namespace std;

int main()
{
  /*
  //Testing Friend Operator
  Card c1(6, 'H');
  c1.setTrump();
  cout << c1;

  Card c2(14, 'S');
  //c2.setTrump();
  cout << c2;

  bool comparison = c1 < c2;
  cout << comparison << endl;
  */

  
  //Main Testing Methods
  Deck deck;
  for(int i = 0; i < deck.getSize(); i++)
  {
    cout << deck[i];
  }

  cout << "Size before Shuffle " << deck.getSize() << endl;
  //cout << "First Card: " << deck.draw;
  //cout << "Last Card: " << deck.draw(0);
  //cout << "Second to Last Card: " << deck.draw(1);
  cout << endl << endl;
  deck.shuffle();

  for(int i = 0; i < deck.getSize(); i++)
  {
    cout << deck[i];
  }
  cout << "Size after Shuffle: " << deck.getSize() << endl;

  deck.setTrump();
  cout << "Trump Suit: " << deck.getTrump() << endl;

  for(int i = 0; i < deck.getSize(); i++)
  {
    cout << deck[i];
  }
  cout << "Size after Shuffle: " << deck.getSize() << endl;

  Hand hand;
  hand.addCard(deck.draw());
  

  


  /*
  //FULL DRAW
  for(int i = 0; i < 36; i++)
  {
    cout << deck.draw();
  }
  cout << "Size after full draw " << deck.getSize() << endl;
  */
  
  
  
  return 0;
}