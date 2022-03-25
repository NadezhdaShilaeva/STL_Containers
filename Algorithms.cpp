#include <iostream>
#include <vector>
#include "algorithms.hpp"

template <typename T>
T max(const T &a, const T &b)
{
    return a > b ? a : b;
}

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "all_of > 5: " << all_of(vec.begin(), vec.end(), [](int x) -> bool { return x > 5; }) << std::endl;
    std::cout << "all_of < 10: " << all_of(vec.begin(), vec.end(), [](int x) -> bool { return x < 10; }) << std::endl;
    std::cout << "any_of == 5: " << any_of(vec.begin(), vec.end(), [](int x) -> bool { return x == 5; }) << std::endl;
    std::cout << "any_of > 10: " << any_of(vec.begin(), vec.end(), [](int x) -> bool { return x > 10; }) << std::endl;
    std::cout << "none_of == 11: " << none_of(vec.begin(), vec.end(), [](int x) -> bool { return x == 11; }) << std::endl;
    std::cout << "none_of > 5: " << none_of(vec.begin(), vec.end(), [](int x) -> bool { return x > 5; }) << std::endl;
    std::cout << "is_sorted ascending: " << is_sorted(vec.begin(), vec.end(), [](int x, int y) -> bool { return x < y; }) << std::endl;
    std::cout << "is_sorted descending: " << is_sorted(vec.begin(), vec.end(), [](int x, int y) -> bool { return x > y; }) << std::endl;
    std::cout << "is_partitioned < 5: " << is_partitioned(vec.begin(), vec.end(), [](int x) -> bool { return x < 5; }) << std::endl;
    std::cout << "is_partitioned 3 < x < 5: " << is_partitioned(vec.begin(), vec.end(), [](int x) -> bool { return x > 3 && x < 5; }) << std::endl;
    std::cout << "find_not 0: " << *find_not(vec.begin(), vec.end(), 0) << std::endl;
    std::cout << "find_backward 2: " << *find_backward(vec.begin(), vec.end(), 2) << std::endl;
    std::cout << "is_palindrome % 3 == 0: " << is_palindrome(vec.begin(), vec.end(), [](int x) -> bool { return x % 3 == 0; }) << std::endl;
    std::cout << "is_palindrome % 2 == 0: " << is_palindrome(vec.begin(), vec.end(), [](int x) -> bool { return x % 2 == 0; }) << std::endl;

    /*all_of - возвращает true, если все элементы диапазона удовлетворяют
некоторому предикату. Иначе false
2. any_of - возвращает true, если хотя бы один из элементов диапазона
удовлетворяет некоторому предикату. Иначе false
3. none_of - возвращает true, если все элементы диапазона не удовлетворяют
некоторому предикату. Иначе false
4. one_of - возвращает true, если ровно один элемент диапазона удовлетворяет
некоторому предикату. Иначе false
5. is_sorted - возвращает true, если все элементы диапазона находятся в
отсортированном порядке относительно некоторого критерия
6. is_partitioned - возвращает true, если в диапазоне есть элемент, делящий все
элементы на удовлетворяющие и не удовлетворяющие некоторому предикату.
Иначе false.
7. find_not - находит первый элемент, не равный заданному
8. find_backward - находит первый элемент, равный заданному, с конца
9. is_palindrome - возвращает true, если заданная последовательность является
палиндромом относительно некоторого условия. Иначе false.*/
    return 0;
}