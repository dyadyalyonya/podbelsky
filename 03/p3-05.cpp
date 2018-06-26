//p3-05.cpp - переопределение внешнего имени внутри блока
#include <iostream>

using namespace std;

int main() {

int k = 0, j = 15;

	{
		cout << "\n\nВнешняя для блока переменная k = " << k;
		char k = 'A'; // определена внутренняя переменная
		cout << "\nВнутренняя переменная k = " << k;
		cout << "\nВидимая в блоке переменная j = " << j;
		j = 30; // изменили значение внешней переменной
	} 

cout << "\nВне блока: k = " << k << ", j = " << j << endl;

return 0;
}
