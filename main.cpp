#include <cnl/all.h>

#include <iostream>

int main() {
    using namespace cnl::literals;
    auto pi = cnl::fixed_point{CNL_INTMAX_C(133628573008120843482460046645233847912)} >> 125_c;
    std::cout << pi << '\n';
    return 0;
}
