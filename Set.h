//
// Created by vcherkov on 12.04.17.
//

#ifndef LAB07_01_SET_H
#define LAB07_01_SET_H

#include <initializer_list>
#include <functional>
#include <memory>
#include <iterator>
#include <iostream>
#include "node_t.h"

#define TEMPLATE_SET template <typename T, typename Cmp_t, typename Alloc>
#define SET Set <T, Cmp_t, Alloc>

template <typename T, typename Cmp_t, typename Alloc>
class iterator_t;

template <typename T, typename Cmp_t = std::less <T>,
        typename Alloc = std::allocator <T>>
class Set {
    typedef std::shared_ptr <node_t <T>> pnode_t;

public: // Итераторы

    typedef iterator_t <T, Cmp_t, Alloc> iterator;
    typedef iterator_t <const T, Cmp_t, Alloc> const_iterator;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

public:
    Set();
    Set(const Set &rhs);
    Set(const std::initializer_list <T>  &l);
    Set(Set &&rhs);
    const SET &operator=(const SET &rhs);


    size_t get_size() const;
    void insert(const T &new_data);
    void erase(const T &key);
    void clear();

/*
public:
    static void* operator new(size_t s, Alloc& allct) {
        return allct.allocate(s);
    }
    static void* operator new(size_t s, Alloc* allct) {
        return allct->allocate(s);
    }

    static void operator delete(void*, size_t) { } // *1
    static void operator delete(void*, Alloc*) { }
    static void operator delete(void*, Alloc&) { }
private:
    static void* operator new(size_t s);
*/

private:
    size_t size;
    pnode_t head;
    Cmp_t comparator;
    Alloc allocator;

    pnode_t copy_tree(const pnode_t &from,
                       const pnode_t &parent = nullptr);

    void insert(pnode_t &new_node, pnode_t &head);
    iterator find(const T &key);
};

// -------------------------------------------------------
//  Конструкторы и присваивание
// -------------------------------------------------------

TEMPLATE_SET
SET::Set():
        head(nullptr),
        size(0),
        comparator(),
        allocator()
{}

TEMPLATE_SET
SET::Set(const Set &rhs):
        size(rhs.size),
        comparator(),
        head(nullptr),
        allocator()
{
    head = copy_tree(rhs.head);
    std::cout << "copy" << std::endl;
}

TEMPLATE_SET
SET::Set(const std::initializer_list<T> &l):
    size(0),
    comparator(),
    allocator(),
    head(nullptr)
{
    auto it = l.begin();
    while (it != l.end()){
        insert(*it);
        std::cout << ".";
        it++;
    }
    std::cout << "initializer" << std::endl;
}

TEMPLATE_SET
SET::Set(Set &&rhs):
    size(rhs.size),
    comparator(),
    head(rhs.head),
    allocator()
{
    rhs.size = 0;
    rhs.head = pnode_t(nullptr);

    std::cout << "move" << std::endl;
}

TEMPLATE_SET
const SET &SET::operator=(const Set &rhs){
    if(this == &rhs)
        return *this;

    Set new_set(rhs);
    std::swap(new_set, *this);

    return *this;
}

// -------------------------------------------------------
//  Получение размера
// -------------------------------------------------------

TEMPLATE_SET
size_t SET::get_size() const {
    return size;
}

// -------------------------------------------------------
// Копирование дерева
// -------------------------------------------------------

TEMPLATE_SET
typename SET::pnode_t SET::copy_tree(const Set::pnode_t &from,
                        const Set::pnode_t &parent) {
    pnode_t new_node(from);

    if(new_node == nullptr)
        return new_node;

    new_node->parent = parent;
    new_node->left = copy_tree(from->left, new_node);
    new_node->right = copy_tree(from->right, new_node);

    return new_node;
}

// -------------------------------------------------------
//  Вставка элемента
// -------------------------------------------------------

TEMPLATE_SET
void SET::insert(const T &new_data) {
    pnode_t new_node(new node_t <T> (new_data));

    if(head == nullptr) {
        size = 1;
        head = new_node;
        return;
    }

    insert(new_node, head);
    size++;
}

TEMPLATE_SET
void SET::insert(pnode_t &new_node, pnode_t &head) {
    // new_value < data
    if(comparator(new_node->data, head->data)) {
        if(head->left)
            insert(new_node, head->left);
        else {
            head->left = new_node;
            new_node->parent = head;
        }

        return;
    }

    // new_value > data
    if(comparator(head->data, new_node->data)) {
        if(head->right)
            insert(new_node, head->right);
        else {
            head->right = new_node;
            new_node->parent = head;
        }

        return;
    }

    // new_value == data
    head->count++;
}

// -------------------------------------------------------
//  Поиск по дереву
// -------------------------------------------------------

