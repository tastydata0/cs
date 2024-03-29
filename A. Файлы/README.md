# Работа с файлами при помощи ifstream, ofstream в C++

В C++ для работы с файлами используются классы ifstream и ofstream, которые наследуются от базового класса fstream. Класс ifstream используется для чтения данных из файла, а класс ofstream - для записи данных в файл.

## Открытие и закрытие файла

Для открытия файла нужно передать в качестве аргумента имя файла.
После того, как поработали с файлом, его надо закрыть, чтобы не было конфликтов или сообщений от ОС по типу: "Файл не может быть удален, т.к. он открыт в программе"

```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // открытие файла для чтения
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл для чтения!" << endl;
        return 1;
    }

    // открытие файла для записи
    ofstream fout("output.txt");
    if (!fout.is_open()) {
        cout << "Не удалось открыть файл для записи!" << endl;
        return 1;
    }

    // закрытие файлов
    fin.close();
    fout.close();

    return 0;
}
```

## Чтение данных из файла

Для чтения данных из файла используется оператор >> для объекта класса ifstream, то есть как с `cin`. Данные будут считываться до первого пробела, перевода строки или другого разделителя.

```c++
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл для чтения!" << endl;
        return 1;
    }

    string name;
    int age;

    fin >> name >> age;

    cout << "Имя: " << name << endl;
    cout << "Возраст: " << age << endl;

    fin.close();

    return 0;
}
```

## Запись данных в файл

Для записи данных в файл используется оператор << для объекта класса ofstream, то есть как с `cout`.

```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout("output.txt");
    if (!fout.is_open()) {
        cout << "Не удалось открыть файл для записи!" << endl;
        return 1;
    }

    fout << "Hello, world!" << endl;

    fout.close();

    return 0;
}
```

## Проверка конца файла
Оператор >> возвращает значение типа bool, означающее, было ли чтение успешным. Можем написать это в while и иметь цикл, считывающий, например, все числа до конца файла:
```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл для чтения!" << endl;
        return 1;
    }

    int x;

    while (fin >> x) {
        cout << x << " ";
    }

    fin.close();
}
```

> getline работает аналогично:
```c++
// Чтение файла целиком
ifstream fin2("text_fish.txt");
string buffer;
while(getline(fin2, buffer)) {
    cout << buffer << endl;
}
```

## Рабочая директория
Рабочая директория - это текущая директория, в которой выполняется программа. При запуске программы в операционной системе ей автоматически назначается рабочая директория, именно в ней программа будет искать файлы, если их путь не указан явно.

В C++ можно получить путь к рабочей директории с помощью функции getcwd, которая объявлена в заголовочном файле <unistd.h> или <direct.h> в зависимости от операционной системы.

```c++
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    char buf[256];
    getcwd(buf, 256);
    cout << "Рабочая директория: " << buf << endl;
    return 0;
}
```

## Абсолютный путь
Абсолютный путь - это полный путь к файлу от корневой директории. Он всегда начинается с корневой директории и содержит все промежуточные директории до целевого файла.
```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout("/home/user/output.txt");
    if (!fout.is_open()) {
        cout << "Не удалось открыть файл для записи!" << endl;
        return 1;
    }

    fout << "Hello, world!" << endl;

    fout.close();

    return 0;
}
```


## Относительный путь

Относительный путь - это путь к файлу относительно текущей директории или другой директории, которую можно указать явно.

Если файл находится в текущей директории, то его имя можно указать без пути. Если файл находится в директории, расположенной выше текущей директории, то в начале пути нужно указать две точки ".." . Если файл находится в директории, расположенной на том же уровне, что и текущая директория, то в начале пути можно указать точку ".", либо ничего не указывать.
```c++
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout("../output.txt");
    if (!fout.is_open()) {
        cout << "Не удалось открыть файл для записи!" << endl;
        return 1;
    }

    fout << "Hello, world!" << endl;

    fout.close();

    return 0;
}
```

## Переменные окружения
Переменные окружения - это переменные, которые используются операционной системой для хранения информации, которая доступна для всех процессов, выполняемых в данном окружении. В C++ можно получить значение переменной окружения с помощью функции getenv, которая объявлена в заголовочном файле <cstdlib>.

```c++
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    char* home_dir = getenv("HOME");
    if (home_dir != nullptr) {
        cout << "Домашняя директория: " << home_dir << endl;
    } else {
        cout << "Переменная HOME не установлена" << endl;
    }
    return 0;
}
```
## Практика!

Сформировать N файлов, в каждом из которых будет содержаться рандомная информация о человеке (имя, фамилия, адрес, возраст). Пример выходного файла:

```
|=----=| Passport |=----=|
| Full name: John Doe
| Address: Mare Boreum, Boreum Planum, Viking Avenue, House 83
| Age: 28
|=----------------------=|
```

Я дам вам 3 файла: набор имен, набор фамилий и набор адресов. Количество строк в файлах я не дам. Нужно читать так, чтобы прочитать все строки и вовремя остановиться.

Выходные данные:
Программа создает N файлов с названиями 1.txt, 2.txt ...., в каждом из которых содержатся данные об 1 человеке. N вводится с консоли.

Если хотите сделать чуть больше, попробуйте формировать еще email из первых 3-4 букв фамилии и суффиксом "@gmail.com" или типа того.

Имена: `https://pastebin.com/raw/sSTQ4Dq6`

Фамилии: `https://pastebin.com/raw/45LYuuDp`

Адреса: `https://pastebin.com/raw/2zcnJgEv`
