#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <cstdlib>

class my_string;
my_string operator +(const char *str_left, const my_string &obj);

class my_string
{
public:
    my_string(const char *str = "");
    my_string(const char *str, size_t n);
    my_string(size_t n, char c);

    my_string(const my_string &obj);
    const my_string &operator=(const my_string &obj);

    ~my_string();

    my_string& append(const my_string& obj);
    my_string& append(const char *s);
    my_string& append(const char *s, size_t n);

    friend std::ostream &operator<<(std::ostream &stream, const my_string &obj);

    bool operator!=(const my_string &obj);

    my_string operator+(const my_string &obj) const;
    my_string operator+(const char* str_right) const;
    friend my_string operator+(const char* str_left, const my_string &obj);

    my_string &operator+=(const my_string& str);
    my_string &operator+=(const char *s);

    size_t lenght() const;
    const char *c_str() const;
    my_string substr(size_t pos = 0, size_t n = 0) const;

    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;

    size_t find(const my_string& str, size_t pos = 0) const;
    size_t find(const char *s, size_t pos, size_t n) const;
    size_t find(const char *s, size_t pos = 0) const;

private:
    size_t len;
    char *str;
};

#endif // MY_STRING_H
