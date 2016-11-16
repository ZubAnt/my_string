#include "my_string.h"
#include <string.h>

my_string::my_string(const char *str)
{
    if(str != nullptr){

        len = strlen(str);
        this->str = new char[len + 1];
        strcpy(this->str, str);
    }
    else{

        throw std::runtime_error("nullptr in my_string(const char *str)");
    }
}

my_string::my_string(const char *str, size_t n)
{
    if(str != nullptr){

        len = strlen(str);
        this->str = new char[len + 1];
        memcpy(this->str, str, n);
        this->str[n] = '\0';
    }
    else{

        throw std::runtime_error("nullptr in my_string(const char *str, size_t n)");
    }
}

my_string::my_string(size_t n, char c):
    len(n),
    str(new char[len + 1])
{
    memset(str, c, n);
    str[len] = '\0';
}

my_string::my_string(const my_string &obj)
{
    len = obj.len;
    str = new char[this->len + 1];
    strcpy(str, obj.str);
}

my_string::~my_string()
{
    delete[] str;
    len = 0;
}

my_string &my_string::append(const my_string &obj)
{
    this->append(obj.str, obj.len);

    return *this;
}

const my_string &my_string::operator=(const my_string &obj)
{
    if(*this != obj){

        this->~my_string();

        len = obj.len;
        str = new char[len + 1];
        strcpy(str, obj.str);
    }
    return *this;
}

my_string &my_string::append(const char *s)
{
    if(s == nullptr){
        throw std::runtime_error("nullptr in append(const char *s)");
    }

    return this->append(s, strlen(s));
}

my_string &my_string::append(const char *s, size_t n)
{

    if( s == nullptr){
        throw std::runtime_error("nullptr in append(const char *s, size_t n)");
    }

    size_t old_len = len;
    size_t new_len = len + n;

    char *tmp_str = new char[new_len + 1];
    memcpy(tmp_str, str, old_len);
    strcpy(tmp_str + old_len, s);

    this->~my_string();

    len = new_len;
    str = tmp_str;

    return *this;
}

bool my_string::operator!=(const my_string &obj)
{
    if(this == &obj){

        return false;
    }

    if(len == obj.len){
        for(size_t i = 0; i < len; ++i){
            if(str[i] != obj.str[i]){
                return true;
            }
        }
        return false;
    }

    return true;
}


my_string my_string::operator+(const my_string &obj) const
{
    size_t len = this->len + obj.len;

    my_string tmp_obj(len, '\0');

    strcpy(tmp_obj.str, this->str);
    strcpy(tmp_obj.str + this->len, obj.str);
    return tmp_obj;
}

my_string my_string::operator+(const char *str_right) const
{
    if(str_right == nullptr){

        throw std::runtime_error("nullptr in operator +(const char *str_right)");

    }

    size_t len = this->len + strlen(str_right);

    my_string tmp_obj(len, '\0');

    strcpy(tmp_obj.str, this->str);
    strcpy(tmp_obj.str + this->len, str_right);

    return tmp_obj;
}

my_string operator+(const char *str_left, const my_string &obj)
{

    if(str_left == nullptr){

        throw std::runtime_error("nullptr in operator +(const char *str_right)");
    }

    size_t len_left = strlen(str_left);
    size_t len = len_left + obj.len;

    my_string tmp_obj(len, '\0');

    strcpy(tmp_obj.str, str_left);
    strcpy(tmp_obj.str + len_left, obj.str);

    return tmp_obj;
}

my_string &my_string::operator+=(const my_string &obj)
{
    return this->append(obj);
}

my_string &my_string::operator+=(const char *s)
{
    if(s == nullptr){
        throw std::runtime_error("nullptr in operator +=(const char *s)");
    }
    return this->append(s);
}

size_t my_string::lenght() const
{
    return len;
}

const char *my_string::c_str() const
{
    return str;
}

my_string my_string::substr(size_t pos, size_t n) const
{
    if(pos + n >= len){
        throw std::runtime_error("range error in substr(size_t pos, size_t n)");
    }

    my_string ret_str(n, '\0');

    memcpy(ret_str.str, str + pos, n);

    return ret_str;
}

char &my_string::operator[](size_t pos)
{

    if(pos >= len){

        throw std::runtime_error("range error in operator[](size_t pos)");
    }

    return str[pos];;
}

const char &my_string::operator[](size_t pos) const
{
    if(pos >= len){

        throw std::runtime_error("range error in operator[](size_t pos)");
    }

    return str[pos];
}

size_t my_string::find(const my_string &obj, size_t pos) const
{
    return this->find(obj.str, pos, obj.len);
}

size_t my_string::find(const char *s, size_t pos, size_t n) const
{
    if(s == nullptr){

       throw std::runtime_error("nullptr in find(const char *s, size_t pos, size_t n)");
    }

    if (pos < len)
    {
        for (size_t i = pos; i + n < len; ++i)
        {
            if (memcmp(str + i, s, n) == 0)
            {
                return i;
            }
        }
    }
    else{

        throw std::runtime_error("range error in find(const char *s, size_t pos, size_t n)");
    }

    return 0;
}

size_t my_string::find(const char *s, size_t pos) const
{
    if(s == nullptr){

       throw std::runtime_error("nullptr in find(const char *s, size_t pos, size_t n)");
    }

    return this->find(s, pos, strlen(s));
}

std::ostream &operator<<(std::ostream &stream, const my_string &obj)
{
    stream << obj.str;
    return stream;
}

