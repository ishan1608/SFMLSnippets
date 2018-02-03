cmake_minimum_required(VERSION 3.9)
project(SFMLSnippets)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.hpp Game.cpp resource_holder.hpp resource_holder.inl)
add_executable(SFMLSnippets ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFMLSnippets ${SFML_LIBRARIES})
endif()
