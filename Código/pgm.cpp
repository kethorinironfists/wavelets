#include "pgm.hpp"

PGM::PGM(int n) {}

void PGM::le(string s) {
	ifstream f_in;
	f_in.open(s.c_str());
	assert(f_in.is_open());
	f_in>>tipo;

	char prim = '0';

	do {
		f_in.ignore(256, '\n');
		prim = f_in.get();
	} while(prim == '#');

	string aux;
	f_in>>aux>>lin>>mx;

	col = prim - '0';
	for(int i=0; i<aux.size(); i++) {
		col = col * 10 + aux[i] - '0';
	}

	mat = vvi(lin, vi(col));
	for(int i=0; i<lin; i++) {
		for(int j=0; j<col; j++) {
			f_in>>mat[i][j];
		}
	}

	f_in.close();
}

void PGM::cria(vvi m) {
	lin = m.size();
	col = m[0].size();
	mx = 255;
	tipo = "P2";
	mat = vvi(lin, vi(col));

	for(int i=0; i<lin; i++) {
		for(int j=0; j<col; j++) {
			mat[i][j] = m[i][j];
		}
	}
}

void PGM::deb() {
	cout<<tipo<<endl;
	cout<<lin<<' '<<col<<endl;
	cout<<mx<<endl;
}

void PGM::salva(string s) {
	ofstream f_out;
	f_out.open(s.c_str());
	assert(f_out.is_open());

	f_out<<tipo<<endl;
	f_out<<"#Criado por Nicao e Diury"<<endl;

	f_out<<col<<' '<<lin<<endl<<mx<<endl;
	for(int i=0; i<lin; i++) {
		for(int j=0; j<col; j++) {
			f_out<<mat[i][j]<<' ';
		}
		f_out<<endl;
	}

	f_out.close();
}
