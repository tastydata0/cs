# Массивы в C++

Массивы в C++ представляют собой структуры данных, которые позволяют хранить коллекцию элементов одного и того же типа. Массивы обладают фиксированным размером, который определяется в момент создания, и каждый элемент массива имеет свой уникальный индекс.

## Создание массивов

### Способ 1: Объявление массива с явным указанием размера (95% случаев)

```cpp
#include <iostream>
using namespace std;

int main() {
    int myArray[5]; // Объявление массива из 5 элементов типа int
    myArray[0] = 10; // Присвоение значения первому элементу
    myArray[1] = 20; // Присвоение значения второму элементу
    // ...
}
```

### Способ 2: Инициализация массива при объявлении (5% случаев)

```cpp
#include <iostream>
using namespace std;

int main() {
    int myArray[] = {10, 20, 30, 40, 50}; // Создание и инициализация массива
}
```

## Ввод и работа с элементами массива

```cpp
#include <iostream>
using namespace std;

int main() {
    int myArray[5];

    // Ввод элементов массива с клавиатуры
    for (int i = 0; i < 5; i++) {
        cout << "Введите элемент " << i << ": ";
        cin >> myArray[i];
    }

    // Вывод элементов массива
    for (int i = 0; i < 5; i++) {
        cout << "Элемент " << i << ": " << myArray[i] << endl;
    }
}
```

## Размер массива

Размер массива не хранится в самом массиве. Вы должны помнить или отслеживать его отдельно. Если вы выходите за границы массива, это может привести к непредсказуемому поведению программы или ошибкам.

### Какого размера тогда создавать массивы в задачах?

Допустим, в задаче вводится N чисел. При этом всегда пишут предел N, например 100.

> Вы просто создаёте массив на максимально возможное кол-во элементов (тут это 100). И работаем только с первыми N элементами (например 10, тогда остальные 90 просто не будут использованы.)

## Техническая работа с массивами

Массивы в памяти компьютера хранятся последовательно, и каждый элемент имеет свой уникальный адрес. Индексация массива - это способ получения доступа к элементам, используя их индексы. Например, для массива `myArray`, `myArray[0]` обращается к первому элементу, `myArray[1]` ко второму и так далее.

Массивы в C++ - это непрерывные области памяти, и при выходе за пределы массива может произойти переписывание данных в соседних областях памяти, что может привести к ошибкам и нестабильной работе программы. Будьте осторожны при работе с массивами и всегда проверяйте индексы перед доступом к элементам.
И да, можно сделать массив массивов. Это будет двумерный массив(таблица). Можно пойти и дальше. Но это уже другая история...

<img src="https://i.stack.imgur.com/Tbe9W.png">


# Самостоятельная работа

Вы живете в эпоху киберпанка, и так сложилось, что ищете уязвимости в сетях. Cоздайте программу, которая помогает выбирать уязвимую сеть.

Из знаний прошлого:
> Каждая сеть имеет ключ, состоящий из 5 чисел. Если сеть использует древний "WPA" и наибольшее число ключа чётное, а наименьшее делится на 3, то эта сеть уязвима для эксплоита *<данные удалены>*.



Запрашивайте у пользователя кол-во сетей данные о беспроводных сетях в формате: ```ИмяСети ТипЗащиты Ключ1 Ключ2 Ключ3 Ключ4 Ключ5 ```

Пример ввода:

```
10
NeonCipher WPA 56 78 92 104 45
QuantumMesh WEP 75 88 64 92 77
CipherWave WPA2 95 112 80 63 101
BinaryStream WPA 84 98 73 110 63
QuantumLink WPA2 70 91 104 82 99
ElectricWave WPA 62 77 88 99 56
StealthNet WPA2 75 92 68 107 40
DarkConnect WEP 80 105 78 93 110
DigitalShadow WPA 72 88 95 78 101
QuantumFlare WPA2 100 115 88 96 77
```

Вывод делайте по своему усмотрению, но нужно вывести имя сети и все её ключи. А формат зависит от вашего воображения.

Пример:
```
! Уязвимость: NeonCipher, Ключи: 56 78 92 104 45
! Уязвимость: BinaryStream, Ключи: 84 98 73 110 63
```

- Постарайтесь сделать так, что если шифрование не подходит, то вы вообще не проверяете ключ, а сразу идёте дальше.
- За оформление вывода с цветами и прочими штучками в стиле киберпанка полагаются доп. баллы !

<img src="https://steamuserimages-a.akamaihd.net/ugc/1661224712069230981/BFD6A13BBBF6F1A2A7FA6A6DA961E0700E98660A/?imw=512&amp;imh=288&amp;ima=fit&amp;impolicy=Letterbox&amp;imcolor=%23000000&amp;letterbox=true">