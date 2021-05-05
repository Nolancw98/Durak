#include "Game.h"    

Game::Game(Player p1)
{
  //deck = Deck();
  deck.shuffle();
  deck.setTrump();
  cout << deck.getTrump() << endl;
  player1 = p1;
  player2.setName("Computer");

  //Deal
  for(int i = 0; i < minCards; i++)
  {
    //cout << deck.getSize() << endl; //DEBUG
    player1.addToHand(deck.draw());
    player2.addToHand(deck.draw());
  }
  activeSet.push_back(player1);
  activeSet.push_back(player2);
  playCPU();
}    

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
        if(!verbose)
          cout << "\033c"; //Screen wipe
        //cout << "Deck Size: " << deck.getSize() << endl;

        cout << activeSet[0].getName() << "'s turn to attack" << endl;
        printField(field);

        cout << "\n" << activeSet[0].getName() << "'s " << activeSet[0].getHand();
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
        if(!verbose)
          cout << "\033c"; //Screen wipe
        cout << activeSet[1].getName() << "'s turn to defend" << endl;
        printField(field);

        cout << "\n" << activeSet[1].getName() << "'s " << activeSet[1].getHand();

        cout << "\n" << activeSet[1].getName() << " Would you like to defend?" << endl;
        
        int choice = promptYesNo();
        if(choice)
        {
          state = 7;
          break;
        }
        else
        {
          cout << "Adding Cards to " << activeSet[1].getName() << "'s hand." << endl;
          toHand(field, activeSet[1]);
          promptContinue();
          state = 3;
          break;
        }
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
          promptContinue();
          state = 3;
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

