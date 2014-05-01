/**
 * @file Mat4f.hpp
 * @brief Matrix description.
 * <p>Describe 4 by 4 float matrices.
 * Support most operations such as matrices multiplication and inversion.</p>
 * @author Jeremie Ferreira
 */

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

/**
 * Matrix description.
 */
class Mat4f
{
public:
    //ctors
    ///implicit ctor
    Mat4f();

    //explicit ctors
	/**
	 * @brief Explicit single value ctor.
	 * Each matrix element is set to <code>value</code>
	 * @param[in] value value to set.
	 */
    Mat4f(float value);
	/**
	 * @brief Explicit array ctor.
	 * Initialize matrix with <code>values</code>. Each set of consecutive
	 * 4-elements is considered as a column.
	 * @see Mat4f::setValues
	 * @warning values must be an initialized at-least-16-elements-array.
	 * @param[in] values values to set.
	 */
	Mat4f(const float values[]);
	/**
	 * @brief Explicit vector ctor.
	 * Initialize matrix with <code>values</code>. Each set of consecutive
	 * 4-elements is considered as a column.
	 * @warning values must be an initialized at-least-16-elements-vector.
	 * @param[in] values values to set.
	 */
    Mat4f(std::vector<float> values);
	/**
	 * @brief Explicit IJKT ctor.
	 * Initialize matrix with 4 column vectors <code>i, j, k, t</code>.
	 * @param[in] i first column vector.
	 * @param[in] j first column vector.
	 * @param[in] k first column vector.
	 * @param[in] t first column vector.
	 */
	Mat4f(const Vec4f& i, const Vec4f& j, const Vec4f& k, const Vec4f& t);

    //copy ctors
	/**
	 * @brief Copy ctor.
	 * Create a new Mat4f from an existing one.
	 * @param[in] matrix matrix to copy.
	 */
    Mat4f(const Mat4f& matrix);

    //dtors
	/**
	 * @brief Destructor.
	 * Deallocate stuff.
	 */
    ~Mat4f();

    //getters
    int getRows() const;
    int getCols() const;
	/**
	 * @brief row getter.
	 * Return row at <code>index</code> as a Vec4f.
	 * @param[in] index row index (starting with 0)
	 * @warning <code>index</code> must belong to [0;3].
	 * @return desired row.
	 */
	Vec4f getRow(int index) const;
	/**
	 * @brief column getter.
	 * Return column at <code>index</code> as a Vec4f.
	 * @param[in] index column index (starting with 0)
	 * @warning <code>index</code> must belong to [0;3].
	 * @return desired column.
	 */
	Vec4f getCol(int index) const;
	/**
	 * @brief I getter.
	 * Alias for <code>Mat4f::getCol(0)</code>.
	 * @return first column as Vec4f.
	 */
	Vec4f getI() const;
	/**
	 * @brief J getter.
	 * Alias for <code>Mat4f::getCol(1)</code>.
	 * @return second column as Vec4f.
	 */
	Vec4f getJ() const;
	/**
	 * @brief K getter.
	 * Alias for <code>Mat4f::getCol(2)</code>.
	 * @return third column as Vec4f.
	 */
	Vec4f getK() const;
	/**
	 * @brief T getter.
	 * Alias for <code>Mat4f::getCol(3)</code>.
	 * @return last column as Vec4f.
	 */
	Vec4f getT() const;
	/**
	 *	@brief return element at <code>(row, col)</code>.
	 *	@param[in] row element row.
	 *	@param[in] col element column.
	 *	@return desired element.
	 */
    float getValueAt(int row, int col) const;
    std::vector<float> getMat4f();
    //setters
	/**
	 * @brief I setter.
	 * Set the first column according to <code>i</code>
	 * @param[in] i Vec4f to set.
	 */
	void setI(const Vec4f& i);

	/**
	 * @brief J setter.
	 * Set the first column according to <code>j</code>
	 * @param[in] j Vec4f to set.
	 */
	void setJ(const Vec4f& j);
	/**
	 * @brief K setter.
	 * Set the first column according to <code>k</code>
	 * @param[in] k Vec4f to set.
	 */
	void setK(const Vec4f& k);
	/**
	 * @brief T setter.
	 * Set the first column according to <code>t</code>
	 * @param[in] t Vec4f to set.
	 */
	void setT(const Vec4f& t);
	/**
	 * @brief array setter.
	 * Reset matrix with <code>values</code>. Each set of consecutive
	 * 4-elements is considered as a column.
	 * @warning values must be an initialized at-least-16-elements-array.
	 * @param[in] values values to set.
	 */
    void setValues(const float values[]);
	/**
	 * @brief vector setter.
	 * Reset matrix with <code>values</code>. Each set of consecutive
	 * 4-elements is considered as a column.
	 * @warning values must be an initialized at-least-16-elements-vector.
	 * @param[in] values values to set.
	 */
    void setValues(const std::vector<float>& values);
	/**
	 * @brief single value setter.
	 * Set <code>value</code> at (<code>row</code>, <code>col</code>).
	 * @param[in] value	value to set.
	 * @param[in] row	value row.
	 * @param[in] col	value column.
	 */
    void setValueAt(float value, int row, int col);
	/**
	 *	@brief value adder.
	 *	<p>Add <code>value</code> to (<code>row</code>, <code>col</code>) element.</p>
	 *	<p>Example:
	 *	@code
	 *	Mat4f m(1);
	 *	m.addValueTo(10, 1, 0);
	 *	cout << m(1, 0);		//print 11
	 *	@endcode
	 *	</p>
	 */
    void addValueTo(float value, int row, int col);
	/**
	 *	@brief row setter.
	 *	Update row <code>index</code> with <code>row</code> values.
	 *	@param[in] index	row index.
	 *	@param[in] row	row to set.
	 *	@warning index must belong to [0;3].
	 */
	void setRow(int index, const Vec4f& row);
	/**
	 *	@brief column setter.
	 *	Update column <code>index</code> with <code>col</code> values.
	 *	@param[in] index	column index.
	 *	@param[in] col	column to set.
	 *	@warning index must belong to [0;3].
	 */
	void setCol(int index, const Vec4f& col);
	/**
	 *	@brief resetter.
	 *	Set each element to <code>value</code>.
	 */
    void clear(float clearValue);

