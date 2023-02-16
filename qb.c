#include <stdio.h>


int main () {
	//loop from 1-1000
	for (int i = 1; i < 1000; i++) {
		int s = 0;
		for (int j = 1; j < i; j++) {
			if (i%j == 0) {

			s += j;
			}//if

		} // for j

		if (s == i) {

		printf ("\nPerfect Number %d\n",i);
		} //if


	} //for i



} //main
