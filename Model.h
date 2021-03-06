// DO NOT EDIT THIS FILE WITHOUT CONSULTING THE GROUP.
#ifndef _UNDERSEA_INVADERS_MODEL_H
#define _UNDERSEA_INVADERS_MODEL_H

/*
  Represents a Starfish in an UnderSea Invaders game. Starfish are the
  projectiles a Player can shoot to damage Invaders.
*/
struct Starfish() {
  int x, y; // the position of a Starfish
  bool shot; // whether a Starfish has been fired
};

/*
  Represents an Invader in an UnderSea Invaders game. Invaders are the enemies
  that the Player is trying to defeat to win the game.
*/
class Invader {
  public:
  Invader(); // generate Invader with default position
  Invader(int ix, int isp, int ihp); // generate Invader at the given position
  ~Invader(); // delete an existing Invader
  /*
    Determines if an Invader has been hit by a Starfish.
  */
  boolean isHit(Starfish star);
  /*
    Determines if an Invader has been defeated by the Player.
  */
  boolean isDefeated();
  /*
    Moves the Invader towards the bottom of the screen.
    @param degree of change in position of Invader
  */
  void moveInvader(int changeY);
  /*
    Returns the x position of the Invader.
  */
  int getX();
  /*
    Returns the y position of the Invader.
  */
  int getY();

  private:
  int x, y, speed, hp; // the position and health of an Invader
};

/*
  Represents the model for an UnderSea Invaders game and implements mechanics:
  shooting Starfish, moving the Player, tracking game state, etc...
*/
class UnderSeaInvadersModel {
  public:
  UnderSeaInvadersModel(); // generates a UnderSeaInvadersModel
  ~UnderSeaInvadersModel(); // destroys an UnderSeaInvadersModel
  /*
    Moves a Player left or right. Players can only move horizontally.
    @param changeX degree of change in position of the Player
  */
  void movePlayer(int changeX);
  /*
    Shoots a Starfish from the current position of the Player. Only one Starfish
    can be onscreen at any one time.
  */
  void shoot();
  /*
    Moves the Starfish after it has been fired towards the top of the screen.
    @paran changeY degree of change in position of the Starfish
  */
  void moveStarfish(int changeY);
  /*
    Moves all Invaders on screen towards the bottom of the screen.
  */
  void moveInvaders();
  /*
    Generates Invaders at the given positions in an UnderSea Invaders game.
    @param invaderX the list of positions of Invaders
  */
  void generateInvaders(vector<int> invaderX);
  /*
    Removes Invaders from the game after they have been defeated.
  */
  void removeInvaders();
  /*
    Returns the x position of the Player.
  */
  int getPlayerX();
  /*
    Returns the y position of the Player.
  */
  int getPlayerY();
  /*
    Returns the Starfish.
  */
  Starfish getStarfish();
  /*
    Returns the list of Invaders.
  */
  vector<Invader> getInvaders();

  private:
  int playerX; // Player x position
  int playerY; // Player y position
  Starfish star; // the state of the Starfish
  vector<Invader> invaders; // the Invaders currently onscreen
};

#endif
