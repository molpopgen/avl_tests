#include <map>
#include <utility>
#include <cstdint>
using namespace std;

int main(int argc, char ** argv)
{
    map<double,double> m;

    for(size_t i=0;i<10000000;++i)
    {
        m.emplace(i,-1.*static_cast<double>(i));
    }
    for(auto && mi : m)
    {
        mi;
    }
}
