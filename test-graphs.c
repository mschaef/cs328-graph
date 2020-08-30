#include <stddef.h>

#include "graph.h"

struct graph *testgraph_alloc() {
     struct graph *g = graph_alloc(100, 100);

     graph_node na = graph_add_node(g, "A");
     graph_node nb = graph_add_node(g, "B");
     graph_node nc = graph_add_node(g, "C");
     graph_node nd = graph_add_node(g, "D");
     graph_node ne = graph_add_node(g, "E");

     graph_add_edge(g, na, nb);
     graph_add_edge(g, nb, nc);
     graph_add_edge(g, nc, nd);
     graph_add_edge(g, nd, ne);
     graph_add_edge(g, ne, na);

     graph_add_edge(g, na, nd);
     graph_add_edge(g, nb, ne);

     return g;
}

