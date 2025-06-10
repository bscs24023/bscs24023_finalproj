#ifndef MYSTR_H
#define MYSTR_H

#include <iostream>
using namespace std;

class String 
{
    int len;
    int cap;
    char *Cs;

public:
    String();

    int length(const char *p) const;

    String(const char *p);
    
    void copy(const char *p);

    String(int n, char c);

    String itos(int num);

    static int stoi(const String s);

    String(int num);

    void replace_first(char c);

    String(const String &s);

    void print() const;

    char operator[](int i) const;

    char& operator[](int i);

    void insert_at(int i, char ch);

    void insert_at(int i, const String &sub);

    bool is_equal(const String& M);

    bool is_less(const String& M);

    bool is_greater(const String& M);

    String& trim();

    String* split(char delim, int &count) const;

    String* tokenize(const char *delim, int &count) const;

    String concat(const String& s2) const;

    int find_first(char ch) const;

    int find_first(const String &sub) const;

    int find_last(char ch) const;

    int find_last(const String &sub) const;

    int* find_all(char ch, int &count) const;

    int* find_all(const String &sub, int &count) const;

    void remove_at(int i);

    void remove_first(char ch);

    void remove_last(char ch);

    void remove_all(char ch);

    void clear();

    void to_upper();

    void to_lower();
    
    friend istream& operator>>(istream& in, String& string);
    friend ostream& operator<<(ostream& out, const String& string);

    ~String();
};

#endif