#include <iostream>
#include <string>
#include "FileManager.h"
#include "Huffman.h"
#define FILE "test.txt"

using namespace std;

int main()
{
    Huffman huffman;
    string text;
    text = readFile((char*)FILE);
    huffman.buildHuffmanTree(text);
    huffman.showList();
}
