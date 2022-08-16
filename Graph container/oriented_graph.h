#ifndef ORIENTED_GRAPH_INCLUDED
#define ORIENTED_GRAPH_INCLUDED

#include <vector>
#include <ostream>
#include <iterator>
#include <algorithm>
#include "Vertex_Iterator.h"
#include "Const_Vertex_iterator.h"
#include "Reverse_Vertex_Iterator.h"
#include "Arc_Iterator.h"
#include "Const_Arc_iterator.h"
#include "Reverse_Arc_Iterator.h"
#include "traits.h"


namespace oriented_graph
{
    /*!
        \brief Class,which realize oriented graph container
        \author Znenya Samchuk
        \version 1.0
        \date November'17
    */
    template <typename T, typename traits_for_vertex = elem_traits<T>, typename traits_for_arc = elem_traits<std::pair<T, T>>>

    class OrientedGraph
    {
    public:
        typedef typename traits_for_vertex::value_type value_type;
        typedef typename traits_for_vertex::const_reference const_reference;
        typedef typename traits_for_vertex::reference reference;
        typedef typename traits_for_vertex::const_value const_value;
        typedef typename traits_for_vertex::pointer pointer;

        // Iterators
        typedef _VertexIterator<value_type> VertexIterator;
        typedef _ConstVertexIterator<value_type> ConstVertexIterator;
        typedef _ReverseVertexIterator<value_type> ReverseVertexIterator;

        typedef _ArcIterator<value_type> ArcIterator;
        typedef _ConstArcIterator<value_type> ConstArcIterator;
        typedef _ReverseArcIterator<value_type> ReverseArcIterator;

        typedef typename traits_for_arc::value_type ArcType;

    private:
        std::vector<std::vector<unsigned short>>
            _adjacencyMatrix; // unsigned short ~ [0..65 535]

        std::vector<value_type> _vertexList; // here also defined list with vertices values because adjacency matrix values and vertex values are not the same

