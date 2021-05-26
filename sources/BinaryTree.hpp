#pragma once
#include "Node.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    private:
        Node<T> _root;

        Node<T> *find(T val)
        {
            return find(val, &(this->_root));
        }

        Node<T> *find(T val, Node<T> *currentNode)
        {
            Node<T> *node1 = nullptr, *node2 = nullptr;
            if (val == currentNode->_value)
            {
                return currentNode;
            }
            if ((currentNode->_left == nullptr) && (currentNode->_right == nullptr))
            {
                return nullptr;
            }
            if (currentNode->_left != nullptr)
            {
                node1 = find(val, currentNode->_left);
            }
            if (node1 != nullptr)
            {
                return node1;
            }
            if (currentNode->_right != nullptr)
            {
                node2 = find(val, currentNode->_right);
            }
            if (node2 != nullptr)
            {
                return node2;
            }
            return nullptr;
        }

        // int depth(Node<T> *currentNode)
        // {
        //     int r_depth = 0, l_depth = 0;
        //     if (currentNode->_right != nullptr)
        //     {
        //         r_depth = depth(currentNode->_right);
        //     }
        //     if (currentNode->_left != nullptr)
        //     {
        //         l_depth = depth(currentNode->_left);
        //     }
        //     return (max(r_depth, l_depth) + 1);
        // }

        // int depth()
        // {
        //     return depth(this->_root);
        // }

        static void printTree(std::ostream &os, const std::string &prefix, const Node<T> *node, bool isLeft)
        {
            if (node != nullptr)
            {
                os << prefix;
                if (isLeft)
                {
                    os << "├──";
                }
                else
                {
                    os << "└──";
                }
                os << node->_value << std::endl;

                printTree(os, prefix + (isLeft ? "│   " : "    "), node->_left, true);
                printTree(os, prefix + (isLeft ? "│   " : "    "), node->_right, false);
            }
        }

    public:
        BinaryTree<T> &add_root(T val)
        {
            this->_root._value = val;
            return *this;
        }

        BinaryTree<T> &add_left(T parent, T child)
        {
            Node<T> *parentNode = find(parent);
            if (parentNode == nullptr)
            {
                throw std::invalid_argument("First value is not in the tree.");
            }
            if (parentNode->_left == nullptr)
            {
                // parentNode->_left = &Node<T>();
                parentNode->add_left();
            }
            parentNode->_left->_value = child;
            return *this;
        }

        BinaryTree<T> &add_right(T parent, T child)
        {
            Node<T> *parentNode = find(parent);
            if (parentNode == nullptr)
            {
                throw std::invalid_argument("First value is not in the tree.");
            }
            if (parentNode->_right == nullptr)
            {
                // parentNode->_right = &Node<T>();
                parentNode->add_right();
            }
            parentNode->_right->_value = child;
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree)
        {
            printTree(os, std::string(""), &tree._root, false);
            return os;
        }

        class iterator
        {
        public:
            enum Order
            {
                PREORDER,
                INORDER,
                POSTORDER
            };

        private:
            Node<T> *ptr_current;
            Node<T> *_root;
            Order _type; // 0 = preorder, 1 = inorder, 2 = postorder

        public:
            iterator(Node<T> *root, Node<T> *curr, Order type) : _type(type), _root(root), ptr_current(curr)
            {
            }
            iterator(Node<T> *root, Order type) : _type(type), _root(root)
            {
                this->ptr_current = root;
            }

            T &operator*() const
            {
                return ptr_current->_value;
            }

            T *operator->() const
            {
                return &(ptr_current->_value);
            }

            bool operator==(const iterator &rhs) const
            {
                return (ptr_current == rhs.ptr_current);
            }

            bool operator!=(const iterator &rhs) const
            {
                return (ptr_current != rhs.ptr_current);
            }

            /*
            Node<T> *inorder_inc(Node<T> *n, Node<T> *to_find)
            {
                static Node<T> *ptr_curr = n;
                static Node<T> *ptr_prev;
                static bool found = false;
                if (n->_left != nullptr)
                {
                    inorder_inc(n->_left);
                    if (found)
                    {
                        return ptr_curr;
                    }
                }
                ptr_prev = ptr_curr;
                ptr_current = n;
                if (ptr_prev == to_find)
                {
                    found = true;
                    return ptr_curr;
                }
                if (n->_right != nullptr)
                {
                    inorder_inc(n->_right);
                    if (found)
                    {
                        return ptr_curr;
                    }
                }
            }

            Node<T> *preorder_inc(Node<T> *n, Node<T> *to_find)
            {
                static Node<T> *ptr_curr = n;
                static Node<T> *ptr_prev;
                static bool found = false;

                ptr_prev = ptr_curr;
                ptr_current = n;
                if (ptr_prev == to_find)
                {
                    found = true;
                    return ptr_curr;
                }

                if (n->_left != nullptr)
                {
                    inorder_inc(n->_left);
                    if (found)
                    {
                        return ptr_curr;
                    }
                }

                if (n->_right != nullptr)
                {
                    inorder_inc(n->_right);
                    if (found)
                    {
                        return ptr_curr;
                    }
                }
            }

            Node<T> *postorder(Node<T> *n, Node<T> *to_find)
            {
                static Node<T> *ptr_curr = n;
                static Node<T> *ptr_prev;
                static bool found = false;

                if (n->_left != nullptr)
                {
                    inorder_inc(n->_left);
                    if (found)
                    {
                        return ptr_curr;
                    }
                }

                if (n->_right != nullptr)
                {
                    inorder_inc(n->_right);
                    if (found)
                    {
                        return ptr_curr;
                    }
                }

                ptr_prev = ptr_curr;
                ptr_current = n;
                if (ptr_prev == to_find)
                {
                    found = true;
                    return ptr_curr;
                }
            }
            */

            // Node<T> *inc(Node<T> *n, Node<T> *to_find, bool restart = false)
            // {
            //     static Node<T> *ptr_curr;
            //     static Node<T> *ptr_prev;
            //     static bool found;
            //     if (restart)
            //     {
            //         found = false;
            //         ptr_curr = n;
            //         ptr_prev = nullptr;
            //     }
            //     else
            //     {
            //         ptr_prev = ptr_curr;
            //         ptr_curr = n;
            //     }

            //     if (this->_type == Order::PREORDER)
            //     {

            //         if (ptr_prev == to_find)
            //         {
            //             found = true;
            //             ptr_curr = n;
            //             return ptr_curr;
            //         }
            //         if (restart)
            //         {
            //             ptr_prev = ptr_curr;
            //             ptr_curr = n;
            //         }
            //     }

            //     if (n->_left != nullptr)
            //     {
            //         inc(n->_left, to_find);
            //         if (found)
            //         {
            //             return ptr_curr;
            //         }
            //         // else
            //         // {
            //         //     Node<T> *tmp = ptr_curr;
            //         //     ptr_curr = ptr_prev;
            //         //     ptr_prev = tmp;
            //         // }
            //     }

            //     if (this->_type == Order::INORDER)
            //     {
            //         if (restart)
            //         {
            //             ptr_prev = ptr_curr;
            //             ptr_curr = n;
            //         }
            //         if (ptr_prev == to_find)
            //         {
            //             found = true;
            //             ptr_curr = n;
            //             return ptr_curr;
            //         }
            //     }

            //     if (n->_right != nullptr)
            //     {
            //         inc(n->_right, to_find);
            //         if (found)
            //         {
            //             return ptr_curr;
            //         }
            //     }
            //     if (restart)
            //     {
            //         ptr_prev = ptr_curr;
            //         ptr_curr = n;
            //     }
            //     if (this->_type == Order::POSTORDER)
            //     {
            //         if (ptr_prev == to_find)
            //         {
            //             found = true;
            //             ptr_curr = n;
            //             return ptr_curr;
            //         }
            //         // if (restart)
            //         // {
            //         //     ptr_prev = ptr_curr;
            //         //     ptr_curr = n;
            //         // }
            //     }
            //     return nullptr;
            // }

            void inc(Node<T> *n, std::queue<Node<T>*>& q)
            {
                if (this->_type == Order::PREORDER)
                {
                    q.push(n);
                }

                if (n->_left != nullptr)
                {
                    inc(n->_left, q);
                }

                if (this->_type == Order::INORDER)
                {
                    q.push(n);
                }

                if (n->_right != nullptr)
                {
                    inc(n->_right, q);
                }

                if (this->_type == Order::POSTORDER)
                {
                    q.push(n);
                }
            }

            iterator &operator++()
            {
                // this->ptr_current = inc(this->_root, this->ptr_current, true);
                // return *this;
                std::queue<Node<T>*> q;
                inc(this->_root, q);
                while(this->ptr_current != q.front()){
                    q.pop();
                }
                q.pop();
                this->ptr_current = q.front();
                return *this;

            }

            const iterator operator++(int)
            {
                iterator temp = *this;
                this->ptr_current = inc(this->_root, this->ptr_current, true);
                return temp;
            }
        };

        iterator begin_preorder()
        {
            return iterator(&(this->_root), iterator::Order::PREORDER);
        }
        iterator end_preorder()
        {
            return iterator(nullptr, iterator::Order::PREORDER);
        }

        iterator begin_inorder()
        {
            Node<T> *p = &(this->_root);
            while (p->_left != nullptr)
            {
                p = p->_left;
            }
            return iterator(&(this->_root), p, iterator::Order::INORDER);
        }
        iterator end_inorder()
        {
            return iterator(nullptr, iterator::Order::INORDER);
        }

        iterator begin_postorder()
        {
            Node<T> *p = &(this->_root);
            while (p->_left != nullptr)
            {
                p = p->_left;
            }
            return iterator(&(this->_root), p, iterator::Order::POSTORDER);
        }
        iterator end_postorder()
        {
            return iterator(nullptr, iterator::Order::POSTORDER);
        }

        iterator begin()
        {
            Node<T> *p = &(this->_root);
            while (p->_left != nullptr)
            {
                p = p->_left;
            }
            return iterator(&(this->_root), p, iterator::Order::INORDER);
        }
        iterator end()
        {
            return iterator(nullptr, iterator::Order::INORDER);
        }
    };
}