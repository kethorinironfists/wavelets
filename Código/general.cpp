#include "general.hpp"

void HaarDecomposition(vld &v) {
	int tam = v.size();
	vld ret(tam);

	for(int i=0; i+1<tam; i+=2) {
		ret[i / 2] = (v[i] + v[i + 1]) / 2.0;
		ret[(tam + i) / 2] = (v[i] - v[i + 1]) / 2.0;

	}

	for(int i=0; i<tam; i++) v[i] = ret[i];
}

void HaarReconstruction(vld &v) {
	int tam = v.size();
	vld ret(tam);

	for(int i=0; i+1<tam; i+=2) {
		ret[i] = v[i / 2] + v[(tam + i) / 2];
		ret[i + 1] = v[i / 2] - v[(tam + i) / 2];
	}

	for(int i=0; i<tam; i++) v[i] = ret[i];
}

void VectorDecomposition(vld &v) {
	HaarDecomposition(v);
}

void VectorReconstruction(vld &v) {
	HaarReconstruction(v);
}
