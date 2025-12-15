//! \file Treap.cpp
//! \brief Реализация методов декартового дерева

#include "Treap.h"
#include <iostream>
#include <algorithm>

//! \brief Конструктор декартового дерева
Treap::Treap() : _root(nullptr)
{
}

//! \brief Деструктор
Treap::~Treap()
{
    ClearHelper(_root);
}

//! \brief Вспомогательная функция для очистки памяти
//! \param node Текущий узел
void Treap::ClearHelper(TreapNode* node)
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
void Treap::DisplayHelper(TreapNode* node, int depth)
{
    if (node != nullptr)
    {
        DisplayHelper(node->GetRight(), depth + 1);

        for (int i = 0; i < depth; i++)
        {
            std::cout << "  ";
        }
        std::cout << node->GetKey() << "[" << node->GetPriority() << "]" << std::endl;

        DisplayHelper(node->GetLeft(), depth + 1);
    }
}

//! \brief Вспомогательная функция для поиска элемента
//! \param node Текущий узел
//! \param key Ключ для поиска
//! \return Приоритет найденного узла или -1 если не найден
int Treap::SearchHelper(TreapNode* node, int key)
{
    if (node == nullptr)
    {
        return -1;
    }

    if (key == node->GetKey())
    {
        return node->GetPriority();
    }
    else if (key < node->GetKey())
    {
        return SearchHelper(node->GetLeft(), key);
    }
    else
    {
        return SearchHelper(node->GetRight(), key);
    }
}

//! \brief Вспомогательная функция для разделения дерева
//! \param node Текущий узел
//! \param key Ключ для разделения
//! \param left Левое поддерево
//! \param right Правое поддерево
void Treap::SplitHelper(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
    if (node == nullptr)
    {
        left = nullptr;
        right = nullptr;
    }
    else if (node->GetKey() <= key)
    {
        // Корень идет в левое поддерево
        TreapNode* leftRight = nullptr;
        SplitHelper(node->GetRight(), key, leftRight, right);
        node->SetRight(leftRight);
        left = node;
    }
    else
    {
        // Корень идет в правое поддерево
        TreapNode* rightLeft = nullptr;
        SplitHelper(node->GetLeft(), key, left, rightLeft);
        node->SetLeft(rightLeft);
        right = node;
    }
}

//! \brief Вспомогательная функция для слияния деревьев
//! \param left Левое поддерево
//! \param right Правое поддерево
//! \return Корень объединенного дерева
TreapNode* Treap::MergeHelper(TreapNode* left, TreapNode* right)
{
    if (left == nullptr || right == nullptr)
    {
        return left != nullptr ? left : right;
    }

    if (left->GetPriority() > right->GetPriority())
    {
        left->SetRight(MergeHelper(left->GetRight(), right));
        return left;
    }
    else
    {
        right->SetLeft(MergeHelper(left, right->GetLeft()));
        return right;
    }
}

//! \brief Вспомогательная функция для вставки (оптимизированной)
//! \param node Текущий узел
//! \param newNode Новый узел
//! \return Корень измененного дерева
TreapNode* Treap::InsertOptimizedHelper(TreapNode* node, TreapNode* newNode)
{
    if (node == nullptr)
    {
        return newNode;
    }

    if (newNode->GetPriority() > node->GetPriority())
    {
        TreapNode* left = nullptr;
        TreapNode* right = nullptr;
        SplitHelper(node, newNode->GetKey(), left, right);
        newNode->SetLeft(left);
        newNode->SetRight(right);
        return newNode;
    }
    else if (newNode->GetKey() < node->GetKey())
    {
        node->SetLeft(InsertOptimizedHelper(node->GetLeft(), newNode));
    }
    else
    {
        node->SetRight(InsertOptimizedHelper(node->GetRight(), newNode));
    }

    return node;
}
//! \brief Вспомогательная функция для удаления (оптимизированного)
//! \param node Текущий узел
//! \param key Ключ для удаления
//! \return Корень измененного дерева
TreapNode* Treap::RemoveOptimizedHelper(TreapNode* node, int key)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (key == node->GetKey())
    {
        TreapNode* result = MergeHelper(node->GetLeft(), node->GetRight());
        delete node;
        return result;
    }
    else if (key < node->GetKey())
    {
        node->SetLeft(RemoveOptimizedHelper(node->GetLeft(), key));
    }
    else
    {
        node->SetRight(RemoveOptimizedHelper(node->GetRight(), key));
    }

    return node;
}

