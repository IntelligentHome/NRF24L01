cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(NRF24L01_tests)

enable_language(C CXX)

set(GOOGLETEST_ROOT ../external/googletest/googletest CACHE STRING "Google Test source root")

include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    ../
    )

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

add_executable(
    unit_tests
    main.cc
    NRF24L01_Create.cc
    NRF24L01_Avr_Build.cc
    ../NRF24L01.cc
    ../Nrf24l01Avr.cc
    ../Nrf24l01Base.cc
    )

add_dependencies(unit_tests googletest)

target_link_libraries(
    unit_tests
    googletest
    pthread
    )
