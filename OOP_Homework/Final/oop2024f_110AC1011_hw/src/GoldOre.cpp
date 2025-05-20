#include "GoldOre.hpp"

#include <memory>

#include "GoldIngot.hpp"
GoldOre::GoldOre() {}
bool GoldOre::BreakableBy(Pickaxe pickaxe) {
    return pickaxe == Pickaxe::Iron || pickaxe == Pickaxe::Diamond;
};
std::shared_ptr<Ingot> GoldOre::Smelt() {
    return std::make_shared<GoldIngot>();
};