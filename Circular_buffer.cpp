#include <iostream>
#include <algorithm>
#include "circular_buffer.h"

int main()
{
    circular_buffer<int> buf(5);
    for (int i = 0; i < 13; ++i)
    {
        buf.push_back(i);
    }
    for (circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    circular_buffer<int>::iterator it = buf.begin();
    *it = 10;
    std::cout << buf[0] << std::endl;
    std::cout << *std::max_element(buf.begin(), buf.end()) << std::endl;
    buf.resize(20);
    for (int i = 23; i<49; ++i)
    {
        buf.push_front(i);
    }
    for (circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::sort(buf.begin(), buf.end());
    for (circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for(int i = 0;  i < 7; ++i)
    {
        buf.pop_back();
    }
    for(int i = 0;  i < 5; ++i)
    {
        buf.pop_front();
    }
    for (circular_buffer<int>::iterator it = buf.begin(); it != buf.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << *std::lower_bound(buf.begin(), buf.end(), 38) << std::endl;
    std::cout << *std::upper_bound(buf.begin(), buf.end(), 39) << std::endl;
    return 0;
}