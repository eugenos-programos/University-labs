#define CATCH_CONFIG_MAIN
#include <iostream>
#include "oriented_graph.h"
#include "catch.hpp"
#include <algorithm>

using namespace oriented_graph;
using namespace std;

TEST_CASE("Testing constructors and operators")
{
    OrientedGraph<char> _orgTest1;
    OrientedGraph<char> _orgTest2(vector<vector<unsigned short>>{{1, 0}, {4, 0}}, vector<char>{'a', 'b'});
    OrientedGraph<char> _orgTest3(vector<vector<unsigned short>>{{1, 2}, {4, 0}}, vector<char>{'a', 'b'});
    OrientedGraph<int> _orgTest4(vector<vector<unsigned short>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, vector<int>{101, 102, 103});
    OrientedGraph<int> _orgTest5(vector<vector<unsigned short>>{{0, 0}, {4, 5}}, vector<int>{101, 102});
    OrientedGraph<int> _orgTest6(_orgTest4);

    REQUIRE(_orgTest4 == _orgTest6); // constructor testing
    REQUIRE(_orgTest2 <= _orgTest3);
    REQUIRE(!(_orgTest2 >= _orgTest3)); // subgraphs
    REQUIRE(_orgTest4 > _orgTest5);     // > < operators
    _orgTest4 = _orgTest5;
    REQUIRE(_orgTest4 == _orgTest5); // = operator

    _orgTest3.clear();
    _orgTest2.clear();
    //  REQUIRE(_orgTest3 == _orgTest1);
    REQUIRE(_orgTest3.empty()); // clear and empty methods
    REQUIRE(_orgTest3 == _orgTest2);
    REQUIRE(_orgTest3 <= _orgTest2); // also > < operators
    REQUIRE(_orgTest3 != _orgTest1);
}

TEST_CASE("Testing main container methods - 1")
{
    OrientedGraph<char> _testGraph1(vector<vector<unsigned short>>{{1, 0, 4, 0}, {2, 4, 0, 0}, {0, 1, 3, 0}, {1, 1, 1, 0}}, vector<char>{'a', 'b', 'c', 'd'});

    REQUIRE(_testGraph1.vertexExist('b') == 1); // vertexExist method return vertex index (or -1)
    REQUIRE(_testGraph1.vertexExist('e') == -1);

    REQUIRE(_testGraph1.arcExistBetweenVertices('b', 'a') == 1);
    REQUIRE(_testGraph1.arcExistBetweenVertices('c', 'a') == 0);

    REQUIRE(_testGraph1.getVertexNumber() == 4);
    REQUIRE(_testGraph1.getArcNumber() == 9);

    REQUIRE(_testGraph1.getPower('b') == 2);
    REQUIRE(_testGraph1.getPower('a', 'c') == 4);

    _testGraph1.addNewVertex('e');
    _testGraph1.addNewArc('e', 'a', 4);
    _testGraph1.addNewArc('e', 'b', 2);
    REQUIRE(_testGraph1.vertexExist('e') == 4);
    REQUIRE(_testGraph1.arcExistBetweenVertices('e', 'a') == 1);
    REQUIRE(_testGraph1.arcExistBetweenVertices('e', 'b') == 1);
    REQUIRE(_testGraph1.getVertexNumber() == 5);
    REQUIRE(_testGraph1.getArcNumber() == 11);
    REQUIRE(_testGraph1.getPower('e') == 2);
    REQUIRE(_testGraph1.getPower('e', 'a') == 4);

    _testGraph1.deleteVertex('a');
    REQUIRE(_testGraph1.getVertexNumber() == 4);
    REQUIRE(_testGraph1.getArcNumber() == 6);
    REQUIRE(_testGraph1.vertexExist('a') == -1);
}

TEST_CASE("Testing container iterators")
{
    OrientedGraph<char> _testGraph(vector<vector<unsigned short>>{{1, 2, 4, 40}, {0, 2, 0, 4}, {0, 0, 1, 3}, {1, 1, 0, 0}}, vector<char>{'a', 'b', 'c', 'd'});

    OrientedGraph<char>::VertexIterator _vertIter(_testGraph.vBegin());
    OrientedGraph<char>::ArcIterator _arcIter(_testGraph.aBegin());
    OrientedGraph<char>::ConstVertexIterator _constVertIter(_testGraph.cvBegin()); // iterators
    OrientedGraph<char>::ReverseVertexIterator _reverseVertIter(_testGraph.rvBegin());

    vector<char> _verticesFromIter;
    REQUIRE(_vertIter == _testGraph.vBegin());
    for (_vertIter; _vertIter != _testGraph.vEnd(); ++_vertIter)
    {
        _verticesFromIter.push_back(*_vertIter);
    }
    REQUIRE(_verticesFromIter == _testGraph.getVertexList());

    _vertIter = _testGraph.avBegin('b');
    REQUIRE(*(++_vertIter) == 'd');

    _verticesFromIter.clear();
    REQUIRE(*(++_constVertIter) == 'b');
    for (_constVertIter = _testGraph.cvBegin(); _constVertIter != _testGraph.cvEnd(); ++_constVertIter)
    {
        _verticesFromIter.push_back(*_constVertIter);
    }
    REQUIRE(_verticesFromIter == _testGraph.getVertexList());

    _constVertIter = _testGraph.cavBegin('a');
    REQUIRE(*(++_constVertIter) == 'b');
    REQUIRE(*(--_constVertIter) == 'a');

    _verticesFromIter.clear();
    REQUIRE(_reverseVertIter == _testGraph.rvBegin());
    REQUIRE(*(++_reverseVertIter) == 'c');
    REQUIRE(*(++_reverseVertIter) == 'b');
    REQUIRE(*(--_reverseVertIter) == 'c');

    _reverseVertIter = _testGraph.ravEnd('d');
    REQUIRE(*(--_reverseVertIter) == 'a');
    REQUIRE(*(--_reverseVertIter) == 'b');
    REQUIRE(*(++_reverseVertIter) == 'a');

    REQUIRE((*(_arcIter)).first == 'a');
    REQUIRE((*(_arcIter)).second == 'a');
    _arcIter = _testGraph.aEnd();
    REQUIRE((*(--_arcIter)).first == 'd');
    REQUIRE((*(_arcIter)).second == 'b');

    OrientedGraph<char>::ConstArcIterator _constArcIter(_testGraph.caiBegin('b'));
    REQUIRE((*_constArcIter).first == 'b');
    REQUIRE((*_constArcIter).second == 'b'); 
    _constArcIter = _testGraph.caiEnd();
    REQUIRE((*--_constArcIter).first == 'b');
    REQUIRE((*_constArcIter).second == 'd');
    
    OrientedGraph<char>::ReverseArcIterator _reverseArcIter(_testGraph.raiBegin('b'));
    REQUIRE((*_reverseArcIter).first == 'b');
    REQUIRE((*_reverseArcIter).second == 'd');
    _reverseArcIter = _testGraph.raiEnd();
    REQUIRE((*--_reverseArcIter).first == 'b');
    REQUIRE((*_reverseArcIter).second == 'b');
}
