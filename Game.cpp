#include "Game.h"    
    
Game::Game(Player p1, Player p2)
{
  //deck = Deck();
  deck.shuffle();
  deck.setTrump();
  cout << deck.getTrump() << endl;

  player1 = p1;
  player2 = p2;

  //Deal
  for(int i = 0; i < minCards; i++)
  {
    //cout << deck.getSize() << endl; //DEBUG
    player1.addToHand(deck.draw());
    player2.addToHand(deck.draw());
  }
  activeSet.push_back(player1);
  activeSet.push_back(player2);
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

void Game::swapTurn()
{
  Player temp = activeSet[0];
  activeSet[0] = activeSet[1];
  activeSet[1] = temp;
}

//Main method
void Game::play()
{
  int state = 0;
  bool playing = true;
  field = {};
  
  while(playing)
  {
    switch(state)
    {
      case 0:
      {

      }
      case 1:
      {

      }
      case 2:
      {

      }
      case 3: //Check if players hands are missing cards
      { 
        
        while(activeSet[0].getHand().getSize() < minCards && deck.getSize() > 0)
        {
          activeSet[0].addToHand(deck.draw());
        }
        while(activeSet[1].getHand().getSize() < minCards && deck.getSize() > 0)
        {
          activeSet[1].addToHand(deck.draw());
        }
        state = 4;
        break;
      }
      case 4: //Print who's attacking, print field, prompt next
      {
        cout << "\033c"; //Screen wipe
        //cout << "Deck Size: " << deck.getSize() << endl;

        cout << activeSet[0].getName() << "'s turn to attack" << endl;
        printField(field);

        cout << "\n" << activeSet[0].getName() << " Would you like to attack?" << endl;
        int choice = promptYesNo();
        if(choice)
        {
          state = 5;
          break;
        }
        else
        {
          state = 8;
          break;
        }
      }
      case 5: //Call attack method
      {
        bool attackSuccessful = activeSet[0].attack(field);

        if(attackSuccessful)
        {
          //Check win for the player who just played a card
          if(checkWin(activeSet[0]))
          {
            state = -1;
            break;
          }
          
          promptContinue();
          state = 6;
          break;
        }
        else
        {
          promptContinue();
          state = 8;
          break;
        }
      }
      case 6: //Print who's defending, print field, prompt next
      {
        cout << "\033c"; //Screen wipe
        cout << activeSet[1].getName() << "'s turn to defend" << endl;
        printField(field);

        promptContinue();
        state = 7;
        break;
      }
      case 7: //Defending player defends
      {
        bool defendSuccesful = activeSet[1].defend(field);
        if(defendSuccesful)
        {
          if(checkWin(activeSet[1]))
          {
            state = -1;
            break;
          }
          state = 4;
          promptContinue();
          break;
        }
        else
        {
          cout << "Adding Cards to " << activeSet[1].getName() << "'s hand." << endl;
          toHand(field, activeSet[1]);
          state = 3;
          promptContinue();
          break;
        }
      }
      case 8: //Move cards to discard, swap turns
      {
        cout << "Cards will be moved to discard" << endl;
        toPile(field);
        field.clear();
        swapTurn();
        //cout << deck.getTrump() << endl;
        
        promptContinue();
        state = 3;
        break;
      }
      default:
      {
        playing = false;
        if(checkWin(activeSet[0]))
        {
          cout << activeSet[0].getName() << " wins!" << endl;
          
        }
        else{
          cout << activeSet[1].getName() << " wins!" << endl;
        }
        break;
      }
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

void Game::promptContinue()
{ 
  cout << "Press Enter to Continue: ";
  cin.ignore();
}

int Game::promptYesNo()
{
  int choice;
  do{
    cout << "0:No, 1:Yes: ";
    cin >> choice;
  }while(choice > 1);
  return choice;
}