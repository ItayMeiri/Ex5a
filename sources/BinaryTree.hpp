#pragma once

#include <iostream>


namespace ariel{
template<class T>
class Node
{
    public:
    int size(){
        return 0;
    }
    friend std::ostream& operator<< (std::ostream& stream, const Node<T> &node)
    {
        return stream;
    }
};

template<class T>
class BinaryTree
{
public:
	T* right;
	T* left;
	T* root;
	BinaryTree()
	{
		right = nullptr;
		left = nullptr;
		root = nullptr;
	}
	BinaryTree<T>& add_root(const T& root) {
		// this->root = root;
		return *this;
	}
	BinaryTree<T>& add_left(const T& t1, const T& t2)
    {
        return *this;
    }
    	BinaryTree<T>& add_right(const T& t1, const T& t2)
    {
        return *this;
    }
    friend std::ostream& operator<< (std::ostream& stream, const BinaryTree<T> &tree)
    {
        return stream;
    }

    Node<T>* begin_preorder()
    {
        return 0;
    }

    Node<T>* begin_postorder()
    {
        return 0;

    }
    Node<T>* begin_inorder()
    {
        return 0;
    }

        Node<T>* end_preorder()
    {
        return 0;
    }

    Node<T>* end_postorder()
    {
        return 0;

    }
    Node<T>* end_inorder()
    {
        return 0;
    }
    
    T* begin()
    {
        return 0;
    }
    T* end()
    {
        return 0;
    }
};
}