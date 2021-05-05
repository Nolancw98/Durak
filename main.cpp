#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Game.h"
#include "Computer.h"
#include "HumanPlayer.h"

using namespace std;

int main()
{
  /*
  //Play a game with two human players
  Player player1("Player 1");
  Player player2("Player 2");
  Game game(player1, player2);
  */


  
  //Play a game against the computer
  Player player1("Player 1");
  Game game(player1);
  
  return 0;
}