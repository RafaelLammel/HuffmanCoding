#include "FileManager.h"

using namespace std;

/** Reading files by the name */
string readFile(char* fileName)
{
    string line, text;
    ifstream myfile (fileName);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            text += line;
        }
        myfile.close();
        return text;
    }

    else
        cout << "Unable to open file";
    return text;
}
