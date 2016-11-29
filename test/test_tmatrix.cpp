#include "utmatrix.h"

#include <gtest.h>

#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
	//ASSERT_NO_THROW(TMatrix<int> m(2));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
	//ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
	//ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);
	//TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
	//ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	//ADD_FAILURE();
	TMatrix<int> Matrix(4);
	Matrix[1][1] = 2;
	TMatrix<int> Matrix1(Matrix);

	EXPECT_EQ(Matrix, Matrix1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	//ADD_FAILURE();
	TMatrix<int> Matrix(4);

	Matrix[1][1] = 1;

	TMatrix<int> Matrix1(Matrix);

	Matrix1[1][1] = 2;

	EXPECT_NE(Matrix1, Matrix);
}

TEST(TMatrix, can_get_size)
{
	//ADD_FAILURE();
	int size = 4;

	TMatrix<int> Matrix(size);

	int res = Matrix.GetSize();

	EXPECT_EQ(res, size);
}

TEST(TMatrix, can_set_and_get_element)
{
	//ADD_FAILURE();
	int res = 2;
	TMatrix<int> Matrix(4);

	Matrix[1][1] = res;

	EXPECT_EQ(res, Matrix[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	//ADD_FAILURE();
	TMatrix<int> Matrix;
	ASSERT_ANY_THROW(Matrix[-2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	//ADD_FAILURE();
	TMatrix<int> Matrix;
	ASSERT_ANY_THROW(Matrix[MAX_MATRIX_SIZE + 1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	//ADD_FAILURE();
	TMatrix<int> Matrix(4);

	ASSERT_NO_THROW(Matrix = Matrix);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	//ADD_FAILURE();
	int size = 4;

	TMatrix<int> Matrix(size);
	TMatrix<int> Matrix1(size);

	Matrix = Matrix1;

	EXPECT_EQ(Matrix, Matrix1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	//ADD_FAILURE();
	int size = 4; int size1 = size + 2;
	TMatrix<int> Matrix(size);
	TMatrix<int> Matrix1(size1);

	Matrix = Matrix1;

	EXPECT_EQ(size1, Matrix.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	//ADD_FAILURE();
	int size = 4;

	TMatrix<int> Matrix(size);
	TMatrix<int> Matrix1(size + 1);

	Matrix = Matrix1;

	EXPECT_EQ(Matrix, Matrix1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	//ADD_FAILURE();
	int size = 4;

	TMatrix<int> Matrix(size);
	TMatrix<int> Matrix1(size);

	EXPECT_EQ(true, Matrix == Matrix1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	//ADD_FAILURE();
	int size = 4;

	TMatrix<int> Matrix(size);

	EXPECT_EQ(true, Matrix == Matrix);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	//ADD_FAILURE();
	int size = 4;

	TMatrix<int> Matrix(size);
	TMatrix<int> Matrix1(size + 1);

	EXPECT_NE(Matrix, Matrix1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	//ADD_FAILURE();
	int size = 2;

	TMatrix<int> tmp(size);
	TMatrix<int> Matrix1(size);
	TMatrix<int> Matrix2(size);
	TMatrix<int> res(size);

	Matrix1[0][0] = 1;
	Matrix1[0][1] = 1;
	Matrix1[1][1] = 1;

	Matrix2[0][0] = 1;
	Matrix2[0][1] = 1;
	Matrix2[1][1] = 1;

	tmp = Matrix1 + Matrix2;

	res[0][0] = 2;
	res[0][1] = 2;
	res[1][1] = 2;

	EXPECT_EQ(res, tmp);

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	//ADD_FAILURE();
	int size = 2; int size1 = size + 1;

	TMatrix<int> Matrix1(size);
	TMatrix<int> Matrix2(size1);

	ASSERT_ANY_THROW(Matrix1 + Matrix2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	//ADD_FAILURE();
	int size = 2;

	TMatrix<int> tmp(size);
	TMatrix<int> Matrix1(size);
	TMatrix<int> Matrix2(size);
	TMatrix<int> res(size);

	Matrix1[0][0] = 2;
	Matrix1[0][1] = 2;
	Matrix1[1][1] = 2;

	Matrix2[0][0] = 1;
	Matrix2[0][1] = 1;
	Matrix2[1][1] = 1;

	tmp = Matrix1 - Matrix2;

	res[0][0] = 1;
	res[0][1] = 1;
	res[1][1] = 1;

	EXPECT_EQ(res, tmp);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	
int size = 2; int size1 = size + 1;

TMatrix<int> Matrix1(size);
TMatrix<int> Matrix2(size1);

ASSERT_ANY_THROW(Matrix1 - Matrix2);
 }
