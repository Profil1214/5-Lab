

#include "IOTreap.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "InputValidator.h" 

//! \brief Отображает меню декартового дерева
void IOTreap::ShowMenu()
{
    std::cout << "\n=== Меню декартового дерева ===" << std::endl;
    std::cout << "1. Добавить элемент (неоптимизированный - 1 Split, 2 Merge)" << std::endl;
    std::cout << "2. Добавить элемент (оптимизированный - 1 Split)" << std::endl;
    std::cout << "3. Удалить элемент (неоптимизированный - 2 Split, 1 Merge)" << std::endl;
    std::cout << "4. Удалить элемент (оптимизированный - 1 Merge)" << std::endl;
    std::cout << "5. Найти элемент" << std::endl;
    std::cout << "6. Вывести дерево" << std::endl;
    std::cout << "7. Очистить дерево" << std::endl;
    std::cout << "8. Вернуться в главное меню" << std::endl;
    std::cout << "Выбор: ";
}

//! \brief Обрабатывает выбор пользователя
//! \param tree Декартово дерево
void IOTreap::ProcessChoice(Treap& tree)
{
    int choice;
    bool running = true;

    while (running)
    {
        ShowMenu();
        choice = InputValidator::GetInt();

        switch (choice)
        {
        case 1:
        {
            int key;
            std::cout << "Введите ключ: ";
            key = InputValidator::GetInt();;

            if (tree.FindElement(key) != -1)
            {
                std::cout << "Ошибка: элемент с ключом " << key << " уже существует!" << std::endl;
                break;
            }

            int priority = rand() % 1000 + 1;
            std::cout << "Сгенерирован приоритет: " << priority << std::endl;

            tree.InsertUnoptimized(key, priority);
            std::cout << "Элемент добавлен" << std::endl;
            break;
        }

        case 2:
        {
            int key;
            std::cout << "Введите ключ: ";
            key = InputValidator::GetInt();;

           
            if (tree.FindElement(key) != -1)
            {
                std::cout << "Ошибка: элемент с ключом " << key << " уже существует!" << std::endl;
                break;
            }

            int priority = rand() % 1000 + 1;
            std::cout << "Сгенерирован приоритет: " << priority << std::endl;
            tree.InsertOptimized(key, priority);
            std::cout << "Элемент добавлен (оптимизированный метод)" << std::endl;
            break;
        }

        case 3:
        {
            int key;
            std::cout << "Введите ключ для удаления: ";
            key = InputValidator::GetInt();;

           
            if (tree.FindElement(key) == -1)
            {
                std::cout << "Ошибка: элемент с ключом " << key << " не найден!" << std::endl;
                break;
            }

            tree.RemoveUnoptimized(key);
            std::cout << "Элемент удален (неоптимизированный метод)" << std::endl;
            break;
        }

        case 4:
        {
            int key;
            std::cout << "Введите ключ для удаления: ";
            key = InputValidator::GetInt();;

            
            if (tree.FindElement(key) == -1)
            {
                std::cout << "Ошибка: элемент с ключом " << key << " не найден!" << std::endl;
                break;
            }

            tree.RemoveOptimized(key);
            std::cout << "Элемент удален (оптимизированный метод)" << std::endl;
            break;
        }

        case 5:
        {
            int key;
            std::cout << "Введите ключ для поиска: ";
            key = InputValidator::GetInt();;
            int priority = tree.FindElement(key);
            if (priority != -1)
            {
                std::cout << "Элемент найден. Ключ: " << key
                    << ", Приоритет: " << priority << std::endl;
            }
            else
            {
                std::cout << "Элемент не найден" << std::endl;
            }
            break;
        }

        case 6:
        {
            std::cout << "\n=== Декартово дерево ===" << std::endl;
            tree.DisplayTree();
            break;
        }

        case 7:
        {
            tree.ClearTree();
            std::cout << "Дерево очищено" << std::endl;
            break;
        }

        case 8:
        {
            running = false;
            break;
        }

        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }
}