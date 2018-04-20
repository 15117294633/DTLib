#include "Exception.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
namespace DTLib
{
    void Exception::init(const char* message,const char*file,int line)
    {

        m_message=strdup(message);//此处有可能为栈，堆
        if(file!=NULL)
        {
            char sl[16]={0};
            /*itoa()函数有3个参数：第一个参数是要转换的数字
             第二个参数是要写入转换结果的目标字符串
             第三个参数是转移数字时所用 的基数。转换基数为10。10：十进制；2：二进制
             */
            itoa(line,sl,10);

            m_location=(char*)malloc(strlen(file)+strlen(sl)+2);
            m_location=strcpy(m_location,file);
            m_location=strcat(m_location,":");
            m_location=strcat(m_location,sl);
        }
        else
        {
            m_location=NULL;
        }
    }
    Exception::Exception(const char*message)
    {
       //cout<<1<<endl;
        init(message,NULL,0);
    }
    Exception::Exception(const char*file,int line)
    {
        init(NULL,file,line);
    }
    Exception::Exception(const char*message,const char*file,int line)
    {
        init(message,NULL,line);
    }
    Exception::Exception(const Exception& e)
    {
       //strdup 内部在堆上创建了一个备份，所以即使没看到malloc也应该在使用完毕后得自己手动释放（free）；
        m_message=strdup(e.message());
        m_location=strdup(e.location());
    }
    Exception&  Exception::operator = (const Exception& e)
    {
        if(this!=&e)
        {
            free(m_message);
            free(m_location);
            m_message=strdup(e.message());
            m_location=strdup(e.location());
        }
        return *this;
    }
    const char* Exception::message() const
   {
        return m_message;
   }
    const char*  Exception::location()const
   {
        return m_location;
   }
    Exception::~Exception()
    {
        free(m_location);
        free(m_message); //release
    }
}
