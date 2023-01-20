/*
 * Test.cpp
 *
 *  Created on: Dec 29, 2022
 *      Author: Nathan
 */
#include <iostream>
#include <cmath>

#include "priori/Math.h"
#include "priori/Graphical.h"
#include "priori/BMPLibrary.h"

using namespace std;
using namespace priori;

int main(){
	cout << "start" << endl;
	Image image(400, 400);
	Polygon p;
	int sides = 6;
	double radius = 50;
	Point center(200, 200);
	cout << "loop" << endl;
	for(int i = 0; i < sides; i++)
		p.push_front(Point(radius*cos(i*(2*M_PI/sides))+center.x, radius*sin(i*(2*M_PI/sides))+center.y));
	cout << distance(p.begin(), p.end()) << endl;
	cout << "draw" << endl;
	drawPolygon(image, 0xFF0000, p);
	cout << "write" << endl;
	writebmp("test.bmp", image);
	cout << "end" << endl;
}
