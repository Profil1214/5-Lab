
#include "InputValidator.h"
#include "IOBinaryTree.h"
#include <iostream>
#include "InputValidator.h" 
//! \brief Отображает меню бинарного дерева
void IOBinaryTree::ShowMenu()
{
    std::cout << "\n=== Меню бинарного дерева поиска ===" << std::endl;
    std::cout << "1. Добавить элемент" << std::endl;
    std::cout << "2. Удалить элемент" << std::endl;
    std::cout << "3. Найти элемент" << std::endl;
    std::cout << "4. Найти минимум" << std::endl;
    std::cout << "5. Найти максимум" << std::endl;
    std::cout << "6. Вывести дерево" << std::endl;
    std::cout << "7. Очистить дерево" << std::endl;
    std::cout << "8. Вернуться в главное меню" << std::endl;
    std::cout << "Выбор: ";
}

//! \brief Обрабатывает выбор пользователя
//! \param tree Бинарное дерево
void IOBinaryTree::ProcessChoice(BinaryTree& tree)
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
            int data;
            std::cout << "Введите значение для добавления: ";
            data = InputValidator::GetInt();

            
            BinaryTreeNode* existing = tree.SearchElement(data);
            if (existing != nullptr)
            {
                std::cout << "Ошибка: элемент " << data << " уже существует!" << std::endl;
                break;
            }

            tree.AddElement(data);
            std::cout << "Элемент " << data << " добавлен" << std::endl;
            break;
        }

        case 2:
        {
            int data;
            std::cout << "Введите значение для удаления: ";
            data = InputValidator::GetInt();

            
            BinaryTreeNode* existing = tree.SearchElement(data);
            if (existing == nullptr)
            {
                std::cout << "Ошибка: элемент " << data << " не найден!" << std::endl;
                break;
            }

            tree.RemoveElement(data);
            std::cout << "Элемент " << data << " удален" << std::endl;
            break;
        }

        case 3:
        {
            int data;
            std::cout << "Введите значение для поиска: ";
            data = InputValidator::GetInt();;
            BinaryTreeNode* result = tree.SearchElement(data);
            if (result != nullptr)
            {
                std::cout << "Элемент " << data << " найден" << std::endl;
            }
            else
            {
                std::cout << "Элемент " << data << " не найден" << std::endl;
            }
            break;
        }

        case 4:
        {
            BinaryTreeNode* minNode = tree.GetMinNode();
            if (minNode != nullptr)
            {
                std::cout << "Минимальный элемент: " << minNode->GetData() << std::endl;
            }
            else
            {
                std::cout << "Дерево пустое" << std::endl;
            }
            break;
        }

        case 5:
        {
            BinaryTreeNode* maxNode = tree.GetMaxNode();
            if (maxNode != nullptr)
            {
                std::cout << "Максимальный элемент: " << maxNode->GetData() << std::endl;
            }
            else
            {
                std::cout << "Дерево пустое" << std::endl;
            }
            break;
        }

        case 6:
        {
            std::cout << "\n=== Бинарное дерево поиска ===" << std::endl;
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