//Main method
void Game::playCPU()
{
  int state = 0;
  bool playing = true;
  field = {};
  bool computerAttack = false;
  bool computerDefend = true;
  
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
        
        while(player1.getHand().getSize() < minCards && deck.getSize() > 0)
        {
          player1.addToHand(deck.draw());
        }
        while(player2.getHand().getSize() < minCards && deck.getSize() > 0)
        {
          player2.addToHand(deck.draw());
        }
        state = 4;
        break;
      }
      case 4: //Print who's attacking, print field, prompt next
      {
        if(!verbose)
          cout << "\033c"; //Screen wipe
        //cout << "Deck Size: " << deck.getSize() << endl;
        if(computerAttack)
        {
          state = 9;
          break;
        }

        cout << player1.getName() << "'s turn to attack" << endl;
        printField(field);

        cout << "\n" << player1.getName() << "'s " << player1.getHand();
        cout << "\n" << player1.getName() << " Would you like to attack?" << endl;
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
        bool attackSuccessful = player1.attack(field);

        if(attackSuccessful)
        {
          //Check win for the player who just played a card
          if(checkWin(player1))
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
        if(!verbose)
          cout << "\033c"; //Screen wipe
        if(computerDefend)
        {
          state = 10;
          break;
        }

        cout << player1.getName() << "'s turn to defend" << endl;
        printField(field);

        cout << "\n" << player1.getName() << "'s " << player1.getHand();

        cout << "\n" << player1.getName() << " Would you like to defend?" << endl;
        
        int choice = promptYesNo();
        if(choice)
        {
          state = 7;
          break;
        }
        else
        {
          cout << "Adding Cards to " << player1.getName() << "'s hand." << endl;
          toHand(field, player1);
          promptContinue();
          state = 3;
          break;
        }
      }
      case 7: //Defending player defends
      {
        bool defendSuccesful = player1.defend(field);
        if(defendSuccesful)
        {
          if(checkWin(player1))
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
          cout << "Adding Cards to " << player1.getName() << "'s hand." << endl;
          toHand(field, player1);
          promptContinue();
          state = 3;
          break;
        }
      }
      case 8: //Move cards to discard, swap turns
      {
        cout << "Cards will be moved to discard" << endl;
        toPile(field);
        field.clear();
        //swapTurn();
        computerAttack = !computerAttack;
        computerDefend = !computerDefend;
        //cout << deck.getTrump() << endl;
        
        promptContinue();
        state = 3;
        break;
      }
      case 9:
      {
        bool attackSuccessful = CPUATK(field);

        if(attackSuccessful)
        {
          //Check win for the player who just played a card
          if(checkWin(player2))
          {
            state = -1;
            break;
          }
          
          //promptContinue();
          state = 6;
          break;
        }
        else
        {
          //promptContinue();
          state = 8;
          break;
        }
      }
      case 10:
      {
        bool defendSuccesful = CPUDEF(field);
        if(defendSuccesful)
        {
          if(checkWin(player2))
          {
            state = -1;
            break;
          }
          state = 4;
          //promptContinue();
          break;
        }
        else
        {
          cout << "Adding Cards to " << player2.getName() << "'s hand." << endl;
          toHand(field, player2);
          //promptContinue();
          state = 3;
          break;
        }
      }
      default:
      {
        playing = false;
        if(checkWin(player1))
        {
          cout << player1.getName() << " wins!" << endl;
          
        }
        else{
          cout << player2.getName() << " wins!" << endl;
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
  cin.ignore(std::numeric_limits<streamsize>::max(),'\n'); //https://stackoverflow.com/questions/903221/press-enter-to-continue
}

int Game::promptYesNo()
{
  int choice;
  do{
    cout << "0=No, 1=Yes: ";
    cin >> choice;
  }while(choice > 1);
  return choice;
}

bool Game::CPUATK(vector<Card>& field)
{
  //cout << "--------------START OF ATTACK--------------" << endl;
  set<int> playable = {};

  cout << endl;
  cout << player2.getName() << "'s " << player2.getHand();
  
  //Determine which indices are playable
  if(field.size() > 0)
  {
    for(int i = 0; i < field.size(); i++)
    {
      for(int j = 0; j < player2.getHand().getSize(); j++)
      {
        if((player2.getHand().getHand()[j].getValue() == field[i].getValue()))
        {
          playable.insert(j);
        }
      }
    }
  }
  else
  {
    for(int j = 0; j < player2.getHand().getSize(); j++)
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
    cout << player2.getHand().getHand()[*p];
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
    Card chosenCard = player2.getHand().getHand()[indexOfHand];
    field.push_back(chosenCard);
    player2.removeFromHand(chosenCard);
    cout << player2.getHand();
    cout << endl;
    //cout << "--------------END OF ATTACK--------------" << endl << endl;
    return true;
  }
  cout << "You had no cards to attack with :(" << endl;
  //cout << "--------------END OF ATTACK--------------" << endl << endl;
  cout << endl;
  return false;
}

bool Game::CPUDEF(vector<Card>& field)
{
  //cout << "--------------START OF DEFENSE--------------" << endl;
  set<int> playable = {};
  Card attackingCard = field.back();

  cout << endl;
  cout << player2.getName() << "'s " << player2.getHand();

  for(int j = 0; j < player2.getHand().getSize(); j++)
  {
    if(player2.getHand().getHand()[j].isTrump())
    {
      if(player2.getHand().getHand()[j] > attackingCard)
      {
        playable.insert(j);
      }
    }
    else
    {
      if(player2.getHand().getHand()[j].getSuit() == attackingCard.getSuit())
      {
        if(player2.getHand().getHand()[j] > attackingCard)
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
    cout << player2.getHand()[*p];
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
    Card chosenCard = player2.getHand()[indexOfHand];
    field.push_back(chosenCard);
    player2.removeFromHand(chosenCard);
    cout << player2.getHand();
    cout << endl;
    //cout << "--------------END OF DEFENSE--------------" << endl << endl;
    return true;
  }
  cout << "You had no cards to defend with :(" << endl;
  //cout << "--------------END OF DEFENSE--------------" << endl << endl;
  cout << endl;
  return false;
}