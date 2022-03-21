#include <iostream>

template <typename T>
class CCircularBuffer
{
public:
    explicit CCircularBuffer(size_t size)
        : size_(size), buffer_(new T[size]), begin_(0), end_(0) {}
    explicit CCircularBuffer(size_t size, T *buffer)
        : size_(size), buffer_(new T[size]), begin_(0), end_(size)
    {
        memcpy(buffer_, buffer, sizeof(T) * size_);
    }
    CCircularBuffer(const CCircularBuffer &other)
        : size_(other.size_), buffer_(new T[other.size_]), begin_(other.begin_), end_(other.end_)
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
        buffer_ = new T[size_];
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
        if (end_ == begin_)
        {
            begin_ = (begin_ + 1) % size_;
        }
        end_ = (end_ + 1) % size_;
    }
    void push_front(const T &value)
    {
        if (begin_ == end_)
        {
            end_ = (end_ - 1) % size_;
        }
        begin_ = (begin_ - 1) % size_;
        buffer_[begin_] = value;
    }
    void pop_back()
    {
        end_ = (end_ - 1) % size_;
    }
    void pop_front()
    {
        begin_ = (begin_ + 1) % size_;
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
        return buffer_[(begin_ + i) % size_];
    }
    void resize(size_t size)
    {
        CCircularBuffer new_buffer{size_ + size};
        memccpy(new_buffer.buffer_, buffer_, sizeof(T) * size_);
        *this = new_buffer;
    }

private:
    T *buffer_;
    size_t size_;
    size_t begin_;
    size_t end_;
};

int main()
{
    return 0;
}