#ifndef ORIENTED_GRAPH_INCLUDED
#define ORIENTED_GRAPH_INCLUDED

#include <vector>
#include <ostream>
#include <iterator>
#include <algorithm>

using namespace std;

namespace oriented_graph
{

    template <typename Type>

    class OrientedGraph
    {
        typedef Type value_type;
        typedef value_type *pointer;
        typedef value_type &reference;
        typedef const pointer const_pointer;

        typedef std::pair<value_type, value_type> ArcType; // typedefes for normal arc iterator
        typedef std::pair<value_type, value_type> &ReferenceArcType;
        typedef ArcType *ArcPointer; // arc pointer will be stored in arciter
        typedef ArcType &ArcReference;

    private:
        std::vector<std::vector<unsigned short>> _adjacencyMatrix; // unsigned short ~ [0..65 535]

        std::vector<value_type> _vertexList; // here also defined list with vertices values because adjacency matrix values and vertex values are not the same

        std::vector<ArcType> _arcList; // arcs for ArcIterator

        std::vector<value_type> _adjVertexList; // adjacency vertices for vertex iterator

        std::vector<ArcType> _incidenceArcList;

    public:
            /**
         * @brief  Oriented Graph constructor
         * @param accepts no parameters
         * @return nothing
         */
        OrientedGraph()
        {
            _adjacencyMatrix = std::vector<std::vector<unsigned short>>{{}};
            _vertexList = std::vector<value_type>{};
        }
         /**
         * @brief  Oriented Graph constructor
         * @param accepts adjacency Matrix and vertex list
         * @return nothing
         */
        OrientedGraph(std::vector<std::vector<unsigned short>> _adjMatrix, std::vector<Type> _vertexList)
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
        std::vector<value_type> getAdjacencyVertices(const value_type &_vertex)
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
        
        // Iterator for vertices
        class VertexIterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
        {
        protected:
            pointer _elemPosition;

        public:
            VertexIterator() = default;
                    /**
         * @brief  empty constructor
         * @param accepts 
         * @return 
         */
            VertexIterator(pointer _elemPositionIn) : _elemPosition(_elemPositionIn)
            {
            }
                    /**
         * @brief  vertex iterator constructor
         * @param accepts vertex pointer
         * @return 
         */
            VertexIterator(const VertexIterator &_iter) : _elemPosition(_iter._elemPosition)
            {
            }
                    /**
         * @brief  Copy constructor
         * @param accepts another iterator with the same type
         * @return 
         */
            bool operator==(const VertexIterator &_iter) const
            {
                return _elemPosition == _iter._elemPosition;
            }
                     /**
         * @brief  operator !=
         * @param accepts second iterator
         * @return true/false
         */
            bool operator!=(const VertexIterator &_iter) const
            {
                return !(*this == _iter);
            }
                     /**
         * @brief  dereference operator 
         * @param accepts
         * @return  reference on element
         */
            reference operator*()
            {
                return *_elemPosition;
            }
                     /**
         * @brief  operator = 
         * @param accepts second iterator
         * @return this reference
         */
            VertexIterator &operator=(const VertexIterator &_iter)
            {
                this->_elemPosition = _iter._elemPosition;
                return *this;
            }
         /**
         * @brief  increment operator
         * @param accepts no
         * @return this reference
         */
            VertexIterator &operator++()
            {
                ++(_elemPosition);
                return *this;
            }

            VertexIterator operator++(int)
            {
                VertexIterator _tmpIter(*this);
                operator++();
                return _tmpIter;
            }
         /**
         * @brief  decrement operator
         * @param accepts no
         * @return this reference
         */
            VertexIterator &operator--()
            {
                --_elemPosition;
                return *this;
            }

            VertexIterator operator--(int)
            {
                VertexIterator _tmpIter(*this);
                operator--();
                return _tmpIter;
            }
        };

        class ConstVertexIterator : public VertexIterator
        {
        public:
            ConstVertexIterator() = default;

            ConstVertexIterator(pointer _elemPositionIn)
            {
                this->_elemPosition = _elemPositionIn;
            }

            ConstVertexIterator(const ConstVertexIterator &_iter)
            {
                this->_elemPosition = _iter._elemPosition;
            }

            const value_type operator*()
            {
                return *this->_elemPosition;
            }
        };
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
        std::vector<ArcType> getAllIncidenceArcs(const value_type &_vertex)
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

        class ArcIterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
        {
        protected:
            ArcPointer _arc;

