#ifndef GENERAL_HPP_INCLUDED
#define GENERAL_HPP_INCLUDED

#include "base.hpp"

void HaarDecomposition(vld &v);
void HaarReconstruction(vld &v);

ld GetLim(vld &v, ld alfa);
void JogaFora(vld &v, ld lim);

void VectorDecomposition(vld &v);
void VectorReconstruction(vld &v);

#endif
