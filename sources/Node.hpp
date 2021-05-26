#pragma once
namespace ariel
{
    template <typename T>
    class Node
    {
    public:
        T _value;
        Node<T> *_left;
        Node<T> *_right;

        void add_right(){
            this->_right = new Node<T>;
        }
        void add_left(){
            this->_left = new Node<T>;
        }
        Node() : _left(nullptr), _right(nullptr) {}
        // Node(T val) : _value(val), _left(nullptr), _right(nullptr) {}

        ~Node(){
            if(this->_right != nullptr){
                delete this->_right;
            }
            if(this->_left != nullptr){
                delete this->_left;
            }
        }
    };
}