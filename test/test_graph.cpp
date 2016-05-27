#include <gtest.h>
#include "graphs.h"

TEST(Graph, can_create_graph){
	ASSERT_NO_THROW(Graph<int>(5,10));
}

TEST(Graph, throws_when_created_graph_with_number_of_vertices_bigger_than_MAX_VERTICE_NUM){
	ASSERT_ANY_THROW(Graph<int>(5,100));
}

TEST(Graph, can_get_set_of_edges){
	Graph<int> g(5,10);
	ASSERT_NO_THROW(g.getEdge(1));
}

TEST(Graph, created_graph_is_empty){
	Graph<int> g(5,10);
	EXPECT_EQ(10, g.getEdgeSize() );
}

TEST(Graph, can_fill_rand_graph){
	Graph<int> g(5,10);
	ASSERT_NO_THROW(g.createGraph(1, 5));
}

TEST(Graph, can_get_number_of_vertices){
	Graph<int> g(5,10);
	g.createGraph(1, 5);
	EXPECT_EQ(g.getRealSize(),10);
}

TEST(Graph, can_add_edge_to_graph){
	Graph<int> g(5,10);
	ASSERT_NO_THROW(g.addEdge(1, 2, 3));
}

TEST(Graph, throws_when_set_weight_have_incorrect_first_or_second_argument){
	Graph<int> g(5,10);
	ASSERT_ANY_THROW(g.addEdge(2,100,1));
}

TEST(Graph, can_get_weight){
	Graph<int> g(5,10);
	g.createGraph(1, 5);
	ASSERT_NO_THROW(g.getWeight(1, 2));
}

TEST(Graph, throws_when_get_weight_have_incorrect_first_or_second_argument){
	Graph<int> g(5,10);
	g.createGraph(1, 5);
	ASSERT_ANY_THROW(g.getWeight(1, 20));
}

TEST(Graph, get_weight_works_properly){
	Graph<int> g(5,10);
	g.addEdge(1, 2, 1);
	EXPECT_EQ(1, g.getWeight(1, 2));
}

TEST(Graph, can_erase_edge){
	Graph<int> g(5,10);
	g.createGraph(-100, 100);
	ASSERT_NO_THROW(g.delEdge(1,2));
}
