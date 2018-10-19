// DO NOT EDIT THIS FILE WITHOUT CONSULTING THE GROUP.
#ifndef _UNDERSEA_INVADERS_MODEL_H
#define _UNDERSEA_INVADERS_MODEL_H

struct Starfish() {
  int ix, iy;
  bool iShot;
  
};


class Invader {
  public:
  Invader();
  Invader(int x, int y, int hp);
  ~Invader();
  
  // check if the invader is hit
  boolean isHit(Starfish sf);
  private:
  int ix, iy, ihp;
};
 
/*
  Represents an UnderSea Invaders game. 
*/
class UnderSeaInvadersModel {
  public:
  UnderSeaInvadersModel();
  ~UnderSeaInvadersModel();

  /*
    Moves a player left or right.
    @param changeX degree of change in position of the player
  */
  void movePlayer(int changeX);
  /*
    Generates Invaders in a game.
    @param invaderX the list of positions of Invaders
  */
  
  
  // creates a starfish
  Starfish shoot(int x, int y, bool shot);

  // moves starfish
  void moveStarfish(Starfish sf);
  
  // Moves all invaders currently in game
  void moveInvaders();
  
  
  void generateInvaders(vector<int> invaderX);
  /*
    Removes Invaders from the game.
  */
  void removeInvaders();

  private:
  int playerX; // player position (create Player class?)
  Starfish starf;
  vector<Invader> invaders; // current Invaders 
};

#endif