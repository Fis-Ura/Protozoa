﻿#include "Code_Utilities.h"

using namespace std;

//"\x1b[48;5;234m\x1b[38;5;76m" Color for the background(48) and foreground(38). 

//Protagoniste Small version A
const array<string, 11> ProtagAsmall = {
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m......\x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m  \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m            \x1b[m\n",
    "\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;13m    \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n",
    "\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m......\x1b[m\n" };
		
//Protagoniste Medium Version A 
const array<string, 18> ProtagAmedium = {
    "\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m......\x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m  \x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m            \x1b[m	\n",
    "\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m	\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m	\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m	\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m	\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m      \x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m  \x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m        \x1b[48;5;234m\x1b[38;5;76m....\x1b[m	\n",
    "\x1b[48;5;76m        \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..........\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..............\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n" };
    //for (int i = 0; i < ProtagAmedium.size(); ++i)
        //cout << ProtagAmedium[i];

//Protagoniste Large Version A		
const array<string, 18> ProtagAlarge = {
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..........................\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m........\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m          \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..........\x1b[48;5;76m      \x1b[48;5;13m      \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m    \x1b[48;5;13m            \x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m......\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..........\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m      \x1b[48;5;13m              \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..........\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m........\x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m    \x1b[48;5;13m              \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;13m                  \x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;13m            \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m........\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m        \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m          \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m........\x1b[m\n",
    "\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..........\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m........\x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m          \x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m......\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m        \x1b[48;5;13m          \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m              \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m............\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m...................\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m................\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n",
    "\x1b[48;5;234m\x1b[38;5;76m..................\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..............\x1b[m\n" };
    //for (int i = 0; i < ProtagAlarge.size(); ++i)
        //cout << ProtagAlarge[i];

const array<string, 22> Inventory = {
        u8"┌─────────────────┬──────────────────────┬────────────────────┐",
        u8"│                 │                      │                    │",
        u8"│ 1: Evolution Vie│ 2: Evolution Vitesse │ 3: Evolution Force │",
        u8"│     2x Calories │       2x Calories    │     2x Calories    │",
        u8"│                 │                      │                    │",
        u8"├─────────────────┴──────────────────────┴────────────────────┤",
        u8"│                                                             │",
        u8"│   Point de Vie:                                             │",
        u8"│                                                             │",
        u8"│   Point de Force:                                           │",
        u8"│                                                             │",
        u8"│   Point de Vitesse:                                         │",
        u8"│                                                             │",
        u8"│   Calories accumulees:                                      │",
        u8"│                                                             │",
        u8"│   Choisissez votre chemin evolutif                          │",
        u8"│   Appuyez sur 1, 2 ou 3 pour faire votre choix              │",
        u8"│   ou Q pour quitter.                                        │",
        u8"│                                                             │",
        u8"│                                                             │",
        u8"│                                                             │",
        u8"└─────────────────────────────────────────────────────────────┘"};