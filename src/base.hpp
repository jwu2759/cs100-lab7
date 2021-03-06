#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include <sstream>
#include <cmath>

class Base {
    public:
        /* Constructors */
        Base() { }

        virtual ~Base() {}
    
        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
};


class Op : public Base {
    //private variable for value
    private: 
	double val;
	std::ostringstream strs;
    public:
        Op(double value) : Base() {
          	val = value;
		strs << val;
  	}
	virtual ~Op(){}
   	virtual double evaluate() { return val; }
   	virtual std::string stringify() { return strs.str(); }
};

class Mult : public Base{
   private:
      Base* left = 0;
      Base* right = 0;
   public: 
      Mult(Base* x1, Base* x2) : Base(){
	 left = x1;
	 right = x2;
      }   
      ~Mult() {
	 delete left;
	 delete right;	
      }
      virtual double evaluate(){
	 return left->evaluate() * right->evaluate();
      }
      virtual std::string stringify(){
	 return "(" + left->stringify() + "*" + right->stringify() + ")";
      }
};

class Add : public Base{
   private:
      Base* leftChild = 0; 
      Base* rightChild = 0;
   public:
      Add(Base* child1, Base* child2) : Base(){
          leftChild = child1;
          rightChild = child2;
      }
      ~Add() {
	 delete leftChild;
	 delete rightChild;	
      }
      virtual double evaluate(){
	return leftChild->evaluate() + rightChild->evaluate();
	}
      virtual std::string stringify(){
	return "(" + leftChild->stringify() + "+" + rightChild->stringify() + ")";
	}

};

class Sub : public Base {
	private:
		Base* left = 0;
		Base* right = 0;
	public:
		Sub(Base* c1, Base* c2) {
			left = c1;
			right = c2;
		}

      ~Sub() {
	 delete left;
	 delete right;	
      }

		virtual double evaluate(){
			return left->evaluate() - right->evaluate();
		}
		virtual std::string stringify(){
			return "(" + left->stringify() + "-" + right->stringify() + ")";
		}
};

class Div : public Base{
   private:
      Base* left = 0;
      Base* right = 0;
   public:
      Div(Base* child1, Base* child2) : Base(){
         left = child1;
	 right = child2;
      }
      ~Div() {
	 delete left;
	 delete right;	

      }
      virtual double evaluate(){
	 return left->evaluate() / right->evaluate();
      }
      virtual std::string stringify(){
	 return "(" + left->stringify() + "/" + right->stringify() + ")";
      }

};

class Pow : public Base {
	private:
		Base* left = 0;
		Base* right = 0;
	public:
		Pow(Base* l, Base* r){
			left = l;
			right = r;
		}

      ~Pow() {
	 delete left;
	 delete right;	
      }

		virtual double evaluate(){
			return pow(left->evaluate(),right->evaluate());
		}
		virtual std::string stringify(){
			return "(" + left->stringify() + "**" + right->stringify() + ")";
		}
};

class Rand : public Base{
   private:
      double val;
      std::ostringstream str;
   public:
      Rand() : Base(){
         val = (double)(std::rand() % 100);
         str << val;
      }
      virtual double evaluate(){return val;}
      virtual std::string stringify(){return str.str();}
};


#endif



