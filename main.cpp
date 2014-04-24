#include <iostream>
#include "SceneObject.hpp"

int main(int argc, char ** argv)
{
	SceneObject o;

	std::cout << o.getLocalMatrix() << std::endl;
	o.scale(2);
	o.translate(Vec4f(1));
	std::cout << o.getLocalMatrix() << std::endl;

	system("PAUSE");
	return 0;
}