#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

void drag(char* string) {
    char first = string[0];
    for (int i = 0; i < strlen(string); i++) {
        i == strlen(string) - 1 ? string[i] = first : string[i] = string[i + 1];
    }
}


void drag_asm(char* string)
{
    _asm {
        push    string   // Сохранение значение s в стеке 
        call    strlen   // Посчитать длину строки (Она сохранится в eax)
        add sp, 4        
        mov ecx, eax     // Записываем в ecx значение eax (Длину строки) 
        dec ecx          // Вычитаем 1 из ecx
        mov esi, string  // Адрес начала строки
        mov edi, esi    
        lodsb            // Загружаем в eax содержимое esi
        push    eax      // Сохранение значение eax в стеке
        rep movsb        // Циклично копирует байт по адресу esi в байт по адресу edi пока ecx не станет равен 0
        pop eax          
        stosb            // Пересылаем содержимое eax в байт по адресу edi
    }
};


void main()
{
    char str[] = "hello world";
    drag_asm(str);
    cout << "CPP: " << str << endl;
    clock_t start = clock();
    for(int i = 0; i < 100000; i++)
        drag_asm(str); 
    clock_t finish = clock();
    cout << " Time: " << finish - start << endl;
    char str_2[] = "hello world";
    drag(str_2);
    cout << "ASM: " << str_2 << endl;
    start = clock();
    for(int i = 0; i < 100000; i++)
        drag(str_2);
    finish = clock();
    cout << " Time: " << finish - start << endl;
};
