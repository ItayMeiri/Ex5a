#include "BinaryTree.hpp"
#include "doctest.h"
using namespace ariel;

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class MyClass {
public:
  string myString;
  int myInt;
};

TEST_CASE("Try to initiate with different types") { //
  CHECK_NOTHROW(BinaryTree<int> tree_of_ints);
  CHECK_NOTHROW(BinaryTree<double> tree_of_ints);
  CHECK_NOTHROW(BinaryTree<std::string> tree_of_ints);
  CHECK_NOTHROW(BinaryTree<bool> tree_of_ints);
  CHECK_NOTHROW(BinaryTree<MyClass> tree_of_myClass);
}

TEST_CASE("int tree") {
  BinaryTree<int> tree_of_ints;

  tree_of_ints.add_root(1)
      .add_left(1, 9)  // Now 9 is the left child of 1
      .add_left(9, 4)  // Now 4 is the left child of 9
      .add_right(9, 5) // Now 5 is the right child of 9
      .add_right(1, 3) // Now 3 is the right child of 1
      .add_left(1, 2); // Now 2 is the left child of 1, instead of 9 (the
                       // children of 9 remain in place)
  SUBCASE("preorder") {
    // prints: 1 2 4 5 3
    vector<int> answer{1, 2, 4, 5, 3};
    auto it2 = answer.begin();
    for (auto it = tree_of_ints.begin_preorder();
         it != tree_of_ints.end_preorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
    CHECK_EQ(it2, answer.end()); // make sure they all went through
  }
  SUBCASE("postorder") {
    // 4 5 2 3 1
    vector<int> answer{4, 5, 2, 3, 1};
    auto it2 = answer.begin();
    for (auto it = tree_of_ints.begin_postorder();
         it != tree_of_ints.end_postorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
    CHECK_EQ(it2, answer.end()); // make sure they all went through
  }

  SUBCASE("inorder") {
    // 4 2 5 1 3
    vector<int> answer{4, 2, 5, 1, 3};
    auto it2 = answer.begin();
    for (auto it = tree_of_ints.begin_inorder();
         it != tree_of_ints.end_inorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
    CHECK_EQ(it2, answer.end()); // make sure they all went through
  }

  SUBCASE("For each") {
    // 4 2 5 1 3
    vector<int> answer{4, 2, 5, 1, 3};
    auto it2 = answer.begin();
    for (int element : tree_of_ints) {
      CHECK_EQ(*it2, element);
      it2++;
    }
    CHECK_EQ(it2, answer.end());


  }

  SUBCASE("Test replace") {
    CHECK_NOTHROW(tree_of_ints.add_root(99));

    vector<int> answer{99, 2, 4, 5, 3};
    auto it2 = answer.begin();
    for (auto it = tree_of_ints.begin_preorder();
         it != tree_of_ints.end_preorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
  }

  SUBCASE("Test throw") {
    CHECK_THROWS(tree_of_ints.add_left(100, 2));
    CHECK_THROWS(tree_of_ints.add_right(100, 2));
  }
}

TEST_CASE("string tree") {
  BinaryTree<string> tree_of_strings;

  tree_of_strings.add_root("1")
      .add_left("1", "9")  // Now 9 is the left child of 1
      .add_left("9", "4")  // Now 4 is the left child of 9
      .add_right("9", "5") // Now 5 is the right child of 9
      .add_right("1", "3") // Now 3 is the right child of 1
      .add_left("1", "2");
  SUBCASE("preorder") {
    // prints: 1 2 4 5 3
    vector<string> answer{"1", "2", "4", "5", "3"};
    auto it2 = answer.begin();
    for (auto it = tree_of_strings.begin_preorder();
         it != tree_of_strings.end_preorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
    CHECK_EQ(it2, answer.end()); // make sure they all went through
  }
  SUBCASE("postorder") {
    // 4 5 2 3 1
    vector<string> answer{"4", "5", "2", "3", "1"};
    auto it2 = answer.begin();
    for (auto it = tree_of_strings.begin_postorder();
         it != tree_of_strings.end_postorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
    CHECK_EQ(it2, answer.end()); // make sure they all went through
  }

  SUBCASE("inorder") {
    // 4 2 5 1 3
    vector<string> answer{"4", "2", "5", "1", "3"};
    auto it2 = answer.begin();
    for (auto it = tree_of_strings.begin_inorder();
         it != tree_of_strings.end_inorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
    CHECK_EQ(it2, answer.end()); // make sure they all went through
  }

  SUBCASE("For each") {
    // 4 2 5 1 3
    vector<string> answer{"4", "2", "5", "1", "3"};
    auto it2 = answer.begin();
    for (string str : tree_of_strings) {
      CHECK_EQ(*it2, str);
      it2++;
    }
    CHECK_EQ(it2, answer.end());
  }

  SUBCASE("Test replace") {
    CHECK_NOTHROW(tree_of_strings.add_root("99"));

    vector<string> answer{"99", "2", "4", "5", "3"};
    auto it2 = answer.begin();
    for (auto it = tree_of_strings.begin_preorder();
         it != tree_of_strings.end_preorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
  }
  SUBCASE("Test throw") {
    CHECK_THROWS(tree_of_strings.add_left("100", "2"));
    CHECK_THROWS(tree_of_strings.add_right("100", "2"));
  }
}

TEST_CASE("double tree") {
  BinaryTree<double> tree_of_doubles;

  tree_of_doubles.add_root(1)
      .add_left(1, 9)  // Now 9 is the left child of 1
      .add_left(9, 4)  // Now 4 is the left child of 9
      .add_right(9, 5) // Now 5 is the right child of 9
      .add_right(1, 3) // Now 3 is the right child of 1
      .add_left(1, 2); // Now 2 is the left child of 1, instead of 9 (the
                       // children of 9 remain in place)
  SUBCASE("preorder") {
    // prints: 1 2 4 5 3
    vector<double> answer{1, 2, 4, 5, 3};
    auto it2 = answer.begin();
    for (auto it = tree_of_doubles.begin_preorder();
         it != tree_of_doubles.end_preorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
    CHECK_EQ(it2, answer.end()); // make sure they all went through
  }
  SUBCASE("postorder") {
    // 4 5 2 3 1
    vector<double> answer{4, 5, 2, 3, 1};
    auto it2 = answer.begin();
    for (auto it = tree_of_doubles.begin_postorder();
         it != tree_of_doubles.end_postorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
    CHECK_EQ(it2, answer.end()); // make sure they all went through
  }

  SUBCASE("inorder") {
    // 4 2 5 1 3
    vector<double> answer{4, 2, 5, 1, 3};
    auto it2 = answer.begin();
    for (auto it = tree_of_doubles.begin_inorder();
         it != tree_of_doubles.end_inorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
    CHECK_EQ(it2, answer.end()); // make sure they all went through
  }

  SUBCASE("For each") {
    // 4 2 5 1 3
    vector<double> answer{4, 2, 5, 1, 3};
    auto it2 = answer.begin();
    for (int element : tree_of_doubles) {
      CHECK_EQ(*it2, element);
      it2++;
    }

    CHECK_EQ(it2, answer.end());
  }

  SUBCASE("Test replace") {
    CHECK_NOTHROW(tree_of_doubles.add_root(99));

    vector<double> answer{99, 2, 4, 5, 3};
    auto it2 = answer.begin();
    for (auto it = tree_of_doubles.begin_preorder();
         it != tree_of_doubles.end_preorder(); ++it) {
      CHECK_EQ(*it2, *it);
      it2++;
    }
  }

  SUBCASE("Test throw") {
    CHECK_THROWS(tree_of_doubles.add_left(100, 2));
    CHECK_THROWS(tree_of_doubles.add_right(100, 2));
  }
}