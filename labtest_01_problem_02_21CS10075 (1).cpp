#include <bits/stdc++.h>
using namespace std;

// Define the Player class

class Player{
     int score;
     public:
         Player(int s=0):score(s){};
         void addToScore(int p){
            score+=p;
         }
         int getScore(){
         return score;
         }
         ~Player(){} 
};

// Define the Zombie class

class Zombie{
   public:
     virtual bool isDead()=0;
     virtual int getValue()=0;
};

// Define the Runner class, which is a subclass of Zombie

class Runner: public Zombie{
     bool d;
     public:
      Runner(bool dead):d(dead){}
      bool isDead()override{return d;}
      int getValue()override{return 10;}
      ~Runner(){}
};

// Define the Stalker class, which is a subclass of Zombie

class Stalker: public Zombie{
     bool d;
     public:
      Stalker(bool dead):d(dead){}
      bool isDead()override{return d;}
      int getValue()override{return 20;}
      ~Stalker(){}
};

// Define the Clicker class, which is a subclass of Zombie

class Clicker: public Zombie{
     bool d;
     public:
      Clicker(bool dead):d(dead){}
      bool isDead()override{return d;}
      int getValue()override{return 30;}
      ~Clicker(){}
};

// Define the Bloater class, which is a subclass of Zombie

class Bloater: public Zombie{
     bool d;
     public:
      Bloater(bool dead):d(dead){}
      bool isDead()override{return d;}
      int getValue()override{return 50;}
      ~Bloater(){}
};

// The main function of the program
int main()
{
    // Create an instance of the Player class and initialize the number of zombies
    Player ellie;
    int numZombies = 4;

    // Create a pointer array of Zombie objects and dynamically allocate memory for them
    Zombie **zombies = new Zombie *[numZombies];

    // Initialize the array with instances of the various Zombie subclasses
    zombies[0] = new Runner(true);
    zombies[1] = new Stalker(false);
    zombies[2] = new Clicker(true);
    zombies[3] = new Bloater(true);

    // Loop through the array and add the value of each dead zombie to the player's score
    for (int i = 0; i < numZombies; i++)
    {
        if (zombies[i]->isDead())
            ellie.addToScore(zombies[i]->getValue());
    }

    // Print the player's score to the console
    cout << "Ellie's score: " << ellie.getScore() << endl;

    // Deallocate memory for the Zombie array
    for (int i = 0; i < numZombies; i++)
    {
        delete zombies[i];
    }
    delete[] zombies;

    // Return 0 to indicate successful program execution
    return 0;
}
