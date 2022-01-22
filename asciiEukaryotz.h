#include "Code_Utilities.h"

using namespace std;

//Protagoniste Small version A
const array<string, 11> ProtagAsmall = {
    "\x1b[48;5;0m      \x1b[48;5;76m    \x1b[48;5;0m      \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;0m    \x1b[48;5;76m  \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;0m  \x1b[48;5;76m            \x1b[m\n",
    "\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;13m    \x1b[48;5;76m    \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;0m    \x1b[m\n",
    "\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m      \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;0m  \x1b[48;5;76m      \x1b[48;5;0m  \x1b[48;5;76m    \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;0m    \x1b[48;5;76m  \x1b[48;5;0m      \x1b[48;5;76m  \x1b[m\n",
    "\x1b[48;5;0m      \x1b[48;5;76m    \x1b[48;5;0m      \x1b[m\n" };
		
//Protagoniste Medium Version A 
const array<string, 18> ProtagAmedium = {
    "\x1b[48;5;0m    \x1b[48;5;76m      \x1b[48;5;0m      \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;0m    \x1b[48;5;76m  \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;0m  \x1b[48;5;76m            \x1b[m	\n",
    "\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m	\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m    \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m	\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m	\n",
    "\x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m    \x1b[48;5;0m  \x1b[m	\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m      \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m  \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;0m    \x1b[48;5;76m  \x1b[m\n",
    "\x1b[48;5;0m    \x1b[48;5;76m        \x1b[48;5;0m    \x1b[m	\n",
    "\x1b[48;5;76m        \x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;0m          \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;0m              \x1b[m\n",
    "\x1b[48;5;0m                \x1b[m\n" };
    //for (int i = 0; i < ProtagAmedium.size(); ++i)
        //cout << ProtagAmedium[i];

//Protagoniste Large Version A		
const array<string, 18> ProtagAlarge = {
    "\x1b[48;5;0m      \x1b[48;5;76m    \x1b[48;5;0m                          \x1b[m\n",
    "\x1b[48;5;0m        \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m          \x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;0m    \x1b[m\n",
    "\x1b[48;5;0m          \x1b[48;5;76m      \x1b[48;5;13m      \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m    \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;0m    \x1b[48;5;76m    \x1b[48;5;13m            \x1b[48;5;76m      \x1b[48;5;0m      \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;0m          \x1b[m\n",
    "\x1b[48;5;0m    \x1b[48;5;76m      \x1b[48;5;13m              \x1b[48;5;76m  \x1b[48;5;0m          \x1b[m\n",
    "\x1b[48;5;0m        \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;0m      \x1b[48;5;76m    \x1b[48;5;13m              \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m  \x1b[m\n",
    "\x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;13m                  \x1b[48;5;76m      \x1b[48;5;0m    \x1b[m\n",
    "\x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;13m            \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;0m        \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m        \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m          \x1b[48;5;76m    \x1b[48;5;0m        \x1b[m\n",
    "\x1b[48;5;76m    \x1b[48;5;0m    \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;0m          \x1b[m\n",
    "\x1b[48;5;0m        \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m          \x1b[48;5;76m      \x1b[48;5;0m      \x1b[m\n",
    "\x1b[48;5;0m    \x1b[48;5;76m        \x1b[48;5;13m          \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m    \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m    \x1b[48;5;76m              \x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;0m    \x1b[m\n",
    "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;0m            \x1b[48;5;76m  \x1b[48;5;0m                  \x1b[m\n",
    "\x1b[48;5;0m                \x1b[48;5;76m    \x1b[48;5;0m                \x1b[m\n",
    "\x1b[48;5;0m                  \x1b[48;5;76m    \x1b[48;5;0m              \x1b[m\n" };
    //for (int i = 0; i < ProtagAlarge.size(); ++i)
        //cout << ProtagAlarge[i];