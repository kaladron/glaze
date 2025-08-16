project(csv_test)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE glz_test_common)

if (MINGW)
    target_compile_options(${PROJECT_NAME} PRIVATE "-Wa,-mbig-obj")
endif ()

target_compile_definitions(${PROJECT_NAME} PRIVATE 
    GLZ_TEST_DIRECTORY="${CMAKE_CURRENT_SOURCE_DIR}"
)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

# Minimal module import test for glaze.csv
if(TARGET glaze.csv)
  add_executable(csv_module_test csv_module_test.cpp)
  target_compile_features(csv_module_test PRIVATE cxx_std_23)
  target_link_libraries(csv_module_test PRIVATE glaze.csv)
  set_property(TARGET csv_module_test PROPERTY CXX_SCAN_FOR_MODULES ON)
  add_test(NAME csv_module_test COMMAND csv_module_test)
else()
  message(STATUS "Skipping csv_module_test: glaze.csv module target not available")
endif()

target_code_coverage(${PROJECT_NAME} AUTO ALL)