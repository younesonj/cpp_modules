#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>class Array{
    private:
        T *arr;
        unsigned int _size;
    public:
        Array() : arr(NULL) , _size(0) {};
        Array(unsigned int n) : _size(n)
        {
            arr = new T[n](); 
        };
        Array(const Array& other)
        {
            _size = other._size;
            arr = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                arr[i] = other.arr[i];
        };
        Array &operator=(const Array& other)
        {
            if (this != &other)
            {
                delete arr;
                _size = other._size;
                if (_size > 0)
                {
                    arr = new T[_size]();
                    for (unsigned int i = 0; i < _size; i++)
                        arr[i] = other.arr[i];
                }
                else
                    arr = other.arr;
            }
            return (*this);
        };
        ~Array()
        {
            delete arr;
        }

        T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return (arr[index]);
        }
        unsigned int size() const
        {
            return (_size);
        }
};

#endif