//! \brief Разделяет дерево на два поддерева
//! \param key Ключ, по которому разделяется дерево
//! \param left Левое поддерево (ключи < key)
//! \param right Правое поддерево (ключи >= key)
void Treap::Split(int key, TreapNode*& left, TreapNode*& right)
{
    SplitHelper(_root, key, left, right);
}

//! \brief Сливает два дерева в одно
//! \param left Левое поддерево
//! \param right Правое поддерево
//! \return Корень объединенного дерева
TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
    return MergeHelper(left, right);
}

//! \brief Ищет элемент в дереве по ключу
//! \param key Ключ для поиска
//! \return Приоритет найденного узла или -1 если не найден
int Treap::FindElement(int key)
{
    return SearchHelper(_root, key);
}

//! \brief Добавляет элемент (неоптимизированный метод)
//! \param key Ключ узла
//! \param priority Приоритет узла
void Treap::InsertUnoptimized(int key, int priority)
{
    TreapNode* newNode = new TreapNode(key, priority);

    // 1. Split по ключу
    TreapNode* left = nullptr;
    TreapNode* right = nullptr;
    SplitHelper(_root, key, left, right);

    // 2. Merge left с новым узлом
    TreapNode* leftWithNew = MergeHelper(left, newNode);

    // 3. Merge результата с right
    _root = MergeHelper(leftWithNew, right);
}

//! \brief Добавляет элемент (оптимизированный метод)
//! \param key Ключ узла
//! \param priority Приоритет узла
void Treap::InsertOptimized(int key, int priority)
{
    TreapNode* newNode = new TreapNode(key, priority);
    _root = InsertOptimizedHelper(_root, newNode);
}

//! \brief Удаляет элемент (неоптимизированный метод)
//! \param key Ключ узла
void Treap::RemoveUnoptimized(int key)
{
    // 1. Split по ключу-1, чтобы отделить элементы <= key
    TreapNode* left1 = nullptr;
    TreapNode* right1 = nullptr;
    SplitHelper(_root, key - 1, left1, right1);

    if (right1 == nullptr)
    {
        // Элемент не найден
        _root = left1;
        return;
    }

    // 2. Split по ключу, чтобы отделить элементы с ключом == key
    TreapNode* left2 = nullptr;
    TreapNode* right2 = nullptr;
    SplitHelper(right1, key, left2, right2);

    // 3. Удаляем узел с ключом == key (если он существует)
    // left2 может содержать узел с ключом == key
    if (left2 != nullptr && left2->GetKey() == key)
    {
        // Сливаем левое и правое поддеревья узла left2
        TreapNode* mergedChildren = MergeHelper(left2->GetLeft(), left2->GetRight());

        // Удаляем узел
        delete left2;
        left2 = mergedChildren;
    }

    // 4. Merge left1 с left2 и right2
    TreapNode* temp = MergeHelper(left1, left2);
    _root = MergeHelper(temp, right2);
}

//! \brief Удаляет элемент (оптимизированный метод)
//! \param key Ключ узла
void Treap::RemoveOptimized(int key)
{
    _root = RemoveOptimizedHelper(_root, key);
}

//! \brief Очищает дерево
void Treap::ClearTree()
{
    ClearHelper(_root);
    _root = nullptr;
}

//! \brief Выводит дерево на экран
void Treap::DisplayTree()
{
    if (_root == nullptr)
    {
        std::cout << "Дерево пустое" << std::endl;
        return;
    }

    std::cout << "Структура дерева (ключ[приоритет]):" << std::endl;
    DisplayHelper(_root, 0);
}

//! \brief Возвращает корень дерева
//! \return Указатель на корневой узел
TreapNode* Treap::GetRoot()
{
    return _root;
}

//! \brief Устанавливает корень дерева
//! \param root Новый корень
void Treap::SetRoot(TreapNode* root)
{
    _root = root;
}