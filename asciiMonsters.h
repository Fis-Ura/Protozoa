#include "Code_Utilities.h"

using namespace std;

array<string, 50> monsters = { R"()" };



//Monster A Form 1, small no spike
	const string monsterAsmall = 
		"\x1b[48;5;0m                \x1b[m\n"
		"\x1b[48;5;0m    \x1b[48;5;9m  \x1b[48;5;11m    \x1b[48;5;9m  \x1b[48;5;0m    \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;9m  \x1b[48;5;10m  \x1b[48;5;9m    \x1b[48;5;10m  \x1b[48;5;9m  \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;9m  \x1b[48;5;10m  \x1b[48;5;9m    \x1b[48;5;10m  \x1b[48;5;9m  \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;0m    \x1b[48;5;9m  \x1b[48;5;11m    \x1b[48;5;9m  \x1b[48;5;0m    \x1b[m\n"
		"\x1b[48;5;0m                \x1b[m\n";
	
//Monster A form 2, small WITH spike
	const string monsterAbig =
		"\x1b[48;5;0m    \x1b[48;5;11m  \x1b[48;5;0m    \x1b[48;5;11m  \x1b[48;5;0m    \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;11m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m  \x1b[48;5;9m    \x1b[48;5;10m  \x1b[48;5;9m  \x1b[48;5;11m  \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;10m  \x1b[48;5;9m    \x1b[48;5;10m  \x1b[48;5;9m  \x1b[48;5;11m  \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;11m  \x1b[48;5;9m  \x1b[48;5;11m    \x1b[48;5;9m  \x1b[48;5;11m  \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;0m    \x1b[48;5;11m  \x1b[48;5;0m    \x1b[48;5;11m  \x1b[48;5;0m    \x1b[m\n";







