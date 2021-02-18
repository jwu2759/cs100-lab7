#include "base.cpp"
#include <string>

class Factory{
	public:
		Base* parse(char** input, int length){
			//i = 0 is the executable command
			Base* root = nullptr;
			for(int i = 1; i < length; ++i){
				if(input[i] == "+"){
				
				}
				else if(input[i] == "-"){
					
				}
				else if(input[i] == "/"){

				}
				else if(input[i] == "*"){

				}
				else if(input[i] == "**"){

				}
				else{
					
				}
			}
			return root;
		}
};
