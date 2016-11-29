#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
	
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
	
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
	
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
	
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);
	

	ASSERT_NO_THROW(TVector<int> v1(v));
	
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	
	int size = 5;
	int SI = 0;
	TVector<int> Vector1(size, SI);

	Vector1[2] = 2;


	

}

TEST(TVector, copied_vector_has_its_own_memory)
{
	
	int size = 4; int si = 0;

	TVector<int> tmp(size, si);

	tmp[2] = 2;

	TVector<int> tmp1(tmp);

	tmp1[2] = 3;

	EXPECT_NE(tmp, tmp1);
}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);
	

	EXPECT_EQ(4, v.GetSize());
	
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);
	

	EXPECT_EQ(2, v.GetStartIndex());
	
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;
	
	EXPECT_EQ(4, v[0]);
	
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	
	TVector<int> Vector;

	ASSERT_ANY_THROW(Vector[-2]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	
	TVector<int> Vector;

	ASSERT_ANY_THROW(Vector[MAX_VECTOR_SIZE + 1]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	
	int size = 4;  int si = 0;

	TVector<int> Vector(size, si);

	ASSERT_NO_THROW(Vector = Vector);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	
	int size = 4; int si = 0;

	TVector<int> Vector(size, si);
	TVector<int> tmp1(size, si);

	EXPECT_EQ(Vector, tmp1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	
	int size = 4; int si = 0;  int size1 = size + 2;

	TVector<int> Vector(size, si);
	TVector<int> tmp1(size1, si);

	Vector = tmp1;


	EXPECT_EQ(size1, Vector.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	
	int size = 4; int size1 = 5; int si = 0;

	TVector<int> Vector(size, si);
	TVector<int> tmp1(size1, si);

	Vector = tmp1;

	EXPECT_EQ(Vector, tmp1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	
	int size = 4; int si = 0;

	TVector<int> Vector1(size, si);
	TVector<int> Vector2(size, si);

	Vector1[1] = 2;
	Vector2[1] = 2;

	EXPECT_EQ(Vector1, Vector2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	
	int size = 4; int si = 0;

	TVector<int> Vector(size, si);

	EXPECT_EQ(Vector, Vector);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	
	int size = 4; int size1 = 5; int si = 0;

	TVector<int> Vector1(size, si);
	TVector<int> Vector2(size1, si);

	EXPECT_NE(Vector1, Vector2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	
	int val = 3;

	TVector<int> Vector1(2, 0);
	TVector<int> Vector2(2, 0);

	Vector1[0] = 1;
	Vector1[1] = 1;
	Vector1 = Vector1 + val;// 4 4 

	Vector2[0] = 4;
	Vector2[1] = 4;
	//4 4  

	EXPECT_EQ(Vector1, Vector2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	
	int val = 1;

	TVector<int> Vector1(2, 0);
	TVector<int> Vector2(2, 0);

	Vector1[0] = 2;
	Vector1[1] = 2;
	// 2 2 
	Vector1 = Vector1 - val;
	//1 1 

	Vector2[0] = 1;
	Vector2[1] = 1;
	//1 1 

	EXPECT_EQ(Vector2, Vector1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	
	int val = 2;

	TVector<int> Vector1(2, 0);
	TVector<int> Vector2(2, 0);

	Vector1[0] = 2;
	Vector1[1] = 2;
	// 2 2 
	Vector1 = Vector1 * val;
	//4 4 

	Vector2[0] = 4;
	Vector2[1] = 4;
	//4 4
	EXPECT_EQ(Vector2, Vector1);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	
	int size = 2;  int si = 0;

	TVector<int> Vector(size, si);
	TVector<int> Vector1(size, si);
	TVector<int> Vector2(size, si);
	TVector<int> Vector3(size, si);

	Vector1[0] = 2;
	Vector1[1] = 2;
	//2 2

	Vector2[0] = 2;
	Vector2[1] = 2;
	//2 2
	Vector3 = Vector2 + Vector1;

	Vector[0] = 4;
	Vector[1] = 4;
	EXPECT_EQ(Vector, Vector3);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	
	int size = 2; int size1 = 3;  int si = 0;

	TVector<int> Vector1(size, si);
	TVector<int> Vector2(size1, si);

	ASSERT_ANY_THROW(Vector1 + Vector2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	
	int size = 2;  int si = 0;

	TVector<int> Vector(size, si);
	TVector<int> Vector1(size, si);
	TVector<int> Vector2(size, si);
	TVector<int> Vector3(size, si);

	Vector1[0] = 5;
	Vector1[1] = 5;
	//5 5 

	Vector2[0] = 2;
	Vector2[1] = 2;
	//2 2
	Vector3 = Vector1 - Vector2;

	Vector[0] = 3;
	Vector[1] = 3;
	//3 3

	EXPECT_EQ(Vector, Vector3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	
	int size = 2; int size1 = 3;  int si = 0;

	TVector<int> Vector1(size, si);
	TVector<int> Vector2(size1, si);

	ASSERT_ANY_THROW(Vector2 - Vector1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	
	int size = 2;  int si = 0;
	int Vector;
	int res;

	TVector<int> Vector1(size, si);
	TVector<int> Vector2(size, si);

	Vector1[0] = 2;
	Vector1[1] = 2;
	//2 2

	Vector2[0] = 2;
	Vector2[1] = 2;
	//2 2
	res = Vector2 * Vector1;//8

	Vector = 8;

	EXPECT_EQ(Vector, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	
int size = 2;  int si = 0;

TVector<int> Vector1(size, si);
TVector<int> Vector2(size + 1, si);

ASSERT_ANY_THROW(Vector2*Vector1);
 }
