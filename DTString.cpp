#include <cstring>
#include <cstdlib>
#include "DTString.h"
#include "Exception.h"
namespace  DTLib {
    //make_pmt
    int* String::make_pmt(const char* p)
    {
        int len=strlen(p);
        int* ret=static_cast<int*>(malloc(sizeof(int)*len));
        if(ret!=NULL)
        {
            ret[0]=0;
            int ll=0;
            for(int i=1;i<len;i++)
            {
                while(ll>0&&p[ll]!=p[i])
                {
                   ll=ret[ll-1];
                }
                if(p[ll]==p[i])
                {
                    ll++;
                }
                ret[i]=ll;
            }
        }
        return ret;
    }
    //@param: s source string
    //           l:need to find string
    int String::kmp(const char* s, const char* l)
    {
        int ret=-1;
        //param
        int s1=strlen(s);
        int l1=strlen(l);
        //kmp 表
        int* kmp=make_pmt(l);
        if((kmp!=NULL)&&(l1>0)&&(s1>l1))
        {
            for(int i=0,j=0;i<s1;i++)
            {
               while(j>0&&(s[i]!=l[j]))
               {
                   j=kmp[j-1];
               }
               if(s[i]==l[j])
               {
                 j++;
               }
               if(j==l1)
               {
                   ret=i+1-l1;
                   break;
               }
            }
        }
        free(kmp);
        return ret;
    }
    void String::init(const char* s)
    {
        //m_str alloc space
        m_str=strdup(s);
        if(m_str)
        {
            //get str length
            m_length=strlen(m_str);
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to creat string");
        }
    }
    //
    bool String::Equal(const char* l,const char* r,int length) const
    {
      bool ret=true;
      for(int i=0;i<length&&ret;i++)
      {
          ret=ret&&(l[i]==r[i]);
      }
      return ret;
    }
    char& String::operator [](int i)//support = operator
    {
        //judgement param
        if((i>=0)&&(i<m_length))
        {
           return m_str[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"operator values out of index");
        }
    }
    char String::operator [](int i) const//const Version
    {
      return const_cast<String&>(*this)[i];
    }
    bool String::startWith(const char* s) const
    {
       bool ret=true;
       ret=ret&(s!=NULL);
       if(ret)
       {
           int len=strlen(s);
           ret=(m_length>len)&&Equal(m_str,s,len);
       }
       return ret;
    }
    bool String::startWith(const String& s) const
    {
        return startWith(s.m_str);
    }
    bool String::endOf(const char* s) const
    {
        bool ret=true;
        ret=ret&(s!=NULL);
        if(ret)
        {
          int len=strlen(s);
          char* str=m_str+m_length-strlen(s);
          ret=(m_length>len)&&Equal(str,s,len);//判断参数合法性
        }
        return ret;
    }
    bool String::endOf(const String& s) const
    {
        return endOf(s.m_str);
    }
    String& String::insert(int i,const char* s)
    {
        //param i
        if((i>=0)&&(i<=m_length))
        {
            int len=strlen(s);
            char* str=static_cast<char*>(malloc(len+m_length+1));//
            if(str!=NULL)
            {
                strncpy(str,m_str,i);//ref strncpy的用法
                strncpy(str+i,s,len);
                strncpy(str+i+len,m_str+i,m_length-i);//字符串拼接
                //attention must add '\0'
                str+='\0';
                free(m_str);
                m_str=str;
                m_length=m_length+len;
            }
            else
            {
               THROW_EXCEPTION(NoEnoughMemoryException,"No memory to creat string");
            }
        }
        else
        {
          THROW_EXCEPTION(IndexOutOfBoundsException,"operator values out of index");
        }
        return *this;
    }
    String& String::insert(int i,const String& s)
    {
        return insert(i,s.m_str);
    }
    String& String::trim()
    {
        int m=0;
        int n=m_length-1;
        //loc space head and tail
        while(m_str[m]==' ') m++;
        while((m_str[n])==' ') n--;
        //是否需要重新申请space
        if(m==0)
        {
           m_str[n+1]='\0';
           m_length=n+1;
        }
        else
        {
           for(int i=0,j=m;j<=n;i++,j++)
           {
                m_str[i]=m_str[j];
           }
           m_str[n-m+1]='\0';
           m_length=n-m+1;
        }
        return *this;
    }
    int String::indexof(const char* s) const
    {
       return kmp(m_str,s?s:"");
    }
    int String::indexof(const String& s)const
    {
        return kmp(m_str,s.m_str?s.m_str:"");
    }
    String& String::remove(int i,int len)
    {
        if((0<=i)&&(i<m_length))
         {
            int m=i;
            int n=i+len;
            while(m<n&&n<m_length)
            {
                m_str[m++]=m_str[n++];
            }
            m_str[m]='\0';
            m_length=m-1;
         }
        return *this;
    }
    String& String::remove(const char* s)
    {
        return remove(indexof(s),s?strlen(s):0);
    }
    String& String::remove(const String& s)
    {
        return remove(s.m_str);
         //return remove(indexof(s.m_str),s.length());
    }
    //replace
    String& String::replace(const char* s,const char* r)
    {
        int index=indexof(s);
        if(index>=0)
        {
           remove(s);
           insert(index,r);
        }
        return *this;
    }
    String& String::replace(const char* s,const String& r)
    {
        return replace(s,r.m_str);
    }
    String& String::replace(const String& s,const char* r)
    {
        return replace(s.m_str,r);
    }
    String& String::replace(const String& s,const String& r)
    {
         return replace(s.m_str,r.m_str);
    }
    String String::Sub(int i,int len) const
    {
        String ret;
        if((i>=0)&&(i<m_length))
        {
            if(len<0) len=0;
            if(m_length<(i+len)) len=m_length-i;
            char* temp=static_cast<char*>(std::malloc(len+1));//must be care
            strncpy(temp,m_str+i,len);
            temp[len]='\0';
            ret=temp;
        }
        return ret;
    }
    //init
    String::String()
    {
        init("");
    }
    String::String(const char* s)
    {
        init(s?s:"");
    }
    String::String(const String &s)
    {
        init(s.str());
    }
    String::String(char c)
    {
        char s[]={c,'\0'};
        init(s);
    }
    String::~String()
    {
        free(m_str);
    }
    int String::length() const
    {
      return m_length;
    }
    //数组类中实现排序算法时候，也用到了这种方式
    const char* String::str() const
    {
      return m_str;
    }
    //strcmp的实现code
    bool String::operator == (const String& s) const
    {
        return (strcmp(m_str,s.m_str)==0);
    }
    bool String::operator ==(const char* s) const
    {
       return (strcmp(m_str,s)==0);
    }
    bool String::operator !=(const String& s) const
    {
        return !(*this==s);
    }
    bool String::operator !=(const char* s) const
    {
        return !(*this==s);
    }
    bool String::operator > (const String& s) const
    {
        return (strcmp(m_str,s.m_str)>0);
    }
    bool String::operator > (const char* s) const
    {
        return (strcmp(m_str,s)>0);
    }
    bool String::operator < (const String& s) const
    {
        return (strcmp(m_str,s.m_str)<0);
    }
    bool String::operator < (const char* s) const
    {
        return (strcmp(m_str,s)<0);
    }
    bool String::operator >= (const String& s) const
    {
        return (strcmp(m_str,s.m_str)>=0);
    }
    bool String::operator >= (const char* s) const
    {
        //return (strcmp(m_str,s)>=0);
        return !(*this<s);
    }
    bool String::operator <= (const String& s) const
    {
        return (strcmp(m_str,s.m_str)<=0);
    }
    bool String::operator <=(const char* s) const
    {
        return !(*this>s);
        //return (strcmp(m_str,s)<=0);
    }

