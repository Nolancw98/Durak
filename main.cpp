#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

using namespace std;

int main()
{
  //Card ace_of_hearts(14, 'H');
  //cout << ace_of_hearts.toString() << endl;

  
  Deck deck;
  for(int i = 0; i < deck.getSize(); i++)
  {
    cout << deck.peekCard(i).toString() << endl;
  }

  cout << "Size before Shuffle " << deck.getSize() << endl;
  //cout << "First Card: " << deck.draw().toString() << endl;
  //cout << "Last Card: " << deck.draw(0).toString() << endl;
  //cout << "Second to Last Card: " << deck.draw(1).toString() << endl;
  cout << endl << endl;
  deck.shuffle();

  for(int i = 0; i < deck.getSize(); i++)
  {
    cout << deck.peekCard(i).toString() << endl;
  }
  cout << "Size after Shuffle: " << deck.getSize() << endl;

  deck.setTrump();
  cout << "Trump Suit: " << deck.getTrump() << endl;

  for(int i = 0; i < deck.getSize(); i++)
  {
    cout << deck.peekCard(i).toString() << endl;
  }
  cout << "Size after Shuffle: " << deck.getSize() << endl;

  //Hand hand;
  //hand.addCard(deck.draw());

  


  /*
  //FULL DRAW
  for(int i = 0; i < 36; i++)
  {
    cout << deck.draw().toString() << endl;
  }
  cout << "Size after full draw " << deck.getSize() << endl;
  */
  
  
  
  return 0;
}