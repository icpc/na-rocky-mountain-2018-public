#ifndef BOUNDS_H
#define BOUNDS_H

int ipow(int a,int b){ return (b == 0 ? 1 : a * ipow(a,b-1)); }

const int MIN_N = 7, MAX_N = ipow(7,3);
const int MIN_M = 7, MAX_M = ipow(7,4);
const int MIN_D = 1, MAX_D = ipow(7,5);

#endif
