#ifndef REVERSE_ARC_ITERATOR
#define REVERSE_ARC_ITERATOR
#include "Arc_Iterator.h"
#include <vector>
namespace oriented_graph
{
    template <typename T>

    /*!
        \brief class that implements reverse arc iterator
    */
    class _ReverseArcIterator : public _ArcIterator<T>
    {
    public:
        using typename _ArcIterator<T>::pointer;
        using typename _ArcIterator<T>::reference;
        using typename _ArcIterator<T>::value_type;
        using typename _ArcIterator<T>::const_value;

        _ReverseArcIterator() = default;

        _ReverseArcIterator(const _ReverseArcIterator &_iter)
        {
            this->_arc = _iter._arc;
        }

        _ReverseArcIterator(const pointer &_arc)
        {
            this->_arc = _arc;
        }

        _ReverseArcIterator(const pointer &_arc, std::vector<value_type> &&_arcList)
        {
            this->_arc = _arc;
            this->_arcList = std::forward<std::vector<value_type>>(_arcList);
        }

        _ReverseArcIterator &operator++()
        {
            --this->_arc;
            return *this;
        }

        _ReverseArcIterator &operator++(int)
        {
            _ReverseArcIterator _tmpIter(*this);
            operator--();
            return _tmpIter;
        }

        _ReverseArcIterator &operator--()
        {
            ++this->_arc;
            return *this;
        }

        _ReverseArcIterator &operator--(int)
        {
            _ReverseArcIterator _tmpIter(*this);
            operator++();
            return _tmpIter;
        }
    };
}
#endif // __REVERSE_ARC_
