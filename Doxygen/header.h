#include <iostream>
#include <fstream>

using namespace std;

/// @brief Функция, суммирующая 2 числа
/// @param a первое слагаемое
/// @param b второе слагаемое
/// @return Сумма a и b
int sum(int a, int b);

/// @brief Считывание содержимого файла
/// @param filename - имя файла относительно рабочей директории, либо абсолютный путь к файлу
/// @return Указатель на строку в динамической памяти с содержимым файла
string* readFile(const string& filename);

/// @brief Функция создания файла
/// @param filename - имя файла относительно рабочей директории, либо абсолютный путь к файлу
inline void createFile(const string& filename);

