#include <cstring>
#include <cstdlib>
#include "DTString.h"
#include "Exception.h"
/*
    String s="abcdabd";
    String t="bd";
    cout<<s.indexof(t)<<endl;
    cout<<s.indexof("cd")<<endl;
    //s.remove(1,2).remove(0,3);//ababd //
    //s.remove(t).remove("cd");
    s.replace("bc","ab");
    //String temp=s-"ab";
    cout<<s.str()<<endl;
    //cout<<temp.str()<<endl;
    cout<<s.length()<<endl
 */
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
                  //注意下标对应
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
        int sl=strlen(s);
        int ll=strlen(l);
        int* kmp=make_pmt(l);
        if(kmp!=NULL&&ll<sl)
        {
            for(int i=0,j=0;i<sl;i++)
            {
                while(j>0&&s[i]!=l[j])
                {
                    j=kmp[j-1];
                }
                if(s[i]==l[j])
                {
                    j++;
                }
                if(j==ll)
                {
                    ret=i-ll+1;
                    break;
                }
            }
            free(kmp);
        }
        else
        {

        }
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
    //对比操作的公共方法
    bool String::Equal(const char* l,const char* r,int length) const
    {
      bool ret=true;
      //0(n)
      for(int i=0;i<length&&ret;i++)
      {
          ret=ret&&(l[i]==r[i]);
      }
      return ret;
    }
    char& String::operator [](int i)//support = operator
    {
        //judgement param
        if((0<=i)&&(i<m_length))
        {
           return m_str[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"operator values out of index");
        }
    }
    //去除const属性的方法
    char String::operator [](int i) const//const Version
    {
      return const_cast<String&>(*this)[i];
    }
    //判断是否以某个指定的字符串开始
    bool String::startWith(const char* s) const
    {
       bool ret=true;
       ret=ret&(s!=NULL);
       if(ret)
       {
           //get len
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
          //指针的操作
          char* str=m_str+m_length-strlen(s);
          ret=(m_length>len)&&Equal(str,s,len);//判断参数合法性
        }
        return ret;
    }
    bool String::endOf(const String& s) const
    {
        return endOf(s.m_str);
    }
    //插入操作
    String& String::insert(int i,const char* s)
    {
        //param i
        if((i>=0)&&(i<=m_length))
        {
            int len=strlen(s);
            char* str=static_cast<char*>(malloc(len+m_length+1));//
            if(str!=NULL)
            {
                /*
                 *  destination
                    Pointer to the destination array where the content is to be copied.
                    source
                    C string to be copied.
                    num
                    Maximum number of characters to be copied from source.
                    size_t is an unsigned integral type.
                 */
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
    //remove方法==>起始index len
    String& String::remove(int i,int len)
    {
        if((0<=i)&&(i<m_length))
        {
            int begin=i;
            int end=i+len;
            while((begin<end)&&(end<m_length))
            {
                m_str[begin++]=m_str[end++];

            }
            m_str[begin]='\0';
            m_length=begin;
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
    //初始化对象
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
    //获取字符串的长度
    int String::length() const
    {
      return m_length;
    }
    //数组类中实现排序算法时候，也用到了这种方式==>const方法的调用 复习
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
    //two sring add operator
    String String::operator + (const String& s) const
    {
     return (*this+s.m_str);
    }
    String String::operator + (const char* s) const
    {
        //step1:creat a temp object
        String ret;
        int len=this->m_length+strlen(s?s:"");
        /*
         *strlen所作的仅仅是一个计数器的工作，它从内存的某个位置（可以是字符串开头，中间某个位置，甚至是某个不确定的内存区域）开始扫描，直到碰到第一个字符串结束符'\0'为止，然后返回计数器值(长度不包含'\0')。
         */
        //==>void* char* reinter_cast==>基本类型指针间的转换
        char* str=static_cast<char*>(malloc(len+1));//字符串后面的结束符'\0'
        if(str)
        {
            /*
                char* strcpy(char* des,const char* source)
                {
                  char* r=des;
                  assert((des != NULL) && (source != NULL));
                　while((*r++ = *source++)!='\0');
                　return des;
                }
             */
            strcpy(str,m_str);
            strcat(str,s?s:"");
            //release operator
            free(ret.m_str);
            ret.m_str=str;
            ret.m_length=len;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to append String values");
        }
        return ret;
    }
    String&  String::String::operator =(const String& s)
    {
        return (*this = s.m_str);
    }
    //1.防止自赋值
    //2.返回自身,支持链式操作
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
    String& String::operator +=(const String& s)
    {
        return (*this = *this+s);
    }
    String& String::operator +=(const char* s)
    {
        return (*this = *this+s);
    }
    //remove的实现 temp对象
    //加入const的reason 返回的是一个局部变量,
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
}

