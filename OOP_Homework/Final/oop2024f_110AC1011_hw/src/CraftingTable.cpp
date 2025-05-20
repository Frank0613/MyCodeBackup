#include "CraftingTable.hpp"

#include <cstddef>
#include <memory>
#include <stdexcept>

CraftingTable::CraftingTable() {}
void CraftingTable::SetInput(std::shared_ptr<ICraftable> input) {
    this->input = input;
}
void CraftingTable::CraftArmor() {
    if (input == nullptr || output != nullptr)
        throw std::runtime_error("");

    output = std::make_shared<Armor>(input->CraftArmor());
    input = nullptr;
}
std::shared_ptr<Armor> CraftingTable::GetOutput() {
    if (output == nullptr)
        throw std::runtime_error("");
    return output;
}