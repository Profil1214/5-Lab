//! \file IOTreap.cpp
//! \brief Реализация функций ввода-вывода для декартового дерева

#include "IOTreap.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//! \brief Отображает меню декартового дерева
void IOTreap::ShowMenu()
{
    std::cout << "\n=== Меню декартового дерева ===" << std::endl;
    std::cout << "1. Добавить элемент (неоптимизированный - 1 Split, 2 Merge)" << std::endl;
    std::cout << "2. Добавить элемент (оптимизированный - 1 Split)" << std::endl;
    std::cout << "3. Удалить элемент (неоптимизированный - 2 Split, 1 Merge)" << std::endl;
    std::cout << "4. Удалить элемент (оптимизированный - 1 Merge)" << std::endl;
    std::cout << "5. Найти элемент" << std::endl;
    std::cout << "6. Разделить дерево" << std::endl;
    std::cout << "7. Слить деревья" << std::endl;
    std::cout << "8. Вывести дерево" << std::endl;
    std::cout << "9. Очистить дерево" << std::endl;
    std::cout << "10. Вернуться в главное меню" << std::endl;
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
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int key, priority;
            std::cout << "Введите ключ: ";
            std::cin >> key;

            // Проверка существования элемента
            if (tree.FindElement(key) != -1)
            {
                std::cout << "Ошибка: элемент с ключом " << key << " уже существует!" << std::endl;
                break;
            }

            std::cout << "Введите приоритет: ";
            std::cin >> priority;
            tree.InsertUnoptimized(key, priority);
            std::cout << "Элемент добавлен (неоптимизированный метод)" << std::endl;
            break;
        }

        case 2:
        {
            int key, priority;
            std::cout << "Введите ключ: ";
            std::cin >> key;

            // Проверка существования элемента
            if (tree.FindElement(key) != -1)
            {
                std::cout << "Ошибка: элемент с ключом " << key << " уже существует!" << std::endl;
                break;
            }

            std::cout << "Введите приоритет: ";
            std::cin >> priority;
            tree.InsertOptimized(key, priority);
            std::cout << "Элемент добавлен (оптимизированный метод)" << std::endl;
            break;
        }

        case 3:
        {
            int key;
            std::cout << "Введите ключ для удаления: ";
            std::cin >> key;

            // Проверка существования элемента
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
            std::cin >> key;

            // Проверка существования элемента
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
            std::cin >> key;
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
            int key;
            std::cout << "Введите ключ для разделения: ";
            std::cin >> key;

            TreapNode* left = nullptr;
            TreapNode* right = nullptr;
            tree.Split(key, left, right);

            std::cout << "Левое поддерево (ключи < " << key << "):" << std::endl;
            Treap tempLeft;
            tempLeft.SetRoot(left);
            tempLeft.DisplayTree();

            std::cout << "\nПравое поддерево (ключи >= " << key << "):" << std::endl;
            Treap tempRight;
            tempRight.SetRoot(right);
            tempRight.DisplayTree();

            // Восстанавливаем исходное дерево
            tree.SetRoot(tree.Merge(left, right));
            std::cout << "\nИсходное дерево восстановлено" << std::endl;
            break;
        }

        case 7:
        {
            std::cout << "Для демонстрации слияния создадим два дерева:" << std::endl;

            Treap tree1;
            tree1.InsertOptimized(5, 50);
            tree1.InsertOptimized(3, 30);
            tree1.InsertOptimized(7, 70);

            Treap tree2;
            tree2.InsertOptimized(9, 90);
            tree2.InsertOptimized(6, 60);
            tree2.InsertOptimized(12, 120);

            std::cout << "Дерево 1:" << std::endl;
            tree1.DisplayTree();

            std::cout << "\nДерево 2:" << std::endl;
            tree2.DisplayTree();

            TreapNode* merged = tree.Merge(tree1.GetRoot(), tree2.GetRoot());

            std::cout << "\nРезультат слияния:" << std::endl;
            Treap mergedTree;
            mergedTree.SetRoot(merged);
            mergedTree.DisplayTree();

            // Очищаем временные деревья, чтобы не было утечек памяти
            tree1.ClearTree();
            tree2.ClearTree();
            mergedTree.ClearTree();
            break;
        }

        case 8:
        {
            std::cout << "\n=== Декартово дерево ===" << std::endl;
            tree.DisplayTree();
            break;
        }

        case 9:
        {
            tree.ClearTree();
            std::cout << "Дерево очищено" << std::endl;
            break;
        }

        case 10:
        {
            running = false;
            break;
        }

        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }
}