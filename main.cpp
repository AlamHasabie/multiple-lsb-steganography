#include "bmp/bmp.h"
#include "vigenere/vigenere.h"
#include "stegano/stegano.h"
#include <iostream>
#include <bitset>

using namespace std;


int main(){



    BMPFile file("files/test.bmp");
    BMPFile file_2("files/test.bmp");

    float psnr;

    string a = "hallloween";
    string b = bitset<8>(a[0]).to_string();
    cout << b.substr(0,8);

    // Read headers

    cout << "message = " << file.getMessage() << endl;

    file.hideText("hallloween valentine",2);
    file.unhideText(30,2);


    cout << "message = " << file.getMessage() << endl;

    //cout << file.getContent() << endl;


    //file.write("files/test_output.bmp");
    // string a = "hello";
    // int b = bitset<8>(a[0]).to_ulong();
    // cout << "a = " << a + char(b) << endl;
    // cout << a.substr(2,3) << endl;

    psnr = file.PSNR(file_2);
    cout << "PSNR : " << psnr << endl;

    return 0;
}