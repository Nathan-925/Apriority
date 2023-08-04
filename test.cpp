#include <iostream>

#include "priori/mapping/HilbertCurve.h"
#include "priori/Graphical.h"
#include "priori/BMPLibrary.h"

using namespace std;
using namespace priori;

int main(){
	cout << "start" << endl;

	int length = pow(pow(2, 5), 2);
	Color* line = new Color[length];
	HilbertCurve<Color> curve(line, length);

	int* r = new int[length],
		 *g = new int[length],
		 *b = new int[length];
	for(int i = 0; i < length; i++){
		r[i] = (256.0/length)*i;
		b[i] = (256.0/length)*(length-i-1);
	}
	for(int i = 0; i < length/2; i++)
		g[i] = (256.0/length)*(i+length/2);
	for(int i = length/2; i < length; i++)
		g[i] = (256.0/length)*(length+length/2-1-i);

	for(auto it = curve.begin(); it < curve.end(); it++){
		*it = Color(r[it.pos], g[it.pos], b[it.pos]);
	}

	int tileWidth = 10;
	Image img(pow(2, curve.order)*tileWidth, pow(2, curve.order)*tileWidth);
	for(int i = 0; i < img.width; i++)
		for(int j = 0; j < img.height; j++)
			img[i][j] = 0xFFFFFF;

	for(auto it = curve.begin(); it+1 < curve.end(); it++){
		auto pos = getHilbertPosition(it.pos, curve.order);
		auto nextPos = getHilbertPosition((it+1).pos, curve.order);
		drawLine(img, *it,
			pos.first*tileWidth+tileWidth/2, pos.second*tileWidth+tileWidth/2,
			nextPos.first*tileWidth+tileWidth/2, nextPos.second*tileWidth+tileWidth/2);
		pos = nextPos;
	}

	writebmp("test.bmp", img);
	cout << "end" << endl;

	Image img1(pow(2, curve.order), pow(2, curve.order));
	for(int i = 0; i < img1.width; i++)
		for(int j = 0; j < img1.height; j++)
			img1[i][j] = curve.matrix[i][j];
	writebmp("test1.bmp", img1);

}
