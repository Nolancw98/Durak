#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include "Deck.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
  public:
    Game(Player p1, Player p2);

    void setPlayer1(Player p1);
    void setPlayer2(Player p2);

    Deck getDeck();
    Player getPlayer1();
    Player getPlayer2();
    vector<Player> getActiveSet();
    
    void swapTurn();
    void play();
    void toHand(vector<Card>& field, Player& p);
    void toPile(vector<Card>& field);
    bool checkWin(Player p);
    void printField(vector<Card> field);
    void promptContinue();
    int promptYesNo();
  private:
    Player player1;
    Player player2;
    vector<Player> activeSet;
    
    const int minCards = 6;
    Deck deck;
    vector<Card> field;
};
#endif