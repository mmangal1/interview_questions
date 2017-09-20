#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <stack>


bool is_valid_string(std::string s){
	
	s = std::regex_replace(s, std::regex("[0-9]"), "");

	const char *cstr = s.c_str();
	
	std::stack<char> opening_chars_stack;
	std::map<char, char> corresponding_chars_map;

	corresponding_chars_map['}'] = '{';
	corresponding_chars_map[')'] = '(';
	corresponding_chars_map[']'] = '[';

	while(*cstr){
		if((*cstr) == '{' || (*cstr) == '(' || (*cstr) == '[' ){
	//		std::cout << "Pushing " << *cstr << std::endl;
			opening_chars_stack.push(*cstr);
			cstr++;
		}else{
			if( (!opening_chars_stack.empty()) && (opening_chars_stack.top() == corresponding_chars_map[*cstr])){
	//			std::cout << "Popping " << opening_chars_stack.top()  << " for " << *cstr << std::endl;
				opening_chars_stack.pop();
				cstr++;
			}
			else{
	//			std::cout << "Stack empty" << std::endl;
				return 0;
			}		
		}
	}

	if(!opening_chars_stack.empty()){
		return 0;
	}
	
	//valid string
	return 1;
}

int main(){

	
	std::string s1 = "{[123]}";
	std::cout << s1 << " expected answer: 1,  is_valid() answer: " << is_valid_string(s1) << std::endl;

	//brace inside brace
	s1 = "{[12]{1}(1)4}";
	std::cout << s1 << " expected answer: 1,  is_valid() answer: " << is_valid_string(s1) << std::endl;
	
	//brace inside brace
	s1 = "{123()}";
	std::cout << s1 << " expected answer: 1,  is_valid() answer: " << is_valid_string(s1) << std::endl;
	
	//no numeric
	s1 = "{}";
	std::cout << s1 << " expected answer: 1,  is_valid() answer: " << is_valid_string(s1) << std::endl;

	//ending with a closing brace of another style	
	s1 = "{1254)";
	std::cout << s1 << " expected answer: 0,  is_valid() answer: " << is_valid_string(s1) << std::endl;
	
	//second half of string is incorrect
	s1 = "{1254}]1[";
	std::cout << s1 << " expected answer: 0,  is_valid() answer: " << is_valid_string(s1) << std::endl;
	
	//closing out of order
	s1 = "{123(4})";
	std::cout << s1 << " expected answer: 0,  is_valid() answer: " << is_valid_string(s1) << std::endl;
	
	//dont close first brace
	s1 = "{123(12)";
	std::cout << s1 << " expected answer: 0,  is_valid() answer: " << is_valid_string(s1) << std::endl;

	return 0;
}

