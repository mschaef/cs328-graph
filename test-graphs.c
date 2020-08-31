#include <stddef.h>

#include "graph.h"

struct graph *testgraph_alloc_simple() {
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

struct graph *testgraph_alloc_dodec() {
     struct graph *g = graph_alloc(100, 100);

     graph_node n1  = graph_add_node(g, "1");
     graph_node n2  = graph_add_node(g, "2");
     graph_node n3  = graph_add_node(g, "3");
     graph_node n4  = graph_add_node(g, "4");
     graph_node n5  = graph_add_node(g, "5");
     graph_node n6  = graph_add_node(g, "6");
     graph_node n7  = graph_add_node(g, "7");
     graph_node n8  = graph_add_node(g, "8");
     graph_node n9  = graph_add_node(g, "9");
     graph_node n10 = graph_add_node(g, "10");

     graph_node n11 = graph_add_node(g, "11");
     graph_node n12 = graph_add_node(g, "12");
     graph_node n13 = graph_add_node(g, "13");
     graph_node n14 = graph_add_node(g, "14");
     graph_node n15 = graph_add_node(g, "15");
     graph_node n16 = graph_add_node(g, "16");
     graph_node n17 = graph_add_node(g, "17");
     graph_node n18 = graph_add_node(g, "18");
     graph_node n19 = graph_add_node(g, "19");
     graph_node n20 = graph_add_node(g, "20");

     graph_add_undirected_edge(g, n1 , n2 );
     graph_add_undirected_edge(g, n2 , n3 );
     graph_add_undirected_edge(g, n3 , n4 );
     graph_add_undirected_edge(g, n4 , n5 );
     graph_add_undirected_edge(g, n5 , n1 );
     graph_add_undirected_edge(g, n1 , n6 );
     graph_add_undirected_edge(g, n2 , n8 );
     graph_add_undirected_edge(g, n3 , n10);
     graph_add_undirected_edge(g, n4 , n2 );
     graph_add_undirected_edge(g, n5 , n14);
     graph_add_undirected_edge(g, n6 , n7 );
     graph_add_undirected_edge(g, n7 , n8 );
     graph_add_undirected_edge(g, n8 , n9 );
     graph_add_undirected_edge(g, n9 , n10);
     graph_add_undirected_edge(g, n10, n11);
     graph_add_undirected_edge(g, n11, n12);
     graph_add_undirected_edge(g, n12, n13);
     graph_add_undirected_edge(g, n13, n14);
     graph_add_undirected_edge(g, n14, n15);
     graph_add_undirected_edge(g, n15, n6 );
     graph_add_undirected_edge(g, n7 , n17);
     graph_add_undirected_edge(g, n9 , n18);
     graph_add_undirected_edge(g, n11, n19);
     graph_add_undirected_edge(g, n13, n20);
     graph_add_undirected_edge(g, n15, n16);
     graph_add_undirected_edge(g, n16, n17);
     graph_add_undirected_edge(g, n17, n18);
     graph_add_undirected_edge(g, n18, n19);
     graph_add_undirected_edge(g, n19, n20);
     graph_add_undirected_edge(g, n20, n16);

     return g;
}
