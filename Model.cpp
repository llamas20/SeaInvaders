#include "Model.h"
#include <vector>
/*
  Implements operations in an UnderSeaInvadersModel.
*/

UnderSeaInvadersModel::UnderSeaInvadersModel(){
  int playerX = 200; // Placeholder
  Starfish starf = {-10, -10, false}; // More Placeholders!!!
  vector<Invader>enemies = {};
}

UnderSeaInvadersModel::~UnderSeaInvadersModel(){
  
}

Invader::Invader() {
  int ix = 200; 
  int iy = -10;
  int ihp = 1;
  
  // All are placeholders
}

Invader::Invader(int x, int y, int hp) {
  ix = x;
  iy = y;
  ihp = hp;
}

Invader::~Invader() {
  
}

Starfish UnderSeaInvadersModel::shoot(int x, bool shot) {
  if(!shot) {
    Starfish star = {x, 250, true}; // 250 is placeholder
  }
}

void UnderSeaInvadersModel::moveStarfish(Starfish sf) {
  sf.iy -= 5; //Placeholder
}

void UnderSeaInvadersModel::moveInvaders() {
  for(Invader inv : enemies) {
    inv.iy += 2;  
  }
}

bool Invader::isHit(Starfish sf) {
  if((sf.ix >= *this.ix && sf.ix <= *this.ix + 10) && (sf.iy >= *this.iy && sf.iy <= this.iy + 10)) { //Placeholders
    this.ihp -= 1;
    return true;
  }
  else {
    return false;
  }
}

void UnderSeaInvadersModel::movePlayer(int changeX){
  playerX += changeX;
}

void UnderSeaInvadersModel::generateInvaders(std::vector<int> invaderX){
  for(int i = 0; i < invaderX.size(); i++) {
    Invader inv = Invader(invaderX[i], -10, 1);  // Placeholder values for the most part
    enemies.push_back(inv);
  }
}

void UnderSeaInvadersModel::removeInvaders(){
  for(int i = enemies.size() - 1; i >= 0; i--) {
    if(enemies[i].ihp == 0) {
      enemies.erase(enemies.begin() + i);
    }
  }
}