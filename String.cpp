//
// Created by vcherkov on 11.04.17.
//

#include "String.h"

String::String():
    len(0),
    max_len(8),
    data(nullptr)
{
    data = new char [max_len];
}

String::String(const String &rhs):
    len(rhs.len),
    max_len(rhs.max_len),
    data(nullptr)
{
    data = new char [max_len];
    memcpy(data, rhs.data, len);
}

String::String(String &&rhs):
    len(rhs.len),
    max_len(rhs.max_len),
    data(rhs.data)
{
    std::cout << "MS ";
    rhs.data = nullptr;
    rhs.len = rhs.max_len = 0;
}

String::String(const char *data, size_t len):
    len(len),
    max_len(len * 2),
    data(nullptr)
{
    this->data = new char[max_len];
    memcpy(this->data, data, len);
}

String::String(const char *data):
        len(strlen(data)),
        max_len(len * 2),
        data(nullptr)
{
    this->data = new char[max_len];
    memcpy(this->data, data, len);
}

const String &String::operator=(const String &rhs) {
    if(this == &rhs)
        return *this;

    String new_string(rhs);
    std::swap(*this, new_string);

    return *this;
}

const String &String::operator=(String &&rhs) {
    *this = std::move(rhs);
}


void String::push_back(char symbol) {
    if(len == max_len) {
        resize_data(max_len * 2);
    }

    data[len++] = symbol;
}

void String::pop_back(){
    if(len)
        len--;
}

char String::back() const throw(std::out_of_range) {
    if(!len)
        throw std::out_of_range("String is empty");

    return data[len - 1];
}

String::~String() {
    delete[] data;
}

size_t String::get_length() const {
    return len;
}

bool String::operator<(const String &rhs) const {
    for(size_t i = 0; i < std::min(len, rhs.len); i++){
        if(data[i] < rhs.data[i])
            return true;
        if(data[i] > rhs.data[i])
            return false;
    }
    if(len < rhs.len)
        return true;
    return false;
}

bool String::operator==(const String &rhs) const {
    if(rhs.len != len)
        return false;

    for(size_t i = 0; i < len; i++)
        if(rhs.data[i] != data[i])
            return false;

    return true;
}

bool String::operator!=(const String &rhs) const {
    if(this->operator==(rhs))
        return false;

    return true;
}

String& String::operator+=(const String &rhs) {
    if(len + rhs.len >= max_len){
        resize_data((len + rhs.len) * 2);
    }

    memcpy(data + len, rhs.data, rhs.len);
    len += rhs.len;
}

String String::operator+(const String &rhs) const {
    String result(*this);
    result += rhs;
    return result;
}

std::ostream &operator<<(std::ostream &os, String &str) {
    //os << str.data;

    for(size_t i = 0; i < str.len; i++)
        os << str.data[i];

    return os;
}
/*
std::istream &operator>>(std::istream &is, String &str) {
    char ch;
    while(ch = is.get())
        str.push_back(ch);
}
*/
char String::operator[](size_t pos) const throw(std::out_of_range) {
    if(pos >= len || pos < 0)
        throw std::out_of_range("Wrong index of element");

    return data[pos];
}

void String::resize_data(size_t new_size) {
    char* new_data = new char [new_size];
    memcpy(new_data, data, std::min(len, new_size));

    delete[] data;
    data = new_data;

    max_len = new_size;
}



