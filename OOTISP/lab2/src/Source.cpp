#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

vector <string> getSentences();

void printSpiral(string);

int main()
{
    vector <string> sentences = getSentences();

    for (int i = 0; i < sentences.size(); i++) {
        printSpiral(sentences[i]);
    }

    return 0;
}


vector <string> getSentences() {

    ifstream in("text.txt");
    string text;

    if (in.is_open()) {
        string word;

        while (!in.eof()) {
            in >> word;
            text.append(word);
            text.append(" ");
        }
    }

    vector <string> sentences;

    string delimiter = ".";

    size_t pos = 0; // Индекс конца предложения(точки)
    string word;
    while ((pos = text.find(delimiter)) != string::npos) { // Пока точки не кончатся
        word = text.substr(0, pos);                        // Добавить предложение
        sentences.push_back(word);
        text.erase(0, pos + delimiter.length());           // Стереть предложение
    }
    
    return sentences;
}


void printSpiral(string str) {
    int n = sqrt(str.length());

    if (str.length() != n * n) {
        string temp = "";
        for (int i = 0; i < (pow((n + 2), 2) - str.length()); i++) {
            temp.append(" ");
        }
        str = temp + str;
        n = sqrt(str.length());
    }

    int m = 0;
    char** a = new char* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new char[n];
    }

    if (n % 2 != 0) {
        a[(n / 2)][(n / 2)] = str[str.length() - 1];  // если N - нечетное то находим центр матрицы и заполняем его последним числом матрицы
    }

    for (int i = 0; i < (n / 2); i++) {
        for (int j = i; j < (n - i); j++) {       // Верхняя грань слева направо 
            a[i][j] = str[m];
            m++;
        }
        for (int j = 1; j < (n - i - i); j++) {   // Правая грань сверху вниз
            a[(j + i)][(n - i) - 1] = str[m];
            m++;
        }
        for (int j = (n - 2) - i; j >= i; j--) {  // Нижняя грань справа налево 
            a[(n - i) - 1][j] = str[m];
            m++;
        }
        for (int j = ((n - i) - 2); j > i; j--) { // Левая грань снизу вверх
            a[j][i] = str[m];
            m++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << a[i][j] << " ";
        }
        cout << a[i][n - 1] << endl;
    }
}