    public:
        /**
         * @brief  Oriented Graph constructor
         * @param accepts no parameters
         * @return nothing
         */
        OrientedGraph()
        {
            _vertexList = {};
            _adjacencyMatrix = {{}};
        }
        /**
         * @brief  Oriented Graph constructor
         * @param accepts adjacency Matrix and vertex list
         * @return nothing
         */
        OrientedGraph(std::vector<std::vector<unsigned short>> _adjMatrix, std::vector<value_type> _vertexList)
        {
            if (_adjMatrix.size() != _vertexList.size())
                throw "Uncorrect input data sizes";
            this->_adjacencyMatrix = _adjMatrix;
            this->_vertexList = _vertexList;
        }
        /**
         * @brief  get AdjMatrix method
         * @param accepts  no arguments
         * @return adjacency matrix
         */
        std::vector<std::vector<unsigned short>> getAdjMatrix() const
        {
            return _adjacencyMatrix;
        }
        /**
         * @brief  getVertexList method
         * @param accepts no arguments
         * @return vertex List
         */
        std::vector<value_type> getVertexList() const
        {
            return _vertexList;
        }
        /**
         * @brief  get Adjacency Matrix method
         * @param accepts no arguments
         * @return Adjacency vertices
         */
        std::vector<value_type> getAdjacencyVertices(const_reference _vertex)
        {
            std::vector<value_type> _vertices;
            if (vertexExist(_vertex) == -1)
                throw "Vertex doesn't exist!";
            for (int _vertexIndex = 0; _vertexIndex < getVertexNumber(); ++_vertexIndex)
            {
                if (arcExistBetweenVertices(_vertex, _vertexList[_vertexIndex]))
                    _vertices.push_back(_vertexList[_vertexIndex]);
            }
            return _vertices;
        }
        /**
         * @brief  get All Arcs method
         * @param accepts no arguments
         * @return all arcs
         */
        std::vector<ArcType> getAllArcs()
        {
            std::vector<ArcType> arcs;
            for (int _rowIndex = 0; _rowIndex < getVertexNumber(); ++_rowIndex)
            {
                for (int _columnIndex = 0; _columnIndex < getVertexNumber(); ++_columnIndex)
                {
                    if (_adjacencyMatrix[_rowIndex][_columnIndex] > 0)
                    {
                        ArcType arc;
                        arc.first = _vertexList[_rowIndex];
                        arc.second = _vertexList[_columnIndex];
                        arcs.push_back(arc);
                    }
                }
            }
            return arcs;
            throw "No arcs";
        }
        /**
         * @brief  get All Incidence Arcs
         * @param accepts vertex
         * @return incidence arcs
         */
        std::vector<ArcType> getAllIncidenceArcs(const_reference _vertex)
        {
            std::vector<value_type> _adjVertices = getAdjacencyVertices(_vertex);
            std::vector<ArcType> _incidenceArcs;
            for (value_type _adjacencyVertex : _adjVertices)
            {
                ArcType _arc;
                _arc.first = _vertex;
                _arc.second = _adjacencyVertex;
                _incidenceArcs.push_back(_arc);
            }
            return _incidenceArcs;
        }
        /**
         * @brief  vBegin method
         * @param accepts no arguments
         * @return iterator on the begin vertex list
         */
        VertexIterator vBegin()
        {
            return *(new VertexIterator(&_vertexList[0]));
        }
        /**
         * @brief  vEnd method
         * @param accepts no arguments
         * @return iterator on the end vertex list
         */
        VertexIterator vEnd()
        {
            return *(new VertexIterator(&_vertexList[getVertexNumber()]));
        }
        /**
         * @brief  cvBegin method
         * @param
         * @return Const iterator on the begin of vertex list
         */
        ConstVertexIterator cvBegin()
        {
            return *(new ConstVertexIterator(&_vertexList[0]));
        }
        /**
         * @brief  cvEnd method
         * @param
         * @return const iterator on the end of vertex list
         */
        ConstVertexIterator cvEnd()
        {
            return *(new ConstVertexIterator(&_vertexList[getVertexNumber()]));
        }
        /**
         * @brief  rvBegin method
         * @param accepts no arguments
         * @return reverse iterator on the begin of vertex list
         */
        ReverseVertexIterator rvBegin()
        {
            return *(new ReverseVertexIterator(&_vertexList[getVertexNumber() - 1]));
        }
        /**
         * @brief  rvEnd method
         * @param accepts no arguments
         * @return reverse iterator on the end of vertex list
         */
        ReverseVertexIterator rvEnd()
        {
            return *(new ReverseVertexIterator(&_vertexList[-1]));
        }
        /**
         * @brief  avBegin method
         * @param accepts vertex
         * @return Iterator on the begin of adj. vertices list
         */
        VertexIterator avBegin(const_reference _vertex)
        {
            std::vector<value_type> _adjVertexList = getAdjacencyVertices(_vertex);
            return *(new VertexIterator(&_adjVertexList[0], std::move(_adjVertexList)));
        }
        /**
         * @brief  avEnd method
         * @param accepts no arguments
         * @return Iterator on the end of adj. vertices list
         */
        VertexIterator avEnd(const_reference _vertex)
        {
            std::vector<value_type> _adjVertexList = getAdjacencyVertices(_vertex);
            return *(new VertexIterator(&_adjVertexList[_adjVertexList.size()], std::move(_adjVertexList)));
        }
        /**
         * @brief  cavBegin method
         * @param accepts vertex
         * @return Const iterator on the begin of adj, vertices list
         */
        ConstVertexIterator cavBegin(const_reference _vertex)
        {
            std::vector<value_type> _adjVertexList = getAdjacencyVertices(_vertex);
            return *new ConstVertexIterator(&_adjVertexList[0], std::move(_adjVertexList));
        }
        /**
         * @brief  cavEnd method
         * @param accepts no arguments
         * @return const iterator on the end of vertex list
         */
        ConstVertexIterator cavEnd(const_reference _vertex)
        {
            std::vector<value_type> _adjVertexList = getAdjacencyVertices(_vertex);
            return *new ConstVertexIterator(&_adjVertexList[_adjVertexList.size()], std::move(_adjVertexList));
        }
        /**
         * @brief  ravBegin method
         * @param accepts vertex
         * @return reverse iterator on the begin of vertex list
         */
        ReverseVertexIterator ravBegin(const_reference _vertex)
        {
            std::vector<value_type> _adjVertexList = getAdjacencyVertices(_vertex);
            return *(new ReverseVertexIterator(&_adjVertexList[_adjVertexList.size() - 1]), std::move(_adjVertexList));
        }
        /**
         * @brief  ravEnd method
         * @param accepts vertex
         * @return reverse iterator on the end of the adjacency vertex list
         */
        ReverseVertexIterator ravEnd(const_reference _vertex)
        {
            std::vector<value_type> _adjVertexList = getAdjacencyVertices(_vertex);
            return *new ReverseVertexIterator((&_adjVertexList[-1]), std::move(_adjVertexList));
        }
        /**
         * @brief  aBegin method
         * @param accepts no arguments
         * @return arc iterator on the begin of arc list
         */
        ArcIterator aBegin()
        {
            std::vector<ArcType> _arcList = getAllArcs();
            return *new ArcIterator(&_arcList[0], std::move(_arcList));
        }
        /**
         * @brief  aEnd method
         * @param accepts no arguments
         * @return iterator on end of arc list
         */
        ArcIterator aEnd()
        {
            std::vector<ArcType> _arcList = getAllArcs();
            return *new ArcIterator(&_arcList[getArcNumber()], std::move(_arcList));
        }
        /**
         * @brief  raBegin method
         * @param accepts no arguments
         * @return reverse iterator on the reverse end of the arc list
         */
        ReverseArcIterator raBegin()
        {
            std::vector<ArcType> _arcList = getAllArcs();
            return *new ReverseArcIterator(&_arcList[getArcNumber() - 1], std::move(_arcList));
        }
        /**
         * @brief  raEnd method
         * @param accepts no arguments
         * @return reverse iterator on the reverse begin of the arc list
         */
        ReverseArcIterator raEnd()
        {
            std::vector<ArcType> _arcList = getAllArcs();
            return *new ReverseArcIterator(&_arcList[-1], std::move(_arcList));
        }
        /**
         * @brief  caBegin method
         * @param accepts no arguments
         * @return constant iterator on the begin of the arc list
         */
        ConstArcIterator caBegin()
        {
            std::vector<ArcType> _arcList = getAllArcs();
            return *new ConstArcIterator(&_arcList[0]);
        }
        /**
         * @brief  caEnd method
         * @param accepts no arguments
         * @return constant iterator on the end of the arc list
         */
        ConstArcIterator caEnd()
        {
            std::vector<ArcType> _arcList = getAllArcs();
            return *new ConstArcIterator(&_arcList[getArcNumber()]);
        }
        /**
         * @brief  aiBegin method
         * @param accepts vertex
         * @return arc iterator on the begin of incidence arc list
         */
        ArcIterator aiBegin(const_reference _vertex)
        {
            std::vector<ArcType> _incidenceArcList = getAllIncidenceArcs(_vertex);
            return *new ArcIterator(&_incidenceArcList[0], std::move(_incidenceArcList));
        }
        /**
         * @brief  aiEnd method
         * @param accepts no arguments
         * @return arc iterator on the end of incidence arc list
         */
        ArcIterator aiEnd(const_reference _vertex)
        {
            std::vector<ArcType> _incidenceArcList = getAllIncidenceArcs(_vertex);
            return *new ArcIterator(&_incidenceArcList[_incidenceArcList.size()], std::move(_incidenceArcList));
        }
        /**
         * @brief  raiBegin method
         * @param accepts vertex
         * @return reverse arc iterator on the reverse begin of incidence arc list
         */
        ReverseArcIterator raiBegin(const_reference _vertex)
        {
            std::vector<ArcType> _incidenceArcList = getAllIncidenceArcs(_vertex);
            return *new ReverseArcIterator(&_incidenceArcList[_incidenceArcList.size() - 1], std::move(_incidenceArcList));
        }
        /**
         * @brief  raiEnd method
         * @param accepts no arguments
         * @return reverse arc iterator on the reverse end of the arc list
         */
        ReverseArcIterator raiEnd(const_reference _vertex)
        {
            std::vector<ArcType> _incidenceArcList = getAllIncidenceArcs(_vertex);
            return *new ReverseArcIterator(&_incidenceArcList[-1], std::move(_incidenceArcList));
        }
        /**
         * @brief  cai Begin method
         * @param accepts vertex
         * @return const arc iterator on the begin of the incidence arc list
         */
        ConstArcIterator caiBegin(const_reference _vertex)
        {
            std::vector<ArcType> _incidenceArcList = getAllIncidenceArcs(_vertex);
            return *new ConstArcIterator(&_incidenceArcList[0], std::move(_incidenceArcList));
        }
        /**
         * @brief  cai End method
         * @param accepts no arguments
         * @return const iterator on the end of the incidence arc list
         */
        ConstArcIterator caiEnd(const_reference _vertex)
        {
            std::vector<ArcType> _incidenceArcList = getAllIncidenceArcs(_vertex);
            return *new ConstArcIterator(&_incidenceArcList[_incidenceArcList.size()], std::move(_incidenceArcList));
        }

