#include "Deck.h"

// Default Constructor for a Deck creates all of the cards
Deck::Deck()
{
  char suit[] = {'H', 'D', 'C', 'S'};

  // Loop through each suit 0 = H, 1 = D, 2 = C, 3 = S'
  for(int i = 0; i < 4; i++)
  {
    // Loop through the values of the cards that need to be added
    // i.e. 6 = 6 ... 11 = J, 12 = Q, 13 = K, 14 = A
    for(int j = 6; j <= 14; j++)
    {
      // Add a card of value j and suit from the array
      deck.push_back(Card(j, suit[i]));
    }
  }
}

// Remove cards randomly from the current deck and add them to a new deck
// Replace empty deck with new deck
void Deck::shuffle()
{
  if(getSize() == 36)
  {
    int shuffleCount = 1; // 7 times is totally random
    for(int i = 0; i < shuffleCount; i++)
    {
      vector<Card> tempDeck;
      while (getSize() > 0)
      {
        srand(time(0));
        int index = (rand() % getSize());
        tempDeck.push_back(draw(index));
      }
      tempDeck.swap(deck);
    }
  }
}

// Should only be used in shuffle()
// To-Do Make private
Card Deck::draw(int index)
{
  vector<Card>::iterator it = deck.begin();
  Card drawnCard = *(it + index);
  deck.erase(it + index);
  return drawnCard;
}

Card Deck::draw()
{ 
  Card drawnCard = deck.back();
  deck.pop_back();
  return drawnCard;
}

char Deck::getTrump()
{
  return trumpSuit;
}

int Deck::getSize()
{
  return deck.size();
}

vector<Card> Deck::getDeck()
{
  return deck;
}

const Card& Deck::operator[](const int& index)
{
  return *(deck.begin() + index);
}

//DEPRECATED
/*
Card Deck::peekCard(int index)
{
  return *(deck.begin() + index);
}
*/

void Deck::setTrump()
{
  Card trump = deck[0];
  trumpSuit = trump.getSuit();
  
  //Set all of the trump cards
  vector<Card>::iterator i; 
  for(i = deck.begin(); i != deck.end(); i++)
  {
    if((*i).getSuit() == trumpSuit)
    {
      (*i).setTrump();
    }
  }
}