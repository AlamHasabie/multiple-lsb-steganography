#include "bmp.h"

#include <iostream>

#include <fstream>


void getShort(unsigned short& num, ifstream& fstream);
void getInt(unsigned int& num, ifstream& fstream);


BMPFile::BMPFile(string filename) {


    this->fileHeader.type =  "";

    ifstream fstream(filename , ios::in | ios::binary);

    this->fileHeader.type.push_back(fstream.get());
    this->fileHeader.type.push_back(fstream.get());

    getInt(this->fileHeader.fileSize,fstream);

    // Offset reserved values
    fstream.seekg(4,fstream.cur);

    getInt(this->fileHeader.dataOffset, fstream);
    getInt(this->infoHeader.infoHeaderSize,fstream);
    getInt(this->infoHeader.width,fstream);
    getInt(this->infoHeader.height,fstream);
    getShort(this->infoHeader.planes,fstream);
    getShort(this->infoHeader.bpp,fstream);
    getInt(this->infoHeader.compression,fstream);
    getInt(this->infoHeader.imageSize,fstream);
    if ((this->infoHeader.imageSize==0)&&(this->infoHeader.compression==0)){
        this->infoHeader.imageSize = this->infoHeader.width * this->infoHeader.height;
    }
    getInt(this->infoHeader.XPixelsPerM, fstream);
    getInt(this->infoHeader.YPixelsPerM,fstream);
    getInt(this->infoHeader.colorUsed, fstream);
    if(this->infoHeader.colorUsed==0){
        this->infoHeader.colorUsed = 2<<(this->infoHeader.bpp);
    }
    getInt(this->infoHeader.importantColors,fstream);
    if(this->infoHeader.importantColors==0){
        this->infoHeader.importantColors = this->infoHeader.colorUsed;
    }


    if(this->infoHeader.bpp<=8){
        // Get color table
        this->colorTable = new char*[this->infoHeader.colorUsed];
        for (int idx = 0 ; idx < this->infoHeader.colorUsed ; idx++){
            this->colorTable[idx] = new char[4];
            for (int c = 0 ; c < 4; c++){
                this->colorTable[idx][c] = fstream.get();
            }
        }

    }


    fstream.seekg(this->fileHeader.dataOffset,fstream.beg);
    this->content = new char[this->infoHeader.imageSize];

    for (int byte = 0; byte < this->infoHeader.imageSize ; byte++){
        this->content[byte] = fstream.get();
    }

    if(fstream.eof()){
        cout << "done !" << endl;
    }
}


// Little endians short and ints

void getShort(unsigned short& num, ifstream& fstream){
    num = 0;
    for (short byte = 0 ; byte < 2 ; byte++){
        num += fstream.get() << (8 * byte);
    }

}
void getInt(unsigned int& num, ifstream& fstream){
    num = 0;
    for (short byte = 0 ; byte < 4 ; byte++){
        num += fstream.get() << (8 * byte);
    }
}