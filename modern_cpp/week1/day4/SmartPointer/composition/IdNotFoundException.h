#ifndef IdNotFoundException_H
#define IdNotFoundException_H

#include<stdexcept>
#include<cstring>

class IdNotFoundException : public std::exception
{
private:
    /* data */
    char* _msg;
public:
    /*  */
    IdNotFoundException() = delete;
    IdNotFoundException(const IdNotFoundException&) = delete;
    IdNotFoundException(IdNotFoundException&&) = default;
    IdNotFoundException& operator=(const IdNotFoundException&) = delete;
    IdNotFoundException&& operator=(IdNotFoundException&&) = delete;

    IdNotFoundException(const char* msg) {
        // strlen();
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    ~IdNotFoundException() {
        delete _msg;
    }

    //overriding what function
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return _msg;
    }
};

#endif // IdNotFoundException_H

ex