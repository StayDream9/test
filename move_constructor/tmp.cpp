//#include "page.h"
//#include <iostream>
//#include <exception>
//using std::domain_error;
//using std::cerr;

//Page::Page(int no, int lines):m_no{no}
//{
//    if(no < 1)
//        throw domain_error("invalid line number.");
//    for(int i = 0; i < lines; i++) //RAII，获取资源
//        _lines.push_back(new Line(i+1));
//}

//Page::Page(const Page &o):
//    m_no{o.m_no}         //普通成员复制
//{
//    for(auto l:o._lines) //资源成员深复制源对象资源
//        _lines.push_back(new Line{*l});
//}

//Page::Page(Page &&o)noexcept:
//    m_no{o.m_no},_lines{o._lines} //普通成员复制，资源成员浅复制
//{
//    o._lines.clear();      //资源成员完成右值源对象资源的移动
//}

//Page &Page::operator=(const Page &o)
//{
//    m_no = o.m_no;      //普通成员赋值

//    for(auto l:_lines)  //资源成员左值源对象赋值-擦除左值资源
//        delete l;       //
//    _lines.clear();     //清除已销毁资源的指针

//    for(auto l:o._lines) //资源成员左值源对象赋值-深复制右值资源
//        _lines.push_back(new Line{*l});//

//    return *this;        //返回左值对象的引用作为赋值表达式的值
//}

//Page &Page::operator=(Page &&o) noexcept
//{
//    m_no = o.m_no;      //普通成员赋值

//    for(auto l:_lines)  //资源成员右值源对象赋值-擦除左值资源
//        delete l;       //
//    _lines = o._lines;  //资源成员右值源对象赋值-移动右值资源
//    o._lines.clear();   //

//    return *this;       //返回左值对象的引用作为赋值表达式的值
//}

//Page::~Page()
//{
//    for(auto &l:_lines){//清理资源
//        delete l;
//        l = nullptr;
//    }
//}

