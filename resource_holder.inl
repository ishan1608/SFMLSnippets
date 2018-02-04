//
// Created by ishan on 4/2/18.
//

#ifndef SFMLSNIPPETS_RESOURCE_HOLDER_INL
#define SFMLSNIPPETS_RESOURCE_HOLDER_INL

#include <cassert>

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier identifier, const std::string& fileName) {
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(fileName)) {
        throw std::runtime_error("ResourceHolder::load - Failed to load " + fileName);
    }
    insertResource(identifier, resource);
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier identifier, const std::string& fileName, const Parameter& secondParam) {
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(fileName, secondParam)) {
        throw std::runtime_error("ResourceHolder::load - Failed to load " + fileName);
    }
    insertResource(identifier, resource);
}

template <typename Resource, typename Identifier>
void ResourceHolder::insertResource(Identifier identifier, std::unique_ptr<Resource> resource) {
    auto resourceInserted = resourcesMap.insert(std::make_pair(identifier, std::move(resource)));
    assert(resourceInserted.second);
};

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) {
    auto found = resourcesMap.find(id);
    assert(found != resourcesMap.end());
    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const {
    auto found = resourcesMap.find(id);
    return *found->second;
}


#endif //SFMLSNIPPETS_RESOURCE_HOLDER_INL