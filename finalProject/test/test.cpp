#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "load.hpp"

int main(int argc, char* argv[]) {
    // global setup...
    int result = Catch::Session().run(1, argv);
    // global clean-up...
    return result;
}

TEST_CASE("Test") {
    REQUIRE(1 == 1);
}

TEST_CASE("Read and writing scores") {
    std::vector<int> highScores;
    std::vector<std::string> highScoreNames;
    
    SECTION("Read score") {
        REQUIRE(loader::ReadScores("/Users/coughlin/Documents/School/CS 126 C++/of_v0.10.1_osx_release/apps/myApps/final-project-Scc33/finalProject/bin/data/highScores.txt", highScores, highScoreNames) == true);
    }
    
    SECTION("Write scores") {
        REQUIRE(loader::WriteScores("/Users/coughlin/Documents/School/CS 126 C++/of_v0.10.1_osx_release/apps/myApps/final-project-Scc33/finalProject/bin/data/highScores.txt", highScores, highScoreNames) == true);
    }
}

TEST_CASE("Other reading and writing") {
    SECTION("Write settings") {
        
    }
    
    SECTION("Read settings") {
        
    }
    
    SECTION("Write market") {
        
    }
    
    SECTION("Read market") {
        
    }
    
    SECTION("Write money") {
        
    }
    
    SECTION("Read money") {
        
    }
}
