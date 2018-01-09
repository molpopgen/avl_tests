#include <unordered_map>
#include <utility>
#include <cstdint>
#include <gsl/gsl_rng.h>

using namespace std;

int
main(int argc, char** argv)
{
    unordered_map<double, double> m;
    m.reserve(10000000);
    gsl_rng* r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, 42);
    m.reserve(1000);
    for (size_t i = 0; i < 10000000; ++i)
        {
            auto a = gsl_rng_uniform(r);
            auto b = gsl_rng_uniform(r);
            m.insert(make_pair(a, b));
            // m[i] = -1.0*static_cast<double>(i);
            // m.emplace(i,-1.*static_cast<double>(i));
        }
    gsl_rng_free(r);
}
