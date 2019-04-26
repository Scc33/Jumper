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
