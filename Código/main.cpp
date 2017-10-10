#include "biblioteca.hpp"

int main() {
	BUFF;

	PGM p(0);
	p.le("cu.pgm");

	WaveletDecomposition wd;

	wd.constroi(p);
	wd.Decomposition();
	wd.Reconstruction();

	return 0;
}
