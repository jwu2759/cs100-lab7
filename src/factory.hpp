#include "base.hpp"
#include <string.h>
#include <iostream>

class Factory{
	private:
		bool isSymbol(char* s){
			return !(strcmp(s,"+") == 0) ||
				!(strcmp(s,"-") == 0) ||
				!(strcmp(s,"/") == 0) ||
				!(strcmp(s,"*") == 0) ||
				!(strcmp(s,"**") == 0);
		}
		bool isNumber(char* s){
			char* endChar = 0;
			strtod(s, &endChar);
			if(*endChar != '\0' || endChar == s)
				return false;
			return true;
		}
	public:
		Base* parse(char** input, int length){
			//i = 0 is the executable command
			Base* root = nullptr;
			Base* temp = nullptr;
			int i = 1;
			if(strcmp(input[i], "R") == 0)
				root = new Rand();
			else if(isNumber(input[i]))
				root = new Op(strtod(input[i], NULL));
			else{
				std::cout << "INVALID INPUT" << std::endl;
				return root;
			}
			++i;
			//check if its a symbol, if it is, then it is invalid
			while(i < length){
				if(strcmp(input[i],"+") == 0){
					temp = root;
					if(i + 1 >= length){
						std::cout << "INVALID INPUT" << std::endl;
						delete root;
						root = nullptr;
						return root;
					}
					if(strcmp(input[++i], "R") == 0)
						root = new Add(temp,new Rand());
					else if(isNumber(input[i]))
						root = new Add(temp,new Op(strtod(input[i],NULL)));
					else{
						std::cout << "INVALID INPUT" << std::endl;
						delete root;
						root = nullptr;
						return root;
					}
					//if input at the incremented i value is a digit then its not right
					++i;
				}
				else if(strcmp(input[i],"-") == 0){
					temp = root;
					if(i + 1 >= length){
						std::cout << "INVALID INPUT" << std::endl;
						delete root;
						root = nullptr;
						return root;
					}
					if(strcmp(input[++i], "R") == 0)
						root = new Sub(temp,new Rand());
					else if(isNumber(input[i]))
						root = new Sub(temp,new Op(strtod(input[i],NULL)));
					else{
						std::cout << "INVALID INPUT" << std::endl;
						delete root;
						root = nullptr;
						return root;
					}
					++i;
				}
				else if(strcmp(input[i],"/") == 0){
					temp = root;
					if(i + 1 >= length){
						std::cout << "INVALID INPUT" << std::endl;
						delete root;
						root = nullptr;
						return root;
					}
					if(strcmp(input[++i], "R") == 0)
						root = new Div(temp,new Rand());
					else if(isNumber(input[i]))
						root = new Div(temp,new Op(strtod(input[i],NULL)));
					else{
						std::cout << "INVALID INPUT" << std::endl;
						delete root;
						root = nullptr;
						return root;
					}
					++i;
				}
				else if(strcmp(input[i],"*") == 0){
					temp = root;
					if(i + 1 >= length){
						std::cout << "INVALID INPUT" << std::endl;
						delete root;
						root = nullptr;
						return root;
					}
					if(strcmp(input[++i], "R") == 0)
						root = new Mult(temp,new Rand());
					else if(isNumber(input[i]))
						root = new Mult(temp,new Op(strtod(input[i],NULL)));
					else{
						std::cout << "INVALID INPUT" << std::endl;
						delete root;
						root = nullptr;
						return root;
					}
					++i;
				}
				else if(strcmp(input[i],"**") == 0){
					temp = root;
					if(i + 1 >= length){
						std::cout << "INVALID INPUT" << std::endl;
						delete root;
						root = nullptr;
						return root;
					}
					if(strcmp(input[++i], "R") == 0)
						root = new Pow(temp,new Rand());
					else if(isNumber(input[i]))
						root = new Pow(temp,new Op(strtod(input[i],NULL)));
					else{
						std::cout << "INVALID INPUT" << std::endl;
						delete root;
						root = nullptr;
						return root;
					}
					++i;
				}
				else{
					std::cout << "INVALID INPUT" << std::endl;
					delete root;
					root = nullptr;
					break;
				}
			}
			return root;
		}
};
