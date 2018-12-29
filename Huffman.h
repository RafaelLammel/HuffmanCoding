#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string>
#include <stdlib.h>

struct node
{
    char c;
    int freq;
    node* left;
    node* right;
};

struct huffmanList
{
    node element[128];
    int n;
};

struct tableCoded
{
    char c;
    std::string code;
};

class Huffman
{

private:
    huffmanList chs;
    node *huffmanTree;
    tableCoded table[128];
    int tableN;
    /** Creating the list of appearing characters */
    void createList(std::string text);
    /** Insertion sort the list in decreasing order */
    void sortList();
    /** Building the Huffman Tree */
    void buildHuffmanTree(std::string text);
    /** Creating an internal node */
    node createInternalNode(node right, node left);
    /** Creating the table of codes */
    void tableCode(node* tree, std::string code);
public:
    /** Initializing the list */
    Huffman();
    /** Encoding the text file based on the table built */
    std::string encode(std::string text);
    /** Decoding the text file based on the table built */
    std::string decode(std::string encodedText);
    /** Showing the table with the codes */
    void showTable();
};

#endif // HUFFMAN_H
