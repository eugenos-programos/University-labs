#ifndef CONST_VERTEX_ITERATOR_INCLUDED
#define CONST_VERTEX_ITERATOR_INCLUDED
#include "Vertex_Iterator.h"
#include "traits.h"

namespace oriented_graph
{
    template <typename T>

    /*!
        \brief class which realize constant vertex iterator
    */
    class _ConstVertexIterator : public _VertexIterator<T>
    {
    public:
        using typename _VertexIterator<T>::pointer;
        using typename _VertexIterator<T>::reference;
        using typename _VertexIterator<T>::value_type;
        using typename _VertexIterator<T>::const_value;

        _ConstVertexIterator() = default;

        _ConstVertexIterator(pointer _elemPositionIn)
        {
            this->_elemPosition = _elemPositionIn;
        }

        _ConstVertexIterator(const pointer &_elemPositionIn, std::vector<value_type> &&_vertexListIn)
        {
            this->_elemPosition = _elemPositionIn;
            this->_vertexList = std::forward<std::vector<value_type>>(_vertexListIn);
        }

        _ConstVertexIterator(const _ConstVertexIterator &_iter)
        {
            this->_elemPosition = _iter._elemPosition;
            this->_vertexList = _iter._vertexList;
        }

        const_value operator*()
        {
            return *this->_elemPosition;
        }

        _ConstVertexIterator &operator++()
        {
            ++(this->_elemPosition);
            return *this;
        }

        _ConstVertexIterator &operator++(int)
        {
            _ConstVertexIterator _tmpIter(*this);
            operator++();
            return _tmpIter;
        }

        _ConstVertexIterator &operator--()
        {
            --(this->_elemPosition);
            return *this;
        }

        _ConstVertexIterator operator--(int)
        {
            _ConstVertexIterator _tmpIter(*this);
            operator--();
            return _tmpIter;
        }
    };
}
#endif
