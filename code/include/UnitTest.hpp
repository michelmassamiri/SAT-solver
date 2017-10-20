/////////////////////////////////////////////////////////////
// FastWay 0.6
// Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
// Pavarino Arthur
/////////////////////////////////////////////////////////////

#ifndef UNITTEST_HPP_INCLUDED
#define UNITTEST_HPP_INCLUDED

namespace fw {

class UnitTest
{

public:

    UnitTest();
    ~UnitTest();
    //template<typename TT>
    void assertTrue(bool b, std::string name);

    //template<typename TF>
    void assertFalse(bool b, std::string name);

    template<typename T, typename T2>
    void assertEquals(T a, T2 b , std::string name);

private:
    std::string m_funcname;
    int m_sucess;
    int m_failed;
};

} // fin du namespace

#include "assertEquals.tpp"
#endif // UNITTEST_HPP_INCLUDED