        public:
            ArcIterator() = default;
         /**
         * @brief  Arc Iterator constructor
         * @param accepts arc
         * @return 
         */
            ArcIterator(ArcPointer _arc)
            {
                this->_arc = _arc;
            }
         /**
         * @brief  Arc Iterator constructor
         * @param accepts another iterator
         * @return 
         */
            ArcIterator(const ArcIterator &_iter)
            {
                this->_arc = _iter._arc;
            }
         /**
         * @brief  == operator
         * @param accepts another iterator
         * @return true/false
         */
            bool operator==(const ArcIterator &_iter) const
            {
                return this->_arc == _iter._arc;
            }
         /**
         * @brief  != operator
         * @param accepts another iterator
         * @return true/false
         */
            bool operator!=(const ArcIterator &_iter) const
            {
                return !(*this == _iter);
            }
         /**
         * @brief  dereference operator
         * @param accepts no
         * @return arc
         */
            ReferenceArcType operator*()
            {
                return *_arc;
            }
         /**
         * @brief  = opeerator
         * @param accepts another iterator
         * @return this reference
         */
            ArcIterator &operator=(const ArcIterator &_iter)
            {
                this->_arc = _iter._arc;
                return *this;
            }
         /**
         * @brief  increment operator
         * @param accepts no
         * @return this reference
         */
            ArcIterator &operator++()
            {
                ++_arc;
                return *this;
            }
            ArcIterator operator++(int)
            {
                ArcIterator _tmpIter(*this);
                operator++();
                return _tmpIter;
            }
         /**
         * @brief  dicrement operator
         * @param accepts no
         * @return this reference
         */
            ArcIterator &operator--()
            {
                --_arc;
                return *this;
            }
            ArcIterator operator--(int)
            {
                ArcIterator _tmpIter(*this);
                operator--();
                return _tmpIter;
            }
        };

        class ConstArcIterator : public ArcIterator
        {
        public:
            ConstArcIterator() = default;

            ConstArcIterator(ArcPointer _arcIn)
            {
                this->_arc = _arcIn;
            }

            ConstArcIterator(const ConstVertexIterator &_iter)
            {
                this->_arc = _iter._arc;
            }

            const ArcType operator*()
            {
                return *(this->_arc);
            }
        };

        class ReverseVertexIterator : public VertexIterator
        {
        public:
            ReverseVertexIterator() = default;

            ReverseVertexIterator(const pointer &_vertex)
            {
                this->_elemPosition = _vertex;
            }

            ReverseVertexIterator(const ReverseVertexIterator &_iter)
            {
                this->_elemPosition = _iter._elemPosition;
            }

            ReverseVertexIterator &operator++()
            {
                --this->_elemPosition;
                return *this;
            }

            ReverseVertexIterator &operator++(int)
            {
                ReverseVertexIterator _tmpIter(*this);
                operator--();
                return _tmpIter;
            }

            ReverseVertexIterator &operator--()
            {
                ++this->_elemPosition;
                return *this;
            }

            ReverseVertexIterator &operator--(int)
            {
                ReverseVertexIterator _tmpIter(*this);
                operator++();
                return _tmpIter;
            }
        };

        class ReverseArcIterator : public ArcIterator
        {
        public:
            ReverseArcIterator() = default;

            ReverseArcIterator(const ReverseArcIterator &_iter)
            {
                this->_arc = _iter._arc;
            }

            ReverseArcIterator(const ArcPointer &_arc)
            {
                this->_arc = _arc;
            }

            ReverseArcIterator &operator++()
            {
                --this->_arc;
                return *this;
            }

            ReverseArcIterator &operator++(int)
            {
                ReverseArcIterator _tmpIter(*this);
                operator--();
                return _tmpIter;
            }

            ReverseArcIterator &operator--()
            {
                ++this->_arc;
                return *this;
            }

