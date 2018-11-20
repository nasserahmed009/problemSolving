#include "pch.h"
#include <iostream>
#include "Shape3D.h"
#include "Cuboid.h"
#include "Sphere.h"
#include <algorithm>
using namespace std;
int main()
{
	Cuboid* c1 = new Cuboid(3, 4, 5, 1, 1, 1);
	Cuboid* c2 = new Cuboid(2, 5, 7, 2, 3, 4);

	Sphere* s1 = new Sphere(4, 0, 0, 0);
	Sphere* s2 = new Sphere(6, 0, 0, 0);
	Sphere* s3 = new Sphere(10, 0, 0, 0);

	Shape3D* shapes[5] = { c1,c2,s1,s2,s3 };

	//Printing all the volumes
	for (int i = 0; i < 5; i++) {
		cout << shapes[i]->calculateVolume() << endl;
	}

	cout << endl;
	//Calculating and printing the max volume
	double maxVolume = 0;
	for (int i = 0; i < 4; i++) {
		int state = shapes[i]->compare(shapes[i + 1]);
		if (state == 1) {
			maxVolume = max(shapes[i]->calculateVolume(), maxVolume);
		}
		else if (state == -1) {
			maxVolume = max(shapes[i + 1]->calculateVolume(), maxVolume);
		}
		else {
			maxVolume = max(shapes[i]->calculateVolume(), maxVolume);
		}

	}
	cout <<"Max Volume = " << maxVolume <<endl;

	cout << endl;
	//Printing all the areas
	cout << "The areas of the shapes" << endl;
	for (int i = 0; i < 5; i++) {
		cout << shapes[i]->calculateArea() << endl;
	}


	//counting the spheres and cuboids
	cout << endl;
	int spheresNumber = 0;
	int cuboidsNumber = 0;

	for (int i = 0; i < 5; i++) {
		Sphere* pSphere = dynamic_cast<Sphere*>(shapes[i]);
		if (pSphere != NULL) spheresNumber++;
		else cuboidsNumber++;
	}
	cout << "Spheres numbers = " << spheresNumber << endl;
	cout << "Cuboids numbers = " << cuboidsNumber << endl;


	//translating the cuboid and sphere
	c1->TranslateShape(2, 0, -1);
	s2->TranslateShape(-2, 1, 2);

	//print information of cuboids
	cout << endl << "Cuboid 1 Info : " << endl;
	c1->PrintInfo();
	cout << endl << "Cuboid 2 Info : " << endl;
	c2->PrintInfo();

	//print information of spheres
	cout << endl << "sphere 1 Info : " << endl;
	s1->PrintInfo();
	cout << endl << "sphere 2 Info : " << endl;
	s2->PrintInfo();
	cout << endl << "sphere 3 Info : " << endl;
	s3->PrintInfo();
}
