// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>  // для роботи з файлами
using namespace std;

int main() {
    // Відкрити файл для зчитування
    ifstream inputFile("matrix.txt");
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл matrix.txt" << endl;
        return 1;
    }

    // Ініціалізація матриці 4x4
    int matrix[4][4];

    // Змінні для обчислення суми та підрахунку елементів, кратних 5
    int sum = 0;
    int count = 0;

    // Зчитування матриці з файлу
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            inputFile >> matrix[i][j];  // Зчитування кожного елемента
            // Перевірка, чи елемент кратний 5
            if (matrix[i][j] % 5 == 0) {
                sum += matrix[i][j];  // Додати до суми
                count++;              // Збільшити лічильник
            }
        }
    }

    // Закриваємо файл
    inputFile.close();

    // Обчислення середнього арифметичного
    if (count > 0) {
        double average = static_cast<double>(sum) / count; // Використання static_cast для точності
        cout << "Середнє арифметичне елементів, кратних 5: " << average << endl;
    }
    else {
        cout << "Немає елементів, кратних 5." << endl;
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
