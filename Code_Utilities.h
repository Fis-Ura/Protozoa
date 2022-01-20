#pragma once
#include <iostream>
#include <string>
#include <array>
#include <time.h>
#include <random>
#include <iomanip> 

using namespace std;

namespace BdB
{
    // Reference: ANSI ESC code convention -> https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

    // CMD
    string ESC = "\x1b[";

    // CURSOR
    string HOME    = "H";
    string UP      = "1A";
    string DOWN    = "1B";
    string RGHT    = "1C";
    string LEFT    = "1D";
    string NEXT_L  = "1E"; // go to beginning of NEXT line
    string PREV_L  = "1F"; // go to beginning of PREVIOUS line

    string SAVE    = "s";  // save current position
    string LOAD    = "u";  // restore last position

    // MODE
    string BOLD    = "1;"; // accentuer -> OK
    string FAINT   = "2;"; // atténuer -> KO
    string ITALC   = "3;"; // -> KO
    string ULINE   = "4;"; // soulign� -> OK
    string BLINK   = "5;"; // -> KO 
    string REVRS   = "7;"; // reverse FGRND/BGRND color -> OK
    string SWTCH   = "8;"; // show/hide -> KO
    string STRKE   = "9;"; // barr� -> KO

    // ERASE
    string ERASE_DWN = "0J\r";   // efface du curseur à la fin de l'écran
    string ERASE_UP  = "1J\r";   // efface du curseur au début de l'écran
    string ERASE_ALL = "2J";
    string ERASE_L   = "2K\r"; // efface toute la ligne

    // COLOR
    string RESET_ALL   = "\x1b[0m";
    string RESET_COLOR = "\x1b[39m";

    // normal text
    string Black       = "30m";
    string Red         = "31m";
    string Green       = "32m";
    string Yellow      = "33m";
    string Blue        = "34m";
    string Magenta     = "35m";
    string Cyan        = "36m";
    string White       = "37m";

    // Light text
    string LBlack      = "90m";
    string LRed        = "91m";
    string LGreen      = "92m";
    string LYellow     = "93m";
    string LBlue       = "94m";
    string LMagenta    = "95m";
    string LCyan       = "96m";
    string LWhite      = "97m";

    // normal BG
    string BG_Black    = "40m";
    string BG_Red      = "41m";
    string BG_Green    = "42m";
    string BG_Yellow   = "43m";
    string BG_Blue     = "44m";
    string BG_Magenta  = "45m";
    string BG_Cyan     = "46m";
    string BG_White    = "47m";

    // Light BG
    string BG_LBlack    = "40;1m";
    string BG_LRed      = "41;1m";
    string BG_LGreen    = "42;1m";
    string BG_LYellow   = "43;1m";
    string BG_LBlue     = "44;1m";
    string BG_LMagenta  = "45;1m";
    string BG_LCyan     = "46;1m";
    string BG_LWhite    = "47;1m";

    // SHORCUT
    string CLS = ESC + ERASE_ALL + ESC + HOME;

    inline void pressToContinue(string s = "")
    {
        if (s == "")
            s = "Appuis sur une touche pour continuer ... ";

#if _WIN32 || _WIN64
        cout << s;
        system("pause >0");
#else
        string cmd = "read -p '" + s + "'";
        system(cmd.c_str());
#endif
    }

    inline default_random_engine& getRand()
    {
        static default_random_engine ran;
        return ran;
    };

    inline void srandInt(int s) { getRand().seed(s); }
    inline int randInt(int min, int max) { return uniform_int_distribution<>{min, max}(getRand()); }
    inline int randInt(int max) { return randInt(0, max); }
}
