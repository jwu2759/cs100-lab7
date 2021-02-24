#include "factory.hpp"
#include <iostream>

int main(int argv, char* argc[]){
	srand(time(0));
	Factory f;
	Base* b = f.parse(argc,argv);
	std::cout << "EVALUATED: " << b->evaluate() << " STRINGIFY: " << b->stringify() << std::endl;
	delete b;
	return 0;
}
