#ifndef _DYNAMIC_ARRAY_HPP
#define _DYNAMIC_ARRAY_HPP
#include <string>
using namespace std;




class DynamicArray
{
    private: string* m_arr;
    private: int m_size;

    public: DynamicArray(int size);
    public: ~DynamicArray();
    public: void Set(int index, string value);
    public: string Get(int index);
    public: int GetSize();
    public: void Display();
};
#endif
