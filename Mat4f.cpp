#include "Mat4f.hpp"

Mat4f::Mat4f()
{
    _values = new float[ROWS * COLS];
    this->clear(0);
}

Mat4f::Mat4f(float value)
{
    _values = new float[ROWS * COLS];
    this->clear(value);
}

Mat4f::Mat4f(std::vector<float> values)
{
    _values = new float[ROWS * COLS];
    int lastElement = COLS * ROWS > values.size() ? COLS * ROWS : values.size();
    for(int i = 0; i < lastElement; i++)
        _values[i] = values[i];
}

Mat4f::Mat4f(const Mat4f& matrix)
{
    this->_values = new float[ROWS * COLS];
    this->setValues(matrix._values);
}

Mat4f::~Mat4f()
{
    delete[] this->_values;
}

int Mat4f::getRows() const { return ROWS; }

int Mat4f::getCols() const { return COLS; }

Vec4f Mat4f::getRow(int index) const
{
	return Vec4f(   this(0, index),
					this(1, index),
					this(2, index),
					this(3, index));
}

Vec4f Mat4f::getI() const { return this->getRow(0); }
Vec4f Mat4f::getJ() const { return this->getRow(1); }
Vec4f Mat4f::getK() const { return this->getRow(2); }
Vec4f Mat4f::getT() const { return this->getRow(3); }

float Mat4f::getValueAt(int row, int col) const { return this->_values[col * ROWS + row]; }

void Mat4f::setValues(const float values[])
{
    for(unsigned int i = 0; i < ROWS * COLS; i++)
        this->_values[i] = values[i];
}

void Mat4f::setValues(const std::vector<float>& values)
{
    int lastElement = COLS * ROWS > values.size() ? COLS * ROWS : values.size();
    for(unsigned int i = 0; i < lastElement; i++)
        _values[i] = values[i];
}

void Mat4f::setValueAt(float value, int row, int col) { this->_values[col * ROWS + row] = value; }

void Mat4f::addValueTo(float value, int row, int col) { this->_values[col * ROWS + row] += value; }

std::vector<float> Mat4f::getMat4f()
{
    std::vector<float> result;
    for(unsigned int i = 0; i < ROWS * COLS; i++)
        result.push_back(this->_values[i]);
    return result;
}

void Mat4f::clear(float clearValue)
{
    for(unsigned int i = 0; i < (ROWS * COLS); i++)
        _values[i] = clearValue;
}

const Mat4f& Mat4f::operator= (const Mat4f& matrix)
{
    this->setValues(matrix._values);
	return *this;
}

float Mat4f::operator() (int row, int col) const
{
    return getValueAt(row, col);
}

Mat4f Mat4f::operator+ (const Mat4f& m) const
{
    std::vector<float> values;
    for(int i = 0; i < COLS * ROWS; i++)
        values.push_back(this->_values[i] + m._values[i]);
    return Mat4f(values);
}

Mat4f Mat4f::operator* (const Mat4f& rhs) const
{
    Mat4f result;
    for(unsigned int row = 0; row < ROWS; row++)
        for(unsigned int col = 0; col < COLS; col++)
            for(unsigned int i = 0; i < COLS; i++)
                result.addValueTo(this->getValueAt(row, i) * rhs.getValueAt(i, col) ,row, col);
    return Mat4f(result.getMat4f());
}

Mat4f Mat4f::operator* (float factor) const
{
    std::vector<float> values;
    for(int i = 0; i < COLS * ROWS; i++)
        values.push_back(this->_values[i] * factor);
    return Mat4f(values);
}

Mat4f& Mat4f::operator++ ()
{
    for(int i = 0; i < COLS * ROWS; i++)
        this->_values[i]++;
    return *this;
}

Mat4f& Mat4f::operator-- ()
{
    for(int i = 0; i < COLS * ROWS; i++)
        this->_values[i]--;
    return *this;
}

Mat4f Mat4f::operator++ (int)
{
    //create a temporary variable with our current matrix
    Mat4f result(*this);
    //use prefix operator to increment this matrix
    ++(*this);
    //return temporary result
    return result;
}

Mat4f Mat4f::operator-- (int)
{
    Mat4f result(*this);
    --(*this);
    return result;
}

const Mat4f& Mat4f::operator+= (const Mat4f& m)
{
    for(int i = 0; i < COLS * ROWS; i++)
        this->_values[i] += m._values[i];
    return *this;
}

const Mat4f& Mat4f::operator-= (const Mat4f& m)
{
    for(int i = 0; i < COLS * ROWS; i++)
        this->_values[i] -= m._values[i];
    return *this;
}

const Mat4f& Mat4f::operator*= (float factor)
{
    for(int i = 0; i < COLS * ROWS; i++)
        this->_values[i] *= factor;
	return *this;
}

const Mat4f& Mat4f::operator/= (float factor)
{
    for(int i = 0; i < COLS * ROWS; i++)
        this->_values[i] /= factor;
	return *this;
}