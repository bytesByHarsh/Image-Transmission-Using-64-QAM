#include <iostream>
#include <cmath>
#include <fstream>
#include "tmwtypes.h"
#include "stdlib.h"

using namespace std;

// Genereate Gaussian R.V
// using fstream store R.V in a txt file.

int main() {
	// random seed.
	srand(2);
	
	// length of sequence.
	int n = 1364*2;

	float x1[n], x2[n], x3[n], x4[n], x5[n];
	float y[n];
	
	for (int i = 0; i < n; i++) {
		x1[i] = (float)rand() / (float)RAND_MAX;
		x2[i] = (float)rand() / (float)RAND_MAX;
		x3[i] = (float)rand() / (float)RAND_MAX;
		x4[i] = (float)rand() / (float)RAND_MAX;
		x5[i] = (float)rand() / (float)RAND_MAX;
	
		y[i] = (x1[i] + x2[i] + x3[i] + x4[i] + x5[i]) / n;
	}
	
	// write file.
	ofstream outfile("gnoise.txt");
	
	for (int i = 0; i < n; i++) {
		outfile << y[i] << "\n";
	}
	
	outfile.close();
	cout<<"Size:"<<n<<endl;
	return 0;
}
