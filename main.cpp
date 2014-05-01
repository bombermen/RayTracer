#include <iostream>
#include "SceneObject.hpp"

int main(int argc, char ** argv)
{
	SceneObject o;

	std::cout << std::fixed;
	std::cout.precision(4);

	o.scale(Vec4f(1,1,2));
	std::cout << o.getLocalMatrix() << std::endl;
	o.rotateX(3.14159265 / 2);

	std::cout << o.getLocalMatrix() << std::endl;

	float values[] = {0,1,1,3,4,1,-2,0,0,5,0,0,-3,2,6,1};
	Mat4f m(values);
	std::cout << m << std::endl;
	std::cout << m.determinant() << std::endl;
	m.invert();
	std::cout << m << std::endl;
	m.invert();
	std::cout << m << std::endl;

	system("PAUSE");
	return 0;
}