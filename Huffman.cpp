#include "Huffman.h"

using namespace std;

/** Initializing the list */
Huffman::Huffman()
{
    chs.n = 0;
    for(int i = 0; i < 100; i++)
        chs.element[i].freq = 0;
    huffmanTree = (node*) malloc(sizeof(node));
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
            chs.element[chs.n].left = NULL;
            chs.element[chs.n].right = NULL;
            chs.n++;
        }
    }
}

/** Insertion sort the list in decreasing order */
void Huffman::sortList()
{
    node chosen;
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

/** Building the Huffman Tree */
void Huffman::buildHuffmanTree(string text)
{
    createList(text);
    tableN = 0;
    sortList();
    while(chs.n > 2)
    {
        chs.element[chs.n-2] = createInternalNode(chs.element[chs.n-2],chs.element[chs.n-1]);
        chs.n--;
        sortList();
    }
    huffmanTree->c = 0;
    huffmanTree->freq = chs.element[0].freq + chs.element[1].freq;
    huffmanTree->left = &chs.element[1];
    huffmanTree->right = &chs.element[0];
}

/** Creating an internal node */
node Huffman::createInternalNode(node right, node left)
{
    node n, *l, *r;
    l = (node*)malloc(sizeof(node));
    r = (node*)malloc(sizeof(node));
    l->c = left.c;
    l->freq = left.freq;
    l->left = left.left;
    l->right = left.right;
    r->c = right.c;
    r->freq = right.freq;
    r->left = right.left;
    r->right = right.right;
    n.c = 0;
    n.freq = r->freq + l->freq;
    n.left = l;
    n.right = r;
    return n;
}

/** Creating the table of codes */
void Huffman::tableCode(node* tree, string code)
{
    string coded;
    coded += code;
    if(tree->c != 0)
    {
        table[tableN].c = tree->c;
        table[tableN].code = coded;
        tableN++;
    }
    if(tree->left!=NULL)
    {
        coded+='0';
        tableCode(tree->left,coded);
    }
    coded.pop_back();
    if(tree->right!=NULL)
    {
        coded+='1';
        tableCode(tree->right,coded);
    }
}

/** Encoding the text file */
string Huffman::encode(string text)
{
    string encodedText = "";
    buildHuffmanTree(text);
    tableCode(huffmanTree,"");
    for (int i = 0; i < text.size(); i++)
        for(int j = 0; j < tableN; j++)
            if(table[j].c == text[i])
            {
                encodedText += table[j].code;
                break;
            }
    return encodedText;
}

string Huffman::decode(string encodedText)
{
    string text = "";
    string ch;
    for(int i = 0; i < encodedText.size(); i++)
    {
        ch += encodedText[i];
        for (int j = 0; j < tableN; j++)
        {
            if(ch.compare(table[j].code) == 0)
            {
                text += table[j].c;
                ch = "";
                break;
            }
        }
    }
    return text;
}

void Huffman::showTable()
{
    cout << "Table of symbols with their codes\n\n";
    for(int i = 0; i < tableN; i++)
    {
        if(table[i].c == '\n')
            cout << "New line" << " - " << table[i].code << endl;
        else if(table[i].c == ' ')
            cout << "Space" << " - " << table[i].code << endl;
        else
            cout << table[i].c << " - " << table[i].code << endl;
    }
    cout << "\n\n";
}
