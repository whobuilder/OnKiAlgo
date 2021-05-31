find_package(Catch2 REQUIRED)
include(Catch)

add_executable(
  tests
  catch_main.cpp
  linspace_tests.cpp
  distribution_tests.cpp
  arange_tests.cpp
  round_tests.cpp
  scale_tests.cpp
  bring_to_front_tests.cpp
  slide_tests.cpp
  slice_tests.cpp
  copy_until_tests.cpp
  repeat_tests.cpp)

target_link_libraries(
  tests PRIVATE project_warnings project_options OnKiAlgo::OnKiAlgo
                Catch2::Catch2)

# automatically discover tests that are defined in catch based test files you
# can modify the unittests. TEST_PREFIX to whatever you want, or use different
# for different binaries
catch_discover_tests(
  tests
  TEST_PREFIX
  "unittests."
  EXTRA_ARGS
  -s
  --reporter=xml
  --out=tests.xml)

report_code_coverage(tests ${CMAKE_CURRENT_BINARY_DIR}/tests)
