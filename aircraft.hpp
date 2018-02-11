//
// Created by ishan on 11/2/18.
//

#ifndef SFMLSNIPPETS_AIRCRAFT_HPP
#define SFMLSNIPPETS_AIRCRAFT_HPP


#include "entity.hpp"

class Aircraft : public Entity {
    public:
        enum class Type {
            Eagle,
            Raptor,
        };

        explicit Aircraft(Type type);

    private:
        Type type;
};


#endif //SFMLSNIPPETS_AIRCRAFT_HPP
