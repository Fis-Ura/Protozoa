#include "Code_Utilities.h"

using namespace std;

array<string, 50> eukaryotz = { R"(xxxxxxxxxxxxxxxxxx
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xoooooooooooooooox
xxxxxxxxxxxxxxxxxx)" };

//Protagoniste Small version A
	const string ProtagAsmall =
		"\x1b[48;5;0m      \x1b[48;5;76m    \x1b[48;5;0m      \x1b[m\n"
		"\x1b[48;5;76m  \x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;0m    \x1b[48;5;76m  \x1b[m\n"
		"\x1b[48;5;76m  \x1b[48;5;0m  \x1b[48;5;76m            \x1b[m\n"
		"\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;13m    \x1b[48;5;76m    \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;0m    \x1b[m\n"
		"\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m      \x1b[48;5;0m  \x1b[m\n"
		"\x1b[48;5;76m  \x1b[48;5;0m  \x1b[48;5;76m      \x1b[48;5;0m  \x1b[48;5;76m    \x1b[m\n"
		"\x1b[48;5;76m  \x1b[48;5;0m    \x1b[48;5;76m  \x1b[48;5;0m      \x1b[48;5;76m  \x1b[m\n"
		"\x1b[48;5;0m      \x1b[48;5;76m    \x1b[48;5;0m      \x1b[m\n";
		
//Protagoniste Medium Version A 
	const string ProtagAmedium =
        "\x1b[48;5;0m    \x1b[48;5;76m      \x1b[48;5;0m      \x1b[m\n"
        "\x1b[48;5;76m  \x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;0m    \x1b[48;5;76m  \x1b[m\n"
        "\x1b[48;5;76m  \x1b[48;5;0m  \x1b[48;5;76m            \x1b[m	\n"
        "\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n"
        "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m	\n"
        "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m    \x1b[48;5;0m  \x1b[m\n"
        "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m	\n"
        "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m	\n"
        "\x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n"
        "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m    \x1b[48;5;0m  \x1b[m	\n"
        "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m      \x1b[m\n"
        "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m  \x1b[m\n"
        "\x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;0m    \x1b[48;5;76m  \x1b[m\n"
        "\x1b[48;5;0m    \x1b[48;5;76m        \x1b[48;5;0m    \x1b[m	\n"
        "\x1b[48;5;76m        \x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m  \x1b[m\n"
        "\x1b[48;5;76m  \x1b[48;5;0m          \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n"
        "\x1b[48;5;76m  \x1b[48;5;0m              \x1b[m\n"
        "\x1b[48;5;0m                \x1b[m\n";

//Protagoniste Large Version A		
	const string ProtagAlarge =
        "\x1b[48;5;0m      \x1b[48;5;76m    \x1b[48;5;0m                          \x1b[m\n"
        "\x1b[48;5;0m        \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m          \x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;0m    \x1b[m\n"
        "\x1b[48;5;0m          \x1b[48;5;76m      \x1b[48;5;13m      \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m    \x1b[m\n"
        "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;0m    \x1b[48;5;76m    \x1b[48;5;13m            \x1b[48;5;76m      \x1b[48;5;0m      \x1b[m\n"
        "\x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;0m          \x1b[m\n"
        "\x1b[48;5;0m    \x1b[48;5;76m      \x1b[48;5;13m              \x1b[48;5;76m  \x1b[48;5;0m          \x1b[m\n"
        "\x1b[48;5;0m        \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;0m  \x1b[m\n"
        "\x1b[48;5;0m      \x1b[48;5;76m    \x1b[48;5;13m              \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m  \x1b[m\n"
        "\x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;13m                  \x1b[48;5;76m      \x1b[48;5;0m    \x1b[m\n"
        "\x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;13m            \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;0m        \x1b[m\n"
        "\x1b[48;5;0m  \x1b[48;5;76m        \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m          \x1b[48;5;76m    \x1b[48;5;0m        \x1b[m\n"
        "\x1b[48;5;76m    \x1b[48;5;0m    \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;0m          \x1b[m\n"
        "\x1b[48;5;0m        \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m          \x1b[48;5;76m      \x1b[48;5;0m      \x1b[m\n"
        "\x1b[48;5;0m    \x1b[48;5;76m        \x1b[48;5;13m          \x1b[48;5;76m    \x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m    \x1b[m\n"
        "\x1b[48;5;0m  \x1b[48;5;76m    \x1b[48;5;0m    \x1b[48;5;76m              \x1b[48;5;0m      \x1b[48;5;76m  \x1b[48;5;0m    \x1b[m\n"
        "\x1b[48;5;0m  \x1b[48;5;76m  \x1b[48;5;0m            \x1b[48;5;76m  \x1b[48;5;0m                  \x1b[m\n"
        "\x1b[48;5;0m                \x1b[48;5;76m    \x1b[48;5;0m                \x1b[m\n"
        "\x1b[48;5;0m                  \x1b[48;5;76m    \x1b[48;5;0m              \x1b[m\n";