#include <iostream>
using namespace std;

const int SIZE{ 100 };
int A[SIZE];
int index; //current last element

int packedUnsorted_search(int a) {
	for (int i{ index }; i >= 0; i--) {
		if (A[i] == a) {
			return i;
		}
	}
	return -1;
}

int main() {
	index = -1;
	char ch{};
	while (ch != 'q') {
		cout << "Array" << endl;
		for (int i{}; i <= index; i++) cout << i << "\t";
		cout << endl;
		for (int i{}; i <= index; i++) cout << A[i] << "\t";
		cout << endl;

		cout << "Enter the option: ";
		cin >> ch;

		if (ch == 's') {
			int a;
			cin >> a;

			int result;
			result = packedUnsorted_search(a);

			if (result == -1) cout << a << " is not in array." << endl;
			else cout << a << " is at " << result << "." << endl;
		}
		else if (ch == 'i') {
			int a;
			cin >> a;

			if (packedUnsorted_search(a) != -1) {
				cout << a << " is already stored." << endl;
			}
			else {
				if ((index + 1) == SIZE) {
					cout << "The array is already full." << endl;
				}
				else {
					index++;
					A[index] = a;
				}
			}
		}
		else if (ch == 'd') {
			int a;
			cin >> a;

			int index_a{};
			index_a = packedUnsorted_search(a);

			if (index == -1) {
				cout << "The array is empty." << endl;
			}

			else if (index_a == -1) {
				cout << a << " is not stored in array." << endl;
			}

			else {
				if (index == index_a) index--;
				else {
					for (int i{ index_a + 1 }; i <= index; i++) {
						A[i - 1] = A[i];
					}
					index--;
				}
			}
		}
	}
	return 0;
}
