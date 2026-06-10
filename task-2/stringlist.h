#pragma once

#include <iostream>


constexpr int MAX_CAPACITY = 100;


struct CStrings {
public:
    virtual ~CStrings() = default;

    virtual int Size() = 0;
    virtual std::string sAt(int i) = 0;

    virtual void add_elem(std::string x) = 0;
};

struct CArray : public CStrings
{
private:
    int m_count = 0;
    int m_capacity = 0;
    std::string *arData = nullptr;

public:

    CArray()
    {
        m_count = 0;
        m_capacity = MAX_CAPACITY;

        arData = new std::string[MAX_CAPACITY];
    }

    ~CArray() override
    {
        delete[] arData;
    }

    CArray(const CArray &other)
    {
        m_count = other.m_count;
        m_capacity = other.m_capacity;

        if (other.arData == nullptr)
        {
            arData = nullptr;
            return ;
        }


        arData = new std::string[m_capacity];

        for (int i = 0; i < m_count; ++i)
        {
            arData[i] = other.arData[i];
        }
    }

    int Size() final
    {
        return m_count;
    }


    int capacity() const
    {
        return m_capacity;
    }

    std::string sAt(const int i) final
    {
        if (i < 0 || i >= MAX_CAPACITY)
        {
            throw std::out_of_range("Index out of range");
        }

        return arData[i];
    }

    void add_elem(const std::string x) final
    {
        if (m_count >= m_capacity)
        {
            throw std::runtime_error("Cannot add element: max capacity is reached");
        }

        arData[m_count++] = x;
    }

    void erase(int i)
    {
        if (i < 0 || i >= MAX_CAPACITY)
        {
            throw std::out_of_range("Index out of range");
        }

        for (size_t j = i; j < m_count - 1; ++j) {
            arData[j] = std::move(arData[j + 1]);
        }

        m_count--;
        arData[m_count].clear();
    }
};