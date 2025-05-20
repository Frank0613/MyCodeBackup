#include "IronOre.hpp"

#include "IronIngot.hpp"
#include <memory>
IronOre::IronOre() {}
bool IronOre::BreakableBy(Pickaxe pickaxe) {
    return pickaxe == Pickaxe::Stone || pickaxe == Pickaxe::Iron ||
           pickaxe == Pickaxe::Diamond;
};
std::shared_ptr<Ingot> IronOre::Smelt() {
    return std::make_shared<IronIngot>();
};