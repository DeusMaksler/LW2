#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main(){
	string line;
	getline(cin, line);

	stringstream ss(line);
	string token;
	stack<int> numbers;

	while (getline(ss, token, ' ')) {
		if (token != "") {
			if (token != "+" && token != "-" && token != "*") {
				numbers.push(stoi(token));
			}
			else {
				int operand2 = numbers.top();
				numbers.pop();
				int operand1 = numbers.top();
				numbers.pop();

				int result;
				if (token == "+") result = operand1 + operand2;
				else if (token == "-") result = operand1 - operand2;
				else if (token == "*") result = operand1 * operand2;

				numbers.push(result);
			}
		}
	}

	cout << numbers.top();
}