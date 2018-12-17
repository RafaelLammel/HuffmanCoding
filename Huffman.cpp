#include "Huffman.h"

using namespace std;

Huffman::Huffman()
{
    chs.n = 0;
    for(int i = 0; i < 100; i++)
        chs.element[i].freq = 0;
}

void Huffman::buildHuffmanTree(string text)
{
    createArray(text);
    sortArray();
}

void Huffman::createArray(string text)
{
    bool inTheList;
    for(int i = 0; i < text.size(); i++)
    {
        inTheList = false;
        for(int j = 0; j < chs.n; j++)
        {
            if(text[i] == chs.element[j].c)
            {
                inTheList = true;
                chs.element[j].freq++;
                break;
            }
        }
        if(!inTheList)
        {
            chs.element[chs.n].c = text[i];
            chs.element[chs.n].freq++;
            chs.n++;
        }
    }
}

void Huffman::sortArray()
{
    charElement chosen;
    int j;
    for (int i = 1; i < chs.n; i++)
    {
        chosen = chs.element[i];
        j = i - 1;
        while ((j >= 0) && (chs.element[j].freq < chosen.freq))
        {
            chs.element[j+1] = chs.element[j];
            j--;
        }
        chs.element[j+1] = chosen;
    }
}

void Huffman::showList()
{
    for (int i = 0; i < chs.n; i++)
        cout << "Char: " << chs.element[i].c << " - Freq: " << chs.element[i].freq << endl;
}
