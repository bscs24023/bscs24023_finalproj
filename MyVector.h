#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
using namespace std;

template <typename X>
class MyVector 
{
    private:
        X* arr;
        int len;
        int cap;

        void double_capacity() 
        {
            X* new_arr = new X[cap + cap + 1];
            for (int i = 0; i < len; i++) 
            {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            cap = cap + cap + 1;
        }

public:
    MyVector() : arr(nullptr), len(0), cap(0) {}

    MyVector(int count, X value) 
    {
        len = count;
        cap = count;
        arr = new X[cap];
        for (int i = 0; i < len; i++) 
        {
            arr[i] = value;
        }
    }

    MyVector(const MyVector& other) 
    {
        len = other.len;
        cap = other.len;
        arr = new X[cap];
        for (int i = 0; i < len; i++) 
        {
            arr[i] = other.arr[i];
        }
    }

    ~MyVector() 
    {
        delete[] arr;
    }

    MyVector& operator=(const MyVector& other) 
    {
        delete[] arr;
        len = other.len;
        cap = other.cap;
        arr = new X[cap];
        for (int i = 0; i < len; i++) 
        {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    X& operator[](int index) 
    {
        return arr[index];
    }

    const X& operator[](int index) const 
    {
        return arr[index];
    }

    bool operator==(const MyVector& other) const 
    {
        if (len != other.len) 
        {
            return false;
        }
        for (int i = 0; i < len; i++) 
        {
            if (arr[i] != other.arr[i]) 
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const MyVector& other) const 
    {
        bool flag = (*this == other);
        return !(flag);
    }

    MyVector operator+(const MyVector& other) const 
    {
        MyVector result(len + other.len, 0);
        for (int i = 0; i < len; i++) 
        {
            result.arr[i] = arr[i];
        }
        for (int i = 0; i < other.len; i++) 
        {
            result.arr[len + i] = other.arr[i];
        }
        result.len = len + other.len;
        return result;
    }

    MyVector& operator+=(const MyVector& other) 
    {
        int new_capacity = len + other.len;
        reserve(new_capacity);
        for (int i = 0; i < other.len; i++) 
        {
            arr[len] = other.arr[i];
            len++;
        }
        return *this;
    }

    void push(X value) 
    {
        if (len == cap) 
        {
            double_capacity();
        }
        arr[len] = value;
        len++;
    }

    void pop() 
    {
        len--;
    }

    void insert_at(int index, X value) 
    {
        if (index < 0 || index > len) 
        {
            return;
        }
        if (len == cap) 
        {
            double_capacity();
        }
        for (int i = len; i > index; i--) 
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        len++;
    }

    void delete_at(int index) 
    {
        if (index < 0 || index >= len) 
        {
            return;
        }
        for (int i = index; i < len - 1; i++) 
        {
            arr[i] = arr[i + 1];
        }
        len--;
    }

    void reserve(int new_capacity) 
    {
        X* new_arr = new X[new_capacity];

        for (int i = 0; i < len; i++) 
        {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        cap = new_capacity;
    }

    void clear() 
    {
        len = 0;
    }

    void swap(MyVector& other) 
    {
        X* temp_arr = arr;
        arr = other.arr;
        other.arr = temp_arr;

        int temp_l = len;
        len = other.len;
        other.len = temp_l;

        int temp_c = cap;
        cap = other.cap;
        other.cap = temp_c;
    }

    void shrink_to_fit() 
    {
        if (cap > len) 
        {
            reserve(len);
        }
    }

    void reverse() 
    {
        for (int i = 0, j = len - 1; i < j; i++, j--) 
        {
            X temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    bool empty() const 
    {
        return len == 0;
    }

    int size() const 
    {
        return len;
    }

    X& at(int index) 
    {
        if (index < 0 || index >= len) 
        {
            return arr[0];
        }
        return arr[index];
    }

    const X& at(int index) const 
    {
        if (index < 0 || index >= len) 
        {
            return arr[0];
        }
        return arr[index];
    }

    X& front() 
    {
        return arr[0];
    }

    const X& front() const 
    {
        return arr[0];
    }

    X& back() 
    {
        return arr[len - 1];
    }

    const X& back() const 
    {
        return arr[len - 1];
    }

    int find(X value) const 
    {
        for (int i = 0; i < len; i++) 
        {
            if (arr[i] == value) 
            {
                return i;
            }
        }
        return -1;
    }
    
    void print()
	{
		cout << "{";
		for (int i = 0; i < this->len; i++)
		{
			if (i != this->len - 1)
				cout << this->arr[i] << " , ";
			else
				cout << this->arr[i];
		}
		cout << "}";
	}
};

#endif
