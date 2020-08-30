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
void graph_add_undirected_edge(struct graph *g, graph_node n1, graph_node n2);

int graph_get_all_nodes(struct graph *g, size_t lim, graph_node buf[]);

int graph_get_next_nodes(struct graph *g, graph_node from, size_t lim, graph_node buf[]);

size_t graph_get_node_count(struct graph *g);