            ReverseArcIterator &operator--(int)
            {
                ReverseArcIterator _tmpIter(*this);
                operator++();
                return _tmpIter;
            }
        };
         /**
         * @brief  vBegin method
         * @param accepts no arguments
         * @return iterator on the begin vertex list
         */
        VertexIterator vBegin()
        {
            if (_vertexList.empty())
                throw "Empty vertex list!";
            return *(new VertexIterator(&_vertexList[0]));
        }
         /**
         * @brief  vEnd method
         * @param accepts no arguments
         * @return iterator on the end vertex list
         */
        VertexIterator vEnd()
        {
            if (_vertexList.empty())
                throw "Empty vertex list!";
            return *(new VertexIterator(&_vertexList[getVertexNumber()]));
        }
         /**
         * @brief  cvBegin method
         * @param 
         * @return Const iterator on the begin of vertex list
         */
        ConstVertexIterator cvBegin()
        {
            if (_vertexList.empty())
                throw "Empty vertex list!";
            return *(new ConstVertexIterator(&_vertexList[0]));
        }
         /**
         * @brief  cvEnd method
         * @param 
         * @return const iterator on the end of vertex list
         */
        ConstVertexIterator cvEnd()
        {
            if (_vertexList.empty())
                throw "Empty vertex list!";
            return *(new ConstVertexIterator(&_vertexList[getVertexNumber()]));
        }
         /**
         * @brief  rvBegin method
         * @param accepts no arguments
         * @return reverse iterator on the begin of vertex list
         */
        ReverseVertexIterator rvBegin()
        {
            if (_vertexList.empty())
                throw "Empty vertex list!";
            return *(new ReverseVertexIterator(&_vertexList[getVertexNumber() - 1]));
        }
         /**
         * @brief  rvEnd method
         * @param accepts no arguments
         * @return reverse iterator on the end of vertex list
         */
        ReverseVertexIterator rvEnd()
        {
            if (_vertexList.empty())
                throw "Empty vertex list!";
            return *(new ReverseVertexIterator(&_vertexList[-1]));
        }
         /**
         * @brief  avBegin method
         * @param accepts vertex
         * @return Iterator on the begin of adj. vertices list
         */
        VertexIterator avBegin(const value_type &_vertex)
        {
            _adjVertexList = getAdjacencyVertices(_vertex);
            if (_adjVertexList.empty())
                throw "Empty adjacency vertex list";
            return *(new VertexIterator(&_adjVertexList[0]));
        }
         /**
         * @brief  avEnd method
         * @param accepts
         * @return Iterator on the end of adj. vertices list
         */
        VertexIterator avEnd()
        {
            return *(new VertexIterator(&_adjVertexList[_adjVertexList.size()]));
        }
         /**
         * @brief  cavBegin method
         * @param accepts vertex
         * @return Const iterator on the begin of adj, vertices list
         */
        ConstVertexIterator cavBegin(const value_type &_vertex)
        {
            _adjVertexList = getAdjacencyVertices(_vertex);
            if (_adjVertexList.empty())
                throw "Empty vertex list";
            return *new ConstVertexIterator(&_adjVertexList[0]);
        }
         /**
         * @brief  cavEnd method
         * @param 
         * @return const iterator on the end of vertex list
         */
        ConstVertexIterator cavEnd()
        {
            return *new ConstVertexIterator(&_adjVertexList[_adjVertexList.size()]);
        }
                 /**
         * @brief  ravBegin method
         * @param accepts vertex
         * @return reverse iterator on the begin of vertex list
         */
        ReverseVertexIterator ravBegin(const value_type &_vertex)
        {
            _adjVertexList = getAdjacencyVertices(_vertex);
            if (_adjVertexList.empty())
                throw "Empty adjacency vertex list";
            return *(new ReverseVertexIterator(&_adjVertexList[_adjVertexList.size() - 1]));
        }
                 /**
         * @brief  ravEnd method
         * @param accepts vertex
         * @return reverse iterator on the end of the adjacency vertex list
         */
        ReverseVertexIterator ravEnd(const value_type &_vertex)
        {
            if (_adjVertexList.empty())
                throw "Empty adjacency vertex";
            return *(new ReverseVertexIterator(&_adjVertexList[-1]));
        }
                 /**
         * @brief  aBegin method
         * @param 
         * @return arc iterator on the begin of arc list
         */
        ArcIterator aBegin()
        {
            _arcList = getAllArcs();
            if (_arcList.empty())
                throw "Empty list";
            return *new ArcIterator(&_arcList[0]);
        }
         /**
         * @brief  aEnd method
         * @param accepts no arguments
         * @return iterator on end of arc list
         */
        ArcIterator aEnd()
        {
            _arcList = getAllArcs();
            if(_arcList.empty()) throw "Empty list";
            return *new ArcIterator(&_arcList[getArcNumber()]);
        }
         /**
         * @brief  raBegin method
         * @param accepts no arguments
         * @return reverse iterator on the reverse end of the arc list
         */
        ReverseArcIterator raBegin()
        {
            _arcList = getAllArcs();
            if (_arcList.empty())
                throw "Empty list";
            return *new ReverseArcIterator(&_arcList[getArcNumber() - 1]);
        }   
         /**
         * @brief  raEnd method
         * @param accepts no arguments
         * @return reverse iterator on the reverse begin of the arc list
         */
        ReverseArcIterator raEnd()
        {
            _arcList = getAllArcs();
            if (_arcList.empty())
                throw "Empty list";
            return *new ReverseArcIterator(&_arcList[-1]);
        }
         /**
         * @brief  caBegin method 
         * @param accepts no arguments
         * @return constant iterator on the begin of the arc list
         */
        ConstArcIterator caBegin()
        {
            _arcList = getAllArcs();
            if (_arcList.empty())
                throw "Empty list";
            return *new ConstArcIterator(&_arcList[0]);
        }
         /**
         * @brief  caEnd method
         * @param accepts no arguments
         * @return constant iterator on the end of the arc list
         */
        ConstArcIterator caEnd()
        {
            _arcList = getAllArcs();
            if (_arcList.empty())
                throw "Empty list";
            return *new ConstArcIterator(&_arcList[getArcNumber()]);
        }
         /**
         * @brief  aiBegin method
         * @param accepts vertex
         * @return arc iterator on the begin of incidence arc list
         */
        ArcIterator aiBegin(const value_type &_vertex)
        {
            _incidenceArcList = getAllIncidenceArcs(_vertex);
            if (_incidenceArcList.empty())
                throw "No incidence arcs";
            return *new ArcIterator(&_incidenceArcList[0]);
        }
         /**
         * @brief  aiEnd method
         * @param accepts no arguments
         * @return arc iterator on the end of incidence arc list
         */
        ArcIterator aiEnd()
        {
            return *new ArcIterator(&_incidenceArcList[_incidenceArcList.size()]);
        }
         /**
         * @brief  raiBegin method
         * @param accepts vertex
         * @return reverse arc iterator on the reverse begin of incidence arc list
         */
        ReverseArcIterator raiBegin(const value_type &_vertex)
        {
            _incidenceArcList = getAllIncidenceArcs(_vertex);
            if (_incidenceArcList.empty())
                throw "No incidence arcs";
            return *new ReverseArcIterator(&_incidenceArcList[_incidenceArcList.size() - 1]);
        }
         /**
         * @brief  raiEnd method
         * @param accepts no arguments
         * @return reverse arc iterator on the reverse end of the arc list
         */
        ReverseArcIterator raiEnd()
        {
            return *new ReverseArcIterator(&_incidenceArcList[-1]);
        }
         /**
         * @brief  cai Begin method
         * @param accepts vertex
         * @return const arc iterator on the begin of the incidence arc list
         */
        ConstArcIterator caiBegin(const value_type &_vertex)
        {
            _incidenceArcList = getAllIncidenceArcs(_vertex);
            if (_incidenceArcList.empty())
                throw "No incidence arcs";
            return *new ConstArcIterator(&_incidenceArcList[0]);
        }
         /**
         * @brief  cai End method
         * @param accepts no arguments
         * @return const iterator on the end of the incidence arc list
         */
        ConstArcIterator caiEnd()
        {
            return *new ConstArcIterator(&_incidenceArcList[_incidenceArcList.size()]);
        }

