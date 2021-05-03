#include "Game.h"    
    
Game::Game()
{
  Deck deck = Deck();
  deck.shuffle();
  deck.setTrump();
  //play();
}

Game::Game(Player p1, Player p2)
{
  Deck deck = Deck();
  deck.shuffle();
  deck.setTrump();

  player1 = p1;
  player2 = p2;

  //Deal
  for(int i = 0; i < minCards; i++)
  {
    player1.addToHand(deck.draw());
    player2.addToHand(deck.draw());
  }
  activeSet.push_back(player1);
  activeSet.push_back(player2);
  dormantSet.push_back(player2);
  dormantSet.push_back(player1);
  play();
}

void Game::setPlayer1(Player p1)
{
  player1 = p1;
}

void Game::setPlayer2(Player p2)
{
  player2 = p2;
}

Deck Game::getDeck()
{
  return deck;
}

Player Game::getPlayer1()
{
  return player1;
}

Player Game::getPlayer2()
{
  return player2;
}

vector<Player> Game::getActiveSet()
{
  return activeSet;
}

vector<Player> Game::getDormantSet()
{
  return dormantSet;
}

void Game::swapTurn()
{
  activeSet.swap(dormantSet);
}

//Main method
void Game::play()
{
  cout << "Game Start" << endl;
  cout << "-----------------------------------------------" << endl;

  field = {};
  bool playing = true;
  while(playing)
  {

    //Check if players hands are missing cards
    if(activeSet[0].getHand().getSize() < minCards && deck.getSize() > 0)
    {
      activeSet[0].addToHand(deck.draw());
    }
    if(activeSet[1].getHand().getSize() < minCards && deck.getSize() > 0)
    {
      activeSet[1].addToHand(deck.draw());
    }

    cout << activeSet[0].getName() << "'s turn to attack" << endl;
    printField(field);
    //Try to attack, return true if successful
    bool attackSuccessful = activeSet[0].attack(field);

    if(attackSuccessful)
    {
      //Check win for the player who just played a card
      if(checkWin(activeSet[0]))
      {
        playing = false;
        break;
      }


      printField(field);
      //Otherwise the next player needs to defend
      cout << activeSet[1].getName() << "'s turn to defend" << endl;
      bool defendSuccesful = activeSet[1].defend(field);
      if(defendSuccesful)
      {
        if(checkWin(activeSet[1]))
        {
          playing = false;
          break;
        }
      }
      else
      {
        toHand(field, activeSet[1]);
      }

      printField(field);
      cout << "Would you like to attack again?" << endl;
      int choice;
      do{
        cout << "0:No, 1:Yes: ";
        cin >> choice;
      }while(choice > 1);

      if(choice)
      {
        continue;
      }
      else{
        toPile(field);
        swapTurn();
      }
    }
    else
    {
      toPile(field);
    }
  }
}

void Game::toHand(vector<Card>& field, Player& p)
{
  for(int i = 0; i < field.size(); i++)
  {
    p.addToHand(field[i]);
  }
  field.clear();
}

void Game::toPile(vector<Card>& field)
{
  field.clear();
}

bool Game::checkWin(Player p)
{
  //If there are still cards in the deck, no win
  if(deck.getSize() > 0)
    return false;
  
  //If cards still in hand, no win
  if(p.getHand().getSize() > 0)
    return false;
  
  //Otherwise, a win is possible
  return true;
}

void Game::printField(vector<Card> field)
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