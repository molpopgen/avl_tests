#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <gsl/gsl_rng.h>

using namespace std;

int
main(int argc, char** argv)
{
    vector<pair<double, double>> m;
    gsl_rng* r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, 42);
    m.reserve(1000);
    for (size_t i = 0; i < 10000000; ++i)
        {
            auto a = gsl_rng_uniform(r);
            auto b = gsl_rng_uniform(r);
            m.push_back(make_pair(a, b));
            // m[i] = -1.0*static_cast<double>(i);
            // m.emplace(i,-1.*static_cast<double>(i));
        }
    sort(m.begin(), m.end());
    m.erase(unique(m.begin(), m.end()), m.end());
    cout << m.size() << '\n';
    try
        {
            for (auto&& mi : m)
                {
                    if (std::isnan(mi.first))
                        {
                            throw std::runtime_error("oops");
                        }
                }
        }
    catch (...)
        {
        }
}
