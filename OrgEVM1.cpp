#include "iostream"
#include "limits"
#include <cmath>
#include <limits>
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

unsigned int ShiftUniInt(unsigned int& uniint, int shift, int little, bool arrow, int bits) {
	unsigned int mask = ((1u << bits) - 1) << little;
	unsigned int cage = (uniint & mask) >> little;
	if (arrow) {
		cage = ((cage << shift) | (cage >> (bits - shift))) & ((1u << bits) - 1);
	}
	else {
		cage = ((cage >> shift) | (cage << (bits - shift))) & ((1u << bits) - 1);
	}
	uniint &= ~mask;
	uniint |= (cage << little);
	return uniint;
}

long double ShiftLonDue(long double& londue, int shift, int little, bool arrow, int bits) {
	uint64_t* p = reinterpret_cast<uint64_t*>(&londue);
	uint64_t mask = (1ull << bits) - 1;
	uint64_t bit = (*p >> little) & mask;
	if (arrow) {
		bit = (bit << shift) | (bit >> (little - shift));
	}
	else {
		bit = (bit >> shift) | (bit << (little - shift));
	}
	*p = (*p & ~(mask << little)) | (bit << little);
	return londue;
}

int main() {
	setlocale(LC_ALL, "RU");
	unsigned int uniint, newint;
	long double londue, newdouble;
	int shift, little, bits;
	int arrow;
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
	// Выполнить циклический сдвиг в заданную пользователем сторону на некоторое количество разрядов в пределах определённой группы разрядов, количество которых и номер младшего разряда в группе задаются с клавиатуры
	cout << "Введите количество разрядов для сдвига:\n";
	cin >> shift;
	cout << "Введите младший разряд:\n";
	cin >> little;
	cout << "Введите количество битов (0-15):\n";
	cin >> bits;
	cout << "Введите сторону сдвига:\n";
	cout << "1 - влево, 2 - вправо\n";
	cin >> arrow;
	if (arrow != 1 or arrow != 2) {
		return 1;
	}
	bool boshiftleft = (arrow == 1);
	newint = ShiftUniInt(uniint, shift, little, boshiftleft, bits);
	newdouble = ShiftLonDue(londue, shift, little, boshiftleft, bits);
	cout << "Преобразованное число типа unsigned int\n";
	cout << newint << "\n";
	cout << "Преобразованное число типа long double\n";
	cout << newdouble << "\n";
}