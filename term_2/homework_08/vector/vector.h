#pragma once

template <typename T>
class Vector
{
public:
    /**
     * @brief Vector values constructor
     *
     * Constructs a vector with the set dimensions and values
     *
     * @param dimensions
     * @param values
     */

    Vector(int dimensions = 0, T *values = nullptr);

    /**
     * @brief Vector copy constructor
     *
     * Constructs a vector with the same dimension and values as param vector
     */

    Vector(const Vector<T> &);

    ~Vector();

    /// "template <typename U>" to be used with friend
    /// "friend" to access private fields

    Vector<T>& operator+=(const Vector<T> &);
    template <typename U> friend Vector<U> operator+(Vector<U>, const Vector<U> &);

    Vector<T>& operator-=(const Vector<T> &);
    template <typename U> friend Vector<U> operator-(Vector<U>, const Vector<U> &);

    template <typename U> friend U operator*(const Vector<U> &, const Vector<U> &);
    template <typename U> friend bool operator==(const Vector<U> &, const Vector<U> &);

    bool isNull() const;

    /**
     * @brief Vector length getter
     *
     * @return int dimensions
     */

    int length() const;

    /**
     * @brief Vector contents getter
     *
     * @return T *values
     */

    T *contents();

private:
    int dimensions;
    T *values;
};



template <typename T>
Vector<T>::Vector(int dimensions, T *values)
{
    this->dimensions = dimensions;
    this->values = new T[dimensions];
    for (int i = 0; i < dimensions; i++)
        this->values[i] = values[i];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &vector)
{
    dimensions = vector.dimensions;
    values = new T[dimensions];
    for (int i = 0; i < dimensions; i++)
        values[i] = vector.values[i];
}

template <typename T>
Vector<T>::~Vector()
{
    delete [] values;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T> &vector)
{
    if (dimensions == vector.dimensions)
        for (int i = 0; i < dimensions; i++)
            values[i] += vector.values[i];

    return *this;
}

template <typename T>
Vector<T> operator+(Vector<T> left, const Vector<T> &right)
{
    Vector<T> result(left);

    return result += right;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T> &vector)
{
    if (dimensions == vector.dimensions)
        for (int i = 0; i < dimensions; i++)
            values[i] -= vector.values[i];

    return *this;
}

template <typename T>
Vector<T> operator-(Vector<T> left, const Vector<T> &right)
{
    Vector<T> result(left);

    return result -= right;
}

template <typename T>
T operator*(const Vector<T> &left, const Vector<T> &right)
{
    T result = 0;

    if (left.dimensions == right.dimensions)
        for (int i = 0; i < left.dimensions; i++)
            result += left.values[i] * right.values[i];

    return result;
}

template <typename T>
bool operator==(const Vector<T> &left, const Vector<T> &right)
{
    if (left.dimensions == right.dimensions)
        for (int i = 0; i < left.dimensions; i++)
            if (left.values[i] != right.values[i])
                return false;

    return true;
}

template <typename T>
bool Vector<T>::isNull() const
{
    for (int i = 0; i < dimensions; i++)
        if (values[i] != 0)
            return false;

    return true;
}

template <typename T>
int Vector<T>::length() const
{
    return dimensions;
}

template <typename T>
T *Vector<T>::contents()
{
    int *result = new int[dimensions];
    for (int i = 0; i < dimensions; i++)
        result[i] = values[i];

    return result;
}
