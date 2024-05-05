#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H
#include <stdexcept>
#include <cstring>

class NotFoundException : public std::exception
{
private:
    char *_msg;

public:
    NotFoundException() = delete;
    NotFoundException(const NotFoundException &) = delete;
    NotFoundException &operator=(const NotFoundException &) = delete;
    NotFoundException(NotFoundException &&) = delete;
    NotFoundException &operator=(NotFoundException &&) = delete;
    ~NotFoundException(){
        delete _msg;
    }

    NotFoundException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }
};

#endif // NOTFOUNDEXCEPTION_H
