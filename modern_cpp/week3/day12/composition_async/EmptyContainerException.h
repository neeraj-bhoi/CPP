#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include<stdexcept>
#include<cstring>
#include<future>

/*
    input through promise

    no promise attached with future

*/

class EmptyContainerException : public std::future_error
{
private:
    /* data */
    char* _msg;
public:
    /*  */
    EmptyContainerException() = delete;
    EmptyContainerException(const EmptyContainerException&) = delete;
    EmptyContainerException(EmptyContainerException&&) = default;
    EmptyContainerException& operator=(const EmptyContainerException&) = delete;
    EmptyContainerException&& operator=(EmptyContainerException&&) = delete;

    EmptyContainerException(const char* msg, std::future_errc ec) 
        :std::future_error(ec)
    {
        // strlen();
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    ~EmptyContainerException() {
        delete _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return _msg;
    }
};

#endif // EMPTYCONTAINEREXCEPTION_H


/*
    there are 4 error codes..
*/
