#include <iostream>

template <typename T>
class CCircularBuffer
{
public:
    explicit CCircularBuffer(size_t size)
        : size_(size), buffer_(new T[size + 1]), begin_(0), end_(0) {}
    explicit CCircularBuffer(size_t size, T *buffer)
        : size_(size), buffer_(new T[size + 1]), begin_(0), end_(size)
    {
        memcpy(buffer_, buffer, sizeof(T) * size_);
    }
    CCircularBuffer(const CCircularBuffer &other)
        : size_(other.size_), buffer_(new T[other.size_ + 1]), begin_(other.begin_), end_(other.end_)
    {
        memcpy(buffer_, other.buffer, sizeof(T) * size_);
    }
    CCircularBuffer &operator=(const CCircularBuffer &other)
    {
        if (&other == this)
        {
            return *this;
        }
        size_ = other.size_;
        delete[] buffer_;
        buffer_ = new T[size_ + 1];
        memcpy(buffer_, other.buffer, sizeof(T) * size_);
        begin_ = other.begin_;
        end_ = other.end_;
        return *this;
    }
    ~CCircularBuffer()
    {
        delete[] buffer_;
    }
    void push_back(const T &value)
    {
        buffer_[end_] = value;
        end_ = (end_ + 1) % (size_ + 1);
        if (end_ == begin_)
        {
            begin_ = (begin_ + 1) % (size_ + 1);
        }
    }
    void push_front(const T &value)
    {
        begin_ = (begin_ - 1) % (size_ + 1);
        buffer_[begin_] = value;
        if (begin_ == end_)
        {
            end_ = (end_ - 1) % (size_ + 1);
        }
    }
    void pop_back()
    {
        end_ = (end_ - 1) % (size_ + 1);
    }
    void pop_front()
    {
        begin_ = (begin_ + 1) % (size_ + 1);
    }
    T &front() const
    {
        return buffer_[begin_];
    }
    T &back() const
    {
        return buffer_[end_ - 1];
    }
    T &operator[](size_t i) const
    {
        return buffer_[(begin_ + i) % (size_ + 1)];
    }
    void resize(size_t size)
    {
        CCircularBuffer new_buffer{size_ + size};
        int i = 0;
        for(Iterator it = this->begin(); it != this->end(); ++it)
        {
            new_buffer.buffer_[i] = *it;
            ++i;
        }
        new_buffer.end_ = i;
        *this = new_buffer;
    }
    bool empty() const
    {
        return begin_ == end_;
    }
    class Iterator;
    Iterator begin()
    {
        return Iterator(this, buffer_ + begin_);
    }
    Iterator end()
    {
        return Iterator(this, buffer_ + end_);
    }

private:
    T *buffer_;
    size_t size_;
    size_t begin_;
    size_t end_;
};

template<typename T>
class CCircularBuffer<T>::Iterator
{
    public:
    Iterator(CCircularBuffer* curr, T* current)
    :circular_buffer_(curr), current_(current) {}
    Iterator(const Iterator &other)
    :circular_buffer_(other.circular_buffer_), current_(other.current_) {}
    Iterator &operator=(const Iterator& other)
    {
        if(*this!=other)
        {
            this->circular_buffer_ = other.circular_buffer_;
            this->current_  = other.current_;
        }
        return *this;
    }
    Iterator &operator++(int)
    {
        Iterator tmp(*this);
        operator++();
        return *this;
    }
    Iterator &operator++()
    {
        ++current_;
        if(current_ == (circular_buffer_->buffer_ + circular_buffer_->size_ + 1))
        {
            current_ = circular_buffer_->buffer_;
        }
        return *this;
    }
    bool operator==(const Iterator& right)
    {
        return current_ == right.current_;
    }
    bool operator!=(const Iterator& right)
    {
        return !(*this == right);
    }
    T& operator*()
    {
        return *current_;
    }
    private:
    CCircularBuffer* circular_buffer_;
    T* current_;
};

int main()
{
    CCircularBuffer<int> buf(5);
    for (int i = 0; i<10; ++i)
    {
        buf.push_back(i);
    }
    for (CCircularBuffer<int>::Iterator it = buf.begin(); it != buf.end(); ++it)
    {
        std::cout << *it << " ";
    }
    CCircularBuffer<int>::Iterator it = buf.begin();
    *it = 10;
    std::cout << buf[0]; 
    return 0;
}