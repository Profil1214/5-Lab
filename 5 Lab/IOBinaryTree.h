#pragma once

#include "BinaryTree.h"

//! \brief Функции для работы с меню бинарного дерева
class IOBinaryTree
{
public:
    //! \brief Отображает меню бинарного дерева
    static void ShowMenu();

    //! \brief Обрабатывает выбор пользователя
    //! \param tree Бинарное дерево
    static void ProcessChoice(BinaryTree& tree);
};