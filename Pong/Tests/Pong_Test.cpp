#include "../Pong.h"

#define BOOST_TEST_MODULE Pong Test
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(pong_test)
{
    Pong p(0);
    /*BOOST_CHECK(p.get() == 0);
    p.run();
    BOOST_CHECK(p.get() == 1);*/
}