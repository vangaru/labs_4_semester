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
        push    string   // ���������� �������� s � ����� 
        call    strlen   // ��������� ����� ������ (��� ���������� � eax)
        add sp, 4        
        mov ecx, eax     // ���������� � ecx �������� eax (����� ������) 
        dec ecx          // �������� 1 �� ecx
        mov esi, string  // ����� ������ ������
        mov edi, esi    
        lodsb            // ��������� � eax ���������� esi
        push    eax      // ���������� �������� eax � �����
        rep movsb        // �������� �������� ���� �� ������ esi � ���� �� ������ edi ���� ecx �� ������ ����� 0
        pop eax          
        stosb            // ���������� ���������� eax � ���� �� ������ edi
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
