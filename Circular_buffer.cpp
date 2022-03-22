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
        memccpy(new_buffer.buffer_, buffer_, sizeof(T) * size_);
        *this = new_buffer;
    }
    bool empty() const
    {
        return begin_ == end_;
    }
    class Iterator;
    Iterator begin()
    {
        return buffer_ + begin_;
    }
    Iterator end()
    {
        return buffer_ + end_;
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

    private:
    T* current;
};

int main()
{
    return 0;
}