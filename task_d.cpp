#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	string line;
	getline(cin, line);
	
	const char* symbols = line.c_str();
	stack<char> brackets;
	int size = line.length();

	for (int i = 0; i < size; i++) {
		char token = symbols[i];
		if (token != ' ') {
			if (token == '(' || token == '{' || token == '[') brackets.push(token);
			else if (brackets.empty() && (token == ')' || token == '}' || token == ']')) brackets.push(token);
			else {
				if (token == ')' && brackets.top() == '(') brackets.pop();
				else if (token == '}' && brackets.top() == '{') brackets.pop();
				else if (token == ']' && brackets.top() == '[') brackets.pop();
				else brackets.push(token);
			}
		}
	}

	std::cout << (brackets.empty() ? "yes" : "no");
}