#ifndef SEARCH_FUNCS_H
#define SEARCH_FUNCS_H

// Declare the linear and binary search functions here
// R. Sheehan 31 - 1 - 2013

namespace search_funcs{

	int linear_search(double position, double *node_list, int n_nodes); // search a list of nodes using linear search

	int binary_search(double position, double *node_list, int n_nodes); // search a list of nodes using binary search

}

#endif