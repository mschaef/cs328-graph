#include <stdio.h>

#include "graph.h"

#include "test-graphs.h"

#define MAX_NODES 100

int path_visited_p(graph_node buf[], size_t path_len, graph_node n) {
     for(size_t ii = 0; ii < path_len; ii++) {
          if (buf[ii] == n) {
               return TRUE;
          }
     }

     return FALSE;
}

int find_hamiltonian1(struct graph *g, size_t lim, graph_node path_buf[], size_t ofs, graph_node at) {

     if (ofs >= lim) {
          return -1;
     }

     if (ofs == graph_get_node_count(g)) {
          return ofs;
     }

     graph_node nodes[MAX_NODES];

     int count = graph_get_next_nodes(g, at, MAX_NODES, nodes);

     for(int ii = 0; ii < count; ii++) {
          graph_node next = nodes[ii];

          if (path_visited_p(path_buf, ofs, next)) {
               continue;
          }

          path_buf[ofs] = next;

          int path_len = find_hamiltonian1(g, lim, path_buf, ofs + 1, next);

          if (path_len >= 0) {
               return path_len;
          }
     }

     return -1;
}

int find_hamiltonian(struct graph *g, size_t lim, graph_node path_buf[]) {
     graph_node nodes[MAX_NODES];

     int count = graph_get_all_nodes(g, MAX_NODES, nodes);

     for(int ii = 0; ii < count; ii++) {
          path_buf[0] = nodes[ii];

          int path_len = find_hamiltonian1(g, lim, path_buf, 1, path_buf[0]);

          if (path_len >= 0) {
               return path_len;
          }

     }

     return -1;
}

int main(int argc, char *argv[]) {

#ifdef DEBUG
     printf("sizeof(int) = %zu, sizeof(size_t) = %zu, sizeof(void *) = %zu\n",
            sizeof(int), sizeof(size_t), sizeof(void *));
#endif

     struct graph *g1 = testgraph_alloc_dodec();

     graph_show(g1);

     graph_node nodes[MAX_NODES];

     int count = find_hamiltonian(g1, MAX_NODES, nodes);

     if (count < 0) {
          printf("Hamiltonian path not found.\n");
     } else {
          printf("Hamiltonian path found: ");

          for(size_t ii = 0; ii < count; ii++) {
               printf("%s ", nodes[ii]);
          }

          printf("\n");
     }

     graph_free(g1);

     printf("end run.\n");

     return 0;
}
