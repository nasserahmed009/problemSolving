#include "pch.h"
#include <iostream>
using namespace std;

class course {
	int code;
	public:
		course(int x) {
			code = x;
		}
};

class teacher {
	course* courserArray[5];
	int count;
	public:
		teacher() {
			count = 0;
		}
		void addCourse(course* pC) {
			courserArray[count] = pC;
			count++;
		}
};

int main()
{
	/*course c1(100);
	course c2(200);
	course c3(300);
	
	teacher t1;
	t1.addCourse(&c1);*/
	
	int x = 5;
	int y = 6;

	int* arr1[2];
	int* arr2[2];


	arr1[0] = &x;
	arr1[1] = &y;

	arr2[0] = arr1[0];
	arr2[1] = arr1[1];

	cout << **arr2;
}
