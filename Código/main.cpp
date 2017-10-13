#include "biblioteca.hpp"

int main() {
	BUFF;

	PGM p(0);
	p.le("lena.pgm");

	ld a[] = {0.01, 0.10, 0.20, 0.50};
	string b[] = {"01.pgm", "10.pgm", "20.pgm", "50.pgm"};

	for(int i=0; i<4; i++) {

		WaveletDecomposition bode;
		bode.constroi(p);
		bode.Decomposition();
		bode.Compression(a[i]);
		bode.Reconstruction();

		PGM r = bode.salva();
		r.salva(b[i]);
	}

	return 0;
}
