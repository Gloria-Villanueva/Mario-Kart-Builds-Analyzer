#ifndef MK8EXCEPTION_H
#define MK8EXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class MK8Exception : public exception {
private:
    string message;
public:
    MK8Exception(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
