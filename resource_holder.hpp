//
// Created by ishan on 4/2/18.
//

#ifndef SFMLSNIPPETS_RESOURCE_HOLDER_HPP
#define SFMLSNIPPETS_RESOURCE_HOLDER_HPP

// Resources
namespace Textures {
    enum class ID {
        Landscape, Airplane, Missile
    };
}

template <typename Resource, typename Identifier>
class ResourceHolder {
    public:
        void load(Identifier identifier, const std::string& fileName);

        Resource& get(Identifier identifier);
        const Resource& get(Identifier id) const;

    private:
        std::map<Identifier, std::unique_ptr<Resource>> resourcesMap;
};

#include "resource_holder.inl"

#endif //SFMLSNIPPETS_RESOURCE_HOLDER_HPP
