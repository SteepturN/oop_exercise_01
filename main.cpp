#include <iostream>
#include <string>
#include "Complex.cpp"
#include <cstdio>
#include <set>
#include "Read_input.cpp"

int main(){
	Complex c1(0,0), c2(0,0);
	char ch(' ');
	char command[20] = {0};
	bool exit;
	std::set<std::string> valid_commands = {"c", "a", "s", "m", "d", "e", "bth", "exit"};
	do {
		exit = false;
		do{
			read_return_t answer = get_command(valid_commands, command);
			switch(answer) {
				case END_OF_FILE: return 0;
				case END_OF_LINE: continue;
				case VALID_INPUT: exit = true; break;
				case INVALID_INPUT:
					do ch=getchar(); while((ch != EOF) && (ch != '\n'));
					std::cout << "wrong input" << std::endl;
					if(ch == EOF) return 0;
					else break;
				}
		} while(!exit);
		if(static_cast<std::string>(command) == "exit") return 0;
		if((get_value<double>(c1.a) != VALID_INPUT) || (get_value<double>(c1.b) != VALID_INPUT)) {
			do ch = getchar(); while((ch != EOF) && (ch != '\n'));
			std::cout << "wrong input" << std::endl;
			if(ch == EOF) return 0;
			continue;
		}
		if(static_cast<std::string>(command) != "c") {
			if((get_value<double>(c2.a) != VALID_INPUT) || (get_value<double>(c2.b) != VALID_INPUT)) {
				do ch=getchar(); while((ch != EOF) && (ch != '\n'));
				std::cout << "wrong input" << std::endl;
				if(ch == EOF) return 0;
				continue;
			}
		}
		if(static_cast<std::string>(command) == "c") {
			c1.conj().print();
		} else if (static_cast<std::string>(command) == "bth") {
			std::cout << c1.bth(c2) << std::endl;
		} else if(static_cast<std::string>(command) == "e") {
			std::cout << c1.equ(c2) << std::endl;
		} else {
			c1.exec(command, c2).print();
		}
	} while(true);
	return 0;
}
