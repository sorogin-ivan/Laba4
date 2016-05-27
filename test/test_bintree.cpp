#include <gtest.h>
#include "bintree.h"


TEST(bintree, can_create_bintree)
{
	ASSERT_NO_THROW(bintree<int> *a = new bintree<int>());
}

TEST(bintree, can_copy_bintree)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 6;
	a->insert(a->root,b);
	ASSERT_NO_THROW(bintree<int> *b = new bintree<int>(*a));
}

TEST(bintree, provekra_copy)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 6;
	a->insert(a->root,b);
	b->key = 2;
	a->insert(a->root,b);
	bintree<int> *c = new bintree<int>(*a);
	int d = a->operator==(*c);
	EXPECT_EQ(d,1);
}

TEST(bintree, proverka_FindKey_if_key_est)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 6;
	a->insert(a->root,b);
	b->key = 2;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b = a->Findkey(a->root, 2);
	EXPECT_EQ(b->key, 2);
}

TEST(bintree, probyem_FindMin)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	Node<int> *c = a->FindMin(a->root);
	EXPECT_EQ(c->key, 0);
}

TEST(bintree, throw_if_in_FindMin_pustoe_tree)
{
	bintree<int> *a = new bintree<int>();
	ASSERT_ANY_THROW(a->FindMin(a->root));
}

TEST(bintree, probyem_FindMax)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	Node<int> *c = a->FindMax(a->root);
	EXPECT_EQ(c->key, 9);
}

TEST(bintree, throw_if_in_FindMax_pustoe_tree)
{
	bintree<int> *a = new bintree<int>();
	ASSERT_ANY_THROW(a->FindMax(a->root));
}

TEST(bintree, probyem_FindNext)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	b->key = 6;
	Node<int> *c = a->FindNext(a->root, b);
	EXPECT_EQ(c->key, 7);
}

TEST(bintree, can_findprevious)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	b->key = 6;
	Node<int> *c = a->FindPrevious(a->root, b);
	EXPECT_EQ(c->key, 5);
}

TEST(bintree, proverka_getsize)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	EXPECT_EQ(a->getSize(), 9);
}

TEST(bintree, proverka_getHeight)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	EXPECT_EQ (a->getHeight(a->root), 4);
}

TEST(bintree, throw_if_uncorrect_findnext)
{
	bintree<int> *a = new bintree<int>;
	Node<int> *b = new Node<int>(1);
	ASSERT_ANY_THROW(a->FindNext(a->root, b));
}

TEST(bintree, throw_if_uncorrect_findprevious)
{
	bintree<int> *a = new bintree<int>;
	Node<int> *b = new Node<int>(1);
	ASSERT_ANY_THROW(a->FindPrevious(a->root, b));
}