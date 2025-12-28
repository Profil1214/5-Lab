
#pragma once
#include "BinaryTreeNode.h"

//! \brief Структура бинарного дерева поиска
struct BinaryTree
{
private:
    //! \brief Корень дерева
    BinaryTreeNode* _root;

    //! \brief Вспомогательная функция для удаления узла
    //! \param node Текущий узел
    //! \param data Значение для удаления
    //! \return Указатель на измененный узел
    BinaryTreeNode* RemoveHelper(BinaryTreeNode* node, int data);

    //! \brief Вспомогательная функция поиска минимального узла
    //! \param node Текущий узел
    //! \return Указатель на минимальный узел
    BinaryTreeNode* FindMinHelper(BinaryTreeNode* node);

    //! \brief Вспомогательная функция для очистки памяти
    //! \param node Текущий узел
    void ClearHelper(BinaryTreeNode* node);

    //! \brief Вспомогательная функция для вывода дерева
    //! \param node Текущий узел
    //! \param depth Глубина узла
    void DisplayHelper(BinaryTreeNode* node, int depth);

public:
    //! \brief Конструктор бинарного дерева
    BinaryTree();

    //! \brief Деструктор
    ~BinaryTree();

    //! \brief Возвращает указатель на корень дерева
    //! \return Указатель на корневой узел
    BinaryTreeNode* GetRoot();

    //! \brief Добавляет элемент в дерево
    //! \param data Значение элемента
    void AddElement(int data);

    //! \brief Удаляет элемент из дерева
    //! \param data Значение элемента
    void RemoveElement(int data);

    //! \brief Находит минимальный элемент
    //! \return Указатель на узел с минимальным значением
    BinaryTreeNode* GetMinNode();

    //! \brief Находит максимальный элемент
    //! \return Указатель на узел с максимальным значением
    BinaryTreeNode* GetMaxNode();

    //! \brief Ищет элемент в дереве
    //! \param data Значение для поиска
    //! \return Указатель на найденный узел или nullptr
    BinaryTreeNode* SearchElement(int data);

    //! \brief Очищает дерево
    void ClearTree();

    //! \brief Выводит дерево на экран
    void DisplayTree();
};