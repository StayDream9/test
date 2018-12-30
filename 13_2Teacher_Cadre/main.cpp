#include <iostream>

using namespace std;

//class T_C{
//protected:

//};

class Teacher{
public:
    Teacher(string nam,int a,char s,string tit,string ad,string t);
    void display();

protected:
    string name;
    int age;
    char sex;
    string title; //职称
    string address;
    string telnum;


};

Teacher::Teacher(string nam, int a, char s, string tit, string ad, string t):
    name{nam}, age{a}, sex{s}, title{tit}, address{ad}, telnum{t}{ }

void Teacher::display()
{
    cout<<"name:"<<name<<endl;
    cout<<"age"<<age<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"title:"<<title<<endl;
    cout<<"address:"<<address<<endl;
    cout<<"tel:"<<telnum<<endl;

}

class Cadre{
public:
    Cadre(string nam,int a,char s,string ad,string t,string p);
    void display();

protected:
    string name;
    int age;
    char sex;
    string address;
    string telnum;
    string post; //职务

};

Cadre::Cadre(string nam,int a,char s,string ad,string t,string p):
    name{nam}, age{a}, sex{s}, address{ad}, telnum{t}, post{p}{ }

void Cadre::display()
{
    cout<<"name:"<<name<<endl;
    cout<<"age"<<age<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"title:"<<address<<endl;
    cout<<"address:"<<telnum<<endl;
    cout<<"tel:"<<post<<endl;
}

class Teacher_Cadre:public Teacher, public Cadre{
public:
    Teacher_Cadre(string nam,int a,char s,string tit,string p,string ad,string t,float w);
    void show();

protected:
    float wages; //工资
};

Teacher_Cadre::Teacher_Cadre(string nam,int a,char s,string tit,string ad,string t,string p,float w):
    Teacher(nam,a,s,tit,ad,t), Cadre (nam, a, s, ad, t, p), wages{w}{ }

void Teacher_Cadre::show()
{
    Teacher::display();
    cout << "post " << Cadre::post << endl;
    cout << "wages " << wages << endl;
}

int main()
{
        Teacher_Cadre te_ca("Wang-li",50,'f',"prof.","135 Beijing Road,Shanghai","(021)61234567","president",1534.5);
        te_ca.show();

        return 0;
}
