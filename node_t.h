//
// Created by vcherkov on 12.04.17.
//

#ifndef LAB07_01_NODE_T_H
#define LAB07_01_NODE_T_H

#include <memory>

//#define node_T node_t <T>

template <typename T>
struct node_t{
    node_t(const T &data);
    node_t(const node_t &rhs);

    const node_t operator=(const node_t &rhs);

    std::shared_ptr <node_t> left;
    std::shared_ptr <node_t> right;
    std::shared_ptr <node_t> parent;

    size_t count;
    T data;
};


template <typename T>
node_t <T> ::node_t(const T &data):
    data(data),
    count(1),
    left(nullptr),
    right(nullptr),
    parent(nullptr)
{ }

template <typename T>
node_t <T>::node_t(const node_t &rhs):
    data(rhs.data),
    count(rhs.count),
    left(rhs.left),
    right(rhs.right),
    parent(rhs.parent)
{ }

template <typename T>
const node_t <T> node_t <T>::operator=(const node_t &rhs) {
    if(this == &rhs)
        return *this;

    node_t new_value(data);
    std::swap(*this, new_value);

    return *this;
}

#endif //LAB07_01_NODE_T_H
