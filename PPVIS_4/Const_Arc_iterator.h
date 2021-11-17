#ifndef CONST_ARC_ITERATOR_INCLUDED
#define CONST_ARC_ITERATOR_INCLUDED
#include "Arc_Iterator.h"
#include "traits.h"
#include <vector>

namespace oriented_graph
{
    template <typename T>

    /*!
        \brief class, which implements const arc iterator
    */
    class _ConstArcIterator : public _ArcIterator<T>
    {
    public:
        using typename _ArcIterator<T>::pointer;
        using typename _ArcIterator<T>::reference;
        using typename _ArcIterator<T>::value_type;
        using typename _ArcIterator<T>::const_value;

        _ConstArcIterator() = default;

        _ConstArcIterator(pointer _arcIn)
        {
            this->_arc = _arcIn;
        }

        _ConstArcIterator(const _ConstArcIterator &_iter)
        {
            this->_arc = _iter._arc;
        }

        _ConstArcIterator(const pointer &_arc, std::vector<value_type> &&_arcList)
        {
            this->_arc = _arc;
            this->_arcList = std::forward<std::vector<value_type>>(_arcList);
        }

        const_value operator*()
        {
            return *(this->_arc);
        }
    };
}
#endif //
