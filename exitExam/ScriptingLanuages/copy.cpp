// C++ program to illustrate the deepcopy and shallow copy
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Class of Car
class Car {
public:
	string name;
	vector<string> colors;

	Car(string name, vector<string> colors)
	{
		this->name = name;
		this->colors = colors;
	}
};

int main()
{
	// Create a Honda car object
	vector<string> honda_colors = { "Red", "Blue" };
	Car honda = Car("Honda", honda_colors);

	// Deepcopy of Honda
	Car deepcopy_honda = honda;
	deepcopy_honda.colors.push_back("Green");
	cout << "Deepcopy: ";
	for (string color : deepcopy_honda.colors) {
		cout << color << " ";
	}
	cout << endl << "Original: ";
	for (string color : honda.colors) {
		cout << color << " ";
	}
	cout << endl;

	// Shallow Copy of Honda
	Car* copy_honda = &honda;
	copy_honda->colors.push_back("Green");
	cout << "Shallow Copy: ";
	for (string color : copy_honda->colors) {
		cout << color << " ";
	}
	cout << endl << "Original: ";
	for (string color : honda.colors) {
		cout << color << " ";
	}
	cout << endl;

	return 0;
}
