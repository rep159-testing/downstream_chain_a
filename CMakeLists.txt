cmake_minimum_required(VERSION 3.22)
project(downstream_chain_a VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(downstream_bin_a 0.2 REQUIRED)

add_library(downstream_chain_a SHARED src/downstream_chain_a.cpp)
add_library(downstream_chain_a::downstream_chain_a ALIAS downstream_chain_a)
target_include_directories(downstream_chain_a PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(downstream_chain_a PRIVATE downstream_bin_a::downstream_bin_a)

install(TARGETS downstream_chain_a EXPORT downstream_chain_aTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT downstream_chain_aTargets NAMESPACE downstream_chain_a::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/downstream_chain_a)
configure_package_config_file(cmake/downstream_chain_aConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/downstream_chain_aConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/downstream_chain_a)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/downstream_chain_aConfigVersion.cmake
  COMPATIBILITY SameMajorVersion)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/downstream_chain_aConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/downstream_chain_aConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/downstream_chain_a)

include(CTest)
if(BUILD_TESTING)
  find_package(GTest REQUIRED)
  add_executable(test_downstream_chain_a test/test_downstream_chain_a.cpp)
  target_link_libraries(test_downstream_chain_a PRIVATE downstream_chain_a GTest::gtest_main)
  add_test(NAME test_downstream_chain_a COMMAND test_downstream_chain_a)
endif()
