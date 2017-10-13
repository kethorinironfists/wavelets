#ifndef BASE_HPP_INCLUDED
#define BASE_HPP_INCLUDED

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>
#include <cassert>
#include <cmath>

#define BUFF ios::sync_with_stdio(false)

using namespace std;

typedef vector < int > vi;
typedef vector < vi > vvi;

typedef long double ld;
typedef vector < ld > vld;
typedef vector < vld > vvld;

typedef pair < char, pair < int, int > > processo;

#define tipo first
#define principal second.first
#define secundario second.second
#define monta(a, b, c) make_pair(a, make_pair(b, c))

#endif
