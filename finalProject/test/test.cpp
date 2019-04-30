#define CATCH_CONFIG_RUNNER
#include "ofApp.h"
#include "catch.hpp"

#include "game.hpp"
#include "player.hpp"
#include "load.hpp"
#include "mainMenu.hpp"
#include "highScoreMenu.hpp"
#include "marketMenu.hpp"
#include "settingsMenu.hpp"
#include "gameEndedMenu.hpp"
#include "globals.hpp"

int main(int argc, char* argv[]) {
    // global setup...
    int result = Catch::Session().run(1, argv);
    // global clean-up...
    return result;
}

TEST_CASE("Game") {
    Game game;
    
    SECTION("Score") {
        REQUIRE(game.getScore() == 0);
    }
}

TEST_CASE("Player") {
    Player player;
    player.setPlayer(1, 2, 10);
    
    SECTION("Create player") {
        REQUIRE(player.getPosX() == 1);
        REQUIRE(player.getPosY() == 2);
    }
    
    player.updatePlayerLocation(5, 5);
    SECTION("Update player") {
        REQUIRE(player.getPosX() == 5);
        REQUIRE(player.getPosY() == 5);
    }
}

TEST_CASE("Main menu") {
    mainMenu mainM;
    mainM.setMainMenu(5, 6, 10);
    Player player;
    player.setPlayer(1, 2, 10);
    mainM.setMainMenuPlayer(player);
    
    SECTION("Getters") {
        REQUIRE(mainM.getCols() == 5);
        REQUIRE(mainM.getRows() == 6);
    }
    
    SECTION("Player location") {
        REQUIRE(mainM.getPosX() == 1);
        REQUIRE(mainM.getPosY() == 1);
    }
}

TEST_CASE("High score menu") {
    highScoreMenu hScoreM;
}

TEST_CASE("Market menu") {
    marketMenu marketM;
}

TEST_CASE("Settings menu") {
    settingsMenu settingsM;
}

TEST_CASE("Engame") {
    gameEndedMenu endM;
}

TEST_CASE("Read and writing scores") {
    std::vector<int> highScores;
    std::vector<std::string> highScoreNames;
    
    SECTION("Read score") {
        REQUIRE(loader::ReadScores(hScoreFileLoc, highScores, highScoreNames) == true);
    }
    
    SECTION("Write scores") {
        REQUIRE(loader::WriteScores(hScoreFileLoc, highScores, highScoreNames) == true);
    }
}

TEST_CASE("Read and writing settings") {
    int color = -1;
    bool fullScreen = false;
    REQUIRE(loader::ReadSettings(settingsFileLoc, color, fullScreen) == true);
    
    SECTION("Read settings") {
        REQUIRE(color != -1);
    }
    
    SECTION("Write settings") {
        REQUIRE(loader::WriteSettings(settingsFileLoc, color, fullScreen) == true);
    }
}

TEST_CASE("Read and write market") {
    int market = -1;
    REQUIRE(loader::ReadMarket(moneyFileLoc, market) == true);
    
    SECTION("Read money") {
        REQUIRE(market != -1);
    }
    
    SECTION("Write money") {
        REQUIRE(loader::WriteMoney(moneyFileLoc, market) == true);
    }
}

TEST_CASE("Read and write money") {
    int money = -1;
    REQUIRE(loader::ReadMoney(moneyFileLoc, money) == true);
    
    SECTION("Read money") {
        REQUIRE(money != -1);
    }
    
    SECTION("Write money") {
        REQUIRE(loader::WriteMoney(moneyFileLoc, money) == true);
    }
}
