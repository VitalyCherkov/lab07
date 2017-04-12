//
// Created by vcherkov on 11.04.17.
//

#ifndef MY_STRING_STRING_H
#define MY_STRING_STRING_H

#include <memory>
#include <iostream>
#include <fstream>
#include <cstring>

class String {
public:
    String();
    String(const String &rhs);
    String(const char* data);
    String(const char* data, size_t len);

    const String &operator=(const String &rhs);

    ~String();

    void push_back(char symbol);
    void pop_back();
    char back() const throw(std::out_of_range);

    size_t get_length() const;

    bool operator<(const String &rhs) const;
    bool operator==(const String &rhs) const;
    bool operator!=(const String &rhs) const;

    String &operator+=(const String &rhs);
    String operator+(const String &rhs) const;

    //friend std::istream &operator>>(std::istream &is, String &str);
    friend std::ostream &operator<<(std::ostream &os, String &str);

    char operator[](size_t pos) const throw(std::out_of_range);
private:

    size_t len;
    size_t max_len;
    char* data;

    void resize_data(size_t new_size);
};


#endif //MY_STRING_STRING_H
