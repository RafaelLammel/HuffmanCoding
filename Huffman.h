#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string>

struct charElement{
    char c;
    int freq;
};

struct huffmanList{
    charElement element[100];
    int n;
};

class Huffman{

private:
    huffmanList chs;

public:
    Huffman();
    void buildHuffmanTree(std::string text);
    void showList();
};

#endif // HUFFMAN_H
