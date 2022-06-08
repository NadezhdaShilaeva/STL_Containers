# STL_Containers
###### Лабораторная работа по программированию №3. 2 семестр.
## 1. Контейнеры

Программа содержится в файле ___circular_buffer.hpp___.  
В программе реализован [кольцевой буфер](https://en.wikipedia.org/wiki/Circular_buffer) в виде stl-совместимого контейнера (например, может
быть использован со стандартными алгоритмами), обеспеченный итератором
произвольного доступа. Реализация не использует ни одни из контейнеров
STL.  
Буфер обладает следующими методами:  
1. ___push_back___ - вставка в конец;  
2. ___push_front___ - вставка в начало;  
3. ___pop_back___ - удаление последнего элемента;  
4. ___pop_front___ - удаление первого элемента;  
5. ___front___ - доступ в начало;  
6. ___back___ - доступ в конец;  
7. ___[N]___ - доступ по индексу;  
8. ___resize___ - изменение капасити;  
9. ___size___ - получение количества элементов, записанных в буфер;  
10. ___capacity___ - получение вместимости буфера;
11. ___empty___ - проверка на пустоту: возвращает true, если буфер пустой, иначе false.  

В файле ___Circular_buffer.cpp___ содержится функция ___main()___ , в котрой реализовано тестирование буфера: создается буфер на 5 элементов, производится запись чисел с 0 по 12; выводятся элементы с помощью итератора; с помощью указателя изменяется значение первого элемента и выводится; изменяется капасити буфера на 20 элементов с помощью метода _resize()_; применяется метод _push_front()_ для чисел с 23 по 48; элементы выводятся; элементы сортируются с помощью _std::sort_ и выводятся; применяютя методы pop_back() 7 раз и _pop_front()_ 5 раз; элементы выводятся; применяются стандартные алгоритмы _std::lower_bound_ для числа 38 и _std::upper_bound_ для числа 39.  

#### Формат входных данных:
Входных данных не требуется.

---
#### Примеры использования программы:
___Входные аргументы:___   
Входных данных не требуется.  
___Выходные данные:___  
8 9 10 11 12  
10  
12  
48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29  
29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48  
34 35 36 37 38 39 40 41  
38  
40  

## 2. Алгоритмы

Программа содержится в файле ___algorithms.hpp___.  
В программе реализованы следующие обобщенные алгоритмы:
1. ___all_of___ - возвращает true, если все элементы диапазона удовлетворяют
некоторому предикату. Иначе false;  
2. ___any_of___ - возвращает true, если хотя бы один из элементов диапазона удовлетворяет некоторому предикату. Иначе false;  
3. ___none_of___ - возвращает true, если все элементы диапазона не удовлетворяют некоторому предикату. Иначе false;  
4. ___one_of___ - возвращает true, если ровно один элемент диапазона удовлетворяет некоторому предикату. Иначе false;  
5. ___is_sorted___ - возвращает true, если все элементы диапазона находятся в отсортированном порядке относительно некоторого критерия;  
6. ___is_partitioned___ - возвращает true, если в диапазоне есть элемент, делящий все элементы на удовлетворяющие и не удовлетворяющие некоторому предикату. Иначе false;  
7. ___find_not___ - находит первый элемент, не равный заданному;  
8. ___find_backward___ - находит первый элемент, равный заданному, с конца;  
9. ___is_palindrome___ - возвращает true, если заданная последовательность является палиндромом относительно некоторого условия. Иначе false.  

Каждый алгоритм выполнен в виде шаблонной функции, позволяющей взаимодействовать со стандартными контейнерами STL с помощью итераторов. Предикаты, условия, операторы сравнения параметризованы.  

В файле ___CRational.hpp___ реализован класс, описывающий рациональную дробь, с переопределенными опрераторами сравнения и вывода в стандартный поток вывода.  

В файле ___Algorithms.cpp___ содержится функция ___main()___ , в котрой продемонстрирована работа алгоритмов как на стандартном, так и на пользовательском типе данных CRational.  

#### Формат входных данных:
Входных данных не требуется.

---
#### Примеры использования программы:
___Входные аргументы:___   
Входных данных не требуется.  
___Выходные данные:___  
0 1 2 3 4 5 6 7 8 9  
all_of > 5: 0  
all_of < 10: 1  
any_of == 5: 1  
any_of > 10: 0  
none_of == 11: 1  
none_of > 5: 0  
is_sorted ascending: 1  
is_sorted descending: 0  
is_partitioned < 5: 1  
is_partitioned 3 < x < 5: 0  
find_not 0: 1  
find_backward 2: 2  
is_palindrome % 3 == 0: 1  
is_palindrome % 2 == 0: 0  
0/1 1/2 1/1 3/2 2/1 5/2 3/1 7/2 4/1 9/2  
all_of > 4: 0  
all_of < 10: 1  
any_of == 4: 1  
any_of > 10: 0  
none_of == 11/2: 1  
none_of > 4: 0  
is_sorted ascending: 1  
is_sorted descending: 0  
is_partitioned < 4: 1  
is_partitioned 1 < x < 2: 0  
find_not 0: 1/2  
find_backward 4: 4/1  
is_palindrome == 0: 0  
is_palindrome > -1: 1  