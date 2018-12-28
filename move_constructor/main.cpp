#include <iostream>
#include "page.h"
#include "line.h"

using namespace std;

Page p0(5,10);

Page f()
{
    Page p(3, 2);
    cerr << "  in the f().\n";
    p.getLine(1)->writeChar("hello");
    return p;
}

Page g()
{
    cerr << "  in the g().\n";
    return Page(4, 2);
}


int main()
{
    cerr << "\n1 Page p1 = Page(1,2);" << endl;
    Page p1 = Page(1,2); //默认省略移动操作,直接触发参数构造函数

    cerr << "\n2 Page p2 {Page(2,3)};" << endl;
    Page p2 {Page(2,3)};//默认省略移动操作,直接触发参数构造函数

    cerr << "\n3 Page p3 = p1;" << endl;
    Page p3 = p1;        //触发复制构造函数

    cerr << "\n4 Page p4 {p1};" << endl;
    Page p4 {p2};        //触发复制构造函数

    cerr << "\n5 Page p5 = std::move(p3);" << endl;
    Page p5 = std::move(p3); //显式触发移动构造函数

    cerr << "Page p3 has " <<
            p3.lines().size() << " lines now." << endl;

    cerr << "\n6 Page p6 {std::move(p4)};" << endl;
    Page p6 {std::move(p4)}; //显式触发移动构造函数
    cerr << "    Page p4 has " << p4.lines().size() << " lines now."<<endl;

    cerr << "\n7 Page p7 = std::move(Page(2,2));" << endl;
    Page p7 = std::move(Page(2,2));//显式触发移动构造函数

    cerr << "\n8 Page p8 {std::move(Page(3,2))};" << endl;
    Page p8 {std::move(Page(3,2))};//显式触发移动构造函数

    cerr << "\n9 Page p9 {f()};" << endl;
    Page p9 {f()};//默认省略移动操作,但可能被优化掉

    cerr << "\n10 Page p10 {g()};" << endl;
    Page p10 {g()};//默认省略移动操作,但可能被优化掉

    cerr << "\n11 Page &&p11 {f()};" << endl;
    Page &&p11 {f()};//默认省略移动操作,但可能被优化掉

    cerr << "\n12 p1 = p2" << endl;
    p1 = p2;//触发operator=(Page &)复制赋值操作

    cerr << "\n13 p1 = Page(2,2);" << endl;
    p1 = Page(2,2);//触发operator=(Page &&)移动赋值操作


    cerr << "\n\n------brefore return 0;---------\n";

    return 0;
}

