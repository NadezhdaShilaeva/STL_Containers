#include <iostream>
#include <vector>
#include "algorithms.hpp"
#include "CRational.hpp"

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

    std::vector<CRational> vec_rat;
    for (int i = 0; i < 10; ++i)
    {
        vec_rat.push_back(CRational(i, 2));
        std::cout << vec_rat[i] << " ";
    }
    std::cout << std::endl;
    CRational val4(4, 1);
    CRational val10(10, 1);
    std::cout << "all_of > 4: " << all_of(vec_rat.begin(), vec_rat.end(), [](CRational x) -> bool { return x > 4; }) << std::endl;
    std::cout << "all_of < 10: " << all_of(vec_rat.begin(), vec_rat.end(), [](CRational x) -> bool { return x < 10; }) << std::endl;
    std::cout << "any_of == 4: " << any_of(vec_rat.begin(), vec_rat.end(), [](CRational x) -> bool { return x == 4; }) << std::endl;
    std::cout << "any_of > 10: " << any_of(vec_rat.begin(), vec_rat.end(), [](CRational x) -> bool { return x > 10; }) << std::endl;
    std::cout << "none_of == 10: " << none_of(vec_rat.begin(), vec_rat.end(), [](CRational x) -> bool { return x == 10; }) << std::endl;
    std::cout << "none_of > 4: " << none_of(vec_rat.begin(), vec_rat.end(), [](CRational x) -> bool { return x > 4; }) << std::endl;
    std::cout << "is_sorted ascending: " << is_sorted(vec_rat.begin(), vec_rat.end(), [](CRational x, CRational y) -> bool { return x < y; }) << std::endl;
    std::cout << "is_sorted descending: " << is_sorted(vec_rat.begin(), vec_rat.end(), [](CRational x, CRational y) -> bool { return x > y; }) << std::endl;
    std::cout << "is_partitioned < 4: " << is_partitioned(vec_rat.begin(), vec_rat.end(), [](CRational x) -> bool { return x < 4; }) << std::endl;
    std::cout << "is_partitioned 1 < x < 2: " << is_partitioned(vec_rat.begin(), vec_rat.end(), [](CRational x) -> bool { return x > 1 && x < 2; }) << std::endl;
    std::cout << "find_not 0: " << *find_not(vec_rat.begin(), vec_rat.end(), 0) << std::endl;
    std::cout << "find_backward 4: " << *find_backward(vec_rat.begin(), vec_rat.end(), 4) << std::endl;
    std::cout << "is_palindrome == 0: " << is_palindrome(vec_rat.begin(), vec_rat.end(), [](CRational x) -> bool { return x == 0; }) << std::endl;
    std::cout << "is_palindrome > -1: " << is_palindrome(vec_rat.begin(), vec_rat.end(), [](CRational x) -> bool { return x > -1; }) << std::endl;

    return 0;
}