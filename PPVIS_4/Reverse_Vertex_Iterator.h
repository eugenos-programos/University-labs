#ifndef REVERSE_VERTEX_ITERATOR
#define REVERSE_VERTEX_ITERATOR
#include "Vertex_Iterator.h"
#include "traits.h"

namespace oriented_graph
{
    /*!
        \brief Class,which realize reverse vertex iterator modification
        \author Znenya Samchuk
        \version 1.0
        \date
    */
    template <typename T>
    class _ReverseVertexIterator : public _VertexIterator<T>
    {
    public:
        using typename _VertexIterator<T>::pointer;
        using typename _VertexIterator<T>::value_type;

        _ReverseVertexIterator() = default;

        _ReverseVertexIterator(const pointer &_vertex)
        {
            this->_elemPosition = _vertex;
        }

        _ReverseVertexIterator(const pointer &_vertex, std::vector<value_type> &&_vertexList)
        {
            this->_elemPosition = _vertex;
            this->_vertexList = std::forward<std::vector<value_type>>(_vertexList);
        }

        _ReverseVertexIterator(const _ReverseVertexIterator &_iter)
        {
            this->_elemPosition = _iter._elemPosition;
            this->_vertexList = _iter._vertexList;
        }

        _ReverseVertexIterator &operator++()
        {
            --this->_elemPosition;
            return *this;
        }

        _ReverseVertexIterator &operator++(int)
        {
            _ReverseVertexIterator _tmpIter(*this);
            operator--();
            return _tmpIter;
        }

        _ReverseVertexIterator &operator--()
        {
            ++this->_elemPosition;
            return *this;
        }

        _ReverseVertexIterator &operator--(int)
        {
            _ReverseVertexIterator _tmpIter(*this);
            operator++();
            return _tmpIter;
        }
    };
}
#endif //
