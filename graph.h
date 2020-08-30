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

struct graph *graph_alloc(size_t node_pool_bytes, size_t edge_pool_entries);

void graph_free(struct graph *g);

void graph_show(struct graph *g);

graph_node graph_add_node(struct graph *g, char *name);

void graph_add_edge(struct graph *g, graph_node from, graph_node to);
