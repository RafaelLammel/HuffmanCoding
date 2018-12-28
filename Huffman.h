#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string>
#include <stdlib.h>

struct node{
    char c;
    int freq;
    node* left;
    node* right;
};

struct huffmanList{
    node element[128];
    int n;
};

class Huffman{

private:
    huffmanList chs;
    node *huffmanTree;
    /** Initializing the list */
    Huffman();
    /** Creating the list of appearing characters */
    void createList(std::string text);
    /** Insertion sort the list in decreasing order */
    void sortList();
    /** Creating an internal node */
    node createInternalNode(node right, node left);
public:
    /** Building the Huffman Tree */
    void buildHuffmanTree(std::string text);
    /** See how is the list; Might be useless later, therefore deleted */
    void showList();
    /** See how is the list; Might be useless later, therefore deleted */
    void encode();
};

#endif // HUFFMAN_H
