# Циклы в C++

Циклы в языке программирования C++ позволяют выполнять одну и ту же последовательность команд несколько раз. В C++ существует два основных типа циклов: циклы `for` и циклы `while`.

## Цикл `while` в C++

Цикл `while` в языке программирования C++ позволяет выполнять блок кода, пока заданное логическое условие истинно. Этот цикл очень похож на условный оператор `if`, но в отличие от `if`, цикл `while` выполняется многократно, пока условие остается истинным.

### Синтаксис цикла `while`:

```cpp
while (условие) {
    // Тело цикла
}
```

### Пример цикла `while`:

```cpp
int count = 0;
while (count < 5) {
    cout << "Итерация " << count << endl;
    count++;
}
```

> Итерация - одно очередное повторение цикла.

В этом примере, цикл `while` выполняется, пока переменная `count` меньше 5. После каждой итерации значение `count` увеличивается на 1.

### Аналогия с условным оператором `if`:

Можно сравнить цикл `while` с условным оператором `if`. Вот аналогия:

- `if` выполняется ОДИН раз при выполнении определенного условия:

  ```cpp
  if (условие) {
      // Блок кода
  }
  ```

- `while` выполняется СКОЛЬКО УГОДНО раз, пока условие истинно:
  ```cpp
  while (условие) {
      // Блок кода
  }
  ```

## Циклы for (со счетчиком)

Цикл `for` представляет собой управляемый цикл, который выполняется определенное количество раз. Он состоит из трех основных частей:

```cpp
for (инициализация; условие; выражение) {
    // Тело цикла
}
```

- **Инициализация**: Выполняется один раз при входе в цикл и инициализирует переменные, используемые в цикле.
- **Условие**: Выполняется перед каждой итерацией цикла. Если условие истинно, цикл продолжает выполняться. Если условие ложно, цикл завершается.
- **Выражение**: Выполняется после каждой итерации и может использоваться для изменения переменных управления циклом.

#### Сравнение `for` и `while`:

В этом примере оба цикла выполняются 5 раз, но цикл `for` предоставляет более компактный способ задания начального значения, условия и шага счетчика.

<table>
<tr>
<td> while </td> <td> for </td>
</tr>
<tr>
<td>

```cpp
int i = 0;
while (i < 5) {
    cout << "Итерация " << i << endl;
    i++;
}
```

</td>
<td>

```cpp
for (int i = 0; i < 5; i++) {
    cout << "Итерация " << i << endl;
}
```

</td>
</tr>

</table>

<center>
<img src="https://i.redd.it/4npl9yfg5js11.jpg" width=60%>
</center>

### Пример с задачей FizzBuzz

Задача FizzBuzz - это популярная задача на программирование. В ней нужно вывести числа от 1 до 100, но если число делится на 3, вывести "Fizz", если на 5 - "Buzz", а если и на 3, и на 5 - "FizzBuzz".

<center><img src="https://code.kx.com/q/img/fizzbuzz.png"></center>

Вот как это может быть решено с использованием цикла `for`:

```cpp
for (int i = 1; i <= 100; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
        cout << "FizzBuzz" << endl;
    } else if (i % 3 == 0) {
        cout << "Fizz" << endl;
    } else if (i % 5 == 0) {
        cout << "Buzz" << endl;
    } else {
        cout << i << endl;
    }
}
```

Этот код использует цикл `for` для перебора чисел от 1 до 100 и проверяет условия, чтобы определить, что выводить.

<center><img src="data:image/jpeg;base64,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"></center>

### Бесконечные циклы

Бесконечные циклы - это циклы, которые выполняются бесконечно, так как их условие никогда не становится ложным. Например:

```cpp
while (true) {
    // Этот цикл выполняется бесконечно
}
```

### Прерывание цикла

В циклах можно использовать оператор `break` для прерывания выполнения цикла и выхода из него досрочно, а оператор `continue` для перехода к следующей итерации без завершения всего цикла.

```cpp
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break; // Прервать цикл при i=5
    }
    cout << i << endl;
}
```

Циклы - это мощный инструмент для повторения операций в программе и обработки данных. Они позволяют упростить и структурировать код, делая его более эффективным и читаемым.

### Как получить случайное число?

