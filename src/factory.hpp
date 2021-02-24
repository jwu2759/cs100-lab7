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
			root = new Op(strtod(input[i++], NULL));
			//NEED TO ADD RAND FUNCTIONALITY
			while(i + 1 < length){
				if(strcmp(input[i],"+") == 0){
					temp = root;
					++i;
					if(input[i] == "R")
						root = new Add(temp,new Rand());
					else
						root = new Add(temp,new Op(strtod(input[i],NULL)));
				}
				else if(strcmp(input[i],"-") == 0){
					temp = root;
					root = new Sub(temp,new Op(strtod(input[++i],NULL)));
				}
				else if(strcmp(input[i],"/") == 0){
					temp = root;
					root = new Div(temp,new Op(strtod(input[++i],NULL)));
				}
				else if(strcmp(input[i],"*") == 0){
					temp = root;
					root = new Mult(temp,new Op(strtod(input[++i],NULL)));
				}
				else if(strcmp(input[i],"**") == 0){
					temp = root;
					root = new Pow(temp,new Op(strtod(input[++i],NULL)));
				}
				else{
					++i;
				}
			}
			return root;
		}
};

