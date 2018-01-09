#include <unordered_map>
#include <utility>
#include <cstdint>
using namespace std;

int main(int argc, char ** argv)
{
    unordered_map<double,double> m;
    m.reserve(10000000);
    for(size_t i=0;i<10000000;++i)
    {
        m.insert(make_pair(i,-1*static_cast<double>(i)));
        //m[i] = -1.0*static_cast<double>(i);
        //m.emplace(i,-1.*static_cast<double>(i));
    }
}

