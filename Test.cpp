#include "sources/BinaryTree.hpp"
#include <array>
#include "doctest.h"
using namespace ariel;

using namespace std;

TEST_CASE("TEST ITERATORS")
{
    vector<int> a{1, 2, 3, 4, 5, 6};
    vector<int> res;
    vector<int> expected_inorder{4, 2, 5, 1, 6, 3};
    vector<int> expected_preorder{1, 2, 4, 5, 3, 6};
    vector<int> expected_postorder{4, 5, 2, 6, 3, 1};
    BinaryTree<int> tree;
    tree.add_root(a.at(0))
        .add_left(a.at(0), a.at(1))
        .add_right(a.at(0), a.at(2))
        .add_left(a.at(1), a.at(3))
        .add_right(a.at(1), a.at(4))
        .add_left(a.at(2), a.at(5));
    cout << tree << endl;

    /* NORMAL */

    for (auto i = tree.begin(); i != tree.end(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_inorder);
    res.clear();

    for (auto i : tree)
    {
        res.push_back(i);
    }
    CHECK_EQ(res, expected_inorder);
    res.clear();

    for (auto i = tree.begin_inorder(); i != tree.end_inorder(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_inorder);
    res.clear();

    for (auto i = tree.begin_preorder(); i != tree.end_preorder(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_preorder);
    res.clear();

    for (auto i = tree.begin_postorder(); i != tree.end_postorder(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_postorder);
}

TEST_CASE("EXCEPTIONS")
{
    vector<int> a{1, 2, 3, 4, 5, 6};
    BinaryTree<int> tree;
    tree.add_root(a.at(0))
        .add_left(a.at(0), a.at(1))
        .add_right(a.at(0), a.at(2))
        .add_left(a.at(1), a.at(3))
        .add_right(a.at(1), a.at(4))
        .add_left(a.at(2), a.at(5));
    cout << tree << endl;
    CHECK_THROWS(tree.add_left(7, 8));
    CHECK_THROWS(tree.add_right(7, 8));
    CHECK_NOTHROW(tree.add_root(8));
    CHECK_NOTHROW(tree.add_left(4, 8));
    CHECK_NOTHROW(tree.add_right(4, 8));
}

TEST_CASE("CHANGES")
{
    vector<int> a{1, 2, 3, 4, 5, 6};
    vector<int> res;
    vector<int> expected_inorder{4, 2, 5, 1, 6, 3};
    vector<int> expected_preorder{1, 2, 4, 5, 3, 6};
    vector<int> expected_postorder{4, 5, 2, 6, 3, 1};
    BinaryTree<int> tree;
    tree.add_root(a.at(0))
        .add_left(a.at(0), a.at(1))
        .add_right(a.at(0), a.at(2))
        .add_left(a.at(1), a.at(3))
        .add_right(a.at(1), a.at(4))
        .add_left(a.at(2), a.at(5));

    tree.add_root(0);
    expected_inorder.at(3) = 0;
    expected_preorder.at(0) = 0;
    expected_postorder.at(5) = 0;
    cout << tree << endl;

    for (auto i = tree.begin(); i != tree.end(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_inorder);
    res.clear();

    for (auto i : tree)
    {
        res.push_back(i);
    }
    CHECK_EQ(res, expected_inorder);
    res.clear();

    for (auto i = tree.begin_inorder(); i != tree.end_inorder(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_inorder);
    res.clear();

    for (auto i = tree.begin_preorder(); i != tree.end_preorder(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_preorder);
    res.clear();

    for (auto i = tree.begin_postorder(); i != tree.end_postorder(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_postorder);
}

TEST_CASE("CLASSES")
{
    vector<string> a{"1", "2", "3", "4", "5", "6"};
    vector<string> res;
    vector<string> expected_inorder{"4", "2", "5", "1", "6", "3"};
    vector<string> expected_preorder{"1", "2", "4", "5", "3", "6"};
    vector<string> expected_postorder{"4", "5", "2", "6", "3", "1"};
    BinaryTree<string> tree;
    tree.add_root(a.at(0))
        .add_left(a.at(0), a.at(1))
        .add_right(a.at(0), a.at(2))
        .add_left(a.at(1), a.at(3))
        .add_right(a.at(1), a.at(4))
        .add_left(a.at(2), a.at(5));
    cout << tree << endl;

    for (auto i = tree.begin(); i != tree.end(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_inorder);
    res.clear();

    for (auto i : tree)
    {
        res.push_back(i);
    }
    CHECK_EQ(res, expected_inorder);
    res.clear();

    for (auto i = tree.begin_inorder(); i != tree.end_inorder(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_inorder);
    res.clear();

    for (auto i = tree.begin_preorder(); i != tree.end_preorder(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_preorder);
    res.clear();

    for (auto i = tree.begin_postorder(); i != tree.end_postorder(); ++i)
    {
        res.push_back(*i);
    }
    CHECK_EQ(res, expected_postorder);
}

// TEST_CASE("FLY_CHARTER")
// {
//     CHECK_THROWS(player_d.fly_direct(City::Tokyo));
//     CHECK_NOTHROW(player_d.fly_direct(City::Tokyo));
// }

// TEST_CASE("FLY_SHUTTLE")
// {
//     CHECK_NOTHROW(player_d.fly_direct(City::Tokyo));
// }

// TEST_CASE("BUILD")
// {
//     CHECK_THROWS(player_d.build());
//     CHECK_NOTHROW(player_oe.build());
// }
