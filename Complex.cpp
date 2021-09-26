//var 1
#include <iostream>
class Complex{
	public:
	Complex(double a, double b)
	:	a(a), b(b) {};
	double a;
	double b;
	
	Complex add(const Complex& c){
		return Complex(a+c.a, b+c.b);
	}
	Complex sub(const Complex& c){
		return Complex(a-c.a, b-c.b);
        }
	Complex mul(const Complex& c){
		return Complex(a*c.a-b*c.b, a*c.b+b*c.a);
        }
	Complex div(const Complex& c){
		return Complex((a*c.a+b*c.b)/(c.a*c.a+c.b*c.b), (b*c.a-a*c.b)/(c.a*c.a+c.b*c.b));
        }
	bool equ(const Complex& c){
		return (a==c.a) && (b==c.b);
        }
	Complex conj(){
		return Complex(a, -b);
        }
	bool bth(const Complex& c){
		return (a*a+b*b) > (c.a*c.a+c.b*c.b);
        }
	void print(){
		std::cout << '(' << a << ',' << b << ')' << std::endl;
	}
};
