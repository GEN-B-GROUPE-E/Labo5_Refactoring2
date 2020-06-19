cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

project(GEN_Refactor2)

include_directories(src)

include(CTest)
set(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations")

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()

# Trivial example using gtest and gmock

add_executable(GEN_Refactor2
        src/Customer.cpp
        src/Customer.h
        #src/main.cpp
        src/Movie.cpp
        src/Movie.h
        src/Rental.cpp
        src/Rental.h
        src/tests.cpp
        src/RegularMovieState.cpp
        src/RegularMovieState.h
        src/ChildrensMovieState.cpp
        src/ChildrensMovieState.h
        src/NewReleaseMovieState.cpp
        src/NewReleaseMovieState.h
        src/MovieState.h)
target_link_libraries(GEN_Refactor2 gtest_main gmock_main)

add_test(NAME test COMMAND GEN_Refactor2)









