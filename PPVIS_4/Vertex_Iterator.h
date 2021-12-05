#ifndef VERTEX_ITERATOR_INCLUDED
#define VERTEX_ITERATOR_INCLUDED
#include "traits.h"
#include <iterator>
#include <vector>

namespace oriented_graph
{

    // Iterator for vertices
    template <typename T, typename traits = elem_traits<T>>

    /*!
        \brief class which realize vertex iterator
    */
    class _VertexIterator 
    {
    public:
        typedef typename traits::value_type value_type;
        typedef typename traits::const_reference const_reference;
        typedef typename traits::reference reference;
        typedef typename traits::const_value const_value;
        typedef typename traits::pointer pointer;

    protected:
        pointer _elemPosition;

        std::vector<value_type> _vertexList;

    public:
        _VertexIterator() = default;
        /**
         * @brief  empty constructor
         * @param accepts no arguments
         * @return no
         */

        _VertexIterator(pointer _elemPositionIn) : _elemPosition(_elemPositionIn)
        {
        }

        _VertexIterator(const pointer &_elemPositionIn, std::vector<value_type> &&_vertexListIn)
            : _elemPosition(_elemPositionIn),
              _vertexList(std::forward<std::vector<value_type>>(_vertexListIn))
        {
        }

        /**
         * @brief  vertex iterator constructor
         * @param accepts vertex pointer
         * @return
         */
        _VertexIterator(const _VertexIterator &_iter) : _vertexList(_iter._vertexList), _elemPosition(_iter._elemPosition)
        {
        }
        /**
         * @brief  Copy constructor
         * @param accepts another iterator with the same type
         * @return
         */
        bool operator==(const _VertexIterator &_iter) const
        {
            return *_elemPosition == *_iter._elemPosition && _vertexList == _iter._vertexList;
        }
        /**
         * @brief  operator !=
         * @param accepts second iterator
         * @return true/false
         */
        bool operator!=(const _VertexIterator &_iter) const
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
        _VertexIterator &operator=(const _VertexIterator &_iter)
        {
            this->_elemPosition = _iter._elemPosition;
            this->_vertexList = _iter._vertexList;
            return *this;
        }
        /**
         * @brief  increment operator
         * @param accepts no
         * @return this reference
         */
        _VertexIterator &operator++()
        {
            ++(_elemPosition);
            return *this;
        }

        _VertexIterator operator++(int)
        {
            _VertexIterator _tmpIter(*this);
            operator++();
            return _tmpIter;
        }
        /**
         * @brief  decrement operator
         * @param accepts no
         * @return this reference
         */
        _VertexIterator &operator--()
        {
            --_elemPosition;
            return *this;
        }

        _VertexIterator operator--(int)
        {
            _VertexIterator _tmpIter(*this);
            operator--();
            return _tmpIter;
        }
    };
}
#endif