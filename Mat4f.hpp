#pragma once

#include <iostream>
#include <vector>

#define ROWS 4
#define COLS 4

class Vec4f
{
public:
	Vec4f(float, float, float, float);
};

class Mat4f
{
public:
    ///ctors
    ///implicit ctor
    Mat4f();
    ///explicit ctors
    Mat4f(float value);
    Mat4f(std::vector<float> values);
    ///copy ctors
    Mat4f(const Mat4f& matrix);

    ///dtors
    ~Mat4f();

    ///getters
    int getRows() const;
    int getCols() const;
	Vec4f getRow(int index) const;
	Vec4f getI() const;
	Vec4f getJ() const;
	Vec4f getK() const;
	Vec4f getT() const;
    float getValueAt(int row, int col) const;
    std::vector<float> getMat4f();

    ///setters
    void setValues(const float values[]);
    void setValues(const std::vector<float>& values);
    void setValueAt(float value, int row, int col);
    void addValueTo(float value, int row, int col);
    void clear(float clearValue);

    ///operators
    ///get value at
    float operator() (int row, int col) const;
    ///multiplication
    Mat4f operator* (const Mat4f& rhs) const;
    Mat4f operator* (float factor) const;
    ///addition
    Mat4f operator+ (const Mat4f& m) const;
    ///assignment
    const Mat4f& operator= (const Mat4f& m);
    ///augmented assignment
    const Mat4f& operator+= (const Mat4f& m);
    const Mat4f& operator-= (const Mat4f& m);
    const Mat4f& operator*= (float factor);
    const Mat4f& operator/= (float factor);
    ///prefix increment - decrement operators
    Mat4f& Mat4f::operator++ ();
    Mat4f& Mat4f::operator-- ();
    ///postfix increment - decrement operators
    Mat4f Mat4f::operator++ (int);
    Mat4f Mat4f::operator-- (int);
    ///output stream
    friend std::ostream& operator<< (std::ostream& os, const Mat4f & m)
    {
        os << "[Mat4f " << ROWS << "*" << COLS << "]" << std::endl;
        for(unsigned int r = 0; r < ROWS; r++)
        {
            for(unsigned int c = 0; c < COLS; c++)
                os << "+-------";
            os << "+" << std::endl;

            for(unsigned int c = 0; c < COLS; c++)
                os << "| " << m.getValueAt(r, c) << "\t";
            os << "|" << std::endl;
        }
        for(unsigned int c = 0; c < COLS; c++)
            os << "+-------";
        os << "+" << std::endl;

        return os;
    }

private:
    ///values
    float * _values;
};