В начале функции `main` напишите `srand(time(0));` - для установки сида. После этого `rand();` будет давать случайное число. Но оно может выдать большое число, так что можно ограничить его от 1 до 10: `int random = rand() % 10 + 1;`

## Задачи!

1. **Угадай число**:

   Напишите программу, которая загадывает случайное число от 1 до 100, а пользователь должен угадать это число. Программа должна предоставлять подсказки (больше или меньше), пока пользователь не угадает число.

2. **Таблица умножения**:

   Напишите программу, которая выводит таблицу умножения для числа, введенного пользователем. Программа должна выводить результаты умножения от 1 до 10.

3. **Факториал числа**:

   Напишите программу, которая вычисляет факториал введенного пользователем числа. Факториал числа `n` вычисляется как `n! = n * (n-1) * (n-2) * ... * 1`.

4. **Проверка на простоту**:

   Напишите программу, которая проверяет, является ли введенное пользователем число простым (делится только на 1 и само себя).

5. **Сумма ряда чисел**:

   Напишите программу, которая считает сумму ряда чисел от 1 до `n`, где `n` вводится пользователем.

6. **Степень числа**:

   Напишите программу, которая вычисляет, сколько знаков в десятичном числе. Само число вводит пользователь.

## Тренировка

В одном файле напишите все эти циклы. Каждый цикл выводит числа через пробел. После каждого цикла нужно делать перенос строки. Я буду сравнивать посимвольно с эталоном, так что не накосячьте с пробелами и переносом. Пробел после последнего числа в строке ставить можно.

> [!IMPORTANT]
> В самом цикле должен быть только оператор вывода в консоль, ничего более.

Вставьте этот код в main и решайте короткие задачи на понимание циклов:

```cpp
// Пример: Напишите цикл, выводящий числа от 3 до 9 включительно.
// Вы пишете так:
for (int i = 3 i <= 9; i++) {
    cout << i << " ";
}
cout << endl;

// Теперь сами! :)

// Напишите цикл, выводящий числа от -10 до 3 НЕ включительно.


// Напишите цикл, выводящий числа от 0 до 18 НЕ включительно, с шагом 2. Не используйте if.


// Напишите цикл, выводящий числа от 10 до 0 включительно. Да, в обратном порядке. Напишите цикл так, чтобы именно i уменьшалось.


// Напишите цикл, выводящий степени двойки, не превышающие 1024. Начинайте с 2 в степени 0. `pow` не используем :) Тут можно проще.


// Напишите цикл, выводящий числа от 10 до -10 с шагом в -3


// Напишите цикл, который выводит буквы от `'a'` до `'f'` включительно. Напоминаю, в теле цикла - только оператор вывода.


// Напишите цикл, который выводит числа, начиная с 200, а заканчивает свою работу, когда встретит число, которое делится на 19 нацело. Тут давайте без `break`.


// Напишите цикл, который через пробел выводит все цифры числа `1937401230`:


// Напишите цикл, который вводит 6 чисел и выводит для каждого числа его корень, умноженный на 3. Тут, конечно, можно не только оператор вывода в цикле использовать. Вводите в консоль числа: `0 9 4 256 100 7`


// Это счастливая задача! Напишите цикл, который выводит 5 смайликов `:)` через пробел!


// *Дополнительная задача:
// Выводите числа, начиная со 160, пока не встретится число, у которого целый корень. Важно: я тоже знаю, что это 169, но программа должна сама проверять корень на наличие дробной части. То есть числа 169 в программе не должно быть. Подсказка: вспоминайте приведения типов (typecast).

```

> Мне присылайте готовый .cpp файл, я его запускаю и проверяю, что всё выводится правильно.

#### Ответы:

> У вас должно в точности совпадать

```
3 4 5 6 7 8 9
-10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2
0 2 4 6 8 10 12 14 16
10 9 8 7 6 5 4 3 2 1 0
1 2 4 8 16 32 64 128 256 512 1024
10 7 4 1 -2 -5 -8
a b c d e f
200 201 202 203 204 205 206 207 208
0 3 2 1 0 4 7 3 9 1
0 9 4 256 100 7 <-- Это мы ввели с консоли!
0 9 6 48 30 7.93725
:) :) :) :) :)
160 161 162 163 164 165 166 167 168
```
