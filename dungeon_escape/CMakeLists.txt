set(SOURCES
    src/helpers.cpp
    src/vector2d.cpp
    src/dungeon.cpp
)

set(TESTS
    test/vector2d.cpp
)

add_executable(dungeon_escape
    src/main.cpp
    ${SOURCES}
)
target_include_directories(dungeon_escape PRIVATE include)


add_executable(dungeon_escape_tests
    test/tests.cpp
    ${SOURCES}
    ${TESTS}
)

target_link_libraries(dungeon_escape_tests Catch2::Catch2)
target_include_directories(dungeon_escape_tests PRIVATE include)
catch_discover_tests(dungeon_escape_tests)
