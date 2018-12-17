#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string>
#include <stdlib.h>

struct charElement{
    char c;
    int freq;
    charElement* left = NULL;
    charElement* right = NULL;
};

struct huffmanList{
    charElement element[100];
    int n;
};

class Huffman{

private:
    huffmanList chs;
    charElement *huffmanTree = (charElement*) malloc(sizeof(charElement));
public:
    /** Initializing the list */
    Huffman();
    /** Building the Huffman Tree */
    void buildHuffmanTree(std::string text);
    /** Inserting nodes in the tree */
    charElement* insertNode(charElement* left, charElement* right);
    /** Creating the list of appearing characters */
    void createList(std::string text);
    /** Insertion sort the list in decreasing order */
    void sortList();
    /** See how is the list; Might be useless later, therefore deleted */
    void showList();
};

#endif // HUFFMAN_H
