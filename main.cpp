#include "bmp/bmp.h"
#include "vigenere/vigenere.h"
#include "stegano/stegano.h"
#include <iostream>
#include <bitset>

using namespace std;


int main(){


    BMPFile file("files/test_output.bmp");

    // Read headers
    cout << file.getImageSize() <<endl;

    cout << "message = " << file.getMessage() << endl;

    file.hideText("hello",3);
    file.unhideText(1000,3);
    
    cout << "message = " << file.getMessage() << endl;

    //cout << file.getContent() << endl;

    //file.write("files/test_output.bmp");
    // string a = "hello";
    // int b = bitset<8>(a[0]).to_ulong();
    // cout << "a = " << a + char(b) << endl;
    // cout << a.substr(2,3) << endl;
    return 0;
}