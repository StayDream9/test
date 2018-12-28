#include "line.h"
#include <exception>
using std::domain_error;
using std::string;

Line::Line(int lineNo):m_no{lineNo}{
    if(lineNo < 1)
        throw domain_error("invalid line number.");
}

void Line::writeChar(string chars){
    m_chars = chars;
}

