#include "score.h"

score::score(std::ofstream &write, std::ifstream &read)
{
    //TODO: open new file if not present, and add highscore 0
    if (read.good())
    {
        read.open(filename);
        std::string str;
        getline(read, str);
        highscore=stoi(str);
        read.close();
    }
}

void score::inc()
{
    m_score++;
}
void score::print()
{
    std::cout
        << "Score:" << m_score
        << " "
        << "Highscore:" << highscore
        << std::endl;
}
void score::save()
{
    if (m_score > highscore)
    {        
        write.open(filename);
        write << m_score;
    }
    write.close();
}
void score::reset()
{
    //TODO: create new file with highscore 0
}
std::string score::get_filename()
{
    return filename;
}
