#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

int main() {
	pair<int,string> p = {5, "Not changed"};
	string &s = p.second;
	s = "Hahaha";

	cout << p.second << '\n';
}