    String String::operator + (const String& s) const
    {
     return (*this+s.m_str);
    }
    String String::operator + (const char* s) const
    {
        String ret;
        int len=m_length+strlen(s?s:"");
        char* str=static_cast<char*>(malloc(len+1));//字符串后面的结束符'\0'
        if(str)
        {
            strcpy(str,m_str);
            strcat(str,s?s:"");
            //release operator
            free(ret.m_str);
            ret.m_str=str;
            ret.m_length=len;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to Add String values");
        }
        return ret;
    }
    String& String::operator +=(const String& s)
    {
        return (*this = *this+s);
    }
    String& String::operator +=(const char* s)
    {
        return (*this = *this+s);
    }
    String  String::operator - (const String& s) const
    {
       return String(*this).remove(s);
    }
    String  String::operator - (const char* s) const
    {
         return String(*this).remove(s);
    }
    String&  String::operator -=(const String& s)
    {
        return remove(s);
    }
    String&  String::operator -=(const char* s)
    {
         return remove(s);
    }
    String&  String::String::operator =(const String& s)
    {
        return (*this = s.m_str);
    }
    //=
    String& String::operator = (const char* s)
    {
        if(m_str!=s)
        {
            char* str=strdup(s?s:"");
            if(str)
            {
                free(m_str);
                m_str=str;
                m_length=strlen(m_str);
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to assign new values...");
            }

        }
        return *this;
    }
    String& String::operator=(char c)
    {
        char s[]={c,'\0'};
        return (*this=s);
    }

}

