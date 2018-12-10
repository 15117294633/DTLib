#ifndef DTSTRING_H
#define DTSTRING_H
#include "Object.h"
namespace DTLib
{
    class String:public Object
    {
    protected:
        char* m_str;
        int m_length;
        void init(const char* s);
        bool Equal(const char* l,const char* r,int length) const;     

        static int* make_pmt(const char* p);//tools must be statict
        static int kmp(const char* s, const char* l);
        String& remove(int i,int len);
    public:
        //construc

        String();
        String(const char* s);
        String(const String& s);
        String(char c);
        //new operator
        char& operator [] (int i);//support = operator
        char operator [] (int i) const;//const Version
        //judgement the start with s
        bool startWith(const char* s) const;
        bool startWith(const String& s) const;
        //judgement the string is end of s
        bool endOf(const char* s) const;
        bool endOf(const String& s) const;
        //insert
        String& insert(int i,const char* s);
        String& insert(int i,const String& s);

        String& trim();//delete space

        int indexof(const char* s) const;
        int indexof(const String& s)const;

        String& remove(const char* s);
        String& remove(const String& s);
        //replace operator
        String& replace(const char* s,const char* r);
        String& replace(const char* s,const String& r);
        String& replace(const String& s,const char* r);
        String& replace(const String& s,const String& r);
        //sub
        String Sub(int i,int len) const;

        int length() const;
        const char* str() const;
        //operator 比较操作符
        bool operator == (const String& s) const;
        bool operator ==(const char* s) const;
        bool operator !=(const String& s) const;
        bool operator !=(const char* s) const;
        bool operator > (const String& s) const;
        bool operator > (const char* s) const;
        bool operator < (const String& s) const;
        bool operator < (const char* s) const;
        bool operator >=(const String& s) const;
        bool operator >=(const char* s) const;
        bool operator <=(const String& s) const;
        bool operator <=(const char* s) const;

        String operator + (const String& s) const;
        String operator + (const char* s) const;
        String& operator +=(const String& s) ;
        String& operator +=(const char* s) ;
        //operator -
        String operator - (const String& s) const;
        String operator - (const char* s) const;

        String& operator -=(const String& s) ;
        String& operator -=(const char* s) ;

        String& operator =(const String& s);
        String& operator =(const char* s);
        String& operator =(char c);
        ~String();

    };
}
#endif // DTSTRING_H
