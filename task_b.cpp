#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	queue<string> nine;
	queue<string> ten;
	queue<string> eleven;

	string line;

	while (getline(cin, line)) {
		if (line == "stop") break;

		int spaceIndex = line.find(' ');
		string degree = line.substr(0, spaceIndex);
		string surename = line.substr(spaceIndex + 1);

		if (degree == "9") { nine.push(surename);}
		else if (degree == "10") { ten.push(surename);}
		else if (degree == "11") { eleven.push(surename);}
	}

	while (!nine.empty()) {
		auto el = nine.front();
		cout << "9 " << el << '\n';
		nine.pop();
	}
	while (!ten.empty()) {
		auto el = ten.front();
		cout << "10 " << el << '\n';
		ten.pop();
	}
	while (!eleven.empty()) {
		auto el = eleven.front();
		cout << "11 " << el << '\n';
		eleven.pop();
	}
}