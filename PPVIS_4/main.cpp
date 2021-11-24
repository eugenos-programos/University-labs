#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
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

    cout << "Graph 2 - " << _orgTest2 << endl;
    cout << "Graph 3 - " << _orgTest3 << endl;
    cout << "Graph 4 - " << _orgTest4 << endl;

    vector<pair<char, char>> _pairVector{{'a', 'a'}, {'b', 'a'}};
    REQUIRE(_pairVector == _orgTest2.getAllArcs());

    _pairVector = {{'a', 'a'}};
    REQUIRE(_pairVector == _orgTest2.getAllIncidenceArcs('a'));

    vector<vector<unsigned short>> _testVector{{1, 0}, {4, 0}};
    vector<char> _testVector1{'a', 'b'};
    REQUIRE(_testVector == _orgTest2.getAdjMatrix());
    REQUIRE(_testVector1 == _orgTest2.getVertexList());
    _testVector1 = {'a'};
    REQUIRE(_testVector1 == _orgTest2.getAdjacencyVertices('a'));
    bool _operationResult = _orgTest4 == _orgTest6;
    REQUIRE(_operationResult == true); // constructor testing
    _operationResult = _orgTest2 <= _orgTest3;
    REQUIRE(_operationResult == true);
    _operationResult = _orgTest2 >= _orgTest3;
    REQUIRE(_operationResult == false); // subgraphs
    _operationResult = _orgTest4 > _orgTest5;
    REQUIRE(_operationResult == true); // > < operators
    _orgTest4 = _orgTest5;
    _operationResult = _orgTest4 == _orgTest5;
    REQUIRE(_operationResult == true); // = operator
    _orgTest3.clear();
    _orgTest2.clear();
    REQUIRE(_orgTest2.getVertexList().empty() == true); //
    REQUIRE(_orgTest3.empty() == true);                 // clear and empty methods
    _operationResult = _orgTest3 == _orgTest2;
    REQUIRE(_operationResult == true); //
    _operationResult = _orgTest3 <= _orgTest2;
    REQUIRE(_operationResult == true); // also > < operators
    _operationResult = _orgTest3 != _orgTest1;
    REQUIRE(_operationResult == true); //
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
    vector<vector<unsigned short>> _resVector{{1, 0, 4, 0, 0}, {2, 4, 0, 0, 0}, {0, 1, 3, 0, 0}, {1, 1, 1, 0, 0}, {4, 2, 0, 0, 0}};
    REQUIRE(_testGraph1.getAdjMatrix() == _resVector);
    REQUIRE(_testGraph1.arcExistBetweenVertices('e', 'a') == 1);
    REQUIRE(_testGraph1.arcExistBetweenVertices('e', 'b') == 1);
    REQUIRE(_testGraph1.getVertexNumber() == 5);
    REQUIRE(_testGraph1.getArcNumber() == 11);
    REQUIRE(_testGraph1.getPower('e') == 2);
    REQUIRE(_testGraph1.getPower('e', 'a') == 4);

    _testGraph1.deleteVertex('a');
    _testGraph1.deleteArc('e', 'b');
    _testGraph1.deleteArc('b', 'b');
    _resVector = {{0, 0, 0, 0}, {1, 3, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(_testGraph1.getAdjMatrix() == _resVector);
    REQUIRE(_testGraph1.getVertexNumber() == 4);
    REQUIRE(_testGraph1.getArcNumber() == 4);
    REQUIRE(_testGraph1.vertexExist('a') == -1);
}

TEST_CASE("Iterator testing")
{
    OrientedGraph<char> _testGraph(vector<vector<unsigned short>>{{1, 2, 4, 40}, {0, 2, 0, 4}, {0, 0, 1, 3}, {1, 1, 0, 0}}, vector<char>{'a', 'b', 'c', 'd'});

    OrientedGraph<char>::VertexIterator _vertIter(_testGraph.vBegin());
    OrientedGraph<char>::ConstVertexIterator _constVertIter(_testGraph.cvBegin()); // iterators
    OrientedGraph<char>::ReverseVertexIterator _reverseVertIter;

    vector<char> _verticesFromIter;

    // SIMPLE VERTEX ITERATOR TESTING

    REQUIRE(_vertIter == _testGraph.vBegin());
    for (_vertIter; _vertIter != _testGraph.vEnd(); ++_vertIter)
    {
        _verticesFromIter.push_back(*_vertIter);
    }
    REQUIRE(_verticesFromIter == _testGraph.getVertexList());
    _vertIter = _testGraph.avBegin('a');
    REQUIRE(*(++_vertIter) == 'b');

    _vertIter = _testGraph.avEnd('d');
    REQUIRE(*(--_vertIter) == 'b');

    _verticesFromIter.clear();
    _vertIter = _testGraph.avBegin('b');
    for (; _vertIter != _testGraph.avEnd('b'); ++_vertIter)
    {
        _verticesFromIter.push_back(*_vertIter);
    }
    REQUIRE(_verticesFromIter == _testGraph.getAdjacencyVertices('b'));

    //  CONSTANT VERTEX ITERATOR TESTING

    _verticesFromIter.clear();
    REQUIRE(*(++_constVertIter) == 'b');
    REQUIRE(*(++_constVertIter) == 'c');
    REQUIRE(*(_constVertIter--) == 'c');
    REQUIRE(*(_constVertIter) == 'b');
    for (_constVertIter = _testGraph.cvBegin(); _constVertIter != _testGraph.cvEnd(); ++_constVertIter)
    {
        _verticesFromIter.push_back(*_constVertIter);
    }
    REQUIRE(_verticesFromIter == _testGraph.getVertexList());

    _testGraph.addNewVertex('e');
    _testGraph.addNewArc('e', 'c', 5);
    _testGraph.addNewArc('e', 'a', 10);

    _constVertIter = _testGraph.cavBegin('e');

    _verticesFromIter.clear();
    _constVertIter = _testGraph.cavBegin('a');
    REQUIRE(*(++_constVertIter) == 'b');
    REQUIRE(*(--_constVertIter) == 'a');

    //  REVERSE VERTEX ITERATOR TESTING

    _verticesFromIter.clear();
    _reverseVertIter = _testGraph.rvBegin();
    REQUIRE(*(_reverseVertIter) == 'e');
    REQUIRE(*(++_reverseVertIter) == 'd');

    for (_reverseVertIter = _testGraph.rvBegin(); _reverseVertIter != _testGraph.rvEnd(); ++_reverseVertIter)
    {
        _verticesFromIter.push_back(*_reverseVertIter);
    }
    std::reverse(_verticesFromIter.begin(), _verticesFromIter.end());
    REQUIRE(_verticesFromIter == _testGraph.getVertexList());

    _reverseVertIter = _testGraph.ravEnd('d');
    REQUIRE(*(--_reverseVertIter) == 'a');
    REQUIRE(*(--_reverseVertIter) == 'b');
    REQUIRE(*(++_reverseVertIter) == 'a');

    // SIMPLE ARC ITERATOR TESTING

    OrientedGraph<int> _testGraph1(vector<vector<unsigned short>>{{1, 2, 0}, {0, 1, 0}, {1, 1, 0}}, vector<int>{1, 2, 3});

    vector<pair<int, int>> _arcIterList;

    OrientedGraph<int>::ArcIterator _arcIter(_testGraph1.aBegin());

    REQUIRE((*(_arcIter)).first == 1);
    REQUIRE((*(_arcIter)).second == 1);

    _arcIter = _testGraph1.aiBegin(2);
    for (_arcIter; _arcIter != _testGraph1.aiEnd(2); ++_arcIter)
    {
        _arcIterList.push_back(*_arcIter);
    }
    REQUIRE(_arcIterList == _testGraph1.getAllIncidenceArcs(2));
    _arcIterList.clear();

    // CONSTANT ARC ITERATOR TESTING

    OrientedGraph<int>::ConstArcIterator _arcConstIter(_testGraph1.caiBegin(1));
    REQUIRE((*_arcConstIter).first == 1);
    REQUIRE((*_arcConstIter).second == 1);
    REQUIRE((*++_arcConstIter).second == 2);
    REQUIRE((*_arcConstIter).first == 1);

    _arcIterList.clear();

    for (_arcConstIter = _testGraph1.caiBegin(1); _arcConstIter != _testGraph1.caiEnd(1); ++_arcConstIter)
    {
        _arcIterList.push_back(*_arcConstIter);
    }
    REQUIRE(_arcIterList == _testGraph1.getAllIncidenceArcs(1));

    // REVERSE ARC ITERATOR TESTING

    _arcIterList.clear();
    OrientedGraph<int>::ReverseArcIterator _arcReverseIter(_testGraph1.raBegin());
    for (_arcReverseIter; _arcReverseIter != _testGraph1.raEnd(); ++_arcReverseIter)
    {
        _arcIterList.push_back(*_arcReverseIter);
    }
    reverse(_arcIterList.begin(), _arcIterList.end());
    REQUIRE(_arcIterList == _testGraph1.getAllArcs());

    _arcIterList.clear();
    _arcReverseIter = _testGraph1.raiBegin(3);
    for (_arcReverseIter; _arcReverseIter != _testGraph1.raiEnd(3); ++_arcReverseIter)
    {
        _arcIterList.push_back(*_arcReverseIter);
    }
    reverse(_arcIterList.begin(), _arcIterList.end());
    REQUIRE(_arcIterList == _testGraph1.getAllIncidenceArcs(3));
}

TEST_CASE("Delete arc or vertex from the iterator methods testing | for_each testinf")
{
    OrientedGraph<string> _testGraph(vector<vector<unsigned short>>{{1, 2, 3}, {0, 0, 1}, {1, 0, 1}}, vector<string>{"first", "second", "third"});
    OrientedGraph<string>::ArcIterator _arcIter(_testGraph.aBegin());
    _testGraph.deleteArc(_arcIter);
    _testGraph.deleteArc(++_arcIter);
    _arcIter = --_testGraph.aEnd();
    _testGraph.deleteArc(_arcIter);
    _testGraph.deleteArc(--_arcIter);
    vector<vector<unsigned short>> _testVector{{0, 0, 3}, {0, 0, 1}, {0, 0, 0}}; // Delete arc
    REQUIRE(_testVector == _testGraph.getAdjMatrix());

    OrientedGraph<string>::VertexIterator _vertexIter(_testGraph.vBegin());
    _testGraph.deleteVertex(_vertexIter);
    _testGraph.deleteArc(_testGraph.aBegin());
    vector<vector<unsigned short>> _testVector1{{0, 0}, {0, 0}}; // last arc deleted
    vector<string> _testVector2{"second", "third"};
    REQUIRE(_testVector1 == _testGraph.getAdjMatrix());
    REQUIRE(_testVector2 == _testGraph.getVertexList());

    _testGraph.deleteVertex(--_testGraph.vEnd());
    _testVector2 = {"second"};
    _testVector1 = {{0}};
    REQUIRE(_testVector2 == _testGraph.getVertexList());
    REQUIRE(_testVector1 == _testGraph.getAdjMatrix());
}