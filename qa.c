#include <stdio.h>
#include <math.h>

int main () {
        //int x = 0;

	for (int x = -100000; x < 7000; x++){

		//1. x + 100 = n^2, x + 100 + 168 = m^2
		float n = sqrt(x+100);
		float m = sqrt(x+100+168);

		if ( n == round(n) && m == round (m) ) {
			printf("\nx is %d\n",x);

		} //if
	} //for


} //main
