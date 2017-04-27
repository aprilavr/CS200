#ifndef _KITTEN_HPP
#define _KITTEN_HPP

#include <string>
#include <iostream>
using namespace std;



class Kitten
{
    private: string m_name;
    public: static int m_kittenCount;
    public: Kitten(string name);
    public: void Display();
};

#endif
