#ifndef ALGORITHMS
#define ALGORITHMS

template <class Input, class Func>
bool all_of(Input begin, Input end, Func func)
{
    for (; begin != end; ++begin)
    {
        if (!func(*begin))
        {
            return false;
        }
    }
    return true;
}

template <class Input, class Func>
bool any_of(Input begin, Input end, Func func)
{
    for (; begin != end; ++begin)
    {
        if (func(*begin))
        {
            return true;
        }
    }
    return false;
}

template <class Input, class Func>
bool none_of(Input begin, Input end, Func func)
{
    for (; begin != end; ++begin)
    {
        if (func(*begin))
        {
            return false;
        }
    }
    return true;
}

template <class Input, class Func>
bool one_of(Input begin, Input end, Func func)
{
    bool is_one = false;
    for (; begin != end; ++begin)
    {
        if (func(*begin))
        {
            if (is_one)
            {
                return false;
            }
            is_one = true;
        }
    }
    return is_one;
}

template <class Input, class Func>
bool is_sorted(Input begin, Input end, Func func)
{
    for (begin += 1; begin != end; ++begin)
    {
        if (!func(*(begin - 1), *begin))
        {
            return false;
        }
    }
    return true;
}

template <class Input, class Func>
bool is_partitioned(Input begin, Input end, Func func)
{
    bool is_satisfy = true;
    for (; begin != end; ++begin)
    {
        if (!func(*begin))
        {
            is_satisfy = false;
        }
        else
        {
            if (!is_satisfy)
            {
                return false;
            }
        }
    }
    return true;
}

template <class Input, class Elem>
Input find_not(Input begin, Input end, Elem elem)
{
    for (; begin != end; ++begin)
    {
        if (*begin != elem)
        {
            return begin;
        }
    }
    return end;
}

template <class Input, class Elem>
Input find_backward(Input begin, Input end, Elem elem)
{
    Input it = end;
    for (; begin != end; ++begin)
    {
        if (*begin == elem)
        {
            it = begin;
        }
    }
    return it;
}

template <class Input, class Func>
bool is_palindrome(Input begin, Input end, Func func)
{
    int count = end - begin;
    for (int i = 0; i < count / 2; ++i)
    {
        if (func(*(begin + i)) != func(*(end - i - 1)))
        {
            return false;
        }
    }
    return true;
}

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

#endif // ALGORITHMS