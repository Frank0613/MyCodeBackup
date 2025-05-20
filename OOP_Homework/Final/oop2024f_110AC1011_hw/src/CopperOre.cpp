#include "CopperOre.hpp"

#include "CopperIngot.hpp"
#include "Pickaxe.hpp"

CopperOre::CopperOre() {}
bool CopperOre::BreakableBy(Pickaxe pickaxe) {
    return pickaxe == Pickaxe::Stone || pickaxe == Pickaxe::Iron ||
           pickaxe == Pickaxe::Diamond;
}
std::shared_ptr<Ingot> CopperOre::Smelt() {
    return std::make_shared<CopperIngot>();
}
