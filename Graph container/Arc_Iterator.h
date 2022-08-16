#ifndef ARC_ITERATOR_INCLUDED
#define ARC_ITERATOR_INCLUDED
#include <iterator>
#include <vector>
#include "traits.h"

namespace oriented_graph
{
    template <typename T, typename traits = elem_traits<std::pair<T, T>>>

    /*!
        \brief class that implements arc iterator
    */
    class _ArcIterator
    {
    public:
        typedef typename traits::value_type value_type;
        typedef typename traits::const_reference const_reference;
        typedef typename traits::const_value const_value;
        typedef typename traits::pointer pointer;
        typedef typename traits::reference reference;

    protected:
        pointer _arc;

        std::vector<value_type> _arcList;

    public:
        _ArcIterator() = default;
        /**
         * @brief  Arc Iterator constructor
         * @param accepts arc
         * @return
         */
        _ArcIterator(pointer _arc)
        {
            this->_arc = _arc;
        }
        /**
         * @brief _ArcIterator constructor
         * @param accepts arc pointer and arc list
         * @return nothing
         */
        _ArcIterator(const pointer &_arc, std::vector<value_type> &&_arcList)
        {
            this->_arc = _arc;
            this->_arcList = std::forward<std::vector<value_type>>(_arcList);
        }

        _ArcIterator(const _ArcIterator &_iter)
        {
            this->_arc = _iter._arc;
            this->_arcList = _iter._arcList;
        }
        /**
         * @brief  == operator
         * @param accepts another iterator
         * @return true/false
         */
        bool operator==(const _ArcIterator &_iter) const
        {
            return *_arc == *_iter._arc;
        }
        /**
         * @brief  != operator
         * @param accepts another iterator
         * @return true/false
         */
        bool operator!=(const _ArcIterator &_iter) const
        {
            return !(*this == _iter);
        }
        /**
         * @brief  dereference operator
         * @param accepts no
         * @return arc
         */
        reference operator*()
        {
            return *_arc;
        }
        /**
         * @brief  = opeerator
         * @param accepts another iterator
         * @return this reference
         */
        _ArcIterator &operator=(const _ArcIterator &_iter)
        {
            this->_arc = _iter._arc;
            return *this;
        }
        /**
         * @brief  increment operator
         * @param accepts no
         * @return this reference
         */
        _ArcIterator &operator++()
        {
            ++_arc;
            return *this;
        }
        _ArcIterator operator++(int)
        {
            _ArcIterator _tmpIter(*this);
            operator++();
            return _tmpIter;
        }
        /**
         * @brief  dicrement operator
         * @param accepts no
         * @return this reference
         */
        _ArcIterator &operator--()
        {
            --_arc;
            return *this;
        }

        _ArcIterator operator--(int)
        {
            _ArcIterator _tmpIter(*this);
            operator--();
            return _tmpIter;
        }
    };
}
#endif
