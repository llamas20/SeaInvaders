#include <cxxtest/TestSuite.h>
#include <Model.h>
#include <vector>

class ExampleSuite : public CxxTest::TestSuite {
 public:
  /*
    Test methods on Invaders.
   */
  void testIsHit() {
    Invader inv(150, 5, 2);
    Starfish starf(150, 0, true);
    Starfish stafy(100, 0, true);
    TS_ASSERT_EQUALS(inv.isHit(starf), true);
    TS_ASSERT_EQUALS(inv.isHit(stafy), false);
  }
  
  void testIsDefeated() {
    Invader inv(150, 5, 2);
    Invader dedded(100, 0, 0);
    TS_ASSERT_EQUALS(inv.isDefeated(), false);
    TS_ASSERT_EQUALS(dedded.isDefeated(), true);
  }
  void testMoveInvader() {
    Invader inv(150, 5, 2);
    inv.moveInvader();
    TS_ASSERT_EQUALS(inv.getY(), -5);
  }
  void testGetXY() {
    Invader inv(140, 10, 1);
    TS_ASSERT_EQUALS(inv.getX(), 140);
    TS_ASSERT_EQUALS(inv.getY(), -10);
  }
  /*
    Test methods on UnderSeaInvadersModel.
  */
  void testMovePlayer() {
    UnderSeaInvadersModel model;
    TS_ASSERT_EQUALS(model.getPlayerX(), 200);
    model.movePlayer(10);
    TS_ASSERT_EQUALS(model.getPlayerX(), 210);
    model.movePlayer(-20);
    TS_ASSERT_EQUALS(model.getPlayerX(), 190);
  }
  void testShoot() {
    UnderSeaInvadersModel model;
    TS_ASSERT_EQUALS(model.star.shot == false);
    model.shoot();
    TS_ASSERT_EQUALS(model.star.shot == true);
  }
  void testMoveStarfish() {
    UnderSeaInvadersModel model;
    TS_ASSERT_EQUALS(model.star.y, 200);
    model.moveStarfish();
    TS_ASSERT_EQUALS(model.star.y, 195);
  }
  void testGenerateInvaders() {
    Invader inv(150, 5, 2);
    std::vector<Invader> invs{inv};
    UnderSeaInvadersModel model;
    model.generateInvaders(invs);
    TS_ASSERT_EQUALS(model.invaders, invs);
  }
  void testMoveInvaders() {
    Invader inv(150, 5, 2);
    std::vector<Invader> invs{inv};
    UnderSeaInvadersModel model;
    model.generateInvaders(invs);
    model.moveInvaders();
    TS_ASSERT_EQUALS(model.invaders[0].getY(), 5);
  }
  void testRemoveInvaders() {
    Invader inv(150, 5, 0);
    std::vector<Invader> invs{inv};
    UnderSeaInvadersModel model;
    model.generateInvaders(invs);
    model.removeInvaders();
    TS_ASSERT_EQUALS(model.invaders, {});
  }
};
