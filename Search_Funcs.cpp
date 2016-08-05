#ifndef ATTACH_H
#include "Attach.h"
#endif

int search_funcs::linear_search(double position, double *node_list, int n_nodes)
{
	// Search a list of nodes using linear search algorithm
	// This function will return the number of the element containing position
	// node_list[ the_element ] < position < node_list[ the_element + 1 ]
	// Complexity is O(n)

	int n_elems = n_nodes - 1; // number of elements = number of nodes -1
	int the_element = -1; // this variable will store the element number

	double eps = 1.0e-12; // use eps to test for equality of floating point numbers

	if(position < node_list[1] || position > node_list[n_nodes]){

		// test to see if the position is actually inside the mesh
	
		cout<<position<<" is outside the mesh"<<node_list[1]<<" < x < "<<node_list[n_nodes]<<endl;

	}
	else{

		// search the node list by checking each element in turn
		for(int m = 1; m<=n_elems; m++){

			if(fabs(position - node_list[m]) < eps){
				// test to see if position = node_list[m]
				the_element = m; 
				break;
			}
			else if(position > node_list[m] && position < node_list[m+1]){
				// test to see if node_list[m] < position < node_list[m+1]
				cout<<position<<" is in element "<<node_list[m]<<" < x < "<<node_list[m+1]<<endl;
				cout<<"This is element number "<<m<<endl;
				cout<<"Position was found after "<<m<<" linear search steps\n\n"; 
				the_element = m; 
				break;
			}
			else{
				continue; 	
			}

		}

	}

	return the_element;
}

int search_funcs::binary_search(double position, double *node_list, int n_nodes)
{
	// Search a list of nodes using binary search algorithm
	// This function will return the number of the element containing position
	// node_list[ the_element ] < position < node_list[ the_element + 1 ]
	// Complexity is O(log n), much faster than linear search

	int n_elems = n_nodes - 1; // number of elements = number of nodes -1
	int the_element = -1; // this variable will store the element number
	int low = 1, middle = 0, high = n_nodes; 
	int iter = 0; // use this to count the number of iterations of bin search alg. 

	double eps = 1.0e-12; // use eps to test for equality of floating point numbers

	if(position < node_list[1] || position > node_list[n_nodes]){

		// test to see if the position is actually inside the mesh
	
		cout<<position<<" is outside the mesh"<<node_list[1]<<" < x < "<<node_list[n_nodes]<<endl;

	}
	else{
		// search the mesh using binary search

		while(low <= high){
			middle = low + (high - low)/2; 

			if(fabs(position - node_list[middle]) < eps){
				// test to see if position = node_list[m]
				cout<<position<<" is in element "<<node_list[middle]<<" < x < "<<node_list[middle+1]<<endl;
				cout<<"This is element number "<<middle<<endl;
				cout<<"Position was found after "<<iter<<" binary search steps\n\n"; 
				the_element = middle; 
				break;
			}
			else if(position > node_list[middle] && position < node_list[middle+1]){
				// test to see if node_list[m] < position < node_list[m+1]
				cout<<position<<" is in element "<<node_list[middle]<<" < x < "<<node_list[middle+1]<<endl;
				cout<<"This is element number "<<middle<<endl;
				cout<<"Position was found after "<<iter<<" binary search steps\n\n"; 
				the_element = middle; 
				break;
			}
			else if(position < node_list[middle]){
				high = middle - 1; 
			}
			else{
				low = middle + 1 ; 
				//cout<<position<<" is not in element "<<node_list[middle]<<" < x < "<<node_list[middle+1]<<endl;
			}

			iter++; 
		}
	}
	
	return the_element; 
}