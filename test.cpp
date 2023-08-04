#include <iostream>

#include "priori/mapping/HilbertCurve.h"
#include "priori/Graphical.h"
#include "priori/BMPLibrary.h"

using namespace std;
using namespace priori;

int main(){
	int a = 0, b = 0, c = 0, d = 0;
	int top = 256;
	int length = pow(top, 4);

	HilbertCurve<Color> curve(length);
	auto it = curve.begin();
	for(int ia = 0; ia < top; ia++)
		for(int ib = 0; ib < top; ib++)
			for(int ic = 0; ic < top; ic++)
				for(int id = 0; id < top; id++){

				}
}
