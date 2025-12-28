
#include "BinaryTreeNode.h"
#include <iostream>

//! \brief Конструктор узла бинарного дерева
//! \param data Значение узла
BinaryTreeNode::BinaryTreeNode(int data)
    : _data(data), _left(nullptr), _right(nullptr)
{
}

//! \brief Деструктор
BinaryTreeNode::~BinaryTreeNode()
{
}

//! \brief Возвращает значение узла
//! \return Значение узла
int BinaryTreeNode::GetData()
{
    return _data;
}

//! \brief Возвращает указатель на левый дочерний узел
//! \return Указатель на левый дочерний узел
BinaryTreeNode* BinaryTreeNode::GetLeft()
{
    return _left;
}

//! \brief Устанавливает левый дочерний узел
//! \param node Левый дочерний узел
void BinaryTreeNode::SetLeft(BinaryTreeNode* node)
{
    _left = node;
}

//! \brief Возвращает указатель на правый дочерний узел
//! \return Указатель на правый дочерний узел
BinaryTreeNode* BinaryTreeNode::GetRight()
{
    return _right;
}

//! \brief Устанавливает правый дочерний узел
//! \param node Указатель на правый дочерний узел
void BinaryTreeNode::SetRight(BinaryTreeNode* node)
{
    _right = node;
}