TEMPLATE_SET
typename SET::iterator SET::find(const T &key) {
    if(!size)
        return iterator(nullptr);

    pnode_t temp_head = head;
    while(temp_head){
        if(comparator(key, temp_head->data)) {
            temp_head = temp_head->left;
            continue;
        }
        if(comparator(temp_head->data, key)) {
            temp_head = temp_head->right;
            continue;
        }
        break;
    }
    return iterator(temp_head);
}

// -------------------------------------------------------
//  Удаление элемента и очистка класса
// -------------------------------------------------------

TEMPLATE_SET
void SET::erase(const T &key) {
    if(!size)
        return;

    iterator it = find(key);
    if(it == end())
        return;

    if(it.p->right == nullptr)
        it.p->right = it.p->left;
    else {
        pnode_t tail = it.p->right;
        while (tail->left)
            tail = tail->left;
        tail->left = it.p->left;
        if(tail->left)
            tail->left->parent = tail;

    }
    it.p->left = pnode_t(nullptr);

    // if head
    if(it.p->parent == nullptr) {
        head = it.p->right;
        if(head)
            head->parent = nullptr;
    }
    else {
        if(!it.p->right) {
            if(it.p->parent->left == it.p)
                it.p->parent->left = pnode_t(nullptr);
            else
                it.p->parent->right = pnode_t(nullptr);
        }
        else {
            pnode_t parent = it.p->parent;
            it.p = it.p->right;
            it.p->parent = parent;
        }
    }

    size--;
}

TEMPLATE_SET
void SET::clear() {
    size = 0;
    head = pnode_t(nullptr);
}

// -------------------------------------------------------
//  Методы итераторные класса Set
// -------------------------------------------------------

TEMPLATE_SET
typename SET::const_iterator SET::end() const {
    return const_iterator();
}

TEMPLATE_SET
typename SET::iterator SET::end() {
    return iterator();
}

TEMPLATE_SET
typename SET::iterator SET::begin() {
    pnode_t temp_head = head;

    if(!temp_head)
        return iterator(nullptr);

    while(temp_head->left)
        temp_head = temp_head->left;
    return iterator(temp_head);
}

TEMPLATE_SET
typename SET::const_iterator SET::begin() const {
    pnode_t temp_head = head;

    if(!temp_head)
        return const_iterator(nullptr);

    while(temp_head->left)
        temp_head = temp_head->left;
    return const_iterator(temp_head);
}

// -------------------------------------------------------
// -------------------------------------------------------
//  Класс Итератор
// -------------------------------------------------------
// -------------------------------------------------------

#define TEMPLATE_ITERATOR template <typename T, typename Cmp_t, typename Alloc>
#define ITERATOR iterator_t <T, Cmp_t, Alloc>

TEMPLATE_ITERATOR
class iterator_t: public std::iterator<std::input_iterator_tag, T> {
    typedef std::shared_ptr <node_t <T>> pnode_t;
    friend class Set <T, Cmp_t>;

private:
    iterator_t();
    iterator_t(const std::shared_ptr <node_t <T>> &p);

public:
    iterator_t(const iterator_t &it);

    bool operator!=(iterator_t const& rhs) const;
    bool operator==(iterator_t const& rhs) const;
    typename iterator_t::reference operator*() const;
    iterator_t& operator++(/*Set<T, Cmp_t> nothing*/);
    iterator_t& operator++(int nothing);

private:
    pnode_t p;

    void increment(pnode_t ancestor);
};

TEMPLATE_ITERATOR
ITERATOR::iterator_t():
        p(nullptr)
{ }

TEMPLATE_ITERATOR
ITERATOR::iterator_t(const std::shared_ptr <node_t <T>> &p):
        p(p)
{ }

TEMPLATE_ITERATOR
ITERATOR::iterator_t(const iterator_t &it):
        p(it.p)
{ }

TEMPLATE_ITERATOR
bool ITERATOR::operator!=(iterator_t const &rhs) const {
    return rhs.p != p;
}

TEMPLATE_ITERATOR
bool ITERATOR::operator==(iterator_t const &rhs) const {
    return rhs.p == p;
}

TEMPLATE_ITERATOR
typename ITERATOR::reference ITERATOR::operator*() const {
    return p->data;
}


TEMPLATE_ITERATOR
ITERATOR &ITERATOR::operator++(/*Set<T, Cmp_t> nothing*/) {
    increment(p->left);
}

TEMPLATE_ITERATOR
ITERATOR &ITERATOR::operator++(int nothing) {
    increment(p->left);
}


TEMPLATE_ITERATOR
void ITERATOR::increment(pnode_t ancestor) {
    if(p == nullptr)
        return;

    if(p->right == nullptr || p->right == ancestor) {
        if(p->parent == nullptr) {
            p = nullptr;
            return;
        }
        if(p->parent->right == p) {
            ancestor = p;
            p = p->parent;
            increment(ancestor);
            return;
        }
        p = p->parent;
        return;
    }
    p = p->right;
    while(p->left)
        p = p->left;
}




#endif //LAB07_01_SET_H
