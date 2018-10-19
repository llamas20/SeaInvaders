#include <cxxtest/TestSuite.h>

class ExampleSuite : public CxxTest::TestSuite
{
 public:
  void testExample(void)
  {
    TS_ASSERT(true);
  }
};
