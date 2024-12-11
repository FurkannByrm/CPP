#include "mint.hpp"
#include <ostream>
#include <istream>


std::ostream &operator<<(std::ostream &os, Mint val)
{
    return os<<"["<<val.mval<<"]";
}

std::istream &operator>>(std::istream &is, Mint &m)
{

    return is >> m.mval;
}