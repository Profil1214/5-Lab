//! \file Laboratory_Work_5.cpp
//! \brief Главный файл лабораторной работы №5
//! \details Реализация структур данных: бинарное дерево поиска и декартово дерево

#include <iostream>
#include "BinaryTree.h"
#include "Treap.h"
#include "IOBinaryTree.h"
#include "IOTreap.h"

//! \brief Отображает главное меню
void ShowMainMenu()
{
    std::cout << "\n=== Главное меню ===" << std::endl;
    std::cout << "1. Бинарное дерево поиска" << std::endl;
    std::cout << "2. Декартово дерево (Treap)" << std::endl;
    std::cout << "3. Выход" << std::endl;
    std::cout << "Выбор: ";
}

//! \brief Главная функция программы
//! \return Код завершения программы
int main()
{
    // Установка русского языка в консоли
    setlocale(LC_ALL, "Russian");

    int choice;
    bool running = true;

    while (running)
    {
        ShowMainMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            BinaryTree tree;
            IOBinaryTree::ProcessChoice(tree);
            break;
        }

        case 2:
        {
            Treap tree;
            IOTreap::ProcessChoice(tree);
            break;
        }

        case 3:
        {
            running = false;
            std::cout << "Выход из программы..." << std::endl;
            break;
        }

        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}