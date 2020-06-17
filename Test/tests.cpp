#include "catch.hpp"
#include "../Arkanoid/Classes/MainView.h"

using namespace Catch::Matchers;

SCENARIO("Velocity", "[velocity]") {
    GIVEN("Velocity object with default params") {
        Velocity velocity;
        REQUIRE(velocity.getDirection() == 90);

        WHEN("velocity change direction") {
            velocity.setDirection(27);

            THEN("the direction changes") {
                REQUIRE(velocity.getDirection() == 27);
            }
        }
    }
    GIVEN("Velocity object with new params") {
        Velocity velocity(30);
        REQUIRE(velocity.getDirection() == 30);

        WHEN("velocity reverse") {
            velocity.reverse();

            THEN("the direction reverses") {
                REQUIRE(velocity.getDirection() == -150);
            }
        }

        WHEN("velocity reverse x") {
            velocity.reverseX();

            THEN("the direction reverses on x axis") {
                REQUIRE(velocity.getDirection() == 150);
            }
        }

        WHEN("velocity reverse y") {
            velocity.reverseY();

            THEN("the direction reverses on y axis") {
                REQUIRE(velocity.getDirection() == -30);
            }
        }
    }
}

TEST_CASE("rect") {
    sf::RectangleShape rect(sf::Vector2f(20, 10));
    REQUIRE(rect.getSize() == sf::Vector2f(20, 10));
}

TEST_CASE("puck") {
    Puck puck;
    REQUIRE(puck.isMoving() == true);
    REQUIRE(puck.isDead == false);
}

TEST_CASE("brick pile") {
    BrickPile pile;
    REQUIRE(pile.bricks.size() == 28);
}