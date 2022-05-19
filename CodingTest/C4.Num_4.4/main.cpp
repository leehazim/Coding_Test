#include <iostream>

unsigned long SameWeight(unsigned long x) {
	short weight;
	unsigned long tmp = x;
	while (tmp) {
		weight += x & 1;
		tmp >>= 1;
	}
	
}