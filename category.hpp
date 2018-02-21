//
// Created by ishan on 21/2/18.
//

#ifndef SFMLSNIPPETS_CATEGORY_HPP
#define SFMLSNIPPETS_CATEGORY_HPP

namespace Category {
    enum class Type {
        None            = 0,
        Scene           = 1 << 0,
        PlayerAircraft  = 1 << 1,
        AlliedAircraft  = 1 << 2,
        EnemyAircraft   = 1 << 3,
    };
}


#endif //SFMLSNIPPETS_CATEGORY_HPP
