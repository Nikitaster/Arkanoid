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
    REQUIRE(pile.get_size() == 7);
}

TEST_CASE("hit regular brick") {
    Brick brick;
    brick.hitBy();
    REQUIRE(brick.isDead == true);
}

TEST_CASE("hit unbreakeable brick") {
    Abrick abrick;
    abrick.hitBy();
    REQUIRE(abrick.isDead == false);
}

SCENARIO("MenuScene", "[menu]") {
    GIVEN("MenuScene object with default params") {
        sf::RenderWindow window;
        PauseScene pause;
        MenuScene menu;
        REQUIRE(menu.get_menu_statement() == true);
    }
}

SCENARIO("PauseScene", "[pause]") {
    GIVEN("PauseScene object with default params") {
        sf::RenderWindow window;
        PauseScene pause;
        REQUIRE(pause.get_pause_statement() == true);
        REQUIRE(pause.get_button() == 0);
        REQUIRE(pause.check_button_pressed(window) == 0);
    }
}

SCENARIO("GameScene", "[game]") {
    GIVEN("GameScene object with default params") {
        GameScene game;
        REQUIRE(game.isGameOver() == false);
        REQUIRE(game.onPause() == false);
    }
}

SCENARIO("GameOverScene", "[gameover]") {
    GIVEN("GameOverScene object with default params") {
        GameOverScene gameover;
        REQUIRE(gameover.getStatement() == true);
        REQUIRE(gameover.getButton() == 0);
        REQUIRE(gameover.getButtonStatus() == 0);
    }
}

SCENARIO("GameWinScene", "[gamewin]") {
	GIVEN("GameWinScene object with default params") {
		GameWinScene gamewin;
		REQUIRE(gamewin.getStatement() == true);
		REQUIRE(gamewin.getButton() == 0);
		REQUIRE(gamewin.getButtonStatus() == 0);
	}
}

SCENARIO("Puddle stops", "[puddle]") {
    GIVEN("Puddle object") {
        Puddle puddle;
        REQUIRE(puddle.velocity.get_speedX() == 7);

        WHEN("Puddle on the right") {
            puddle.get_sprite().setPosition(800, 0);
            puddle.move(800);

            THEN("Puddle must stop") {
                REQUIRE(puddle.velocity.get_speedX() == 0);
            }
        }

        WHEN("Puddle on the left") {
            puddle.get_sprite().setPosition(0 - puddle.velocity.get_speedX(), 0);
            puddle.move(800);

            THEN("Puddle must stop") {
                REQUIRE(puddle.velocity.get_speedX() == 0);
            }
        }
    }
}

SCENARIO("Puck supply", "[puck]") {
    GIVEN("Supply of objects puck ") {
        PuckSupply pucks;
        REQUIRE(pucks.have_alive_puck() == true);

        WHEN("Puck goes down for 3 times") {
            pucks.get_alive_puck().isDead = true;
            pucks.get_alive_puck().isDead = true;
            pucks.get_alive_puck().isDead = true;

            THEN("All pucks in puck supply must be gone.......") {
                REQUIRE(pucks.have_alive_puck() == false);
            }
        }

        WHEN("Puck goes down for less than 3 times") {
            pucks.get_alive_puck().isDead = true;
            pucks.get_alive_puck().isDead = true;

            THEN("We still have some pucks in puck supply") {
                REQUIRE(pucks.have_alive_puck() == true);
            }
        }
    }
}

SCENARIO("New level", "[levels]") {
    GIVEN("Brick pile ") {
        BrickPile pile;
        pile.generate_objects();
        REQUIRE(pile.get_size() == 7);

        WHEN("new level starts") {
            pile.generate_objects(1, pile.get_size() + 3);

            THEN("New level begins") {
                REQUIRE(pile.get_size() == 10);
            }
        }
    }
}