	//operations
	/**
	 *	@brief Matrix determinant.
	 *	@return target matrix determinant.
	 */
	float determinant() const;
	/**
	 *	@brief Compute target's comatrix.
	 *	@return target's comatrix.
	 */
	Mat4f comatrix() const;
	/**
	 *	@brief Compute target's adjugate.
	 *	The adjugate is the transposed comatix.
	 *	@return target's adjugate.
	 */
	Mat4f adjugate() const;
	/**
	 *	@brief Compute target's traspose.
	 *	@return target's transpose.
	 */
	Mat4f transposed() const;
	/**
	 *	@brief Transpose target.
	 *	@return target's transpose.
	 */
	Mat4f transpose();
	/**
	 *	@brief Compute invert.
	 *	@return
	 *		- target's invert if possible.
	 *		- 0-filled Mat4f else.
	 */
	Mat4f inverted() const;
	/**
	 *	@brief Invert target.
	 *	@return target's invert.
	 */
	Mat4f invert();
	/**
	 *	@brief Compute the minor at <code>(i, j)</code>
	 *	@param[in]	row i
	 *	@param[in]	col j
	 *	@param[out]	minor result, must be an initialized 9-float array
	 */
	void minor(int row, int col, float * minor) const;
	/**
	 *	@return Identity matrix I<sub>4</sub>.
	 */
	static Mat4f identity();

    //operators
    /**
	 *	@brief value getter.
	 *	Alias of Mat4f::getValueAt(int, int, int).
	 *	@param[in]	row value row.
	 *	@param[in]	col value column.
	 *	@return value at <code>(row, col)</code>.
	 */
    float operator() (int row, int col) const;
    /**
	 *	@brief Matrix multiplication.
	 *	@param[in] rhs right-hand side of multplication
	 *	@return multiplication of target and rhs.
	 */
    Mat4f operator* (const Mat4f& rhs) const;
	/**
	 *	@brief Vector multiplication
	 *	@param[in] rhs right-hand side of multplication
	 *	@return multiplication of target and rhs.
	 */
	Mat4f operator* (const Vec4f& rhs) const;
	/**
	 *	@brief scalar multiplication.
	 *	multiply each target element by <code>factor</code>.
	 *	@param[in] rhs right-hand side of multplication
	 *	@return multiplication of target and rhs.
	 */
    Mat4f operator* (float factor) const;
    //addition
	/**
	 *	@brief Matrix addition.
	 *	@param[in] rhs right-hand side of addition
	 *	@return addition of target and rhs
	 */
    Mat4f operator+ (const Mat4f& rhs) const;
    //assignment
	/**
	 *	@brief Assignement.
	 *	Copy <code>rhs</code> values into target.
	 *	@param[in] rhs right-hand side of assignement.
	 *	@return target after assignement.
	 */
    const Mat4f& operator= (const Mat4f& rhs);
    //augmented assignments
	/**
	 *	@brief augmented addition
	 *	@param[in] rhs right-hand side of operation.
	 *	@return target after operation.
	 */
    const Mat4f& operator+= (const Mat4f& rhs);
	/**
	 *	@brief augmented subtraction
	 *	@param[in] rhs right-hand side of operation.
	 *	@return target after operation.
	 */
    const Mat4f& operator-= (const Mat4f& rhs);
	/**
	 *	@brief augmented scalar multiplication
	 *	@param[in] factor right-hand side of operation.
	 *	@return target after operation.
	 */
    const Mat4f& operator*= (float factor);
	/**
	 *	@brief augmented vector multiplication
	 *	@param[in] rhs right-hand side of operation.
	 *	@return target after operation.
	 */
	const Mat4f& operator*= (const Vec4f& rhs);
    const Mat4f& operator/= (float factor);
    ///prefix increment
    Mat4f& Mat4f::operator++ ();
	///prefix decrement
    Mat4f& Mat4f::operator-- ();
    ///postfix increment
    Mat4f Mat4f::operator++ (int);
	///postfix decrement
    Mat4f Mat4f::operator-- (int);
    ///output stream
    friend std::ostream& operator<< (std::ostream& os, const Mat4f & m);

private:
    ///values
    float * _values;
};

float getMat3Determinant(const float m[9]);

#endif