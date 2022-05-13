#include "Engine.hpp"

void Engine::print(std::ostream &os) const
{
    CarPart::print(os);
    os << " - " << horsePower << " hp";
}