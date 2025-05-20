#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "ICraftable.hpp"
#include "Ingot.hpp"

class Diamond final : public Ingot, public ICraftable {
public:
    Diamond();
    Armor CraftArmor() override;
};

#endif
