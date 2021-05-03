#include "Player.h"

Player::Player()
{
  Hand hand = Hand();
}

Hand Player::getHand()
{
  return hand;
}

bool Player::attack(vector<Card>& field)
{
  cout << "--------------START OF ATTACK--------------" << endl;
  set<int> playable = {};

  cout << hand;
  //Determine which indices are playable
  if(field.size() > 0)
  {
    for(int i = 0; i < field.size(); i++)
    {
      for(int j = 0; j < hand.getSize(); j++)
      {
        if((hand.getHand()[j].getValue() == field[i].getValue()))
        {
          playable.insert(j);
        }
      }
    }
  }
  else
  {
    for(int j = 0; j < hand.getSize(); j++)
    {
      playable.insert(j);
    }
  }

  //Print the cards that are available to play
  cout << "Playable: [";
  set<int>::iterator p;
  int count = 0;
  for(p = playable.begin(); p != playable.end(); p++)
  {
    cout << hand.getHand()[*p];
    if(count < playable.size() - 1)
    {
      cout << ", ";
    }
    count++;
  }
  cout << "]";
  cout << endl;

  //Chose a playable card by using the index
  if(playable.size() > 0)
  {
    int choice;
    do
    {
      cout << "Which card would you like to attack with?" << endl;
      cout << "Enter index of card in Playable: ";
      cin >> choice;
    }while(choice >= playable.size());

    int indexOfHand = *next(playable.begin(),choice);
    Card chosenCard = hand.getHand()[indexOfHand];
    field.push_back(chosenCard);
    hand.removeCard(chosenCard);
    cout << hand;
    cout << endl;
    cout << "--------------END OF ATTACK--------------" << endl;
    return true;
  }
  cout << "You had no cards to attack with :(" << endl;
  cout << "--------------END OF ATTACK--------------" << endl;
  return false;
}

bool Player::defend(vector<Card>& field)
{
  cout << "--------------START OF DEFENSE--------------" << endl;
  set<int> playable = {};
  Card attackingCard = field.back();
  cout << hand;

  for(int j = 0; j < hand.getSize(); j++)
  {
    if(hand.getHand()[j].getSuit() == attackingCard.getSuit())
    {
      if(hand.getHand()[j] > attackingCard)
      {
        playable.insert(j);
      }
    }
  }

  //Print the cards that are available to play
  cout << "Playable: [";
  set<int>::iterator p;
  int count = 0;
  for(p = playable.begin(); p != playable.end(); p++)
  {
    cout << hand.getHand()[*p];
    if(count < playable.size() - 1)
    {
      cout << ", ";
    }
    count++;
  }
  cout << "]";
  cout << endl;

  //Chose a playable card by using the index
  if(playable.size() > 0)
  {
    int choice;
    do
    {
      cout << "Which card would you like to defend with?" << endl;
      cout << "Enter index of card in Playable: ";
      cin >> choice;
    }while(choice >= playable.size());

    int indexOfHand = *next(playable.begin(),choice);
    Card chosenCard = hand.getHand()[indexOfHand];
    field.push_back(chosenCard);
    hand.removeCard(chosenCard);
    cout << hand;
    cout << "--------------END OF DEFENSE--------------" << endl;
    return true;
  }
  cout << "You had no cards to defend with :(" << endl;
  cout << "--------------END OF DEFENSE--------------" << endl;
  return false;
}

void Player::addToHand(Card toAdd)
{
  hand.addCard(toAdd);
}