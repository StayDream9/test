#ifndef PAGE_H
#define PAGE_H
#include <vector>
#include "line.h"

class Page
{
public:
    Page(int no, int lines);
    Page(const Page &o);
    Page(Page &&o) noexcept;
    Page &operator= (const Page &o);
    Page &operator=(Page &&o) noexcept;
    ~Page();

    Line *getLine(int lineNo){
        return _lines[lineNo - 1];
    }
    auto lines(){ return _lines; }
private:
    int m_no;
    std::vector<Line *> _lines;
};

#endif // PAGE_H
