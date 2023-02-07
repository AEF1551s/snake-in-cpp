#include "score.h"

void score::inc()
{
    m_score++;
}
void score::print()
{
    std::cout
        << "Score:" << m_score
        << "Highscore:" << highscore
        << std::endl;
}
void score::save()
{
    if (m_score > highscore)
    {
        // write replace highscore in file.
    }
}
