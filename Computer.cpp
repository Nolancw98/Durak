/*#include "Computer.h"

Computer::Computer()
{
  setName("Computer");
}

bool Computer::attack(vector<Card>& field)
{
  //cout << "--------------START OF ATTACK--------------" << endl;
  set<int> playable = {};

  cout << endl;
  cout << getName() << "'s " << getHand();
  
  //Determine which indices are playable
  if(field.size() > 0)
  {
    for(int i = 0; i < field.size(); i++)
    {
      for(int j = 0; j < getHand().getSize(); j++)
      {
        if((getHand().getHand()[j].getValue() == field[i].getValue()))
        {
          playable.insert(j);
        }
      }
    }
  }
  else
  {
    for(int j = 0; j < getHand().getSize(); j++)
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
    cout << getHand().getHand()[*p];
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
    int choice = 0; //Comptuer always picks first card!  

    int indexOfHand = *next(playable.begin(),choice);
    Card chosenCard = getHand().getHand()[indexOfHand];
    field.push_back(chosenCard);
    getHand().removeCard(chosenCard);
    cout << getHand();
    cout << endl;
    //cout << "--------------END OF ATTACK--------------" << endl << endl;
    return true;
  }
  cout << "You had no cards to attack with :(" << endl;
  //cout << "--------------END OF ATTACK--------------" << endl << endl;
  cout << endl;
  return false;
}

bool Computer::defend(vector<Card>& field)
{
  //cout << "--------------START OF DEFENSE--------------" << endl;
  set<int> playable = {};
  Card attackingCard = field.back();

  cout << endl;
  cout << getName() << "'s " << getHand();

  for(int j = 0; j < getHand().getSize(); j++)
  {
    if(getHand().getHand()[j].isTrump())
    {
      if(getHand().getHand()[j] > attackingCard)
      {
        playable.insert(j);
      }
    }
    else
    {
      if(getHand().getHand()[j].getSuit() == attackingCard.getSuit())
      {
        if(getHand().getHand()[j] > attackingCard)
        {
          playable.insert(j);
        }
      }
    }
  }

  //Print the cards that are available to play
  cout << "Playable: [";
  set<int>::iterator p;
  int count = 0;
  for(p = playable.begin(); p != playable.end(); p++)
  {
    cout << getHand()[*p];
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
    int choice = 0; //Comptuer always picks first card!  

    int indexOfHand = *next(playable.begin(),choice);
    Card chosenCard = getHand()[indexOfHand];
    field.push_back(chosenCard);
    getHand().removeCard(chosenCard);
    cout << getHand();
    cout << endl;
    //cout << "--------------END OF DEFENSE--------------" << endl << endl;
    return true;
  }
  cout << "You had no cards to defend with :(" << endl;
  //cout << "--------------END OF DEFENSE--------------" << endl << endl;
  cout << endl;
  return false;
}*/