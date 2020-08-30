#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRAPH_MAGIC 0x4c567668

typedef char *graph_node;

struct graph_edge {
     graph_node from;
     graph_node to;
};

struct graph {
     int magic;

     size_t node_pool_bytes;
     size_t edge_pool_entries;

     char *node_pool;
     char *node_pool_end;

     struct graph_edge *edge_pool;
     struct graph_edge *edge_pool_end;
};

void assert_graph(struct graph *g) {
     assert(g && g->magic == GRAPH_MAGIC);
}

struct graph *graph_alloc(size_t node_pool_bytes, size_t edge_pool_entries) {

     size_t bytes = sizeof(struct graph)
          + node_pool_bytes
          + sizeof(struct graph_edge) * edge_pool_entries;

     struct graph *g = (struct graph *)malloc(bytes);

     memset(g, 0, bytes);

     g->magic = GRAPH_MAGIC;
     g->node_pool_bytes = node_pool_bytes;
     g->edge_pool_entries = edge_pool_entries;

     g->node_pool = ((char *)g) + sizeof(struct graph);
     g->node_pool_end = g->node_pool;

     g->edge_pool = (struct graph_edge *)(((char *)g) + sizeof(struct graph) + node_pool_bytes);
     g->edge_pool_end = g->edge_pool;

     return g;
}

void graph_free(struct graph *g) {
     assert_graph(g);
     free(g);
}

graph_node graph_next_node(struct graph *g, graph_node n) {
     assert_graph(g);

     assert(n >= g->node_pool);
     assert(n <= g->node_pool_end);

     return n + strlen(n) + 1;
}

void graph_show(struct graph *g) {
     assert_graph(g);

     printf("graph (%p) {\n", g);
     printf("   node_pool_bytes = %zu\n", g->node_pool_bytes);
     printf("   edge_pool_entries = %zu\n", g->edge_pool_entries);
     printf("   node_pool = %p..%p\n", g->node_pool, g->node_pool_end);
     printf("   edge_pool = %p..%p\n", g->edge_pool, g->edge_pool_end);

     printf("   nodes {\n");
     for(graph_node n = g->node_pool; *n; n = graph_next_node(g, n)) {
          printf("        %s\n", n);
     }
     printf("   }\n");

     printf("   edges {\n");
     for(size_t ii = 0; ii < g->edge_pool_entries; ii++) {
          struct graph_edge *e = &g->edge_pool[ii];

          if (!e->from) {
               break;
          }
          printf("        %s -> %s\n", e->from, e->to);
     }
     printf("   }\n");

     printf("}\n");
}

graph_node graph_add_node(struct graph *g, char *name) {
     assert_graph(g);

     strcpy(g->node_pool_end, name);

     graph_node n = g->node_pool_end;

     g->node_pool_end = graph_next_node(g, n);

     return n;
}

void graph_add_edge(struct graph *g, graph_node from, graph_node to) {
     assert_graph(g);

     g->edge_pool_end->from = from;
     g->edge_pool_end->to = to;

     g->edge_pool_end++;
}


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
