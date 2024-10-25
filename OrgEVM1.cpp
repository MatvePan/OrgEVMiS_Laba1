#include "iostream"
using namespace std;
// Вариант 15: unsigned int и long double

void UniIntBinaryTranslate(unsigned int number) {
	int size = sizeof(unsigned int)*8;
	for (int i = size-1; i >= 0; i--) {
		cout << ((number >> i) & 1);
		if (i % 8 == 0)
			cout << "|";
	}
	cout << "\n";
}

void LonDueBinaryTranslate(long double number) {
	int size = sizeof(long double);
	unsigned char* str = reinterpret_cast<unsigned char*>(&number);
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 7; j >= 0; j--) {
			cout << ((str[i] >> j) & 1);
		}
		if (i == size - 2)
			cout << ".";
	}
	cout << "\n";
}

int main() {
	setlocale(LC_ALL, "RU");
	unsigned int uniint;
	long double londue;
	int unibit, lonbit;
	cout << "Введите число типа unsigned int\n";
	cin >> uniint;
	cout << "Введите чисор типа long double\n";
	cin >> londue;
	cout << "\n";
	cout << "Двоичное представление unsigned int:\n";
	UniIntBinaryTranslate(uniint);
	cout << "\n";
	cout << "Двоичное представление long double:\n";
	LonDueBinaryTranslate(londue);
	cout << "\n";
	cout << "Преобразования\n";

}