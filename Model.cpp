#include "Model.h"
#include <vector>

/*
  Implements operations in an UnderSeaInvadersModel.
*/

Invader::Invader() {
  this(200, 10, 1); // TODO set default Invader x position
}

Invader::Invader(int ix, int isp, int ihp) {
  x = ix;
  y = -10; // Invaders should descend from offscreen
  speed = speed;
  hp = ihp;
}

Invader::~Invader() {}

bool Invader::isHit(Starfish star) {
  if((star.x >= *x && star.x <= *x + 10) &&
  (star.y >= *y && star.y <= y + 10)) { //Placeholders
    hp -= 1;
    return true;
  }
  else {
    return false;
  }
}

bool Invader::isDefeated() {
  return hp == 0;
}

void Invader::moveInvader() {
  y += speed;
}

int Invader::getX() {
  return x;
}

int Invader::getY() {
  return y;
}

UnderSeaInvadersModel::UnderSeaInvadersModel(){
  playerX = 200; // TODO set default player x position
  playerY = 200; // TODO set player Y position
  star = {playerX, playerY, false};
  invaders = {};
}

UnderSeaInvadersModel::~UnderSeaInvadersModel(){}

void UnderSeaInvadersModel::movePlayer(int changeX){
  playerX += changeX;
}

void UnderSeaInvadersModel::shoot() {
  if(!star.shot) {
    star = {playerX, playerY, true};
  }
}

void UnderSeaInvadersModel::moveStarfish() {
  star.y -= 5; //Placeholder
  // reset the Starfish if it hits an Invader
  for(int i = invaders.size() - 1; i >= 0; i--) {
    if(invades[i].isHit(star)) {
      star = {playerX, playerY, false};
    }
  }
}

void UnderSeaInvadersModel::moveInvaders() {
  for(Invader inv : invaders) {
    inv.moveInvader();
  }
}

void UnderSeaInvadersModel::generateInvaders(vector<int> invaderX){
  for(int i = 0; i < invaderX.size(); i++) {
    Invader inv = {invaderX[i], 1};
    invaders.push_back(inv);
  }
}

void UnderSeaInvadersModel::removeInvaders(){
  for(int i = invaders.size() - 1; i >= 0; i--) {
    if(invaders[i].isDefeated()) {
      invaders.erase(invaders.begin() + i);
    }
  }
}

int UnderSeaInvadersModel::getPlayerX() {
  return playerX;
}

int UnderSeaInvadersModel::getPlayerY() {
  return playerY;
}

Starfish UnderSeaInvadersModel::getStarfish() {
  return new Starfish{star.x, star.y, star.shot};
}

vector<Invader> UnderSeaInvadersModel::getInvaders() {
  // TODO return a deep copy of invaders
}