        /**
         * @brief  operator =
         * @param accepts another graph
         * @return this reference
         */

        OrientedGraph &operator=(const OrientedGraph<value_type> &_graph)
        {
            this->_adjacencyMatrix = _graph._adjacencyMatrix;
            this->_vertexList = _graph._vertexList;
            return *this;
        }
        /**
         * @brief == operator
         * @param accepts another graph
         * @return true/false
         */
        bool operator==(const OrientedGraph &_graph)
        {
            return _adjacencyMatrix == _graph.getAdjMatrix(); //&& _vertexList == _graph.getVertexList();
        }
        /**
         * @brief  != operator
         * @param accepts another graph
         * @return true/false
         */
        bool operator!=(const OrientedGraph &_graph)
        {
            return !(*this == _graph);
        }
        /**
         * @brief  < operator
         * @param accepts two graphes
         * @return true/false
         */
        friend bool operator<(const OrientedGraph<value_type> &_firstGraph, const OrientedGraph<value_type> &_secondGraph)
        {
            if (_firstGraph.getVertexNumber() > _secondGraph.getVertexNumber() || _firstGraph.getArcNumber() > _secondGraph.getArcNumber())
                return false;
            OrientedGraph<value_type> _auxiliaryGraph = _secondGraph;
            for (int _vertexListIndex = 0; _vertexListIndex < _firstGraph.getVertexList().size(); ++_vertexListIndex)
            {
                if (_auxiliaryGraph.vertexExist(_firstGraph.getVertexList()[_vertexListIndex]) == -1)
                    return false;
            }
            for (int _vertexListIndex = 0; _vertexListIndex < _auxiliaryGraph.getVertexList().size(); ++_vertexListIndex)
            {
                if (_firstGraph.vertexExist(_auxiliaryGraph.getVertexList()[_vertexListIndex]) == -1)
                {
                    _auxiliaryGraph.deleteVertex(_auxiliaryGraph.getVertexList()[_vertexListIndex]);
                }
            }
            for (int _rawAdjIndex = 0; _rawAdjIndex < _auxiliaryGraph.getVertexNumber(); ++_rawAdjIndex)
            {
                for (int _columnAdjIndex = 0; _columnAdjIndex < _auxiliaryGraph.getVertexNumber(); ++_columnAdjIndex)
                {
                    if (_firstGraph._adjacencyMatrix[_rawAdjIndex][_columnAdjIndex] != 0) // when arc in subgraph exists
                        if (_firstGraph._adjacencyMatrix[_rawAdjIndex][_columnAdjIndex] != _auxiliaryGraph.getAdjMatrix()[_rawAdjIndex][_columnAdjIndex])
                            return false;
                }
            }
            return true;
        }
        /**
         * @brief  > operator
         * @param accepts two graphes
         * @return true/false
         */
        friend bool operator>(const OrientedGraph _firstGraph, const OrientedGraph _secondGraph)
        {
            return _secondGraph < _firstGraph;
        }
        /**
         * @brief  >= method
         * @param accepts another graph
         * @return true/false
         */
        bool operator>=(const OrientedGraph &_graph)
        {
            return *this > _graph || *this == _graph;
        }
        /**
         * @brief  <= method
         * @param accepts another graph
         * @return true/false
         */
        bool operator<=(const OrientedGraph &_graph)
        {
            return *this == _graph || *this < _graph;
        }
        /**
         * @brief Oriented Graph constructor
         * @param accepts graph
         * @return
         */
        OrientedGraph(OrientedGraph *_exampleGraph) : _vertexList(_exampleGraph->_vertexList), _adjacencyMatrix(_exampleGraph->_adjacencyMatrix)
        {
        }
        /**
         * @brief  Container default destructor
         * @param accepts no arguments
         * @return nothing
         */
        ~OrientedGraph() = default;
        /**
         * @brief  empty method
         * @param
         * @return true / false
         */
        bool empty()
        {
            return _vertexList.size() == 0;
        }
        /**
         * @brief  clear method
         * @param
         * @return
         */
        void clear()
        {
            _vertexList.clear();
            _adjacencyMatrix.clear();
        }
        /**
         * @brief  vertex exist method
         * @param accepts vertex
         * @return true/false
         */
        int vertexExist(const_reference _vertex) const
        {
            for (unsigned int _vertexIndex = 0; _vertexIndex < _vertexList.size(); ++_vertexIndex)
            {
                if (this->_vertexList[_vertexIndex] == _vertex)
                    return _vertexIndex;
            }
            return -1;
        }
        /**
         * @brief  arc exist between two vertices method
         * @param accepts two vertices
         * @return true/false
         */
        bool arcExistBetweenVertices(const_reference _startVertex, const_reference _endVertex)
        {
            if (vertexExist(_startVertex) == -1 || vertexExist(_endVertex) == -1)
                throw "Input vertex doesn't exist!";
            return _adjacencyMatrix[vertexExist(_startVertex)][vertexExist(_endVertex)] > 0;
        }
        /**
         * @brief  get vertex number method
         * @param
         * @return vertex number
         */
        unsigned int getVertexNumber() const
        {
            return _vertexList.size();
        }
        /**
         * @brief  get arc number method
         * @param
         * @return arc number
         */
        unsigned int getArcNumber() const
        {
            unsigned int _resultNumber = 0;
            for (std::vector<unsigned short> _adjRow : _adjacencyMatrix)
            {
                for (unsigned short _adjElem : _adjRow)
                {
                    _resultNumber = _adjElem > 0 ? _resultNumber + 1 : _resultNumber;
                }
            }
            return _resultNumber;
        }
        /**
         * @brief  get power method
         * @param accepts vertex
         * @return vertex power
         */
        unsigned int getPower(const_reference _vertex)
        {
            if (vertexExist(_vertex) == -1)
                throw "Input vertex doesn't exist!";
            unsigned short _resPower = 0;
            for (unsigned short _vertexRowElem : _adjacencyMatrix[vertexExist(_vertex)])
            {
                _resPower = _vertexRowElem > 0 ? _resPower + 1 : _resPower;
            }
            return _resPower;
        }
        /**
         * @brief  get power method
         * @param accepts two vertices
         * @return arc power
         */
        unsigned int getPower(const_reference _startVertex, const_reference _endVertex)
        {
            if (!arcExistBetweenVertices(_startVertex, _endVertex))
                throw "Arc doesn't exist!";
            return _adjacencyMatrix[vertexExist(_startVertex)][vertexExist(_endVertex)];
        }
        /**
         * @brief  add new vertex method
         * @param accepts vertex
         * @return nothing
         */
        void addNewVertex(const_reference _newVertex)
        {
            if (vertexExist(_newVertex) != -1)
                throw "Input vertex already exist!";
            _vertexList.push_back(_newVertex);
            _adjacencyMatrix.push_back(std::vector<unsigned short>(getVertexNumber() - 1, 0));
            for (int _index = 0; _index < getVertexNumber(); _index++)
            {
                _adjacencyMatrix[_index].push_back(0);
            }
        }
        /**
         * @brief  add new arc method
         * @param accepts two vertices
         * @return nothing
         */
        void addNewArc(const_reference _startVertex, const_reference _endVertex, unsigned short power)
        {
            if (arcExistBetweenVertices(_startVertex, _endVertex) || power <= 0)
                throw "Uncorrect input!";
            _adjacencyMatrix[vertexExist(_startVertex)][vertexExist(_endVertex)] = power;
        }
        /**
         * @brief  delete vertex method
         * @param accepts  vertex
         * @return nothing
         */
        void deleteVertex(const_reference _vertex)
        {
            if (vertexExist(_vertex) == -1)
                throw "Input vertex doesn't exist.";
            _adjacencyMatrix.erase(_adjacencyMatrix.begin() + vertexExist(_vertex)); // delete accordance row into matrix
            for (unsigned int _rawIndex = 0; _rawIndex < _adjacencyMatrix.size(); ++_rawIndex)
            {
                _adjacencyMatrix[_rawIndex].erase(_adjacencyMatrix[_rawIndex].begin() + vertexExist(_vertex));
            }
            _vertexList.erase(_vertexList.begin() + vertexExist(_vertex));
        }
        /**
         * @brief  delete vertex iterator
         * @param accepts iterator on vertex
         * @return no
         */
        void deleteVertex(VertexIterator _iterOnVertex)
        {
            deleteVertex(*_iterOnVertex);
        }
        /**
         * @brief delete Arc method
         * @param acccepts vertices
         * @return nothing
         */
        void deleteArc(const_reference _startVertex, const_reference _endVertex)
        {
            if (!arcExistBetweenVertices(_startVertex, _endVertex))
                throw "Arc does not exist!";
            _adjacencyMatrix[vertexExist(_startVertex)][vertexExist(_endVertex)] = 0;
        }
        /**
         * @brief  delete Arc method
         * @param accepts iterator on arc
         * @return no
         */
        void deleteArc(ArcIterator _iter)
        {
            ArcType _arc = *_iter;
            if (!arcExistBetweenVertices(_arc.first, _arc.second))
                throw "Arc doesn't exist!";
            _adjacencyMatrix[vertexExist(_arc.first)][vertexExist(_arc.second)] = 0;
        }

        /**
         * @brief  << operator
         * @param accepts out stream and arc
         * @return out stream
         */
    };

    template <typename T>
    std::ostream &operator<<(std::ostream &out, OrientedGraph<T> _graph)
    {
        out << "Vertices:\n";
        std::for_each(_graph.vBegin(), _graph.vEnd(), [&](T name)
                      { out << name << ' '; });
        return out << std::endl;
    }
}

#endif
