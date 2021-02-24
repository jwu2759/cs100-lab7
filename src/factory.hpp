#include "base.hpp"
#include <string.h>
#include <iostream>

class Factory{
	public:
		Base* parse(char** input, int length){
			//i = 0 is the executable command
			Base* root = nullptr;
			Base* temp = nullptr;
			int i = 1;
			if(strcmp(input[i], "R") == 0)
				root = new Rand();
			else
				root = new Op(strtod(input[i], NULL));
			++i;
			//NEED TO ADD RAND FUNCTIONALITY
			while(i + 1 < length){
				if(strcmp(input[i],"+") == 0){
					temp = root;
					if(strcmp(input[++i], "R") == 0)
						root = new Add(temp,new Rand());
					else
						root = new Add(temp,new Op(strtod(input[i],NULL)));
				}
				else if(strcmp(input[i],"-") == 0){
					temp = root;
					if(strcmp(input[++i], "R") == 0)
						root = new Sub(temp,new Rand());
					else
						root = new Sub(temp,new Op(strtod(input[i],NULL)));
				}
				else if(strcmp(input[i],"/") == 0){
					temp = root;
					if(strcmp(input[++i], "R") == 0)
						root = new Div(temp,new Rand());
					else
						root = new Div(temp,new Op(strtod(input[i],NULL)));
				}
				else if(strcmp(input[i],"*") == 0){
					temp = root;
					if(strcmp(input[++i], "R") == 0)
						root = new Mult(temp,new Rand());
					else
						root = new Mult(temp,new Op(strtod(input[i],NULL)));
				}
				else if(strcmp(input[i],"**") == 0){
					temp = root;
					if(strcmp(input[++i], "R") == 0)
						root = new Pow(temp,new Rand());
					else
						root = new Pow(temp,new Op(strtod(input[i],NULL)));
				}
				else{
					++i;
				}
			}
			return root;
		}
};

