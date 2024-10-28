#include "iostream"
#include "limits"
#include "string"
using namespace std;
// Вариант 15: unsigned int и long double

union UniInt {
	unsigned int unit;
	unsigned char bit[sizeof(unsigned int)];
};

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
	unsigned char* str = reinterpret_cast<unsigned char*>(&number);
	int size = sizeof(long double);
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 7; j >= 0; j--) {
			cout << ((str[i] >> j) & 1);
		}
		if (i == size - 2) cout << ".";
		cout << "|";
	}
	cout << endl;
}

unsigned int ShiftUniInt(unsigned int uniint) {
	
	return uniint;
}

long double ShiftLonDue(long double londue) {
	
	return londue;
}

int main() {
	setlocale(LC_ALL, "RU");
	unsigned int uniint;
	long double londue;
	int shift, littleint, littledouble;
	bool left;
	string arrow;
	cout << "Введите число типа unsigned int\n";
	cin >> uniint;
	cout << "Введите число типа long double\n";
	cin >> londue;
	cout << "\n";
	cout << "Двоичное представление unsigned int:\n";
	UniIntBinaryTranslate(uniint);
	cout << "\n";
	cout << "Двоичное представление long double:\n";
	LonDueBinaryTranslate(londue);
	cout << "\n";
	cout << "Преобразования\n";
	// Выполнить циклический сдвиг в заданную пользователем сторону на некоторое количество разрядов в пределах определённой группы разрядов, количество которых и номер младшего разряда в группе задаются с клавиатуры
	cout << "Введите количество разрядов для сдвига:\n";
	cin >> shift;
	cout << "Введите младший разряд для unsigned int (0-31):\n";
	cin >> littleint;
	cout << "Введите младший разряд для long double (0-79):\n";
	cin >> littledouble;
	cout << "Введите сторону сдвига:\n";
	cout << "l - влево, r - вправо\n";
	cin >> arrow;
	if (arrow == "l" or arrow == "left")
		left = true;
	else if (arrow == "r" or arrow == "right")
		left = false;
	else
		return 1;
	cout << "Преобразованное число типа unsigned int\n";
	cout << "Преобразованное число типа long double\n";
}