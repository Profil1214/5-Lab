//! \file TreapNode.h
//! \brief Заголовочный файл структуры узла декартового дерева
#pragma once

//! \brief Структура узла декартового дерева
struct TreapNode
{
private:
    //! \brief Ключ узла
    int _key;

    //! \brief Приоритет узла
    int _priority;

    //! \brief Левый дочерний узел
    TreapNode* _left;

    //! \brief Правый дочерний узел
    TreapNode* _right;

public:
    //! \brief Конструктор узла декартового дерева
    //! \param key Ключ узла
    //! \param priority Приоритет узла
    TreapNode(int key, int priority);

    //! \brief Деструктор
    ~TreapNode();

    //! \brief Возвращает ключ узла
    //! \return Ключ узла
    int GetKey();

    //! \brief Возвращает приоритет узла
    //! \return Приоритет узла
    int GetPriority();

    //! \brief Возвращает левый дочерний узел
    //! \return Указатель на левый дочерний узел
    TreapNode* GetLeft();

    //! \brief Устанавливает левый дочерний узел
    //! \param node Указатель на левый дочерний узел
    void SetLeft(TreapNode* node);

    //! \brief Возвращает правый дочерний узел
    //! \return Указатель на правый дочерний узел
    TreapNode* GetRight();

    //! \brief Устанавливает правый дочерний узел
    //! \param node Указатель на правый дочерний узел
    void SetRight(TreapNode* node);
};