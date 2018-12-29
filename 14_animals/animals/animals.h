#ifndef ANIMALS_H
#define ANIMALS_H

#include "iostream"
#include<string>
using namespace std;
class Animal
{
    protected:
    string name;
public:
    Animal(string nam):name(nam){}
    virtual void cry() = 0;
};

class Mouse : public Animal
{
private:
    char sex;
public:
    Mouse(string nam, char s):Animal(nam),sex(s) {}
    virtual void cry()
    {
        cout<<"我叫"<<name<<"，是一只"<<((sex=='m')?"男":"女")<<"老鼠，我的叫声是：吱吱吱！"<<endl;
    }
};

class Cat : public Animal
{
public:
    Cat(string nam):Animal(nam) {}
    virtual void cry()
    {
        cout<<"我叫"<<name<<"，是一只猫，我的叫声是：喵喵喵！"<<endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string nam):Animal(nam) {}
    virtual void cry()
    {
        cout<<"我叫"<<name<<"，是一条狗，我的叫声是：汪汪汪！"<<endl;
    }
};

class Giraffe : public Animal
{
private:
    char sex;
public:
    Giraffe(string nam,char s):Animal(nam), sex(s) {}
    virtual void cry()
    {
        cout<<"我叫"<<name<<"，是"<<((sex=='m')?"男":"女")<<"长颈鹿，我的脖子太长，发不出声音来！"<<endl;
    }
};



#endif // ANIMALS_H
