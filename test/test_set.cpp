#include <gtest.h>
#include "sets.h"

TEST(Set, can_create_disjoint_set) {
    ASSERT_NO_THROW(sets<int> a(3));
}

TEST(Set, throws_when_create_disjoint_set_vith_negative_size) {
    ASSERT_ANY_THROW(sets<int> a(-1));
}


TEST(Set, can_make_set) {
    sets<int> a(10);
	ASSERT_NO_THROW(a.makesets(2));
}

TEST(Set, throws_when_create_set_with_incorrect_argument) {
    sets<int> a(10);
	ASSERT_ANY_THROW(a.makesets(-1));
}

TEST(Set, throws_when_create_set_with_incorrect_argument2) {
    sets<int> a(10);
	ASSERT_ANY_THROW(a.makesets(11));
}

TEST(Set, can_find_sets) {
    sets<int> a(10);
    a.makesets(7);
	EXPECT_EQ(7, a.findsets(7));
}

TEST(Set, can_union_sets) {
    sets<int> a(10);
    a.makesets(7);
    a.makesets(4);
    ASSERT_NO_THROW(a.unionsets(7, 4));
}

TEST(Set, throws_when_union_sets_with_invalid_arguments) {
    sets<int> a(10);
    a.makesets(7);
    a.makesets(4);
    ASSERT_ANY_THROW(a.unionsets(-1, 0));
}

TEST(Set, throws_when_union_sets_with_invalid_arguments2) {
    sets<int> a(10);
    a.makesets(7);
    a.makesets(4);
    ASSERT_ANY_THROW(a.unionsets(0, -1));
}

TEST(Set, throws_when_unite_existing_and_non_existing_sets) {
    sets<int> a(10);
    a.makesets(7);
    a.makesets(4);
    ASSERT_ANY_THROW(a.unionsets(1, 7));
}

TEST(Set, throws_when_unite_existing_and_non_existing_sets2) {
    sets<int> a(10);
    a.makesets(7);
    a.makesets(4);
    ASSERT_ANY_THROW(a.unionsets(7, 1));
}

TEST(Set, can_find_root_of_set) {
    sets<int> a(10);
	a.makesets(7);
    a.makesets(4);
    a.unionsets(4, 7);
    ASSERT_NO_THROW(a.findsets(7));
}

TEST(Set, can_find_root_of_set2) {
    sets<int> a(10);
	a.makesets(7);
    a.makesets(4);
    a.unionsets(4, 7);
	EXPECT_EQ(4, a.findsets(7));
}

TEST(Set, throws_when_findSet_has_incorrect_argument) {
    sets<int> a(10);
    ASSERT_ANY_THROW(a.findsets(-1));
}

TEST(Set, throws_when_findSet_has_incorrect_argument2) {
    sets<int> a(10);
    ASSERT_ANY_THROW(a.findsets(11));
}

TEST(Set, can_get_set) {
    sets<int> a(10);
   	a.makesets(7);
    a.makesets(4);
    a.unionsets(4, 7);
    ASSERT_NO_THROW(a.getsets(4));
}

TEST(Set, can_get_set2) {
    sets<int> a(10);
   	a.makesets(7);
    a.makesets(4);
    a.unionsets(4, 7);
	int *c = a.getsets(4);
    int *b = new int[2];
	b[0] = 2; b[1] = 7; b[2] = 4;
	int tmp = 0;
	for (int i=0;i<3;i++)
	{
		if (c[i] != b[i])
			tmp = 1;
	}
    EXPECT_EQ(tmp, 0);
}

TEST(Set, throws_when_get_non_existing_set) {
    sets<int> a(10);
   	a.makesets(7);
    a.makesets(4);
    a.unionsets(4, 7);
    int *c = new int;
    ASSERT_ANY_THROW(c = a.getsets(1));
}

TEST(Set, throws_when_get_set_with_incorrect_argument) {
    sets<int> a(10);
	int *c = new int;
    ASSERT_ANY_THROW(c = a.getsets(-1));
}

TEST(Set, throws_when_get_set_with_incorrect_argument2) {
    sets<int> a(10);
	int *c = new int;
    ASSERT_ANY_THROW(c = a.getsets(11));
}