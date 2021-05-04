#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Game.h"

using namespace std;

int main()
{
  /*
  Deck deck;
  cout << deck.getSize() << endl;

  for(int i = 0; i < deck.getSize(); i++)
  {
    cout << i << ": ";
    cout << deck[i];
    cout << endl;
  }

  deck.shuffle();
  cout << endl << deck.getSize() << endl;
  for(int i = 0; i < deck.getSize(); i++)
  {
    cout << i << ": ";
    cout << deck[i];
    cout << endl;
  }


  deck.setTrump();
  cout << endl << deck.getSize() << endl;
  for(int i = 0; i < deck.getSize(); i++)
  {
    cout << i << ": ";
    cout << deck[i];
    cout << endl;
  }
  */


  
  Player player1("Player 1");
  Player player2("Player 2");

  Game game(player1, player2);
  
  
  return 0;
}