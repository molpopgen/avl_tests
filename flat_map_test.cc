#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int
main(int argc, char** argv)
{
    vector<pair<double, double>> m;
    m.reserve(1000);
    for (size_t i = 0; i < 10000000; ++i)
        {
            m.push_back(make_pair(-1 * static_cast<double>(i), i));
            // m[i] = -1.0*static_cast<double>(i);
            // m.emplace(i,-1.*static_cast<double>(i));
        }
    std::sort(m.begin(), m.end());
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
