#include "Code_Utilities.h"

using namespace std;

//Logo for end of intro
	const array<string,16> logo = { R"(PPPPPPPPPPPPPPPPP   RRRRRRRRRRRRRRRRR        OOOOOOOOO     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO     ZZZZZZZZZZZZZZZZZZZ     OOOOOOOOO                 AAA               )",
R"(P::::::::::::::::P  R::::::::::::::::R     OO:::::::::OO   T:::::::::::::::::::::T   OO:::::::::OO   Z:::::::::::::::::Z   OO:::::::::OO              A:::A              )",
R"(P::::::PPPPPP:::::P R::::::RRRRRR:::::R  OO:::::::::::::OO T:::::::::::::::::::::T OO:::::::::::::OO Z:::::::::::::::::Z OO:::::::::::::OO           A:::::A             )",
R"(PP:::::P     P:::::PRR:::::R     R:::::RO:::::::OOO:::::::OT:::::TT:::::::TT:::::TO:::::::OOO:::::::OZ:::ZZZZZZZZ:::::Z O:::::::OOO:::::::O         A:::::::A            )",
R"(  P::::P     P:::::P  R::::R     R:::::RO::::::O   O::::::OTTTTTT  T:::::T  TTTTTTO::::::O   O::::::OZZZZZ     Z:::::Z  O::::::O   O::::::O        A:::::::::A           )",
R"(  P::::P     P:::::P  R::::R     R:::::RO:::::O     O:::::O        T:::::T        O:::::O     O:::::O        Z:::::Z    O:::::O     O:::::O       A:::::A:::::A          )",
R"(  P::::PPPPPP:::::P   R::::RRRRRR:::::R O:::::O     O:::::O        T:::::T        O:::::O     O:::::O       Z:::::Z     O:::::O     O:::::O      A:::::A A:::::A         )",
R"(  P:::::::::::::PP    R:::::::::::::RR  O:::::O     O:::::O        T:::::T        O:::::O     O:::::O      Z:::::Z      O:::::O     O:::::O     A:::::A   A:::::A        )",
R"(  P::::PPPPPPPPP      R::::RRRRRR:::::R O:::::O     O:::::O        T:::::T        O:::::O     O:::::O     Z:::::Z       O:::::O     O:::::O    A:::::A     A:::::A       )",
R"(  P::::P              R::::R     R:::::RO:::::O     O:::::O        T:::::T        O:::::O     O:::::O    Z:::::Z        O:::::O     O:::::O   A:::::AAAAAAAAA:::::A      )",
R"(  P::::P              R::::R     R:::::RO:::::O     O:::::O        T:::::T        O:::::O     O:::::O   Z:::::Z         O:::::O     O:::::O  A:::::::::::::::::::::A     )",
R"(  P::::P              R::::R     R:::::RO::::::O   O::::::O        T:::::T        O::::::O   O::::::OZZZ:::::Z     ZZZZZO::::::O   O::::::O A:::::AAAAAAAAAAAAA:::::A    )",
R"(PP::::::PP          RR:::::R     R:::::RO:::::::OOO:::::::O      TT:::::::TT      O:::::::OOO:::::::OZ::::::ZZZZZZZZ:::ZO:::::::OOO:::::::OA:::::A             A:::::A   )",
R"(P::::::::P          R::::::R     R:::::R OO:::::::::::::OO       T:::::::::T       OO:::::::::::::OO Z:::::::::::::::::Z OO:::::::::::::OOA:::::A               A:::::A  )",
R"(P::::::::P          R::::::R     R:::::R   OO:::::::::OO         T:::::::::T         OO:::::::::OO   Z:::::::::::::::::Z   OO:::::::::OO A:::::A                 A:::::A )",
R"(PPPPPPPPPP          RRRRRRRR     RRRRRRR     OOOOOOOOO           TTTTTTTTTTT           OOOOOOOOO     ZZZZZZZZZZZZZZZZZZZ     OOOOOOOOO  AAAAAAA                   AAAAAAA)" };