#include "factory.hpp"
#include <iostream>

int main(int argv, char* argc[]){
	Factory f;
	Base* b = f.parse(argc,argv);
	std::cout << "EVALUATED: " << b->evaluate() << " STRINGIFY: " << b->stringify() << std::endl;
	return 0;
}
