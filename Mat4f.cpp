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

Mat4f::Mat4f(const float values[]) {
	_values = new float[ROWS * COLS];
	this->setValues(values);
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

Mat4f::Mat4f(const Vec4f& i, const Vec4f& j, const Vec4f& k, const Vec4f& t)
{
	this->_values = new float[ROWS * COLS];
	this->setI(i);
	this->setJ(j);
	this->setK(k);
	this->setT(t);
}

Mat4f::~Mat4f()
{
    delete[] this->_values;
}

Mat4f Mat4f::identity()
{
	float values[] = {1,0,0,0,
					  0,1,0,0,
					  0,0,1,0,
					  0,0,0,1};

	return Mat4f(values);
}

int Mat4f::getRows() const { return ROWS; }

int Mat4f::getCols() const { return COLS; }

Vec4f Mat4f::getCol(int index) const
{
	return Vec4f(   this->getValueAt(0, index),
					this->getValueAt(1, index),
					this->getValueAt(2, index),
					this->getValueAt(3, index));
}

Vec4f Mat4f::getRow(int index) const
{
	return Vec4f(   this->getValueAt(index, 0),
					this->getValueAt(index, 1),
					this->getValueAt(index, 2),
					this->getValueAt(index, 3));
}

Vec4f Mat4f::getI() const { return this->getCol(0); }
Vec4f Mat4f::getJ() const { return this->getCol(1); }
Vec4f Mat4f::getK() const { return this->getCol(2); }
Vec4f Mat4f::getT() const { return this->getCol(3); }

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

void Mat4f::setRow(int index, const Vec4f& row)
{
	this->setValueAt(row.getX(), index, 0);
	this->setValueAt(row.getY(), index, 1);
	this->setValueAt(row.getZ(), index, 2);
	this->setValueAt(row.getW(), index, 3);
}

void Mat4f::setCol(int index, const Vec4f& col)
{
	this->setValueAt(col.getX(), 0, index);
	this->setValueAt(col.getY(), 1, index);
	this->setValueAt(col.getZ(), 2, index);
	this->setValueAt(col.getW(), 3, index);
}

void Mat4f::setI(const Vec4f& i) { this->setCol(0, i); }
void Mat4f::setJ(const Vec4f& j) { this->setCol(1, j); }
void Mat4f::setK(const Vec4f& k) { this->setCol(2, k); }
void Mat4f::setT(const Vec4f& t) { this->setCol(3, t); }

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

Mat4f Mat4f::transposed() const
{
	return Mat4f(
		this->getRow(0),
		this->getRow(1),
		this->getRow(2),
		this->getRow(3)
		);
}

Mat4f Mat4f::transpose()
{
	*this = this->transposed();
	return *this;
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
    for(int i = 0; i < COLS * ROWS; ++i)
        values.push_back(this->_values[i] + m._values[i]);
    return Mat4f(values);
}

Mat4f Mat4f::operator* (const Mat4f& rhs) const
{
    Mat4f result;
    for(unsigned int row = 0; row < ROWS; ++row)
        for(unsigned int col = 0; col < COLS; ++col)
            for(unsigned int i = 0; i < COLS; ++i)
                result.addValueTo(this->getValueAt(row, i) * rhs.getValueAt(i, col) ,row, col);
    return Mat4f(result.getMat4f());
}

Mat4f Mat4f::operator* (const Vec4f& rhs) const
{
	float values[ROWS * COLS];

	for(int i = 0; i < ROWS; ++i)
	{
		for(int j = 0; j < COLS; ++j)
		{
			values[i + j * COLS] = this->getRow(i) * rhs(j);
		}
	}

	return Mat4f(values);
}

Mat4f Mat4f::operator* (float factor) const
{
    std::vector<float> values;
    for(int i = 0; i < COLS * ROWS; ++i)
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

const Mat4f& Mat4f::operator*= (const Vec4f& rhs)
{
    for(int i = 0; i < COLS * ROWS; i++)
        this->_values[i] *= rhs(i);
	return *this;
}

const Mat4f& Mat4f::operator/= (float factor)
{
    for(int i = 0; i < COLS * ROWS; i++)
        this->_values[i] /= factor;
	return *this;
}

float Mat4f::determinant() const
{
	float det = 0;
	float sign = 1;

	for(int i = 0; i < COLS; ++i)
	{
		float minor[9];
		this->minor(0, i, minor);
		float minorDet = getMat3Determinant(minor);
		det += sign * this->getValueAt(0, i) * minorDet;
		sign *= -1;
	}

	return det;
}

float getMat3Determinant(const float m[9])
{
	return m[0] * m[4] * m[8] +
			m[3] * m[7] * m[2] +
			m[6] * m[1] * m[5] -
			m[6] * m[4] * m[2] -
			m[0] * m[7] * m[5] -
			m[3] * m[1] * m[8];
}

void Mat4f::minor(int row, int col, float * minor) const
{
	int minorIndex = 0;
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			if(i != row && j != col)
			{
				minor[minorIndex] = this->getValueAt(i,j);
				++minorIndex;
			}
		}
	}
}

Mat4f Mat4f::comatrix() const
{
	Mat4f com;
	float sign = 1;
	
	for(int i = 0 ; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			float minor[9];
			float minorDeterminant;

			this->minor(i, j, minor);
			minorDeterminant = getMat3Determinant(minor);
			com.setValueAt(sign * minorDeterminant, i, j);

			sign *= -1;
		}
		sign *= -1;
	}
	
	return Mat4f(com);
}

Mat4f Mat4f::adjugate() const
{
	Mat4f comatrix = this->comatrix();
	return comatrix.transposed();
}

Mat4f Mat4f::inverted() const
{
	float determinant = this->determinant();
	Mat4f adjugate;

	if(determinant == 0) {
		return *this;
	}

	adjugate = this->adjugate();
	return adjugate * (1 / determinant);
}

Mat4f Mat4f::invert()
{
	Mat4f i = this->inverted();
	return *this = i;
}

std::ostream& operator<< (std::ostream& os, const Mat4f & m)
{
    os << "[Mat4f " << ROWS << "*" << COLS << "]" << std::endl;
    for(unsigned int r = 0; r < ROWS; r++)
    {
        for(unsigned int c = 0; c < COLS; c++)
            os << "+--------";
        os << "+" << std::endl;

        for(unsigned int c = 0; c < COLS; c++)
		{
			float value = m.getValueAt(r, c);
			if(value < .00001 && value > -.00001)
				value = 0;
			if(value < 0) 
				os << "|";
			else
				os << "| ";
            os << value << " ";
			
		}
        os << "|" << std::endl;
    }
    for(unsigned int c = 0; c < COLS; c++)
        os << "+--------";
    os << "+" << std::endl;

    return os;
}