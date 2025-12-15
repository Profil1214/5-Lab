//! \file BinaryTree.cpp
//! \brief Реализация методов бинарного дерева поиска

#include "BinaryTree.h"
#include <iostream>
#include <algorithm>

//! \brief Конструктор бинарного дерева
BinaryTree::BinaryTree() : _root(nullptr)
{
}

//! \brief Деструктор
BinaryTree::~BinaryTree()
{
    ClearHelper(_root);
}

//! \brief Вспомогательная функция для очистки памяти
//! \param node Текущий узел
void BinaryTree::ClearHelper(BinaryTreeNode* node)
{
    if (node != nullptr)
    {
        ClearHelper(node->GetLeft());
        ClearHelper(node->GetRight());
        delete node;
    }
}

//! \brief Вспомогательная функция для вывода дерева
//! \param node Текущий узел
//! \param depth Глубина узла
void BinaryTree::DisplayHelper(BinaryTreeNode* node, int depth)
{
    if (node != nullptr)
    {
        DisplayHelper(node->GetRight(), depth + 1);

        for (int i = 0; i < depth; i++)
        {
            std::cout << "  ";
        }
        std::cout << node->GetData() << std::endl;

        DisplayHelper(node->GetLeft(), depth + 1);
    }
}

//! \brief Возвращает указатель на корень дерева
//! \return Указатель на корневой узел
BinaryTreeNode* BinaryTree::GetRoot()
{
    return _root;
}

//! \brief Добавляет элемент в дерево
//! \param data Значение элемента
void BinaryTree::AddElement(int data)
{
    BinaryTreeNode* newNode = new BinaryTreeNode(data);

    if (_root == nullptr)
    {
        _root = newNode;
        return;
    }

    BinaryTreeNode* current = _root;
    BinaryTreeNode* parent = nullptr;

    while (current != nullptr)
    {
        parent = current;

        if (data < current->GetData())
        {
            current = current->GetLeft();
        }
        else if (data > current->GetData())
        {
            current = current->GetRight();
        }
        else
        {
            // Элемент уже существует
            delete newNode;
            return;
        }
    }

    if (data < parent->GetData())
    {
        parent->SetLeft(newNode);
    }
    else
    {
        parent->SetRight(newNode);
    }
}

//! \brief Вспомогательная функция поиска минимального узла
//! \param node Текущий узел
//! \return Указатель на минимальный узел
BinaryTreeNode* BinaryTree::FindMinHelper(BinaryTreeNode* node)
{
    while (node != nullptr && node->GetLeft() != nullptr)
    {
        node = node->GetLeft();
    }
    return node;
}

//! \brief Вспомогательная функция для удаления узла
//! \param node Текущий узел
//! \param data Значение для удаления
//! \return Указатель на измененный узел
BinaryTreeNode* BinaryTree::RemoveHelper(BinaryTreeNode* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (data < node->GetData())
    {
        node->SetLeft(RemoveHelper(node->GetLeft(), data));
    }
    else if (data > node->GetData())
    {
        node->SetRight(RemoveHelper(node->GetRight(), data));
    }
    else
    {
        // Узел найден
        if (node->GetLeft() == nullptr && node->GetRight() == nullptr)
        {
            // Нет потомков
            delete node;
            return nullptr;
        }
        else if (node->GetLeft() == nullptr)
        {
            // Только правый потомок
            BinaryTreeNode* temp = node->GetRight();
            delete node;
            return temp;
        }
        else if (node->GetRight() == nullptr)
        {
            // Только левый потомок
            BinaryTreeNode* temp = node->GetLeft();
            delete node;
            return temp;
        }
        else
        {
            // Два потомка
            BinaryTreeNode* minNode = FindMinHelper(node->GetRight());
            // Копируем данные минимального узла
            int minData = minNode->GetData();
            node->SetRight(RemoveHelper(node->GetRight(), minData));
            // Устанавливаем новые данные в текущий узел
            // В реальной реализации нужно было бы менять данные,
            // но так как GetData возвращает int, а не указатель,
            // мы не можем изменить данные напрямую
            // Вместо этого создадим новый узел и удалим старый
            BinaryTreeNode* newNode = new BinaryTreeNode(minData);
            newNode->SetLeft(node->GetLeft());
            newNode->SetRight(node->GetRight());
            delete node;
            node = newNode;
        }
    }
    return node;
}

//! \brief Удаляет элемент из дерева
//! \param data Значение элемента
void BinaryTree::RemoveElement(int data)
{
    _root = RemoveHelper(_root, data);
}

//! \brief Находит минимальный элемент
//! \return Указатель на узел с минимальным значением
BinaryTreeNode* BinaryTree::GetMinNode()
{
    return FindMinHelper(_root);
}

//! \brief Находит максимальный элемент
//! \return Указатель на узел с максимальным значением
BinaryTreeNode* BinaryTree::GetMaxNode()
{
    BinaryTreeNode* current = _root;
    while (current != nullptr && current->GetRight() != nullptr)
    {
        current = current->GetRight();
    }
    return current;
}

//! \brief Ищет элемент в дереве
//! \param data Значение для поиска
//! \return Указатель на найденный узел или nullptr
BinaryTreeNode* BinaryTree::SearchElement(int data)
{
    BinaryTreeNode* current = _root;

    while (current != nullptr)
    {
        if (data == current->GetData())
        {
            return current;
        }
        else if (data < current->GetData())
        {
            current = current->GetLeft();
        }
        else
        {
            current = current->GetRight();
        }
    }

    return nullptr;
}

//! \brief Очищает дерево
void BinaryTree::ClearTree()
{
    ClearHelper(_root);
    _root = nullptr;
}

//! \brief Выводит дерево на экран
void BinaryTree::DisplayTree()
{
    if (_root == nullptr)
    {
        std::cout << "Дерево пустое" << std::endl;
        return;
    }

    std::cout << "Структура дерева:" << std::endl;
    DisplayHelper(_root, 0);
}