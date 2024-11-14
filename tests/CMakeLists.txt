include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  binsearch_tests
  binsearch_tests.cpp
)

target_link_libraries(
  binsearch_tests
  binsearch
  GTest::gtest_main
)

target_include_directories(binsearch_tests PUBLIC ${PROJECT_SOURCE_DIR}/lib/binsearch)

include(GoogleTest)

gtest_discover_tests(binsearch_tests)