#include "bmp/bmp.h"
#include "vigenere/vigenere.h"
#include "stegano/stegano.h"
#include <iostream>
#include <bitset>
#include <string>

using namespace std;


int main(){

    // BMPFile file("files/test.bmp");
    // BMPFile file_2("files/test.bmp");

    // float psnr;

    // string a = "hallloween";
    // string b = bitset<8>(a[0]).to_string();
    // cout << b.substr(0,8);

    // // Read headers

    // cout << "message = " << file.getMessage() << endl;

    // file.hideText("hallloween valentine",3);
    // cout << "infiltration 2" << endl;
    // file.unhideText(30,3);


    // cout << "message = " << file.getMessage() << endl;

    // //cout << file.getContent() << endl;


    // //file.write("files/test_output.bmp");
    // // string a = "hello";
    // // int b = bitset<8>(a[0]).to_ulong();
    // // cout << "a = " << a + char(b) << endl;
    // // cout << a.substr(2,3) << endl;

    // psnr = file.PSNR(file_2);
    // cout << "PSNR : " << psnr << endl;

    int stop = 0;

    while (stop = 0){
        string plainteks;
        string use_cipher;
        string key;
        int n_lsb;
        cout << "Welcome to tHE StEGANO" << endl;
        cout << "Teks to hide :";
        cin >> plainteks;
        // image file to hide
        BMPFile file("files/test.bmp");
        cout << "Enkripsi (y/n)? ";
        cin >> use_cipher;
        if (use_cipher == "y") {
            cout << "Kunci = ";
            cin >> key;
            //enkripsi
        };
        cout << "Bit LSB =";
        cin >> n_lsb;
        // hiding text in image
        file.hideText(plainteks,n_lsb);
        // output
        file.write("files/test_output.bmp");

        cout << "Continue? (y/n) ";
        cin >> stop;
    }


    return 0;
}