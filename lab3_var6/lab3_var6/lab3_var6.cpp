#include <iostream>
#include <math.h>
#include <string>
using namespace std;

/// <summary>
/// Функция по нахождению суммы элементов одномерного массива.
/// </summary>
void main() {
    setlocale(LC_ALL, "ru-RU"); // установка локального параметра русского языка для всей программы
    int n; // объявление переменной n
    cout << "Введите размер массива" << endl; // вывод сообщения на консоль с просьбой ввести размер массива
    cin >> n; // инициализация n с введенных данных с консоли
    int *array = new int[n](); // выделение динамического массива и установка указателя на его первый элемент
    for (size_t i = 0; i < n; i++)
        array[i] = i; // заполнение массива числами от 0 до n
    int x = 1; // инициализация переменной на величину которой будет производиться переход между элементами
    double root = sqrt(n); // нахождение корня из n
    int sum = 0; // инициализация счетчика для подсчета суммы элементов
    string elements; // объявлие строки, в которую будут записываться просуммированные элементы
    for (size_t i = 0; i < root; i+= x) // цикл for идет до тех пор, пока i, к которому добавляется x при каждой итерации, не достигнет корня из n
    {
        elements += to_string(i + 1) + ", "; // запись номера элемента в строку
        sum += array[i]; // добавление элемента в сумму
        x+= 2; // увеличение x на 2, исходя из условия, где необходимо найти сумму 1-го(x=1), 4-го(x=1+2), 9-го(x=3+2), 16-го(x=5+2),... элементов 
    }
    elements[elements.length() - 2] = ' '; // удаление лишней запятой в конце
    cout << "Сумма элементов " + elements + "равна " + to_string(sum); // вывод сообщения на консоль с суммой элементов и их номерами
}