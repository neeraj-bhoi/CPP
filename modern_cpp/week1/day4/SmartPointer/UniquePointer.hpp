#ifndef UNIQUEPOINTER_HPP
#define UNIQUEPOINTER_HPP

template <typename T>
class UniquePointer
{
private:
    T * _mptr;

public:
    UniquePointer(T* ptr): _mptr{ptr} {
        ptr = null; // after copying pointer to _mptr -> set ptr = null
                    // user ab access ni kr payega ptr se
    }

    // copy constructor not allowed for unique pointers
    UniquePointer(const T*) = delete;
    UniquePointer& operator= (const T*) = delete;

    //move pointers are allowed
    UniquePointer(T* &&) = default;
    UniquePointer& operator= (const T* &&) = default;

    void release() { delete _mptr; _mptr = nullptr; }
    ~UniquePointer() { delete _mptr; _mptr = nullptr; }
};


#endif // UNIQUEPOINTER_HPP

/*
    RAII principle
    release aquisition in initialisation

    SBRM principle
    scope based resource management
*/