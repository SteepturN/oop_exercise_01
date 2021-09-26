#include <iostream>
#include <cstring>
#include "Complex.cpp"
#include <cstdio>
int main(){
	double re1(0), im1(0), re2(0), im2(0);
	char ch(' ');
	char command[20];
	do{
		do ch = getchar(); while(ch == ' ' || ch == '\n' || ch == '\t');
		if(ch == EOF) return 0;
		else ungetc(ch, stdin);
		scanf("%s", command);
		if(strcmp(command,"c")==0){
			scanf("%lf%lf", &re1, &im1);
			Complex(re1, im1).conj().print();
		}
		else{
			scanf("%lf%lf%lf%lf", &re1, &im1, &re2, &im2);
			if(strcmp(command,"a")==0){
				Complex(re1, im1).add(Complex(re2, im2)).print();
			}
			else if(strcmp(command,"s")==0){
				Complex(re1, im1).sub(Complex(re2, im2)).print();
			}
			else if(strcmp(command,"m")==0){
				Complex(re1, im1).mul(Complex(re2, im2)).print();
			}
			else if(strcmp(command,"d")==0){
				Complex(re1, im1).div(Complex(re2, im2)).print();
			}
			else if(strcmp(command,"e")==0){
				std::cout << Complex(re1, im1).equ(Complex(re2, im2));
			}
			else if(strcmp(command,"bth")==0){
				std::cout << Complex(re1, im1).bth(Complex(re2, im2)) << std::endl;
			}
			else if(strcmp(command, "exit")==0) return 0;
			else{
				std::cout << "wrong input" << std::endl;
				while((ch = getchar()) != '\n');
			}
		}
	} while(strcmp(command,"exit"));
	return 0;
}
