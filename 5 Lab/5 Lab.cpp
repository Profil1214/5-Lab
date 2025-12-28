
#include <iostream>
#include "BinaryTree.h"
#include "Treap.h"
#include "IOBinaryTree.h"
#include "IOTreap.h"
#include "InputValidator.h" 

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
    setlocale(LC_ALL, "Russian");

    int choice;
    bool running = true;

    while (running)
    {
        ShowMainMenu();
        choice = InputValidator::GetInt();

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