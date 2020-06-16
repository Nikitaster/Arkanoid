#include "catch.hpp"
#include "../Arkanoid/Classes/Velocity.cpp"

using namespace Catch::Matchers;

SCENARIO("Velocity has default constructor", "[velocity]") {

    GIVEN("Velocity object with default params") {
        Velocity velocity;
        REQUIRE(velocity.getDirection() == 90);

        WHEN("velocity change direction") {
            velocity.setDirection(27);

            THEN("the direction change") {
                REQUIRE(velocity.getDirection() == 27);
            }
        }
    }
}