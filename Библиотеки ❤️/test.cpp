// Нужно скачать этот файл и поместить рядом с вашим. Ссылка на репозиторий:
// https://github.com/agauniyal/rang

// Команда терминала для скачивания файла на реплите/линуксе/маке:
// curl -O https://raw.githubusercontent.com/agauniyal/rang/master/include/rang.hpp

#include "rang.hpp"
#include <iostream>

using namespace std;
using namespace rang;

int main()
{
    cout << "Обычный текст" << endl;

    cout << style::bold << "Жирный текст" << style::reset << endl;

    cout << style::crossed << "Зачеркнутый текст" << style::reset << endl;

    cout << style::italic << fg::green << "Зеленый текст курсивом" << style::reset
         << endl;

    cout << style::underline << style::bold << fg::magenta << bgB::cyan
         << "Подчеркнутый фиолетовый жирный текст с ярким голубым фоном"
         << style::reset << endl;

    cout << style::bold << bg::red << fg::gray << "RANG!!" << style::reset
         << endl;

    cout << fg::gray << "╔════╦═══════════════╗\n";
    cout << "║ ";
    cout << style::bold << style::italic << fg::reset << "HP " << style::reset;
    cout << fg::gray << "║ ";
    cout << bg::red << fg::gray << " 80/100   " << style::reset << "    " << fg::gray << "║" << endl;
    cout << fg::gray << "╚════╩═══════════════╝\n";

    cout << fg::gray << "╔════╦═══════════════╗\n";
    cout << "║ ";
    cout << style::bold << style::italic << fg::reset << "AP " << style::reset;
    cout << fg::gray << "║ ";
    cout << bg::blue << fg::gray << " 5/5         " << style::reset << fg::gray << " ║" << endl;
    cout << fg::gray << "╚════╩═══════════════╝\n";
}