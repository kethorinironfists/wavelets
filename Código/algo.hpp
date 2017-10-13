#ifndef ALGO_HPP_INCLUDED
#define ALGO_HPP_INCLUDED

#include "base.hpp"
#include "pgm.hpp"
#include "general.hpp"

class WaveletDecomposition {
	public: stack < processo > backup;
		int lin_original, col_original;
		int lin, col;
		int cont_lin, cont_col;
		int mx;
		string tipo;
		vvld mat;

		WaveletDecomposition();

		void constroi(PGM p);

		PGM salva();

		void DecompositionLin(int lim1, int lim2);

		void DecompositionCol(int lim1, int lim2);

		void ReconstructLin(int lim1, int lim2);

		void ReconstructCol(int lim1, int lim2);

		void pergunta();

		void Decomposition();

		void Reconstruction();

		void Compression(ld alfa);
};

#endif
