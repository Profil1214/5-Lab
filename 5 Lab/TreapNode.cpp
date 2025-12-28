
#include "TreapNode.h"

//! \brief Конструктор узла декартового дерева
//! \param key Ключ узла
//! \param priority Приоритет узла
TreapNode::TreapNode(int key, int priority)
    : _key(key), _priority(priority), _left(nullptr), _right(nullptr)
{
}

//! \brief Деструктор
TreapNode::~TreapNode()
{
    // Дочерние узлы удаляются в Treap
}

//! \brief Возвращает ключ узла
//! \return Ключ узла
int TreapNode::GetKey()
{
    return _key;
}

//! \brief Возвращает приоритет узла
//! \return Приоритет узла
int TreapNode::GetPriority()
{
    return _priority;
}

//! \brief Возвращает левый дочерний узел
//! \return Указатель на левый дочерний узел
TreapNode* TreapNode::GetLeft()
{
    return _left;
}

//! \brief Устанавливает левый дочерний узел
//! \param node Указатель на левый дочерний узел
void TreapNode::SetLeft(TreapNode* node)
{
    _left = node;
}

//! \brief Возвращает правый дочерний узел
//! \return Указатель на правый дочерний узел
TreapNode* TreapNode::GetRight()
{
    return _right;
}

//! \brief Устанавливает правый дочерний узел
//! \param node Указатель на правый дочерний узел
void TreapNode::SetRight(TreapNode* node)
{
    _right = node;
}