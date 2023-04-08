#include <catch2/catch.hpp>
#include "vector2d.hpp"

TEST_CASE("2d vectors can be default initialized", "[vector2d]")
{
    Vector2D v;
}

TEST_CASE("2d vectors can be initialized with parameters", "[vector2d]")
{
    Vector2D v{1, 2};
    REQUIRE(v.x == 1);
    REQUIRE(v.y == 2);
}

TEST_CASE("2d vectors have members for x and y", "[vector2d]")
{
    Vector2D v{1, 2};

    v.x = 5;
    REQUIRE(v.x == 5);
    REQUIRE(v.y == 2);

    v.y = 6;
    REQUIRE(v.x == 5);
    REQUIRE(v.y == 6);
}

TEST_CASE("2d vectors allow addition", "[vector2d]")
{
    Vector2D v{2, 3};
    Vector2D u{3, 4};

    Vector2D result = u + v;

    REQUIRE(result.x == 5);
    REQUIRE(result.y == 7);
}

TEST_CASE("2d vectors allow subtraction", "[vector2d]")
{
    Vector2D v{2, 1};
    Vector2D u{3, 4};

    Vector2D result = u - v;

    REQUIRE(result.x == 1);
    REQUIRE(result.y == 3);
}

TEST_CASE("2d vectors allow multiplication", "[vector2d]")
{
    Vector2D v{2, 1};
    Vector2D u{3, 4};

    Vector2D result = u * v;

    REQUIRE(result.x == 6);
    REQUIRE(result.y == 4);
}

TEST_CASE("2d vectors allow addition assignment", "[vector2d]")
{
    Vector2D v{2, 3};
    Vector2D result{3, 4};

    result += v;

    REQUIRE(result.x == 5);
    REQUIRE(result.y == 7);
}

TEST_CASE("2d vectors allow subtraction assignment", "[vector2d]")
{
    Vector2D v{2, 1};
    Vector2D result{3, 4};

    result -= v;

    REQUIRE(result.x == 1);
    REQUIRE(result.y == 3);
}

TEST_CASE("2d vectors allow multiplication assignment", "[vector2d]")
{
    Vector2D v{2, 1};
    Vector2D result{3, 4};

    result *= v;

    REQUIRE(result.x == 6);
    REQUIRE(result.y == 4);
}

TEST_CASE("2d vectors allow addition assignment with scalar", "[vector2d]")
{
    int s = 2;
    Vector2D result{3, 4};

    result += s;

    REQUIRE(result.x == 5);
    REQUIRE(result.y == 6);
}

TEST_CASE("2d vectors allow subtraction assignment with scalar", "[vector2d]")
{
    int s = 2;
    Vector2D result{3, 4};

    result -= s;

    REQUIRE(result.x == 1);
    REQUIRE(result.y == 2);
}

TEST_CASE("2d vectors allow multiplication assignment with scalar", "[vector2d]")
{
    int s = 2;
    Vector2D result{3, 4};

    result *= s;

    REQUIRE(result.x == 6);
    REQUIRE(result.y == 8);
}

TEST_CASE("2d vectors allow addition with scalar", "[vector2d]")
{
    int s = 2;
    Vector2D u{3, 4};

    Vector2D result1 = u + s;

    REQUIRE(result1.x == 5);
    REQUIRE(result1.y == 6);

    Vector2D result2 = s + u;

    REQUIRE(result2.x == 5);
    REQUIRE(result2.y == 6);
}

TEST_CASE("2d vectors allow multiplication with scalar", "[vector2d]")
{
    int s = 2;
    Vector2D u{3, 4};

    Vector2D result1 = u * s;

    REQUIRE(result1.x == 6);
    REQUIRE(result1.y == 8);

    Vector2D result2 = s * u;

    REQUIRE(result2.x == 6);
    REQUIRE(result2.y == 8);
}

TEST_CASE("2d vectors allow subtraction with scalar", "[vector2d]")
{
    int s = 2;
    Vector2D u{3, 4};

    Vector2D result1 = u - s;

    REQUIRE(result1.x == 1);
    REQUIRE(result1.y == 2);

    Vector2D result2 = s - u;

    REQUIRE(result2.x == -1);
    REQUIRE(result2.y == -2);
}
