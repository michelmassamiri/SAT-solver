/////////////////////////////////////////////////////////////
// FastWay 0.6
// Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
// Pavarino Arthur
/////////////////////////////////////////////////////////////

#include "Fastway.hpp"

namespace fw {


/** \brief tests if a function/var are equals
 *
 * \param a - a function or a var
 * \param b - a function or a var
 * \param name - the name of the test
 * \return true if the param a is equal to the param b
 *
 */
template<typename T, typename T2>
void UnitTest::assertEquals(T a, T2 b , std::string const& name)
{
    if(a == b)
    {
        std::cout << " " << name << " : OK" << std::endl;
        m_sucess ++;
    }
    else
    {
        std::cout << " " << name << " : FAILED" << std::endl;
        m_failed ++;
    }
}

} // fin du namespace
