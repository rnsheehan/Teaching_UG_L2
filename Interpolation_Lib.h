#ifndef INTERPOLATION_LIB_H
#define INTERPOLATION_LIB_H

// This library contains functions used to perform polynomial interpolation
// R. Sheehan 31 - 1 - 2013

namespace interpolation{

	// function for computing the value of a LIP relative to some set of nodes
	double LIP(double x_pos, double *node_list, int n_nodes, int exclude);

	// function for computing the value of an interpolating polynomial relative to some data set
	double LIP_Poly(double x_pos, double *node_list, double *fval_list, int n_nodes); 

}

#endif