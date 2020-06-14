#include <cnl/all.h>

#include <array>
#include <cstdlib>

using coord = cnl::elastic_scaled_integer<24, -16>;
using point = std::array<coord, 2>;
using namespace cnl::literals;

int mandelbrot(point const c, int const limit)
{
    point z{};

    for (auto iterations = 0; iterations!=limit; ++iterations) {
        using intermediate = cnl::elastic_scaled_integer<31, -16>;
        intermediate r{z[0]*z[0]-z[1]*z[1]+c[0]};
        intermediate i{2_elastic*z[0]*z[1]+c[1]};
        auto mag_squared = r*r+i*i;
        if (mag_squared>intermediate{4}) {
            return iterations;
        }
        z[0] = r;
        z[1] = i;
    }

    return limit;
}

int main()
{
    constexpr auto width = 79;
    constexpr auto height = 49;
    constexpr auto limit = 94;
    for (auto row = 0; row!=height; ++row) {
        for (auto col = 0; col!=width; ++col) {
            point c {{
                coord{col}*4/(width-1)-2,
                coord{row}*4/(height-1)-2
            }};
            auto const iterations = mandelbrot(c, limit);
            auto const r = (iterations==limit) ? ' ' : ' '+iterations;
            std::putchar(r);
        }
        std::putchar('\n');
    }
}
