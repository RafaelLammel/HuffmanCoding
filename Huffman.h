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
    /** Creating the list of appearing characters */
    void createList(std::string text);
    /** Insertion sort the list in decreasing order */
    void sortList();
    /** Creating an internal node */
    node createInternalNode(node right, node left);
    /** Creating the table of codes */
    void tableCode(node* tree, std::string code);
public:
    /** Initializing the list */
    Huffman();
    /** Building the Huffman Tree */
    void buildHuffmanTree(std::string text);
    /** See how is the list; Might be useless later, therefore deleted */
    void encode();
    /** See how is the list; Might be useless later, therefore deleted */
    void showList();
};

#endif // HUFFMAN_H
