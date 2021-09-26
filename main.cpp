#include <iostream>
#include <cstring>
#include "Complex.cpp"
#include <cstdio>
#include <set>

int main(){

	double re1(0), im1(0), re2(0), im2(0);
	char ch(' ');
	char command[20] = {0};
	std::set<const char*> valid_commands = {"c", "a", "s", "m", "d", "e", "bth", "exit"};
	do{
		do ch = getchar(); while(ch == ' ' || ch == '\n' || ch == '\t');
		if(ch == EOF) return 0;
		else ungetc(ch, stdin);
		scanf("%s", command);
		if(valid_commands.count(command)) {
			if(strcmp(command,"bth")==0){
				std::cout << Complex(re1, im1).bth(Complex(re2, im2)) << std::endl;
			}
			else if(strcmp(command,"e")==0) {
				std::cout << Complex(re1, im1).equ(Complex(re2, im2)) << std::endl;
			}
			else if(strcmp(command, "exit")==0) return 0;
			else {
				scanf("%lf%lf", &re1, &im1);
				if(strcmp(command, "c") != 0) scanf("%lf%lf", &re2, &im2);
				Complex(re1, im1).exec(command, Complex(re2, im2)).print();
			}
		} else {
			std::cout << "wrong input" << std::endl;
			while((ch = getchar()) != '\n');
		}
	} while(strcmp(command,"exit"));
	return 0;
}
