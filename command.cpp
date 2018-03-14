//
// Created by ishan on 21/2/18.
//

#include "command.hpp"
#include "category.hpp"


Command::Command()
: action()
, category(static_cast<unsigned int>(Category::Type::None)) {
}
