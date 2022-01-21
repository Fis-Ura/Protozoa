#include "Code_Utilities.h"

using namespace std;

array<string, 2> blob = { R"(/\)", R"(\/)"};


const array<string,2> BlobASmall = {
    u8"\x1b[48;5;76m\x1b[38;5;15m/‾\\\x1b[m\n",
    u8"\x1b[48;5;76m\x1b[38;5;15m\\_/\x1b[m\n"
};
//cout << BlobASmall;

const string BlobBSmall =
    u8"\x1b[48;5;76m\x1b[38;5;15m/‾‾\\\x1b[m\n"
    u8"\x1b[48;5;76m\x1b[38;5;15m\\__/\x1b[m\n";
//cout << BlobBSmall;

const string BlobAmedium =
    u8"\x1b[48;5;76m\x1b[38;5;15m/‾Ō‾Ō\\\x1b[m\n"
    u8"\x1b[48;5;76m\x1b[38;5;15m\\\x1b[4mO O \x1b[24m/\x1b[m\n";
//cout << BlobAmedium;

const string BlobBmedium =
    u8"\x1b[48;5;76m\x1b[38;5;15m/Ō‾Ō‾\\\x1b[m\n"
    u8"\x1b[48;5;76m\x1b[38;5;15m\\\x1b[4m O O\x1b[24m/\x1b[m\n";
//cout << BlobBmedium;