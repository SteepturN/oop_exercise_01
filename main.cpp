#include <iostream>
#include <string>
#include "Complex.cpp"
#include <cstdio>
#include <set>

int main(){

	Complex c1(0,0), c2(0,0);
	char ch(' ');
	char command[20] = {0};
	std::set<std::string> valid_commands = {"c", "a", "s", "m", "d", "e", "bth", "exit"};
	do{
		if(get_command(valid_commands, command) == EOF) return 0;
		while(get_double(c1.a) && get_double(c1.b));
		if(command != "c") while(get_double(c2.a) && get_double(c2.b));
		if(command == "bth"){
			if(get_complex_num(c1) == EOF || get_complex_num(c2) == EOF) return 0;
			std::cout << Complex(re1, im1).bth(Complex(re2, im2)) << std::endl;
		}
		else if(command == "e") {
			std::cout << Complex(re1, im1).equ(Complex(re2, im2)) << std::endl;
		}
		else if(command == "exit") return 0;
		else {
			Complex(re1, im1).exec(command, Complex(re2, im2)).print();
		}
	} while(strcmp(command,"exit"));
	return 0;
}

char get_command(std::set<const char*>& valid_commands, std::string& command)
{
	char ch(0);
	while(true)
	{
		std::cin >> ch;
		if(ch == EOF) return EOF;
		else ungetc(ch, stdin);
		std::cin >> command;
		if(valid_commands.count(command)) return 0;
		else {
			std::cin.ignore(10000, '\n')
			std::cout << "wrong input" << std::endl;
		}
	}
}
char get_complex_num(Complex& c1)
{
	double a(0), b(0);
	char ch(0);
	//can be better< have no time
	std::cin >> ch;
	if(ch == EOF) return EOF;
	else ungetc(ch, stdin);
	std::cin >> a;
	if(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "wrong input\n";
		

	}
	std::cin >> b;
        if(std::cin.fail())
        {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "wrong input\n";
        }
	c1.a = a; c1.b = b;
	return 0;
}

