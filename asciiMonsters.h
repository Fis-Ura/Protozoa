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

//Monster A dying 
    const array<string, 8> monsterAdyingA = {
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;94m  \x1b[48;5;172m    \x1b[48;5;94m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;208m  \x1b[48;5;76m    \x1b[48;5;208m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;172m  \x1b[48;5;106m    \x1b[48;5;172m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;1m  \x1b[48;5;214m    \x1b[48;5;1m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n" };
    //for (int i = 0; i < monsterAdyingA.size(); ++i)
        //cout << monsterAdyingA[i];


    //Monster A dying 2
    const array<string, 8> monsterAdyingB = {
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;94m    \x1b[48;5;234m\x1b[38;5;76m......\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;94m  \x1b[48;5;100m    \x1b[48;5;94m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;94m  \x1b[48;5;100m    \x1b[48;5;94m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;94m    \x1b[48;5;234m\x1b[38;5;76m......\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n" };
    //for (int i = 0; i < monsterAdyingB.size(); ++i)
        //cout << monsterAdyingB[i];

    //Monster A dying 3
    const array<string, 8> monsterAdyingC = {
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m.......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m.......\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n"
		"\x1b[48;5;234m\x1b[38;5;76m................\x1b[m\n" };
    //for (int i = 0; i < monsterAdyingC.size(); ++i)
        //cout << monsterAdyingC[i];



