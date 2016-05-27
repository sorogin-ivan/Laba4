#include <gtest.h>
#include "Table.h"

TEST(Table, can_create_Table) 
{
	ASSERT_NO_THROW(ScanTable<int> *a = new ScanTable<int>(5));
}

TEST(Table, created_Table_is_empty) 
{
	ScanTable<int> *a = new ScanTable<int>(5);
	EXPECT_EQ(1, a->isEmpty());
}

TEST(Table, can_insert_record_to_Table) 
{
	ScanTable<int> *a = new ScanTable<int>(5);
	ASSERT_NO_THROW(a->insert(1,2));
}

TEST(Table, can_erase_record_from_Table) 
{
	ScanTable<int> *a = new ScanTable<int>(5);
	a->insert(1,2);
	ASSERT_NO_THROW(a->erase(1));
}

TEST(Table, can_erase_record_from_Table2) 
{
	ScanTable<int> *a = new ScanTable<int>(5);
	a->insert(1,2);
	EXPECT_EQ(a->isEmpty(), 0);
}

TEST(Table, can_find_record) 
{
	ScanTable<int> *a = new ScanTable<int>(5);
	a->insert(1,2);
	a->insert(2,3);
	a->insert(3,4);
	ASSERT_NO_THROW(a->search(2));
}

TEST(Table, can_find_record2) 
{
	ScanTable<int> *a = new ScanTable<int>(5);
	a->insert(1,2);
	a->insert(2,3);
	a->insert(3,4);
	EXPECT_EQ(a->search(2)->getData(), 3);
}

TEST(Table, cant_insert_record_to_Table_when_Table_is_full) 
{
	ScanTable<int> *a = new ScanTable<int>(5);
	a->insert(1,2);
	a->insert(2,3);
	a->insert(3,4);
	a->insert(4,5);
	a->insert(5,6);
	ASSERT_ANY_THROW(a->insert(6,7));
}

TEST(Table, can_isfull)
{
	ScanTable<int> *a = new ScanTable<int>(5);
	a->insert(1,2);
	a->insert(2,3);
	a->insert(3,4);
	a->insert(4,5);
	a->insert(5,6);
	EXPECT_EQ(a->isFull(), 1);
}

TEST(Table, can_getCount)
{
	ScanTable<int> *a = new ScanTable<int>(5);
	a->insert(1,2);
	a->insert(2,3);
	a->insert(3,4);
	a->insert(4,5);
	EXPECT_EQ(a->GetCount(), 4);
}

TEST(Table, throw_if_getNext_full_table)
{
	ScanTable<int> *a = new ScanTable<int>(5);
	a->insert(1,2);
	a->insert(2,3);
	a->insert(3,4);
	a->insert(4,5);
	a->insert(5,6);
	EXPECT_EQ(a->goNext(), 1);
}

TEST(Table, can_create_sorttable)
{
	ASSERT_NO_THROW(SortTable<int> *a = new SortTable<int>(5));
}

TEST(Table, can_copy_scantable_to_sorttable)
{
	ScanTable<int> *a = new ScanTable<int>(5);
	ASSERT_NO_THROW(SortTable<int> *b = new SortTable<int>(*a) );
}

TEST(Table, can_search_in_sorttable)
{
	SortTable<int> *a = new SortTable<int>(5);
	a->insert(1,2);
	a->insert(2,3);
	a->insert(3,4);
	a->insert(4,5);
	a->insert(5,6);
	EXPECT_EQ(a->search(3)->getData(), 4);
}

TEST(Table, can_erase_in_sorttable)
{
	SortTable<int> *a = new SortTable<int>(5);
	a->insert(1,2);
	a->insert(2,3);
	a->insert(3,4);
	a->insert(4,5);
	a->insert(5,6);
	ASSERT_NO_THROW(a->erase(3));
}

TEST(Table, can_sort_table)
{
	SortTable<int> *a = new SortTable<int>(5);
	a->insert(1,2);
	a->insert(2,3);
	a->insert(3,4);
	a->insert(4,5);
	a->insert(5,6);
	ASSERT_NO_THROW(a->sort());
}

TEST(Table, can_getmin)
{
	SortTable<int> *a = new SortTable<int>(5);
	a->insert(1,2);
	a->insert(2,3);
	a->insert(3,4);
	a->insert(4,5);
	a->insert(5,6);
	EXPECT_EQ(a->min()->getData(), 2);
}
