#include "Exception.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
namespace DTLib
{
    void Exception::init(const char* message,const char*file,int line)
    {

        m_message=strdup(message);//�˴��п���Ϊջ����
        if(file!=NULL)
        {
            char sl[16]={0};
            /*itoa()������3����������һ��������Ҫת��������
             �ڶ���������Ҫд��ת�������Ŀ���ַ���
             ������������ת������ʱ���� �Ļ�����ת������Ϊ10��10��ʮ���ƣ�2��������
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
       //strdup �ڲ��ڶ��ϴ�����һ�����ݣ����Լ�ʹû����mallocҲӦ����ʹ����Ϻ���Լ��ֶ��ͷţ�free����
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
