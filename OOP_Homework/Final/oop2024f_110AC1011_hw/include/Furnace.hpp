#ifndef FURNACE_HPP
#define FURNACE_HPP

#include <memory>

#include "ISmeltable.hpp"
#include "Ingot.hpp"

class Furnace final {
private:
    std::shared_ptr<ISmeltable> input = nullptr;
    std::shared_ptr<Ingot> output = nullptr;

public:
    Furnace();
    void Smelt();

    void SetInput(std::shared_ptr<ISmeltable> input);
    std::shared_ptr<Ingot> GetOutput();

private:
};

#endif
