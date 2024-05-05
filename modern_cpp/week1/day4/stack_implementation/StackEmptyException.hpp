#ifndef STACKEMPTYEXCEPTION_HPP
#define STACKEMPTYEXCEPTION_HPP

#include<stdexcept>
#include<cstring>

class StackEmptyException : public std::exception
{
private:
    /* data */
    char* _msg;

public:

    StackEmptyException() = delete;
    StackEmptyException(const StackEmptyException&) = delete;
    StackEmptyException(StackEmptyException&&) = default;
    StackEmptyException& operator=(const StackEmptyException&) = delete;
    StackEmptyException&& operator=(StackEmptyException&&) = delete;

    explicit StackEmptyException (const char* msg) {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    ~StackEmptyException () {
        delete _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
        return _msg;
    }
};

#endif // STACKEMPTYEXCEPTION_HPP


/*
    Pop
    throw StackEmptyException("Data is Empty")

    compiler will identify StackEmptyException class and
    calls the constructor of custom exception class
    |
    |
    |
    object of type custom exception
    [stored in catch table]

    [<objname>.what() will return _msg ]
*/



/*
    throw StackEmptyException("data is empty");
    |
    |
    throw<expression> // 2 parts of the statement
    |
    |
    throw Constructor call i.e. function call
    throw   [   _msg = "data is empty"    ]
        <--------NO NAME-------->
    throw rvalue of type StackEmptyException
    [catch table]
*/