#ifndef GOLD_INGOT_HPP
#define GOLD_INGOT_HPP

#include "ICraftable.hpp"
#include "Ingot.hpp"

class GoldIngot final : public Ingot, public ICraftable {
public:
    GoldIngot();
    Armor CraftArmor() override;
};

#endif
