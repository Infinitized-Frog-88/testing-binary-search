
# Проект для тестирования бинарного поиска

## Описание
Этот проект реализует и тестирует алгоритм бинарного поиска на языке C++. В проекте включены unit-тесты для проверки корректности и производительности функции бинарного поиска. Тесты написаны с использованием библиотеки Google Test.

## Структура проекта
Проект имеет следующую структуру:
- `bin/`: содержит `main.cpp`, файл с основной функцией программы.
- `lib/`: содержит реализацию бинарного поиска (`binsearch.h` и `binsearch.cpp`).
  - `lib/binsearch/`: папка с исходниками бинарного поиска.
- `tests/`: содержит файлы тестов и их CMake конфигурацию.
  - `binsearch_tests.cpp`: файл с тестами для функции бинарного поиска.

## Зависимости
Для выполнения тестов используется библиотека **Google Test**. CMake автоматически скачивает её при сборке, если она ещё не установлена в системе.

 ## Инструкции по сборке и запуску

Для сборки проекта и тестов выполните следующие шаги:

1. **Клонирование репозитория**

```bash

git clone https://github.com/Infinitized-Frog-88/testing-binary-search.git

cd testing-binary-search
```
2. **Сборка проекта**


Создайте и перейдите в папку `build`:
```bash
mkdir build
cd build
```
Затем выполните команду CMake для генерации make-файлов и сборки:
```bash
cmake .. -G "MinGW Makefiles"
cmake --build .
```
3. **Запуск тестов**

После сборки выполните скомпилированные тесты:
```bash
ctest --output-on-failure
```
