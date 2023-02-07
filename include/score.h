#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <string>
#include <fstream>
#include <iostream>

class score
{
private:
    int m_score = 0;
    int highscore;
    std::string filename;

public:
    // score();
    void inc();
    void save();
    void print();
    // void check();
};

#endif