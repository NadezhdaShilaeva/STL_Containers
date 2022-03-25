#ifndef CIRCULAR_BUFFER
#define CIRCULAR_BUFFER

template <typename T>
class circular_buffer
{
public:
    explicit circular_buffer(size_t size)
        : size_(size), buffer_(new T[size + 1]), begin_(0), end_(0) {}
    circular_buffer(const circular_buffer &other)
        : size_(other.size_), buffer_(new T[other.size_ + 1]), begin_(other.begin_), end_(other.end_)
    {
        memcpy(buffer_, other.buffer, sizeof(T) * size_);
    }
    circular_buffer &operator=(const circular_buffer &other)
    {
        if (&other == this)
        {
            return *this;
        }
        size_ = other.size_;
        delete[] buffer_;
        buffer_ = new T[size_ + 1];
        memcpy(buffer_, other.buffer_, sizeof(T) * size_);
        begin_ = other.begin_;
        end_ = other.end_;
        return *this;
    }
    ~circular_buffer()
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
        begin_ = (begin_ - 1 + size_ + 1) % (size_ + 1);
        buffer_[begin_] = value;
        if (begin_ == end_)
        {
            end_ = (end_ - 1 + size_ + 1) % (size_ + 1);
        }
    }
    void pop_back()
    {
        end_ = (end_ - 1 + size_ + 1) % (size_ + 1);
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
        return buffer_[(end_ - 1 + size_ + 1) % (size_ + 1)];
    }
    T &operator[](size_t i) const
    {
        return buffer_[(begin_ + i) % (size_ + 1)];
    }
    void resize(size_t size)
    {
        circular_buffer new_buffer{size};
        int i = 0;
        for (iterator it = this->begin(); it != this->end() && i < size; ++it)
        {
            new_buffer.buffer_[i] = *it;
            ++i;
        }
        new_buffer.end_ = i;
        *this = new_buffer;
    }
    size_t size() const
    {
        if (begin_ < end_)
        {
            return end_ - begin_;
        }
        else
        {
            return size_ + 1 - begin_ + end_;
        }
    }
    size_t capacity()
    {
        return size_;
    }
    bool empty() const
    {
        return begin_ == end_;
    }
    class iterator;
    iterator begin()
    {
        return iterator(this, buffer_ + begin_);
    }
    iterator end()
    {
        return iterator(this, buffer_ + end_);
    }

private:
    T *buffer_;
    size_t size_;
    size_t begin_;
    size_t end_;
};

template <typename T>
class circular_buffer<T>::iterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
    iterator(circular_buffer *curr, T *current)
        : circular_buffer_(curr), current_(current) {}
    iterator(const iterator &other)
        : circular_buffer_(other.circular_buffer_), current_(other.current_) {}
    ~iterator() {}
    iterator &operator=(const iterator &other)
    {
        if (*this != other)
        {
            circular_buffer_ = other.circular_buffer_;
            current_ = other.current_;
        }
        return *this;
    }
    iterator operator++(int)
    {
        iterator tmp(*this);
        tmp.operator++();
        return tmp;
    }
    iterator &operator++()
    {
        ++current_;
        if (current_ == (circular_buffer_->buffer_ + circular_buffer_->size_ + 1))
        {
            current_ = circular_buffer_->buffer_;
        }
        return *this;
    }
    iterator operator--(int)
    {
        iterator tmp(*this);
        tmp.operator--();
        return tmp;
    }
    iterator &operator--()
    {
        if (current_ == circular_buffer_->buffer_)
        {
            current_ = circular_buffer_->buffer_ + circular_buffer_->size_;
        }
        else
        {
            --current_;
        }
        return *this;
    }
    iterator operator+(int right)
    {
        iterator tmp(*this);
        int max_count = circular_buffer_->buffer_ + circular_buffer_->size_ - current_;
        if (right > max_count)
        {
            tmp.current_ = circular_buffer_->buffer_ + right - max_count - 1;
        }
        else
        {
            tmp.current_ += right;
        }
        return tmp;
    }
    iterator operator-(int right)
    {
        iterator tmp(*this);
        int max_count = current_ - circular_buffer_->buffer_;
        if (right > max_count)
        {
            tmp.current_ = circular_buffer_->buffer_ + circular_buffer_->size_ - right + max_count + 1;
        }
        else
        {
            tmp.current_ -= right;
        }
        return tmp;
    }
    int operator-(const iterator &right)
    {
        if (current_ > right.current_)
        {
            return current_ - right.current_;
        }
        else
        {
            return circular_buffer_->buffer_ + circular_buffer_->size_ + 1 - right.current_ + (current_ - circular_buffer_->buffer_);
        }
    }
    iterator &operator+=(int right)
    {
        *this = *this + right;
        return *this;
    }
    iterator &operator-=(int right)
    {
        *this = *this - right;
        return *this;
    }
    bool operator==(const iterator &right)
    {
        return current_ == right.current_;
    }
    bool operator!=(const iterator &right)
    {
        return !(*this == right);
    }
    bool operator<(const iterator &right)
    {
        if (current_ == right.current_)
        {
            return false;
        }
        if (current_ < right.current_)
        {
            if (circular_buffer_->begin_ > circular_buffer_->end_ && right.current_ >= circular_buffer_->buffer_ + circular_buffer_->begin_ && current_ <= circular_buffer_->buffer_ + circular_buffer_->end_)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            if (circular_buffer_->begin_ > circular_buffer_->end_ && current_ >= circular_buffer_->buffer_ + circular_buffer_->begin_ && right.current_ <= circular_buffer_->buffer_ + circular_buffer_->end_)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    bool operator>(const iterator &right)
    {
        return *this != right && !(*this < right);
    }
    T &operator*()
    {
        return *current_;
    }

private:
    circular_buffer *circular_buffer_;
    T *current_;
};

#endif // CIRCULAR_BUFFER