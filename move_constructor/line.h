#ifndef LINE_H
#define LINE_H
#include <string>
#include <iostream>

class Line
{
public:
    Line(int lineNo);
    ~Line(){ std::cerr << "  delete a line.";}

    void writeChar(std::string chars);
    std::string chars(){return m_chars;}
private:
    int m_no;
    std::string m_chars;
};

#endif // LINE_H
