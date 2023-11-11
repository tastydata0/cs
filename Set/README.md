# std::set в C++

## Введение

`std::set` - это контейнер, который хранит уникальные элементы в отсортированном порядке. Он реализован в виде красно-черного дерева, что обеспечивает быстрый доступ к элементам и поддерживает логарифмическую сложность для операций вставки, удаления и поиска.

## Подключение

Для использования `std::set` необходимо подключить заголовочный файл `<set>`:

```c++
#include <set>
using namespace std;
```

## Создание и инициализация

Создание пустого `std::set`:

```c++
set<int> mySet;
```

Создание `std::set` с начальными значениями:

```c++
set<int> mySet = {1, 2, 3};
```

## Вставка элементов

Вставка элемента в `std::set`:

```c++
mySet.insert(4);
```

Вставка нескольких элементов в `std::set`:

```c++
mySet.insert({5, 6, 7});
```

## Удаление элементов

Удаление элемента из `std::set`:

```c++
mySet.erase(4);
```

Удаление всех элементов из `std::set`:

```c++
mySet.clear();
```

## Поиск элементов
Поиск элемента в `std::set` при помощи `count()`:

```c++
if (mySet.count(3)) {
    cout << "Element found" << endl;
} else {
    cout << "Element not found" << endl;
}
```

Метод `count()` возвращает количество элементов в `std::set`, равных заданному значению. Если элемент найден, то метод вернет 1, иначе - 0.

Поиск элемента в `std::set` на итераторах:

```c++
auto it = mySet.find(3);
if (it != mySet.end()) {
    cout << "Element found: " << *it << endl;
} else {
    cout << "Element not found" << endl;
}
```

## Итерация по элементам

Итерация по элементам `std::set`:

```c++
for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    cout << *it << endl;
}
```
Итерация по элементам `std::set` при помощи цикла `foreach`:

```c++
for (const auto& element : mySet) {
    cout << element << endl;
}
```

Цикл `foreach` позволяет проходить по элементам контейнера без явного использования итератора. Ключевое слово `const` перед ссылкой на элемент гарантирует, что элементы не будут изменены в процессе итерации.
## Размер и пустота

Получение размера `std::set`:

```c++
cout << "Size: " << mySet.size() << endl;
```

Проверка на пустоту `std::set`:

```c++
if (mySet.empty()) {
    cout << "Set is empty" << endl;
} else {
    cout << "Set is not empty" << endl;
}
```

## Пример использования

```c++
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> mySet = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    cout << "Size: " << mySet.size() << endl;

    cout << "Elements: ";
    for (const auto& element : mySet) {
        cout << element << " ";
    }
    cout << endl;

    auto it = mySet.find(5);
    if (it != mySet.end()) {
        cout << "Element found: " << *it << endl;
    } else {
        cout << "Element not found" << endl;
    }

    mySet.erase(5);

    cout << "Size: " << mySet.size() << endl;

    cout << "Elements: ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    mySet.clear();

    if (mySet.empty()) {
        cout << "Set is empty" << endl;
    } else {
        cout << "Set is not empty" << endl;
    }

    return 0;
}
```

## Вывод

`std::set` - это удобный и эффективный контейнер для хранения уникальных элементов в отсортированном порядке. Он обеспечивает быстрый доступ к элементам и поддерживает логарифмическую сложность для операций вставки, удаления и поиска.