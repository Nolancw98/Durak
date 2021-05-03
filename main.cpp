#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Game.h"

using namespace std;

int main()
{
  Player player1("Player 1");
  Player player2("Player 2");

  Game game(player1, player2);
  
  return 0;
}