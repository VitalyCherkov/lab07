#include <iostream>

#include "Set.h"
#include "String.h"

using std::cin;
using std::cout;

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::cout << "OK: ";
    Set <String> st;        //std::cout << "OK: ";
    st.insert("Hello");     //std::cout << "OK: ";
    st.insert("It's me");   //std::cout << "OK: ";
    st.insert("azaza");     //std::cout << "OK: ";
    st.insert("lolkek");    //std::cout << "OK: ";
    st.insert("Putin");     //std::cout << "OK: ";
    Set <String> st2 = {"Hello", "It's me", "azaza", "lolkek", "Putin"};

    std::cout << "OK: ";

    for(auto it: st2){
        std::cout << it << " ";
    }

    while (st2.get_size()){
        st2.erase(*st.begin());
    }


    if(st2.begin() == st.end())
       std::cout << "BIG OK ";

    return 0;
}