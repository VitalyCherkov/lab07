#include <iostream>

#include "Set.h"
#include "String.h"

using std::cin;
using std::cout;

int main() {
    std::cout << "Hello, World!" << std::endl;

    /*
    std::cout << "OK: ";
    Set <String> st;        //std::cout << "OK: ";
    st.insert("Hello");     //std::cout << "OK: ";
    st.insert("It's me");   //std::cout << "OK: ";
    st.insert("azaza");     //std::cout << "OK: ";
    st.insert("lolkek");    //std::cout << "OK: ";
    st.insert("Putin");     //std::cout << "OK: ";
    */

    Set <String> st2 = {"Hello", "It's me", "azaza", "lolkek", "Putin"};
    st2.insert(String("google"));
    std::cout << "OK: ";

    String str("asf");

    for(auto it: st2){
        std::cout << it << " ";
    }

    /*Set <String> st3(Set <String> =
            {"Hello", "It's me", "azaza", "lolkek", "Putin"});

    for(auto it: st3){
        std::cout << it << " ";
    }*/

    if(st2.begin() == st2.end())
        std::cout << "BIG OK ";

    while (st2.get_size()){
        st2.erase(*st2.begin());
    }


    if(st2.begin() == st2.end())
       std::cout << "BIG OK ";
    return 0;
}