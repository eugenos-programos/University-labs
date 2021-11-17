#ifndef TRAITS_H
#define TRAITS_H
namespace oriented_graph
{
    template <typename T>

    /*!
        \brief traits class
    */
    class elem_traits
    {
    public:
        typedef const T &const_reference;
        typedef T &reference;
        typedef const T const_value;
        typedef T *pointer;
    };
}
#endif //