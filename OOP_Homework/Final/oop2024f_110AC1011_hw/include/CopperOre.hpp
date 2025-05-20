#ifndef COPPER_ORE_HPP
#define COPPER_ORE_HPP

#include "ISmeltable.hpp"
#include "Ingot.hpp"
#include "Ore.hpp"

class CopperOre final : public Ore, public ISmeltable {
public:
    CopperOre();
    bool BreakableBy(Pickaxe pickaxe) override;
    std::shared_ptr<Ingot> Smelt() override;
};

#endif
