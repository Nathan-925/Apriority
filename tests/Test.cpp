/*
 * Test.cpp
 *
 *  Created on: Dec 29, 2022
 *      Author: Nathan
 */
#include <iostream>

#include "priori/Graphical.h"

using namespace std;
using namespace priori;

int main(){
	Color color(0x11ABCDEF);
	cout << hex << (int)color.r << " " << (int)color.g << " " << (int)color.b << " " << (int)color.a << endl;
}
