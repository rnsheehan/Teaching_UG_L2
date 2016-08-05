#ifndef ATTACH_H
#include "Attach.h"
#endif

double interpolation::LIP(double x_pos, double *node_list, int n_nodes, int exclude)
{
	// Compute the value of a Lagrange interpolating polynomial at position x_pos
	// relative to the node set node_list
	// R. Sheehan 31 - 1 - 2013

	double p_term = 1.0; // variable to hold a term in the product calculation
	double p_res = 1.0; // variable to hold the result of the product calculation
	double numer, denom; // variables used in the calculation

	for(int i=1; i<=n_nodes; i++){
		
		if(node_list[i] == node_list[exclude]){

			p_term = 1.0;

		}
		else{
			numer = x_pos - node_list[i]; // x - x_{i}

			denom = node_list[exclude] - node_list[i]; // x_{j} - x_{i}
			
			p_term = numer / denom; 
		}

		p_res = p_res * p_term; // compute the product

	}

	return p_res; 
}

double interpolation::LIP_Poly(double x_pos, double *node_list, double *fval_list, int n_nodes)
{
	// Compute the value of the interpolating polynomial that approximates the data set (node_list, fval_list)
	// at some position x_pos
	// R. Sheehan 31 - 1 - 2013

	double LIP_val = 0.0;
	double s_term = 0.0;
	double s_res = 0.0; 

	for(int i=1; i<= n_nodes; i++){

		LIP_val = LIP(x_pos, node_list, n_nodes, i); // Compute the value of the LIP

		s_term = LIP_val * fval_list[i]; // Compute the term in the sum

		s_res = s_res + s_term; // Compute the sum
	}

	return s_res; 
}