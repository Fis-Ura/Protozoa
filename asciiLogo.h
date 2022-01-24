#include "Code_Utilities.h"

using namespace std;

//Logo for end of intro
const array<string, 16> logo = { 
R"(PPPPPPPPPPPPPPPPP   RRRRRRRRRRRRRRRRR        OOOOOOOOO     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO     ZZZZZZZZZZZZZZZZZZZ     OOOOOOOOO                 AAA               )",
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

const array<string, 16> logo2 = { 
R"(PPPPPP PPPPPPPPPP   RRRRR RRRRR RRRRR        OOO OOOOO     TTTTTTTTT TTTTTTTT TTTT     OOOO OOOO     ZZZZZZ ZZZZZ ZZZZZZ     O OO OO O                 AAA               )",
R"(P: :::::: :::::: P  R:::: ::::::: :::R     OO:::::: ::OO   T ::::::::::: :::: :::T   OO::: :::::OO    : : :: :::::: :::Z    O:: ::::::OO              A ::               )",
R"(P: :: :PPP PP:::: P R : :::RR RRR:::::R  O ::: ::::   ::OO T:: :  : :::: ::::: ::T OO  ::: :::::::OO   :::: :::  ::: ::Z OO:: : :::: :::OO           A :::               )",
R"(PP:: ::P     P:::::PRR: : :R     R:::::RO:::: ::OOO:::::::OT::::: T:::::::T :::::TO::::  :OOO::  :::OZ  :  ZZ ZZZ :: :Z O:: ::::O O:::: ::O         A:  ::::A            )",
R"(  P::: P     P: :::P    :::R     R:::::RO:: :::O   O:::: :OT TTTT  T: :: T  TT TTTO:: :::O   O::::::OZZZZZ     Z:::::Z  O :: : O   O: ::::O         :: :: :::A           )",
R"(  P::::P     P:::::   R::::R     R: : :RO  :::O     O:::::O        T:  ::T         :::::O     O:: ::         Z: :: Z    O:::::      O: :::O       A:::::A:: ::A          )",
R"(  P::::PP PPP::: :P   R::::RRRRRR:::::R O::::       O:: ::O        T :  :T         : :: O     O ::::O       Z::: :Z     O : : O     O:: ::        : : :A A: :::          )",
R"(  P:: :  :::::::PP    R: :::::::::::RR   :::::O     O:::::O        T:::::         O ::::O     O:::::        : :::Z      O  :::      O::: :O     A:::  A      :::A        )",
R"(  P::::PPPP PPPP      R :  RRRRRR:::::R O: :::O     O : ::O        T:: ::T        O: :::       :: ::O     Z:::::Z       O:::::      O ::::O    A: :::A     A:::: A       )",
R"(  P::::P               ::::R      :::::RO ::: O     O:::::O        T:::::T          ::  O     O: :::O     : :  Z         :  ::O     O: :::O    :::: A AAA AAA:: ::A      )",
R"(   ::::P               :: :      R: :::R :: ::O     O: : :          : :::         O:::::O     O:::: O   Z  :::Z         O ::: O     O::: :O   : :::: ::::: ::: : ::A     )",
R"(  P::::P              R:: :R     R: :::R ::::::O   O::::::O        T:::::T        O    ::O   O: ::::OZZ :: ::Z     ZZ ZZO:: :::O   O::::  O A::::: AA AAAAA AA : :::A    )",
R"(PP::: ::PP           R:: ::R     R:::::RO:::::::OO ::::: :O      TT:: ::  TT      O:::::::OOO:::::::OZ : ::: ZZZZ ZZ:::Z : :::::OO ::  :::OA::   A             A ::  A   )",
R"(P::::::::P          R:::: :R      :::::R OO: :::::::: ::OO       T: :::::::T       OO:: :::: ::  :OO Z:: ::: :::: : :: Z OO::: :::::::: OOA: :::A               A ::::A  )",
R"(P  :: ::            R::: ::R     R:::::    OO: :::::::OO         T:::::::::T         O :: ::::::OO   Z ::: ::::::::::::Z   O :::::: ::OO A ::::A                 A ::::A )",
R"(PPPPP P PP           RRR RRR     RRR RRR     OOOOOOOOO           TTTTT  TTTT           O OOOO OO     ZZZZ ZZZ ZZ ZZZ ZZZ     O O  OOOO  A  A A                    A A   A)" };

const array<string, 16> logo3 = { 
R"(P  PP P  P PP PP    RRR R RRR RRRRRRR        OOO OO OO     TTTT TT TTTT TTT TT TTT     OOO OOOO      ZZ  Z ZZZZ ZZZ Z ZZ     O OOO O O                 AAA               )",
R"(P: ::: :: : :: : P  R:::: :: : :  : :R     OO ::::: ::OO     :: :::  ::: : :: : :T   OO::  :: : O     : : :: :  : :  ::Z    O:: : :::  O              A ::               )",
R"(P: ::  P    P:  : P R :  :: R RRR:  ::R  O ::: : ::   ::OO T:: :  :   :: ::::: ::T OO  : :  : ::::OO   :::  :::  ::: ::Z OO:: :  ::: :  O            A : :               )",
R"(PP :  :P       :: :PRR: :  R     R::: : O:  :    OO: :::::OT: ::: T:::::::T ::::: O::::  :OOO::  :::OZ  :  ZZ ZZZ :: :Z O::  :::O    :: ::O         A:  ::::             )",
R"(  P::  P     P: :::P    ::       R ::::  :: :::O   O:::  :OT T TT  T   : T  TT T TO:: :::O   O:: :: OZ   Z     Z:::: Z  O :: : O   O  ::::O         :: ::  : A           )",
R"(    :::       :::::   R   :R     R: :  RO  :::O      :: ::O         :  ::T         : :::       :   :         Z: :: Z    O::: :       : :::O       A:: :: :: ::           )",
R"(    : :PP   P ::  P   R:::  RRR  :: ::  O: ::       O:: ::O          :  :T         : :: O     O ::::O        :::  Z       : : O     O:: ::        : : :A A: :::          )",
R"(  P : :   : ::::PP     :  ::: :::: :RR   :::::O      : :::O        T ::::         O ::::      O: :::        : :::Z      O  :::      O: : :O      :::  A      :::A        )",
R"(  P::  PPP  PPP R :  RRRRRR : ::R       O:  ::O     O : ::O        T :  :T        O  :::       :: ::O     Z::  :Z       O:::::        ::::O    A: :::A     A:::: A       )",
R"(  P :::                :: :R      :::::RO  :: O     O ::::O        T: :::T          :   O     O:  ::O     : :  Z         :  ::O      : :::O     ::: A A A AA :: ::A      )",
R"(   : : P               :: :      R: :::  :: ::      O: : :          :  ::         O:::::O     O::   O   Z  :::Z         O ::  O     O::: :O   : :::: ::::: ::: : : A     )",
R"(  P   :P              R:   R      :  : R ::  ::O   O :: ::O        T:::::T        O    ::O   O  ::::O Z :: ::Z     ZZ ZZO::  ::    O::::  O  ::: : A   A  A  A : :::A    )",
R"(P  :: ::PP           R:  ::R     R:: ::RO:::: ::OO ::: : :O      TT:: ::  TT      O  :: ::OO :: : : OZ : ::  ZZ Z ZZ:::Z : :::: OO ::  :::O ::   A             A ::      )",
R"(P:: : :::P          R : : :       :: ::R OO: : :::::: ::OO        : :::::::T       OO:: :::: ::  :OO Z:: ::: ::::   :: Z O : : :::::::: O A: :::A                 ::::   )",
R"(P     ::            R  : ::R     R:::::    OO: ::: :::OO         T :: : :: T         O :: : : : OO     ::  ::::: ::::::Z   O :::: : ::OO A : : A                 A :: :  )",
R"(P P   P  P            RR RR      RR  RR      O OO OOOO           T T T  TT T           O O OO OO     ZZ Z Z Z ZZ Z Z Z Z     O O  OOO   A  A A                          A)" };

const array<string, 16> logo4 = { 
R"(P  P  P  P P  PP    R R R RR  RR R RR        OO  OO OO     TT T TT T TT T T TT T T     O   OO O      Z   Z Z Z  Z Z Z ZZ     O O O O O                 AAA               )",
R"(P: : :  : :  : :    R : :  : : :  : :R         :: : : O      ::  ::   :  : :: : :T   O ::  :  : O     : : :: :  : :  ::      :: : : :  O              A :                )",
R"( : ::  P    P:  :   R :  :: R   R:  ::R    ::: :  :   ::     : :  :   :  :::   ::T     : :  : : :  O   ::   ::   : : ::Z  O:: :  : : :                 :                 )",
R"(PP :  :        :: :  R: :         : : : O:  :     O: : : :  : : :  :  :: :T :: ::  : ::  :  O::  : :O   :   Z  Z  :  :  O :  :::     :  : O         A:  :: :             )",
R"(  P :  P      : : :P    ::       R : ::  ::   :O   O ::  :O    T   T   : T     T  O:: :::    O : :  O    Z      :::: Z    :  : O   O  :: :          :: ::  : A           )",
R"(    :::       :  ::   R   :R      : :  R   ::        :: ::          :  ::          : :::       :   :         Z:  : Z    O: : :       : :: O       A:  :  :: :            )",
R"(    : : P      :  P   R: :  R R  :: ::  O: ::       O : ::           :  :T         :  : O       ::: O        ::   Z       : :       O:  ::        : : :A  : :::          )",
R"(  P : :   : : :  P     :  ::: : :: : R   : : :O      : :: O        T :: :         O :: :      O: :::        : :::Z      O  :::       : : :O      ::          : :A        )",
R"(  P :   P   P     :  R R    : ::R       O:  ::      O :  :           :  :         O  :::       :: :        ::  :        O::  :        ::::O    A: : :      A:::          )",
R"(    :::                 : :       ::: :R   :          :: :O        T: :: T          :   O      :  ::O     : :  Z         :  ::O      : :::O     ::  A   A  A :   :A      )",
R"(   : : P               :: :      R: :::  :  ::      O: : :          :   :         O::  :       ::   O      :::          O ::         ::: :    :  ::  ::  : : : :         )",
R"(  P   :               R:   R      :  :   :   :     O :: ::O        T :: :T             ::    O   : :O Z :   :Z      Z ZZ ::  ::    O::::  O  : :   A      A  A :  ::A    )",
R"(P  :: ::P            R   ::      R : ::R  : : ::   :   :  O      TT : :   T       O  :: :: O :: : :  Z : ::  Z    Z :::  : :: : O  ::  :::O ::   A             A :       )",
R"(P : : : :P          R : : :       ::  :R O   : : : :: ::O         : :: : ::         O:  :  : ::  :O  Z:: ::  :: :   :: Z O : : ::: :::  O  : : :A                 : ::   )",
R"(P     :             R  : : R     R: :::      :  :: :: OO         T :: : :: T              : : : O      ::   : :: :: ::     O :: : : ::O  A : :                     :: :  )",
R"(P     P                R  R      RR  R       O  O O                T T  T  T           O O O  O      Z  Z   Z  Z Z   Z Z       O   O    A    A                          A)" };

const array<string, 16> logo5 = { 
R"(P     P  P     P    R   R R   R  R R         O    O  O      T T T  T  T T    T T       O    O            Z   Z  Z   Z Z      O O   O                   AAA               )",
R"(P: : :  : :    :    R : :  :   :  : :          :  :   O               :  : :  : :    O :   :    O       :       : :   :      :    : :                 A                  )",
R"( :  :           :     :     R       :        :    :    :     :    :   :  :       T     :    :   :            :   : : :        :  :   :                 :                 )",
R"(P  :  :           :   : :         :   :  :  :     O    : :  :   :  :  :      :     :     :         :    :      Z  :  :  O    : :     :  : O         A   :  :             )",
R"(    :  P      : : :     ::       R :  :  :                                     T   :   :     O   :       Z      :  :      :           :  :           : :   : A           )",
R"(     ::       :            R      : :      :            :           :  :              :        :   :          :  :       :   :       : :          A   :   : :            )",
R"(      : P      :       : :              O:  :       O :  :           :             :  : O           O        :            : :       O:   :        : : :   : : :          )",
R"(  P : :   :   :        :    :    : : R   : :              O        T    :              :       :   :        : :  Z          :        : :  O      :           : :A        )",
R"(    :       P     :  R        :          :   :      O    :           :  :         O  : :        : :         :  :        O :  :         :       A  : :         :          )",
R"(    :                   : :       :        :          :               :  T          :   O      :   :      : :            :  ::O      :   :      :   A      A     :A      )",
R"(   : : P               :  :              :  :          : :          :   :          :            :   O      :              :              :    :  :   :   : : : :         )",
R"(  P   :                :   R      :  :   :            : :          T :   T             :     O     :    :   :         Z   :  :     O : :  O  : :   A         A :  :      )",
R"(   :  :              R    :      R   :    :    :   :      O      T    :           O   : :     :   :    :  :         : :  : :  :     :  : :  :                  A :       )",
R"(P :   :               :   :       :      O   :   : :  :           :  :    :          :  :  : :       Z :  :  :  :   :  Z     : :   :           :                  : :    )",
R"(      :             R      R      :   :      :   : :   O           :  :                     : :        :    : :  :   :       :  : : :    A : :                      : :  )",
R"(P                      R             R          O                          T                  O         Z      Z       Z       O   O    A    A                          A)" };

const array<string, 16> logo6 = { 
R"(P        P                R      R                   O      T                  T            O            Z            Z        O                       A                 )",
R"(     :         :        :           :          :                           :  :      O :                              :      :    :                   A                  )",
R"( :  :           :     :             :        :    :    :     :           :                                   :       :        :                                          )",
R"(P  :  :                                                            :  :      :                          :                            :  : O             :                )",
R"(    :                   :                :                                                       :           :  :                                          : A           )",
R"(              :                     :      :            :           :  :                           :          :  :       :                                               )",
R"(      :                                     :                        :             :                                                                 :                   )",
R"(              :        :    :              :                            :                      :              :             :        : :                                 )",
R"(    :       P        R                       :           :           :  :                       : :                                    :          : :         :          )",
R"(                                  :        :          :                                 O          :      : :            :  :                                            )",
R"(   :                                                   : :          :   :                                                                     :  :                       )",
R"(      :                :          :      :            :                  T                         :    :                 :                 : :               :  :       )",
R"(   :                                 :    :        :      O      T    :                       :   :                 :               :  :                         :       )",
R"(P :                   :   :       :      O   :   :    :                   :                                        :                          :                          )",
R"(      :                           :   :                            :  :                                :         :   :                                              : :  )",
R"(P                                                                          T                  O                                         A                                )" };