#include <stdio.h>

#include "graph.h"

int main(int argc, char *argv[]) {

     printf("sizeof(int) = %zu, sizeof(size_t) = %zu, sizeof(void *) = %zu\n",
            sizeof(int), sizeof(size_t), sizeof(void *));

     struct graph *g1 = graph_alloc(100, 100);

     graph_show(g1);

     graph_node n1 = graph_add_node(g1, "alpha");
     graph_node n2 = graph_add_node(g1, "beta");

     graph_add_edge(g1, n1, n2);

     graph_show(g1);

     graph_free(g1);


     printf("end run.\n");

     return 0;
}
