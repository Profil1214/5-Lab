//! \file Treap.h
//! \brief Заголовочный файл структуры декартового дерева
#pragma once

#include "TreapNode.h"

//! \brief Структура декартового дерева
struct Treap
{
private:
    //! \brief Корневой узел дерева
    TreapNode* _root;

    //! \brief Вспомогательная функция для очистки памяти
    //! \param node Текущий узел
    void ClearHelper(TreapNode* node);

    //! \brief Вспомогательная функция для вывода дерева
    //! \param node Текущий узел
    //! \param depth Глубина узла
    void DisplayHelper(TreapNode* node, int depth);

    //! \brief Вспомогательная функция для поиска элемента
    //! \param node Текущий узел
    //! \param key Ключ для поиска
    //! \return Приоритет найденного узла или -1 если не найден
    int SearchHelper(TreapNode* node, int key);

    //! \brief Вспомогательная функция для разделения дерева
    //! \param node Текущий узел
    //! \param key Ключ для разделения
    //! \param left Левое поддерево
    //! \param right Правое поддерево
    void SplitHelper(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

    //! \brief Вспомогательная функция для слияния деревьев
    //! \param left Левое поддерево
    //! \param right Правое поддерево
    //! \return Корень объединенного дерева
    TreapNode* MergeHelper(TreapNode* left, TreapNode* right);

    //! \brief Вспомогательная функция для вставки (оптимизированной)
    //! \param node Текущий узел
    //! \param newNode Новый узел
    //! \return Корень измененного дерева
    TreapNode* InsertOptimizedHelper(TreapNode* node, TreapNode* newNode);

    //! \brief Вспомогательная функция для удаления (оптимизированного)
    //! \param node Текущий узел
    //! \param key Ключ для удаления
    //! \return Корень измененного дерева
    TreapNode* RemoveOptimizedHelper(TreapNode* node, int key);

public:
    //! \brief Конструктор декартового дерева
    Treap();

    //! \brief Деструктор
    ~Treap();

    //! \brief Разделяет дерево на два поддерева
    //! \param key Ключ, по которому разделяется дерево
    //! \param left Левое поддерево (ключи < key)
    //! \param right Правое поддерево (ключи >= key)
    void Split(int key, TreapNode*& left, TreapNode*& right);

    //! \brief Сливает два дерева в одно
    //! \param left Левое поддерево
    //! \param right Правое поддерево
    //! \return Корень объединенного дерева
    TreapNode* Merge(TreapNode* left, TreapNode* right);

    //! \brief Ищет элемент в дереве по ключу
    //! \param key Ключ для поиска
    //! \return Приоритет найденного узла или -1 если не найден
    int FindElement(int key);

    //! \brief Добавляет элемент (неоптимизированный метод)
    //! \param key Ключ узла
    //! \param priority Приоритет узла
    void InsertUnoptimized(int key, int priority);

    //! \brief Добавляет элемент (оптимизированный метод)
    //! \param key Ключ узла
    //! \param priority Приоритет узла
    void InsertOptimized(int key, int priority);

    //! \brief Удаляет элемент (неоптимизированный метод)
    //! \param key Ключ узла
    void RemoveUnoptimized(int key);

    //! \brief Удаляет элемент (оптимизированный метод)
    //! \param key Ключ узла
    void RemoveOptimized(int key);

    //! \brief Очищает дерево
    void ClearTree();

    //! \brief Выводит дерево на экран
    void DisplayTree();

    //! \brief Возвращает корень дерева
    //! \return Указатель на корневой узел
    TreapNode* GetRoot();

    //! \brief Устанавливает корень дерева
    //! \param root Новый корень
    void SetRoot(TreapNode* root);
};