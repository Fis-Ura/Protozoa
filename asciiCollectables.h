#include "Code_Utilities.h"

using namespace std;

const array<string,2> BlobASmall = {
    "\x1b[48;5;76m\x1b[38;5;15m/¯\\\x1b[m",
    "\x1b[48;5;76m\x1b[38;5;15m\\_/\x1b[m"
};
//for (int i = 0; i < BlobASmall.size(); ++i)
    //cout << BlobASmall[i];

const array<string,2> BlobBSmall = {
    "\x1b[48;5;76m\x1b[38;5;15m/¯¯\\\x1b[m",
    "\x1b[48;5;76m\x1b[38;5;15m\\__/\x1b[m"};
//for (int i = 0; i < BlobBSmall.size(); ++i)
    //cout << BlobBSmall[i];


const array<string,2> BlobAmedium = {
    "\x1b[48;5;76m\x1b[38;5;15m/¯ö¯ö\\\x1b[m",
    "\x1b[48;5;76m\x1b[38;5;15m\\\x1b[4mo o \x1b[24m/\x1b[m"};
//for (int i = 0; i < BlobAmedium.size(); ++i)
    //cout << BlobAmedium[i];

const array<string,2> BlobBmedium = {
    "\x1b[48;5;76m\x1b[38;5;15m/ö¯ö¯\\\x1b[m",
    "\x1b[48;5;76m\x1b[38;5;15m\\\x1b[4m o o\x1b[24m/\x1b[m"};
//for (int i = 0; i < BlobBmedium.size(); ++i)
        //cout << BlobBmedium[i];