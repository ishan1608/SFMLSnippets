//
// Created by ishan on 15/2/18.
//

#ifndef SFMLSNIPPETS_STRING_HELPERS_HPP
#define SFMLSNIPPETS_STRING_HELPERS_HPP

#include <sstream>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

#include "string_helpers.inl"

#endif //SFMLSNIPPETS_STRING_HELPERS_HPP
