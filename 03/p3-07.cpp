//p3-07.cpp - файл с текстом программы (модуль)
// Обобщение соглашений о сферах действия и видимости объектов

#include <iostream>

using namespace std;

char dc[] = "Объект 1"; // Глобальный для модуля объект 1
int ex = 33; // Определение с инициализацией

void func1(void)
{ extern int ex; // Описание внешней переменной
  cout << "\nf1:ex = " << ex;
  cout << "\nf1.dc = " << dc; // Виден глобальный объект 1
  
  char dc[] = "Объект 2"; // Локальный для func1() объект 2
  cout << "\nf1.dc = " << dc; // Виден локальный объект 2
      { // Внутренний блок для func1()
        // Виден локальный для func1() объект 2:
        cout << "\nf1.block.dc = " << dc;
        
        // Локализованный в блоке объект 3:
        char dc[] = "Объект 3";
        // Виден локальный объект 3:
        cout << "\nf1.block.dc = " << dc;
        // Виден глобальный объект 1:
        cout << "\nf1.block.::dc = " << ::dc;
      } // Конец блока
      
  // Виден локальный для функции 1() объект 2:
  cout << "\nf1.dc = " << dc;
  // Виден глобальный объект 1:
  cout << "\nf1.::dc = " << ::dc;
} // Конец функции func1()

void func2(char *dc)					// dc - параметр функции
{ cout << "\nf2.parametr.dc = " << dc; // Виден параметр
  // Виден глобальный объект 1:
  cout << "\nf2.::dc = " << ::dc;
      { // Внутренний блок для func2()
        // Локализованный в блоке объект 4:
        char dc[] = "Объект 4";
        // Виден локальный для func2() объект 4:
        cout << "\nf2.dc = " << dc;
      } // конец блока
} // Конец функции func2()

int main(void)
{ 
  // Виден глобальный объект 1:
  cout << "\nfmain.dc = " << dc;
  
  char dc[] = "Объект 5"; // Локальный для MAIN объект 5
  
  func1();
  func2(dc);
  
  // Виден локальный для MAIN() объект 5:
  cout << "\nfmain.dc = " << dc << endl; 
return 0;
}