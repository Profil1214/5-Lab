
#include "Treap.h"
#include <iostream>

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

//! \brief Вспомогательная функция для разделения дерева (ИСПРАВЛЕНО)
//! \param node Текущий узел
//! \param key Ключ для разделения
//! \param left Левое поддерево (ключи < key)
//! \param right Правое поддерево (ключи >= key)
void Treap::SplitHelper(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
    if (node == nullptr)
    {
        left = nullptr;
        right = nullptr;
        return;
    }

    // Разделяем по ключу, а не по приоритету!
    if (node->GetKey() <= key)
    {
        // Узел идет в левое дерево (ключ <= разделителя)
        TreapNode* leftRight = nullptr;
        TreapNode* newRight = nullptr;
        SplitHelper(node->GetRight(), key, leftRight, newRight);
        node->SetRight(leftRight);
        left = node;
        right = newRight;
    }
    else
    {
        // Узел идет в правое дерево (ключ > разделителя)
        TreapNode* newLeft = nullptr;
        TreapNode* rightLeft = nullptr;
        SplitHelper(node->GetLeft(), key, newLeft, rightLeft);
        node->SetLeft(rightLeft);
        left = newLeft;
        right = node;
    }
}

//! \brief Вспомогательная функция для слияния деревьев (ИСПРАВЛЕНО)
//! \param left Левое поддерево (все ключи < ключей правого поддерева)
//! \param right Правое поддерево (все ключи >= ключей левого поддерева)
//! \return Корень объединенного дерева
TreapNode* Treap::MergeHelper(TreapNode* left, TreapNode* right)
{
    if (left == nullptr)
    {
        return right;
    }

    if (right == nullptr)
    {
        return left;
    }

    // Сравниваем приоритеты для поддержки свойства кучи
    if (left->GetPriority() > right->GetPriority())
    {
        // Левый узел имеет больший приоритет
        TreapNode* mergedRight = MergeHelper(left->GetRight(), right);
        left->SetRight(mergedRight);
        return left;
    }
    else
    {
        // Правый узел имеет больший или равный приоритет
        TreapNode* mergedLeft = MergeHelper(left, right->GetLeft());
        right->SetLeft(mergedLeft);
        return right;
    }
}

//! \brief Вспомогательная функция для вставки (оптимизированной) - ИСПРАВЛЕНО
//! \param node Текущий узел
//! \param newNode Новый узел
//! \return Корень измененного дерева
TreapNode* Treap::InsertOptimizedHelper(TreapNode* node, TreapNode* newNode)
{
    if (node == nullptr)
    {
        return newNode;
    }

    // Если приоритет нового узла выше текущего
    if (newNode->GetPriority() > node->GetPriority())
    {
        // Разделяем поддерево по ключу нового узла
        TreapNode* left = nullptr;
        TreapNode* right = nullptr;
        SplitHelper(node, newNode->GetKey(), left, right);

        // Новый узел становится корнем
        newNode->SetLeft(left);
        newNode->SetRight(right);
        return newNode;
    }
    else if (newNode->GetKey() < node->GetKey())
    {
        // Идем в левое поддерево
        node->SetLeft(InsertOptimizedHelper(node->GetLeft(), newNode));
    }
    else
    {
        // Идем в правое поддерево (при равенстве ключей - тоже вправо)
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

//! \brief Добавляет элемент (неоптимизированный метод) - ИСПРАВЛЕНО
//! \param key Ключ узла
//! \param priority Приоритет узла
void Treap::InsertUnoptimized(int key, int priority)
{
    // Проверяем, не существует ли уже такой ключ
    if (FindElement(key) != -1)
    {
        return; // Элемент уже существует
    }

    TreapNode* newNode = new TreapNode(key, priority);

    // 1. Разделяем текущее дерево по ключу
    TreapNode* left = nullptr;
    TreapNode* right = nullptr;
    SplitHelper(_root, key, left, right);

    // 2. Сливаем левую часть с новым узлом
    TreapNode* leftWithNew = MergeHelper(left, newNode);

    // 3. Сливаем результат с правой частью
    _root = MergeHelper(leftWithNew, right);
}

//! \brief Добавляет элемент (оптимизированный метод)
//! \param key Ключ узла
//! \param priority Приоритет узла
void Treap::InsertOptimized(int key, int priority)
{
    // Проверяем, не существует ли уже такой ключ
    if (FindElement(key) != -1)
    {
        return; // Элемент уже существует
    }

    TreapNode* newNode = new TreapNode(key, priority);
    _root = InsertOptimizedHelper(_root, newNode);
}

//! \brief Удаляет элемент (неоптимизированный метод) - ИСПРАВЛЕНО
//! \param key Ключ узла
void Treap::RemoveUnoptimized(int key)
{
    // 1. Разделяем дерево на элементы с ключом < key и >= key
    TreapNode* left = nullptr;
    TreapNode* right = nullptr;
    SplitHelper(_root, key - 1, left, right);

    if (right == nullptr)
    {
        // Элемент не найден
        _root = left;
        return;
    }

    // 2. Разделяем правую часть на элементы с ключом == key и > key
    TreapNode* middle = nullptr;
    TreapNode* newRight = nullptr;
    SplitHelper(right, key, middle, newRight);

    // 3. Если middle не пустой, удаляем его (это узел с ключом == key)
    if (middle != nullptr)
    {
        // Сливаем левое и правое поддерево middle (игнорируем сам middle)
        TreapNode* mergedChildren = MergeHelper(middle->GetLeft(), middle->GetRight());
        delete middle;

        // 4. Сливаем все части обратно
        TreapNode* temp = MergeHelper(left, mergedChildren);
        _root = MergeHelper(temp, newRight);
    }
    else
    {
        // Элемент не найден, восстанавливаем дерево
        _root = MergeHelper(left, newRight);
    }
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