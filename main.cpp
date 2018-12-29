#include <iostream>
#include <string>
#include "FileManager.h"
#include "Huffman.h"
#define FILE "test.txt"

using namespace std;

int main()
{
    Huffman huffman;
    string original, encoded, decoded;
    original = readFile((char*)FILE);
    cout << "Original text:\n\n" << original << "\n\n";
    encoded = huffman.encode(original);
    cout << "------------------------------" << "\n\n";
    huffman.showTable();
    cout << "------------------------------" << "\n\n";
    cout << "Encoded text:\n\n";
    cout << encoded << "\n\n";
    cout << "------------------------------" << "\n\n";
    cout << "Decoded text (must be equal to the original):\n\n";
    decoded = huffman.decode(encoded);
    cout << decoded << "\n\n";
}
