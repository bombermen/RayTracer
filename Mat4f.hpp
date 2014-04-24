#ifndef __MAT4F_HPP_INCLUDED
#define __MAT4F_HPP_INCLUDED
#ifndef __MAT4F_HPP_DEFINED
#define __MAT4F_HPP_DEFINED
class Mat4f;
#include "Vec4f.hpp"
#endif

#include <iostream>
#include <vector>
#include "Vec4f.hpp"

#define ROWS 4
#define COLS 4

class Mat4f
{
public:
    ///ctors
    ///implicit ctor
    Mat4f();
    ///explicit ctors
    Mat4f(float value);
	Mat4f(const float values[]);
    Mat4f(std::vector<float> values);
	Mat4f(const Vec4f& i, const Vec4f& j, const Vec4f& k, const Vec4f& t);
    ///copy ctors
    Mat4f(const Mat4f& matrix);

    ///dtors
    ~Mat4f();

    ///getters
    int getRows() const;
    int getCols() const;
	Vec4f getRow(int index) const;
	Vec4f getCol(int index) const;
	Vec4f getI() const;
	Vec4f getJ() const;
	Vec4f getK() const;
	Vec4f getT() const;
    float getValueAt(int row, int col) const;
    std::vector<float> getMat4f();

    ///setters
	void setI(const Vec4f& i);
	void setJ(const Vec4f& j);
	void setK(const Vec4f& k);
	void setT(const Vec4f& t);
    void setValues(const float values[]);
    void setValues(const std::vector<float>& values);
    void setValueAt(float value, int row, int col);
    void addValueTo(float value, int row, int col);
	void setRow(int index, const Vec4f& row);
	void setCol(int index, const Vec4f& col);
    void clear(float clearValue);

	Mat4f transposed() const;
	Mat4f transpose();

	static Mat4f identity();

    ///operators
    ///get value at
    float operator() (int row, int col) const;
    ///multiplication
    Mat4f operator* (const Mat4f& rhs) const;
	Mat4f operator* (const Vec4f& rhs) const;
    Mat4f operator* (float factor) const;
    ///addition
    Mat4f operator+ (const Mat4f& m) const;
    ///assignment
    const Mat4f& operator= (const Mat4f& m);
    ///augmented assignment
    const Mat4f& operator+= (const Mat4f& m);
    const Mat4f& operator-= (const Mat4f& m);
    const Mat4f& operator*= (float factor);
	const Mat4f& operator*= (const Vec4f& rhs);
    const Mat4f& operator/= (float factor);
    ///prefix increment - decrement operators
    Mat4f& Mat4f::operator++ ();
    Mat4f& Mat4f::operator-- ();
    ///postfix increment - decrement operators
    Mat4f Mat4f::operator++ (int);
    Mat4f Mat4f::operator-- (int);
    ///output stream
    friend std::ostream& operator<< (std::ostream& os, const Mat4f & m);

private:
    ///values
    float * _values;
};

#endif