         /**
         * @brief  operator = 
         * @param accepts another graph
         * @return this reference
         */

        OrientedGraph &operator=(const OrientedGraph<Type> &_graph)
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
            return this->_adjacencyMatrix == _graph.getAdjMatrix() && this->_vertexList == _graph.getVertexList();
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
            return *this < _graph || *this == _graph;
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
         * @brief  Container destructor
         * @param 
         * @return 
         */
        ~OrientedGraph()
        {
            _adjacencyMatrix.clear();
            _vertexList.clear();
        }
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
        int vertexExist(const value_type &_vertex) const
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
        bool arcExistBetweenVertices(const value_type &_startVertex, const value_type &_endVertex)
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
        unsigned int getPower(const value_type &_vertex)
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
        unsigned int getPower(const value_type &_startVertex, const value_type &_endVertex)
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
        void addNewVertex(const value_type &_newVertex)
        {
            if (vertexExist(_newVertex) != -1)
                throw "Input vertex already exist!";
            _vertexList.push_back(_newVertex);
            _adjacencyMatrix.push_back(std::vector<unsigned short>(getVertexNumber(), 0));
            for (std::vector<unsigned short> _adjRow : _adjacencyMatrix)
            {
                _adjRow.resize(_adjRow.size() + 1);
            }
        }
         /**
         * @brief  add new arc method
         * @param accepts two vertices
         * @return nothing
         */
        void addNewArc(const value_type &_startVertex, const value_type &_endVertex, unsigned short power)
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
        void deleteVertex(const value_type &_vertex)
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
        void deleteArc(const value_type &_startVertex, const value_type &_endVertex)
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
        friend std::ostream &operator<<(std::ostream &out, ArcType _arc)
        {
            out << _arc.first << ' ' << _arc.second << '\n';
            return out;
        }

        /*friend std::ostream &operator<<(std::ostream &out, OrientedGraph _graph)
        {
            out << "Vertices:\n";
            std::for_each(_graph.vBegin(), _graph.vEnd(), _graph.printVertex());
            return out;
        }*/
    };

}

#endif
