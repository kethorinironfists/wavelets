#include "algo.hpp"

WaveletDecomposition::WaveletDecomposition() {}

void WaveletDecomposition::constroi(PGM p) {
	lin_original = p.lin;
	col_original = p.col;
	mx = p.mx;
	tipo = p.tipo;

	lin = 1, col = 1;
	while(lin < lin_original) lin += lin;
	while(col < col_original) col += col;
	cout<<lin<<' '<<col<<endl;

	cont_lin = col;
	cont_col = lin;

	mat = vvld(lin, vld(col, 0));
	for(int i=0; i<lin_original; i++) {
		for(int j=0; j<col_original; j++) {
			mat[i][j] = p.mat[i][j];
		}
	}
}

PGM WaveletDecomposition::salva() {
	PGM ret(0);

	ret.tipo = "P2";
	ret.lin = lin_original;
	ret.col = col_original;
	ret.mx = mx;
	ret.mat = vvi(lin_original, vi(col_original, 0));

	for(int i=0; i<lin_original; i++) {
		for(int j=0; j<col_original; j++) {
			ret.mat[i][j] = max((int)mat[i][j], 0);
		}
	}

	return ret;
}


void WaveletDecomposition::DecompositionLin() {
	backup.push(monta('L', lin, col));

	for(int i=0; i<lin; i++) {
		vld v(col);
		for(int j=0; j<col; j++) {
			v[j] = mat[i][j];
		}
		VectorDecomposition(v);
		for(int j=0; j<col; j++) {
			mat[i][j] = v[j];
		}
	}
}

void WaveletDecomposition::DecompositionCol() {
	backup.push(monta('C', col, lin));

	for(int j=0; j<col; j++) {
		vld v(lin);
		for(int i=0; i<lin; i++) {
			v[i] = mat[i][j];
		}
		VectorDecomposition(v);
		for(int i=0; i<lin; i++) {
			mat[i][j] = v[i];
		}
	}
}

void WaveletDecomposition::ReconstructLin(int lim1, int lim2) {
	for(int i=0; i<lim1; i++) {
		vld v(lim2);
		for(int j=0; j<lim2; j++) {
			v[j] = mat[i][j];
		}
		VectorReconstruction(v);
		for(int j=0; j<lim2; j++) {
			mat[i][j] = v[j];
		}
	}
}

void WaveletDecomposition::ReconstructCol(int lim1, int lim2) {
	for(int j=0; j<lim1; j++) {
		vld v(lim2);
		for(int i=0; i<lim2; i++) {
			v[i] = mat[i][j];
		}
		VectorReconstruction(v);
		for(int i=0; i<lim2; i++) {
			mat[i][j] = v[i];
		}
	}
}

void WaveletDecomposition::pergunta() {
	cout<<"Deseja salvar o processo em seu estado atual? (y/n): ";
	char c;
	cin>>c;
	if(c == 'y') {
		cout<<"Digite o nome da imagem: ";
		string s;
		cin>>s;

		PGM ret = salva();
		ret.salva(s);
	}
}

void WaveletDecomposition::Decomposition() {
	cout<<"Decompondo a imagem..."<<endl;

	while(lin > 1 and col > 1) {
		DecompositionLin();

		pergunta();

		DecompositionCol();

		pergunta();

		lin /= 2;
		col /= 2;
	}

	while(col > 1) {
		DecompositionLin();
		col /= 2;
	}

	while(lin > 1) {
		DecompositionCol();
		lin /= 2;
	}
}

void WaveletDecomposition::Reconstruction() {
	cout<<"Reconstruindo a imagem..."<<endl;

	while(!backup.empty()) {
		processo p = backup.top();
		backup.pop();
		if(p.tipo == 'L') {
			ReconstructLin(p.principal, p.secundario);
		}
		else {
			ReconstructCol(p.principal, p.secundario);
		}
		
		pergunta();
	}
}
