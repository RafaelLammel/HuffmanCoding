#include "Huffman.h"

using namespace std;

/** Initializing the list */
Huffman::Huffman()
{
    chs.n = 0;
    for(int i = 0; i < 100; i++)
        chs.element[i].freq = 0;
}

/** Building the Huffman Tree */
void Huffman::buildHuffmanTree(string text)
{
    charElement *aux;
    createList(text);
    sortList();
    while(chs.n > 2)
    {
        aux = insertNode(&chs.element[chs.n-2],&chs.element[chs.n-1]);
        chs.element[chs.n-1] = *aux;
        sortList();
        chs.n--;
    }
    huffmanTree = insertNode(&chs.element[chs.n-1],&chs.element[chs.n-2]);
    while(huffmanTree != NULL)
    {
        cout << huffmanTree->freq << endl;
        huffmanTree = huffmanTree->left;
    }
}

/** Inserting nodes in the tree */
charElement* Huffman::insertNode(charElement* left, charElement* right)
{
    charElement* a;
    a = (charElement*) malloc(sizeof(charElement));
    a->c = 0;
    a->freq = left->freq + right->freq;
    a->left = left;
    a->right = right;
    return a;
}

/** Creating the list of appearing characters */
void Huffman::createList(string text)
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

/** Insertion sort the list in decreasing order */
void Huffman::sortList()
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

/** See how is the list; Might be useless later, therefore deleted */
void Huffman::showList()
{
    for (int i = 0; i < chs.n; i++)
        cout << "Char: " << chs.element[i].c << " - Freq: " << chs.element[i].freq << endl;
}
