#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

#define GRAPH_MAGIC 0x4c567668

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

     g->node_count = 0;

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

#ifdef DEBUG
     printf("graph (%p) {\n", g);
     printf("   node_pool_bytes = %zu\n", g->node_pool_bytes);
     printf("   edge_pool_entries = %zu\n", g->edge_pool_entries);
     printf("   node_pool = %p..%p\n", g->node_pool, g->node_pool_end);
     printf("   edge_pool = %p..%p\n", g->edge_pool, g->edge_pool_end);
#else
     printf("graph {\n");
#endif

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
     g->node_count++;

     return n;
}

void graph_add_edge(struct graph *g, graph_node from, graph_node to) {
     assert_graph(g);

     g->edge_pool_end->from = from;
     g->edge_pool_end->to = to;

     g->edge_pool_end++;
}

void graph_add_undirected_edge(struct graph *g, graph_node n1, graph_node n2) {
     graph_add_edge(g, n1, n2);
     graph_add_edge(g, n2, n1);
}

int graph_get_all_nodes(struct graph *g, size_t lim, graph_node buf[]) {
     assert_graph(g);

     size_t count = 0;

     graph_node n = g->node_pool;

     while(*n) {
          assert(count < lim);

          buf[count] = n;

          count++;

          n = graph_next_node(g, n);
     }

     return count;
}

int graph_get_next_nodes(struct graph *g, graph_node from, size_t lim, graph_node buf[]) {
     assert_graph(g);

     size_t count = 0;

     struct graph_edge *e = g->edge_pool;

     while(e->from) {

          if (e->from == from) {
               assert(count < lim);
               buf[count] = e->to;
               count++;
          }

          e++;
     }

     return count;
}

size_t graph_get_node_count(struct graph *g) {
     assert_graph(g);

     return g->node_count;
}
