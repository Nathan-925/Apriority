#include <iostream>

#include "priori/mapping/HilbertCurve.h"
#include "priori/Graphical.h"
#include "priori/BMPLibrary.h"

using namespace std;
using namespace priori;

int main(){
	cout << "start" << endl;

	int length = 1024;
	Color* line = new Color[length];
	HilbertCurve<Color> curve(line, length);

	int tileWidth = 10;
	Image img(pow(2, curve.order), pow(2, curve.order));
	auto pos = make_pair(0, 0);
	for(auto it = curve.begin(); it < curve.end(); it++){
		auto nextPos = getHilbertPosition(it.pos, curve.order);
		drawLine(img, *it,
			pos.first*tileWidth+tileWidth/2, pos.second*tileWidth+tileWidth/2,
			nextPos.first*tileWidth+tileWidth/2, nextPos.second*tileWidth+tileWidth/2);
		pos = nextPos;
	}

	writebmp("test.bmp", img);
	cout << "end" << endl;
}