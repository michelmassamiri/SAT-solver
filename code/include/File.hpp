/////////////////////////////////////////////////////////////
// FastWay 0.6
// Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
// Pavarino Arthur
/////////////////////////////////////////////////////////////

#ifndef FILE_HPP_INCLUDED
#define FILE_HPP_INCLUDED

#define FWEOF "fweof"

namespace fw
{

class FileSize;
class File
{
public:

    File(std::string name, std::string extension, std::string path = "");
    std::string getPath() const;
    std::string getName() const;
    std::string getExtension() const;
    std::string getFullPath() const;
    bool exists() const;
    bool create() const;
    bool del() const;
    bool addToNextLine(std::string text) const;
    bool addToLine(std::string text) const;
    FileSize getSize() const;
    bool compareSize(File const& file) const;
    std::string readLine(const unsigned int number) const;
    int nbOfLine() const;
    std::string contents() const;
    std::string plainText() const;
    std::string retrieveLineContents(std::string contents) const;
    bool changeLineContent(std::string const &contents, int lineNumber) const;
    bool rename(std::string name, std::string extension = ".");
    bool move(std::string path);
    int lineOfContent(std::string const& contents) const;
    bool isEmpty() const;
    bool clear() const;
    std::string readNextLine();
    void resetCursor();
    bool replace(std::string str, std::string newStr) const;
    bool replace(char const str, char const newStr) const;
    bool copy(File f) const;
private:

    void setPath(std::string const& path);
    void setName(std::string const& name);
    void setExtension(std::string const& name);
    std::string m_name;
    std::string m_extension;
    std::string m_path;
    int m_lineIndex;
};

}
#endif // FILE_HPP_INCLUDED
