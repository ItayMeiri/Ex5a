#pragma once

#include <iostream>
#include <map>
#include <vector>

namespace ariel {
template <class T> class Node {
public:
  Node<T> *root;
  Node<T> *left;
  Node<T> *right;
  T t;
  Node<T>() {}
  Node<T>(T t) {
    this->t = t;
    root = nullptr;
    left = nullptr;
    right = nullptr;
  }
  int size() {
    int ans = 2;
    if (left == nullptr) {
      ans--;
    }
    if (right == nullptr) {
      ans--;
    }
    return ans;
  }
  friend std::ostream &operator<<(std::ostream &stream, const Node<T> &node) {
    return stream << node.t;
  }
};

template <class T> class BinaryTree {
public:
  std::vector<T> _it2;
  std::map<T, Node<T>> nodes;
  T root;
  BinaryTree<T>() {}
  BinaryTree<T> &add_root(T root) {

    if (nodes.find(this->root) != nodes.end()) {
      nodes.at(this->root).t = root;
    }
    nodes.insert(std::make_pair(root, Node<T>(root)));
    this->root = nodes.at(root).t;
    return *this;
  }
  BinaryTree<T> &add_left(T t1, T t2) {
    if (nodes.find(t1) == nodes.end()) {
      throw std::invalid_argument("left doesn't exist");
    }

    if (nodes.find(t2) == nodes.end()) {
      nodes.insert(std::make_pair(t2, Node<T>(t2))); // create t2
    }

    if (nodes.at(t1).left != nullptr) {
      // link the new left with the children of old left
      nodes.at(t2).left = nodes.at(t1).left->left;
      nodes.at(t2).right = nodes.at(t1).left->right;
      // link children with new parent
      nodes.at(t1).left->right->root = &nodes.at(t2);
      nodes.at(t1).left->left->root = &nodes.at(t2);

      nodes.erase(nodes.at(t1).left->t); // erase old left from nodes list
    }

    nodes.at(t1).left = &nodes.at(t2);
    nodes.at(t2).root = &nodes.at(t1);
    return *this;
  }
  BinaryTree<T> &add_right(T t1, T t2) {
    if (nodes.find(t1) == nodes.end()) {
      throw std::invalid_argument("right doesn't exist");
    }
    if (nodes.find(t2) == nodes.end()) {
      nodes.insert(std::make_pair(t2, Node<T>(t2))); // create t2
    }

    if (nodes.at(t1).right != nullptr) {
      // link the new right with the children of old right
      nodes.at(t2).left = nodes.at(t1).right->left;
      nodes.at(t2).right = nodes.at(t1).right->right;
      // link children with new parent
      nodes.at(t1).right->right->root = &nodes.at(t2);
      nodes.at(t1).right->left->root = &nodes.at(t2);

      nodes.erase(nodes.at(t1).right->t); // erase old left from nodes list
    }
    nodes.at(t1).right = &nodes.at(t2);
    nodes.at(t2).root = &nodes.at(t1);
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &stream,
                                  const BinaryTree<T> &tree) {
    return stream;
  }

  void build_preorder(Node<T> *node) {
    if (node == nullptr) {
      return;
    }

    _it2.push_back(node->t);
    build_preorder(node->left);
    build_preorder(node->right);
  }

  void build_postorder(Node<T> *node) {
    if (node == nullptr) {
      return;
    }
    build_postorder(node->left);
    build_postorder(node->right);
    _it2.push_back(node->t);
  }

  void build_inorder(Node<T> *node) {
    if (node == nullptr) {
      return;
    }
    build_inorder(node->left);
    _it2.push_back(node->t);
    build_inorder(node->right);
  }
  auto begin_preorder() {
    build_preorder(&nodes.at(root));
    return _it2.begin();
  }

  auto begin_postorder() {
    build_postorder(&nodes.at(root));
    return _it2.begin();
  }
  auto begin_inorder() {
    build_inorder(&nodes.at(root));
    return _it2.begin();
  }

  auto end_preorder() { return _it2.end(); }

  auto end_postorder() { return _it2.end(); }
  auto end_inorder() { return _it2.end(); }

  auto begin() {
    build_inorder(&nodes.at(root));
    return _it2.begin();
  }
  auto end() { return _it2.end(); }
};

} // namespace ariel