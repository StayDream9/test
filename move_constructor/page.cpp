#include "page.h"
#include <iostream>
#include <exception>
using std::domain_error;
using std::cerr;

Page::Page(int no, int lines):m_no{no}
{
    if(no < 1)
        throw domain_error("invalid line number.");

    for(int i = 1; i < lines + 1; i++)
        _lines.push_back(new Line(i));

    cerr << "  call Page's parameter constructor.";
    cerr << " The "<< m_no
         <<" Page has " << _lines.size() << " lines now.\n";
}

Page::Page(const Page &o):
    m_no{o.m_no}
{
    for(auto l:o._lines)
        _lines.push_back(new Line{*l});
    cerr << "  call Page's copy constructor.";
    cerr << " This Page has " << _lines.size() << " lines now.\n";
}


Page::Page(Page &&o)noexcept:
    m_no{o.m_no},_lines{o._lines} //普通成员复制，资源成员浅复制
{
    o._lines.clear();             //资源成员完成资源移动
    cerr << "  call Page's move constructor.";
    cerr << " The "<< m_no
         <<" Page has " << _lines.size() << " lines now.\n";
}

//复制赋值
Page &Page::operator=(const Page &o)
{
    cerr << "  call Page's operator=(Page &).";
    m_no=o.m_no;  //普通成员赋值

//    cerr << "  _lines=" <<_lines.size() <<  " before erase,";
    for(auto l:_lines)  //资源成员深赋值-擦除左值资源
        delete l;
    _lines.clear();
//    cerr << "  o._lines=" <<o._lines.size() <<  " before copy,";
    for(auto l:o._lines) //资源成员深赋值-复制
        _lines.push_back(new Line{*l});
//    cerr << "  o._lines=" << o._lines.size() <<  " after copy,";
//    cerr << "  _lines="<< _lines.size() << " now.\n";

    return *this;
}

//移动赋值
Page &Page::operator=(Page &&o) noexcept
{
    for(auto l:_lines)  //清理左值对象的资源
        delete l;

    m_no=o.m_no;        //普通成员赋值
    _lines = o._lines;  //资源成员浅赋值
    o._lines.clear();   //资源成员完成资源移动

    return *this;       //返回赋值表达式的值
}

Page::~Page()
{
    cerr << "  call Page's destructor.";
    for(auto &l:_lines){
        delete l;
        l = nullptr;
    }
    cerr << " This Page had " << _lines.size() << " lines before.\n";
}

