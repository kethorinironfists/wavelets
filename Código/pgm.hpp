#ifndef PGM_HPP_INCLUDED
#define PGM_HPP_INCLUDED

#include "base.hpp"

class PGM {
		public:
			string tipo;
			int lin, col;
			int mx;
			vvi mat;

			PGM(int n);

			void le(string s);

			void cria(vvi m);

			void deb();

			void salva(string s);
};

#endif
