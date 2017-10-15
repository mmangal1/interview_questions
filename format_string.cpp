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
			opening_chars_stack.push(*cstr);
			cstr++;
		}else{
			if( (!opening_chars_stack.empty()) && (opening_chars_stack.top() == corresponding_chars_map[*cstr])){
				opening_chars_stack.pop();
				cstr++;
			}
			else{
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

void fix_invalid_string(std::string s){
	//implement fix right as we go along
	std::cout << s << std::endl;
	std::string valid_string = "";

	std::stack<int> opening_chars_stack;
	std::map<char, char> corresponding_chars_map;

	corresponding_chars_map['}'] = '{';
	corresponding_chars_map[')'] = '(';
	corresponding_chars_map[']'] = '[';

	int index = 0;
	int len = s.length();
	std::cout << "len = " << len << std::endl;
	while(index < len){
		if(s[index] >= '0' && s[index] <= '9'){
			valid_string += s[index];
		}
		else if(s[index] == '{' || s[index] == '(' || s[index] == '[' ){
			valid_string += s[index];
			opening_chars_stack.push(s[index]);

		}else{
			if( !opening_chars_stack.empty() && (opening_chars_stack.top() == corresponding_chars_map[s[index]])){
				valid_string += s[index];
				opening_chars_stack.pop();
			}
			else{
				valid_string += corresponding_chars_map[s[index]];
			//	opening_chars_stack.push(corresponding_chars_map[s[index]]);
				valid_string += s[index];
			}
		}
		index++;
	}

	while(!opening_chars_stack.empty()){
		char open_char = opening_chars_stack.top();
		opening_chars_stack.pop();
		if(open_char == '{'){
			valid_string += '}';
		}
		else if(open_char == '['){
			valid_string += ']';
		}
		if(open_char == '('){
			valid_string += ')';
		}
	}
	
	std::cout << valid_string << std::endl << std::endl;
	
}

int main(){

/*	
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
*/

	std::string s1 = "{123]";
	fix_invalid_string(s1);
	s1 = "{123)";
	fix_invalid_string(s1);
	s1 = "{123}]1[";
	fix_invalid_string(s1);
	s1 = "{123(4})";
	fix_invalid_string(s1);
	s1 = "}123(4})";
	fix_invalid_string(s1);
	s1 = "({)";
	fix_invalid_string(s1);
	s1 = "(12)";
	fix_invalid_string(s1);

	return 0;
}

