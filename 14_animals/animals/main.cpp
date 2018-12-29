#include <iostream>
#include "animals.h"
using namespace std;


int main( )
{
    Animal *p;
//    p = new Animal();
//    p->cry(); //输出: 不知哪种动物，让我如何学叫？
    Mouse m1("Jerry",'m');
    p=&m1;
    p->cry(); //输出: 我叫Jerry，是一只男老鼠，我的叫声是：吱吱吱！
    Mouse m2("Jemmy",'f');
    p=&m2;
    p->cry(); //输出: 我叫Jemmy，是一只女老鼠，我的叫声是：吱吱吱！
    Cat c1("Tom");
    p=&c1;
    p->cry(); //输出: 我叫Tom，是一只猫猫，我的叫声是：喵喵喵！
    Dog d1("Droopy");
    p=&d1;
    p->cry(); //输出: 我叫Droopy，是一条狗狗，我的叫声是：汪汪汪！
    Giraffe g1("Gill",'m');
    p=&g1;
    p->cry(); //输出: 我叫Gill，是男长颈鹿，脖子太长，发不出声音来！
    return 0;
}
