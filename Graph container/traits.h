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
        typedef T value_type;
        typedef const value_type &const_reference;
        typedef value_type &reference;
        typedef const value_type const_value;
        typedef value_type *pointer;
    };
}
#endif //