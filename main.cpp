#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

void printField(vector<Card> field);

int main()
{
  //Main Testing Methods
  Deck deck;
  deck.shuffle();
  deck.setTrump();

  for(int i = 0; i < deck.getSize(); i++)
  {
    cout << deck[i];
    cout << ", ";
  }
  cout << endl;
  cout << "Size after Set Trump: " << deck.getSize() << endl;

  cout << "\nCreating Player, add 6 cards to hand" << endl;
  Player player1;

  player1.addToHand(deck.draw());
  player1.addToHand(deck.draw());
  player1.addToHand(deck.draw());
  player1.addToHand(deck.draw());
  player1.addToHand(deck.draw());
  player1.addToHand(deck.draw());

  vector<Card> field = {deck.draw(), deck.draw()};
  printField(field);

  bool resultOfAttack = player1.attack(field);
  cout << "Result of Attack: " << resultOfAttack << endl << endl;

  player1.addToHand(deck.draw());
  printField(field);

  bool resultOfDefense = player1.defend(field);
  cout << "Result of Defense: " << resultOfDefense << endl << endl;
  
  return 0;
}

void printField(vector<Card> field)
{
  vector<Card>::iterator i;
  cout << "Field: [";
  int count = 0;
  for(i = field.begin(); i != field.end(); i++)
  {
    cout << *i;
    if(count < field.size() - 1)
    {
      cout << ", ";
    }
    count++;
  }
  cout << "]" << endl;
}