#include "Furnace.hpp"

#include <stdexcept>

Furnace::Furnace() {}
void Furnace::SetInput(std::shared_ptr<ISmeltable> input) {
    this->input = input;
};
void Furnace::Smelt() {
    if (input == nullptr || output != nullptr)
        throw std::runtime_error("");
    output = input->Smelt();
    input = nullptr;
};
std::shared_ptr<Ingot> Furnace::GetOutput() {
    if (output == nullptr)
        throw std::runtime_error("");
    return output;
};
