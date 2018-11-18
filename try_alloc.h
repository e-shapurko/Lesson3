#ifndef TRY_ALLOC_H
#define TRY_ALLOC_H

#include <iostream>

template<typename T>
class try_alloc
{
    using value_type = T;

    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    template<typename U>
    struct rebind {
        using other = try_alloc<U>;
    };

    T *allocate(std::size_t n);

    void deallocate(T *p, std::size_t n);

    template<typename U, typename ...Args>
    void construct(U *p, Args &&...args)
    {
        new(p) U(std::forward<Args>(args)...);
    }

    void destroy(T *p);
};

#endif // TRY_ALLOC_H
