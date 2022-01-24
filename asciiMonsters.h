#include "Code_Utilities.h"

using namespace std;

//"\x1b[48;5;234m\x1b[38;5;76m" Color for the background(48) and foreground(38). 

//Monster A Form 1, small no spike
	const array<string,8> monsterAsmall = {
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;9m  \x1b[48;5;11m    \x1b[48;5;9m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;9m  \x1b[48;5;10m  \x1b[48;5;9m    \x1b[48;5;10m  \x1b[48;5;9m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;9m  \x1b[48;5;10m  \x1b[48;5;9m    \x1b[48;5;10m  \x1b[48;5;9m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;9m  \x1b[48;5;11m    \x1b[48;5;9m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n" };
	//for (int i = 0; i < monsterAsmall.size(); ++i)
			//cout << monsterAsmall[i];
	
//Monster A form 2, small WITH spike
	const array<string,8> monsterAbig = {
		"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;11m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;11m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;11m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
		"\x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m  \x1b[48;5;9m    \x1b[48;5;10m  \x1b[48;5;9m  \x1b[48;5;11m  \x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
		"\x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m  \x1b[48;5;9m    \x1b[48;5;10m  \x1b[48;5;9m  \x1b[48;5;11m  \x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;11m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m\n",
		"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;11m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;11m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n" };
	//for (int i = 0; i < monsterAbig.size(); ++i)
           //cout << monsterAbig[i];







