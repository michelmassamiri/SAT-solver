/////////////////////////////////////////////////////////////
// FastWay 0.6
// Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
// Pavarino Arthur
/////////////////////////////////////////////////////////////

#ifndef FILESIZE_HPP_INCLUDED
#define FILESIZE_HPP_INCLUDED

namespace fw {

class FileSize
{

public:
    FileSize();
    FileSize(double size);
    double inBytes() const;
    double inKo() const;
    double inMo() const;
    double inGo() const;

private:

     double m_size;

};

} // fin du namespace
#endif // FILESIZE_HPP_INCLUDED
