//! \file IOTreap.h
//! \brief Заголовочный файл для ввода-вывода декартового дерева
#pragma once

#include "Treap.h"

//! \brief Функции для работы с меню декартового дерева
class IOTreap
{
public:
    //! \brief Отображает меню декартового дерева
    static void ShowMenu();

    //! \brief Обрабатывает выбор пользователя
    //! \param tree Декартово дерево
    static void ProcessChoice(Treap& tree);
};