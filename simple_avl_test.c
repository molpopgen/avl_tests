#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "avl.h"
#include <gsl/gsl_rng.h>

typedef struct
{
    double a;
    double b;
} pair;

static int
comp_pair(const void *a, const void *b)
{
    const pair *a_ = (pair *)a;
    const pair *b_ = (pair *)b;
    int ret = (a_->a > b_->a) - (a_->a < b_->a);
    if (ret == 0)
        {
            ret = (a_->b > b_->b) - (a_->b < b_->b);
        }
    return ret;
}

static void
free_pair(void *p)
{
    pair *p_ = (pair *)p;
    free(p_);
}

int
main(int argc, char **argv)
{
    avl_tree_t *tree = avl_alloc_tree(comp_pair, free_pair);
    size_t i;
    pair *p;
    avl_node_t *node, *irv;
    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, 42);
    int nulls = 0;
    for (i = 0; i < 10000000; ++i)
        {
            p = (pair *)malloc(sizeof(pair));
            p->a = gsl_rng_uniform(r);
            p->b = gsl_rng_uniform(r);
            irv = avl_insert(tree, p);
            if (irv == NULL)
                ++nulls;
        }
    for (node = tree->head; node; node = node->next)
        {
            p = (pair *)node->item;
        }
    printf("%d %d\n", avl_count(tree), nulls);
    gsl_rng_free(r);
    avl_free_tree(tree);
    return 0;
}
