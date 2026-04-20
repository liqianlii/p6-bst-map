#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"
#include <sstream>

using namespace std;

TEST(testEmptyEmptyTree) {
  BinarySearchTree<int> tree;
  ASSERT_TRUE(tree.empty());
}

TEST(testEmptyNotEmptyTree) {
  BinarySearchTree<int> tree;
  tree.insert(5);
  ASSERT_EQUAL(tree.size(), 1);
  ASSERT_FALSE(tree.empty());
}

TEST(testSizeEmptyTree) {
  BinarySearchTree<int> tree;
  ASSERT_EQUAL(tree.size(), 0);
}

TEST(testSizeOneNodeTree) {
  BinarySearchTree<int> tree;
  tree.insert(5);
  ASSERT_EQUAL(tree.size(), 1);
}

TEST(testSizeManyNodesTree) {
  BinarySearchTree<int> tree;
  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  ASSERT_EQUAL(tree.size(), 5);
}

TEST(testHeightEmptyTree) {
  BinarySearchTree<int> tree;
  ASSERT_EQUAL(tree.height(), 0);
}

TEST(testHeightOneNodeTree) {
  BinarySearchTree<int> tree;
  tree.insert(5);
  ASSERT_EQUAL(tree.height(), 1);
}

TEST(testHeightManyNodesTree) {
  BinarySearchTree<int> tree;
  tree.insert(3);
  tree.insert(1);
  tree.insert(2);
  tree.insert(4);
  ASSERT_EQUAL(tree.height(), 3);
}

TEST(testHeightSizeStickTree) {
  BinarySearchTree<int> tree;
  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  ASSERT_EQUAL(tree.height(), 5);
  ASSERT_EQUAL(tree.size(), 5);
}

TEST(testtraverseInorderEmptyTree) {
  BinarySearchTree<int> tree;
  string expected = "";
  ostringstream oss;
  tree.traverse_inorder(oss);
  ASSERT_EQUAL(oss.str(), expected);
}

TEST(testtraverseInorderOneNodeTree) {
  BinarySearchTree<int> tree;
  tree.insert(1);
  string expected = "1 ";
  ostringstream oss;
  tree.traverse_inorder(oss);
  ASSERT_EQUAL(oss.str(), expected);
}

TEST(testtraverseInorderManyNodesTree) {
  BinarySearchTree<int> tree;
  tree.insert(8);
  tree.insert(4);
  tree.insert(5);
  tree.insert(2);
  tree.insert(1);
  tree.insert(3);
  tree.insert(7);
  tree.insert(6);
  string expected = "1 2 3 4 5 6 7 8 ";
  ostringstream oss;
  tree.traverse_inorder(oss);
  ASSERT_EQUAL(oss.str(), expected);
}

TEST(testtraversePreorderEmptyTree) {
  BinarySearchTree<int> tree;
  string expected = "";
  ostringstream oss;
  tree.traverse_preorder(oss);
  ASSERT_EQUAL(oss.str(), expected);
}

TEST(testtraversePreorderOneNodeTree) {
  BinarySearchTree<int> tree;
  tree.insert(1);
  string expected = "1 ";
  ostringstream oss;
  tree.traverse_preorder(oss);
  ASSERT_EQUAL(oss.str(), expected);
}

TEST(testtraversePreorderManyNodesTree) {
  BinarySearchTree<int> tree;
  tree.insert(8);
  tree.insert(4);
  tree.insert(5);
  tree.insert(2);
  tree.insert(1);
  tree.insert(3);
  tree.insert(7);
  tree.insert(6);
  string expected = "8 4 2 1 3 5 7 6 ";
  ostringstream oss;
  tree.traverse_preorder(oss);
  ASSERT_EQUAL(oss.str(), expected);
}

TEST(testCheckSortingInvariantEmptyTree) {
  BinarySearchTree<int> tree;
  ASSERT_TRUE(tree.check_sorting_invariant());
}

TEST(testCheckSortingInvariantOneNodeTree) {
  BinarySearchTree<int> tree;
  tree.insert(8);
  ASSERT_TRUE(tree.check_sorting_invariant());
}

TEST(testCheckSortingInvariantManyNodesTree) {
  BinarySearchTree<int> tree;
  tree.insert(4);
  tree.insert(5);
  tree.insert(2);
  tree.insert(1);
  auto i = tree.find(1);
  *i = 6;
  ASSERT_FALSE(tree.check_sorting_invariant());
}

