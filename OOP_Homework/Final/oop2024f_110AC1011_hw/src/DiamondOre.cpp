#include "DiamondOre.hpp"
DiamondOre::DiamondOre() {}
bool DiamondOre::BreakableBy(Pickaxe pickaxe) {
    return pickaxe == Pickaxe::Iron || pickaxe == Pickaxe::Diamond;
}