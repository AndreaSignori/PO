#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <string>
#include <exception>

using std::string;

/* classe myException
 * genera eccezzioni e blocca il programma mostrando un messaggio
 */
class MyException : public std::exception {
    const string msg;
public:
    MyException(string msg);
    const char* what() const noexcept;
};

#endif // MYEXCEPTION_H