TEST(testCheckSortingInvariantDuplicates) {
  BinarySearchTree<int> tree;
  tree.insert(4);
  tree.insert(5);
  tree.insert(2);
  tree.insert(1);
  auto i = tree.find(1);
  *i = 5;
  ASSERT_FALSE(tree.check_sorting_invariant());
}

TEST(testMinElementEmptyTree) {
  BinarySearchTree<int> tree;
  BinarySearchTree<int>::Iterator it = tree.min_element();
  ASSERT_TRUE(it == tree.end());
}

TEST(testMinElementOneNodeTree) {
  BinarySearchTree<int> tree;
  tree.insert(4);
  BinarySearchTree<int>::Iterator it = tree.min_element();
  ASSERT_EQUAL(*it, 4);
}

TEST(testMinElementManyNodesTree) {
  BinarySearchTree<int> tree;
  tree.insert(8);
  tree.insert(4);
  tree.insert(5);
  tree.insert(2);
  tree.insert(1);
  tree.insert(3);
  tree.insert(7);
  tree.insert(6);
  BinarySearchTree<int>::Iterator it = tree.min_element();
  ASSERT_EQUAL(*it, 1);
}

TEST(testMaxElementEmptyTree) {
  BinarySearchTree<int> tree;
  BinarySearchTree<int>::Iterator it = tree.max_element();
  ASSERT_TRUE(it == tree.end());
}

TEST(testMaxElementOneNodeTree) {
  BinarySearchTree<int> tree;
  tree.insert(4);
  BinarySearchTree<int>::Iterator it = tree.max_element();
  ASSERT_EQUAL(*it, 4);
}

TEST(testMaxElementManyNodesTree) {
  BinarySearchTree<int> tree;
  tree.insert(1);
  tree.insert(4);
  tree.insert(5);
  tree.insert(2);
  tree.insert(8);
  tree.insert(3);
  tree.insert(7);
  tree.insert(6);
  BinarySearchTree<int>::Iterator it = tree.max_element();
  ASSERT_EQUAL(*it, 8);
}

TEST(testMinGreaterThanElementEmptyTree) {
  BinarySearchTree<int> tree;
  BinarySearchTree<int>::Iterator it = tree.min_greater_than(1);
  ASSERT_TRUE(it == tree.end());
}

TEST(testMinGreaterThanElementOneNodeTree) {
  BinarySearchTree<int> tree;
  tree.insert(4);
  BinarySearchTree<int>::Iterator it = tree.min_greater_than(3);
  ASSERT_EQUAL(*it, 4);
}

TEST(testMinGreaterThanElementManyNodesTree) {
  BinarySearchTree<int> tree;
  tree.insert(1);
  tree.insert(4);
  tree.insert(5);
  tree.insert(2);
  tree.insert(8);
  tree.insert(3);
  tree.insert(7);
  tree.insert(6);
  BinarySearchTree<int>::Iterator it = tree.min_greater_than(5);
  ASSERT_EQUAL(*it, 6);
}

TEST(testFindEmptyTree) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.find(1) == tree.end());
}

TEST(testFindOneNodeTree) {
    BinarySearchTree<int> tree;
    tree.insert(1);
    ASSERT_EQUAL(*tree.find(1), 1);
    ASSERT_TRUE(tree.find(1) == tree.begin());
    ASSERT_TRUE(tree.find(2) == tree.end());
}

TEST(testFindManyNodesTree) {
    BinarySearchTree<int> tree;
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);
    tree.insert(2);
    tree.insert(8);
    tree.insert(3);
    tree.insert(7);
    tree.insert(6);
    ASSERT_EQUAL(*tree.find(1), 1);
    ASSERT_EQUAL(*tree.find(2), 2);
    ASSERT_EQUAL(*tree.find(3), 3);
    ASSERT_EQUAL(*tree.find(4), 4);
    ASSERT_EQUAL(*tree.find(5), 5);
    ASSERT_EQUAL(*tree.find(6), 6);
    ASSERT_EQUAL(*tree.find(7), 7);
    ASSERT_EQUAL(*tree.find(8), 8);
    ASSERT_TRUE(tree.find(1) == tree.begin());
    ASSERT_TRUE(tree.find(9) == tree.end());
}

TEST_MAIN()
