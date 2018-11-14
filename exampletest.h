#include <cxxtest/TestSuite.h>
#include <Model.h>

class ExampleSuite : public CxxTest::TestSuite {
 public:
  /*
    Test methods on Invaders.
   */
  void testIsHit() {
    // TODO
  }
  void testIsDefeated() {
    // TODO
  }
  void testMoveInvader() {
    Invader inv{150, 5, 2};
    inv.moveInvader();
    TS_ASSERT_EQUALS(inv.getY(), -5);
  }
  void testGetXY() {
    Invader inv{140, 10, 1};
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
    // TODO
  }
  void testMoveStarfish() {
    // TODO
  }
  void testMoveInvaders() {
    // TODO
  }
  void testGenerateInvaders() {
    // TODO
  }
  void testRemoveInvaders() {
    // TODO
  }
};
