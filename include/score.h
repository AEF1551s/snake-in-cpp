#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <string>
#include <fstream>
#include <iostream>

class score
{
private:
    int m_score = 0;
    int highscore=0;
    std::string filename="hscore_log.dat";
    std::ofstream write;
    std::ifstream read;

public:
    std::ofstream in;
    score(std::ofstream &write, std::ifstream &read);
    void inc();
    void save();
    void print();
    void reset();
    std::string get_filename();
    // void check();
};

#endif