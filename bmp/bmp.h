#ifndef _BMP_H_
#define _BMP_H_


#include <string>

using namespace std;




struct BMPFileHeader{

    string type;
    unsigned int fileSize;
    unsigned int dataOffset;
    unsigned int reserved;
    
};

struct BMPInfoHeader {


    unsigned int imageSize;
    unsigned int compression;
    unsigned int XPixelsPerM;
    unsigned int YPixelsPerM;
    unsigned int infoHeaderSize;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bpp ; // bits per pixel
    unsigned int colorUsed;
    unsigned int importantColors;




    // pixel data

};

class BMPFile {

    private :

        // For now color table will NOT be implemented
        BMPFileHeader fileHeader;
        BMPInfoHeader infoHeader;
        char* content;
        char** colorTable;

    public :
        
        BMPFile(string filename);
        unsigned int getImageSize();
        string getType();
        char* getContent();	
		void setContent(int idx, char c);


        // Function to write file out
        void write(string filename);




};


#endif
