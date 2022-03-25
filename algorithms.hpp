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

#endif // ALGORITHMS