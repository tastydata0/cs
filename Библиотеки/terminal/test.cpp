/*
 * This example shows how to interpret keys presses from Terminal.
 */
#include "terminal.h"

using namespace Term;

int main() {
  // Создаем терминал
  Terminal term(true, false);

  // Получаем его размер
  int terminalSizeY, terminalSizeX;
  term.get_term_size(terminalSizeY, terminalSizeX);
  std::cout << "Terminal size:" << terminalSizeX << "x" << terminalSizeY
            << std::endl;

  // Позиция нашего персонажа
  int my_position = 0;

  std::cout << "Press any key:" << std::endl;

  while (true) {
    // Вводим клавишу. read_key останавливает выполнение до ввода. read_key0 не
    // останавливает и возвращает 0, если ничего не ввели.
    int key = term.read_key();

    // if (key == 0)
    //   continue;

    // Проверяем, что ввели
    if (key == Key::ARROW_LEFT) {
      my_position--;
      std::cout << "Arrow left" << std::endl;
    } else if (key == Key::ARROW_RIGHT) {
      my_position++;
      std::cout << "Arrow right" << std::endl;
    } else if (key == Key::ARROW_UP) {
      std::cout << "Arrow up" << std::endl;
    } else if (key == Key::ARROW_DOWN) {
      std::cout << "Arrow down" << std::endl;
    } else if (key == Key::ESC) {
      std::cout << "ESC" << std::endl;
      break;
    } else if (key >= 'a' && key <= 'z') {
      std::cout << "Key " << (char)key << std::endl;
    }

    // Раскомментируйте код ниже, когда разберетесь с тем, что выше.

    // // Не даем персонажу уйти за пределы
    // if (my_position < 0)
    //   my_position = 0;
    // if (my_position > terminalSizeX - 3)
    //   my_position = terminalSizeX - 3;

    // // Очищаем терминал, выводя достаточно много пустых строк
    // for (int i = 0; i < terminalSizeY; i++) {
    //   std::cout << "\n";
    // }

    // // Отображаем позицию персонажа, печатая перед ним пробелы
    // for (int i = 0; i < my_position; i++) {
    //   std::cout << " ";
    // }
    // std::cout << "me\n";
  }
}
