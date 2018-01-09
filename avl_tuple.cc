#include "avl.h"
#include <cstdlib>
#include <tuple>
#include <cstdio>
#include <gsl/gsl_rng.h>

using namespace std;

using ttype = std::tuple<double, double>;

static int
cmp_ttype(const void *a, const void *b)
{
    const ttype *ta = static_cast<const ttype *>(a);
    const ttype *tb = static_cast<const ttype *>(b);

    int x = (get<0>(*ta) > get<0>(*tb)) - (get<0>(*ta) < get<0>(*tb));
    if (x == 0)
        {
            x = (get<1>(*ta) > get<1>(*tb)) - (get<1>(*ta) < get<1>(*tb));
        }
    return x;
}

static void
free_ttype(void *p)
{
    ttype *p_ = (ttype *)p;
    delete(p_);
}

int
main(int argc, char **argv)
{
    avl_tree_t *tree = avl_alloc_tree(cmp_ttype, free_ttype);
    size_t i;
    ttype *p;
    avl_node_t *node;

    gsl_rng* r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, 42);
    for (i = 0; i < 10000000; ++i)
        {
            auto a = gsl_rng_uniform(r);
            auto b = gsl_rng_uniform(r);
            p = new ttype(make_tuple(a,b));
            avl_insert(tree, p);
        }
    for (node = tree->head; node; node = node->next)
        {
            p = (ttype *)node->item;
        }
    printf("%d\n", avl_count(tree));
    gsl_rng_free(r);
    avl_free_tree(tree);
}
