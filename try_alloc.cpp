 #include "try_alloc.h"

template<typename T>
T *try_alloc<T>::allocate(std::size_t n)
{
    auto p = std::malloc(n * sizeof(T));
    if (!p)
        throw std::bad_alloc();
    return static_cast<pointer>(p);
}

template<typename T>
void try_alloc<T>::deallocate(T *p, std::size_t n)
{
    std::free(p);
}

template<typename T>
void try_alloc<T>::destroy(T *p)
{
    p->~T();
}

//template<typename U, typename Args>
//void construct(U *p, Args &&args)
//{
//    new(p) U(std::forward<Args>(args)...);
//}
