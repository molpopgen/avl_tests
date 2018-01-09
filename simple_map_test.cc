#include <map>
#include <utility>
#include <cstdint>
#include <gsl/gsl_rng.h>

using namespace std;

int
main(int argc, char **argv)
{
    map<double, double> m;
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, 42);

    for (size_t i = 0; i < 10000000; ++i)
        {
            auto a = gsl_rng_uniform(r);
            auto b = gsl_rng_uniform(r);
            m.emplace(a, b);
        }
    for (auto &&mi : m)
        {
            mi;
        }
    gsl_rng_free(r);
}
