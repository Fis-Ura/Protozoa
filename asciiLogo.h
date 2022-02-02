#pragma once

#include "Code_Utilities.h"

using namespace std;

//Logo for end of intro
const array<string, 16> logo = { 
"PPPPPPPPPPPPPPPPP   RRRRRRRRRRRRRRRRR        OOOOOOOOO     TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO     ZZZZZZZZZZZZZZZZZZZ     OOOOOOOOO                 AAA               ",
"P::::::::::::::::P  R::::::::::::::::R     OO:::::::::OO   T:::::::::::::::::::::T   OO:::::::::OO   Z:::::::::::::::::Z   OO:::::::::OO              A:::A              ",
"P::::::PPPPPP:::::P R::::::RRRRRR:::::R  OO:::::::::::::OO T:::::::::::::::::::::T OO:::::::::::::OO Z:::::::::::::::::Z OO:::::::::::::OO           A:::::A             ",
"PP:::::P     P:::::PRR:::::R     R:::::RO:::::::OOO:::::::OT:::::TT:::::::TT:::::TO:::::::OOO:::::::OZ:::ZZZZZZZZ:::::Z O:::::::OOO:::::::O         A:::::::A            ",
"  P::::P     P:::::P  R::::R     R:::::RO::::::O   O::::::OTTTTTT  T:::::T  TTTTTTO::::::O   O::::::OZZZZZ     Z:::::Z  O::::::O   O::::::O        A:::::::::A           ",
"  P::::P     P:::::P  R::::R     R:::::RO:::::O     O:::::O        T:::::T        O:::::O     O:::::O        Z:::::Z    O:::::O     O:::::O       A:::::A:::::A          ",
"  P::::PPPPPP:::::P   R::::RRRRRR:::::R O:::::O     O:::::O        T:::::T        O:::::O     O:::::O       Z:::::Z     O:::::O     O:::::O      A:::::A A:::::A         ",
"  P:::::::::::::PP    R:::::::::::::RR  O:::::O     O:::::O        T:::::T        O:::::O     O:::::O      Z:::::Z      O:::::O     O:::::O     A:::::A   A:::::A        ",
"  P::::PPPPPPPPP      R::::RRRRRR:::::R O:::::O     O:::::O        T:::::T        O:::::O     O:::::O     Z:::::Z       O:::::O     O:::::O    A:::::A     A:::::A       ",
"  P::::P              R::::R     R:::::RO:::::O     O:::::O        T:::::T        O:::::O     O:::::O    Z:::::Z        O:::::O     O:::::O   A:::::AAAAAAAAA:::::A      ",
"  P::::P              R::::R     R:::::RO:::::O     O:::::O        T:::::T        O:::::O     O:::::O   Z:::::Z         O:::::O     O:::::O  A:::::::::::::::::::::A     ",
"  P::::P              R::::R     R:::::RO::::::O   O::::::O        T:::::T        O::::::O   O::::::OZZZ:::::Z     ZZZZZO::::::O   O::::::O A:::::AAAAAAAAAAAAA:::::A    ",
"PP::::::PP          RR:::::R     R:::::RO:::::::OOO:::::::O      TT:::::::TT      O:::::::OOO:::::::OZ::::::ZZZZZZZZ:::ZO:::::::OOO:::::::OA:::::A             A:::::A   ",
"P::::::::P          R::::::R     R:::::R OO:::::::::::::OO       T:::::::::T       OO:::::::::::::OO Z:::::::::::::::::Z OO:::::::::::::OOA:::::A               A:::::A  ",
"P::::::::P          R::::::R     R:::::R   OO:::::::::OO         T:::::::::T         OO:::::::::OO   Z:::::::::::::::::Z   OO:::::::::OO A:::::A                 A:::::A ",
"PPPPPPPPPP          RRRRRRRR     RRRRRRR     OOOOOOOOO           TTTTTTTTTTT           OOOOOOOOO     ZZZZZZZZZZZZZZZZZZZ     OOOOOOOOO  AAAAAAA                   AAAAAAA" };

const array<string, 16> logo2 = { 
"PPPPPP PPPPPPPPPP   RRRRR RRRRR RRRRR        OOO OOOOO     TTTTTTTTT TTTTTTTT TTTT     OOOO OOOO     ZZZZZZ ZZZZZ ZZZZZZ     O OO OO O                 AAA               ",
"P: :::::: :::::: P  R:::: ::::::: :::R     OO:::::: ::OO   T ::::::::::: :::: :::T   OO::: :::::OO    : : :: :::::: :::Z    O:: ::::::OO              A ::               ",
"P: :: :PPP PP:::: P R : :::RR RRR:::::R  O ::: ::::   ::OO T:: :  : :::: ::::: ::T OO  ::: :::::::OO   :::: :::  ::: ::Z OO:: : :::: :::OO           A :::               ",
"PP:: ::P     P:::::PRR: : :R     R:::::RO:::: ::OOO:::::::OT::::: T:::::::T :::::TO::::  :OOO::  :::OZ  :  ZZ ZZZ :: :Z O:: ::::O O:::: ::O         A:  ::::A            ",
"  P::: P     P: :::P    :::R     R:::::RO:: :::O   O:::: :OT TTTT  T: :: T  TT TTTO:: :::O   O::::::OZZZZZ     Z:::::Z  O :: : O   O: ::::O         :: :: :::A           ",
"  P::::P     P:::::   R::::R     R: : :RO  :::O     O:::::O        T:  ::T         :::::O     O:: ::         Z: :: Z    O:::::      O: :::O       A:::::A:: ::A          ",
"  P::::PP PPP::: :P   R::::RRRRRR:::::R O::::       O:: ::O        T :  :T         : :: O     O ::::O       Z::: :Z     O : : O     O:: ::        : : :A A: :::          ",
"  P:: :  :::::::PP    R: :::::::::::RR   :::::O     O:::::O        T:::::         O ::::O     O:::::        : :::Z      O  :::      O::: :O     A:::  A      :::A        ",
"  P::::PPPP PPPP      R :  RRRRRR:::::R O: :::O     O : ::O        T:: ::T        O: :::       :: ::O     Z:::::Z       O:::::      O ::::O    A: :::A     A:::: A       ",
"  P::::P               ::::R      :::::RO ::: O     O:::::O        T:::::T          ::  O     O: :::O     : :  Z         :  ::O     O: :::O    :::: A AAA AAA:: ::A      ",
"   ::::P               :: :      R: :::R :: ::O     O: : :          : :::         O:::::O     O:::: O   Z  :::Z         O ::: O     O::: :O   : :::: ::::: ::: : ::A     ",
"  P::::P              R:: :R     R: :::R ::::::O   O::::::O        T:::::T        O    ::O   O: ::::OZZ :: ::Z     ZZ ZZO:: :::O   O::::  O A::::: AA AAAAA AA : :::A    ",
"PP::: ::PP           R:: ::R     R:::::RO:::::::OO ::::: :O      TT:: ::  TT      O:::::::OOO:::::::OZ : ::: ZZZZ ZZ:::Z : :::::OO ::  :::OA::   A             A ::  A   ",
"P::::::::P          R:::: :R      :::::R OO: :::::::: ::OO       T: :::::::T       OO:: :::: ::  :OO Z:: ::: :::: : :: Z OO::: :::::::: OOA: :::A               A ::::A  ",
"P  :: ::            R::: ::R     R:::::    OO: :::::::OO         T:::::::::T         O :: ::::::OO   Z ::: ::::::::::::Z   O :::::: ::OO A ::::A                 A ::::A ",
"PPPPP P PP           RRR RRR     RRR RRR     OOOOOOOOO           TTTTT  TTTT           O OOOO OO     ZZZZ ZZZ ZZ ZZZ ZZZ     O O  OOOO  A  A A                    A A   A" };

const array<string, 16> logo3 = { 
"P  PP P  P PP PP    RRR R RRR RRRRRRR        OOO OO OO     TTTT TT TTTT TTT TT TTT     OOO OOOO      ZZ  Z ZZZZ ZZZ Z ZZ     O OOO O O                 AAA               ",
"P: ::: :: : :: : P  R:::: :: : :  : :R     OO ::::: ::OO     :: :::  ::: : :: : :T   OO::  :: : O     : : :: :  : :  ::Z    O:: : :::  O              A ::               ",
"P: ::  P    P:  : P R :  :: R RRR:  ::R  O ::: : ::   ::OO T:: :  :   :: ::::: ::T OO  : :  : ::::OO   :::  :::  ::: ::Z OO:: :  ::: :  O            A : :               ",
"PP :  :P       :: :PRR: :  R     R::: : O:  :    OO: :::::OT: ::: T:::::::T ::::: O::::  :OOO::  :::OZ  :  ZZ ZZZ :: :Z O::  :::O    :: ::O         A:  ::::             ",
"  P::  P     P: :::P    ::       R ::::  :: :::O   O:::  :OT T TT  T   : T  TT T TO:: :::O   O:: :: OZ   Z     Z:::: Z  O :: : O   O  ::::O         :: ::  : A           ",
"    :::       :::::   R   :R     R: :  RO  :::O      :: ::O         :  ::T         : :::       :   :         Z: :: Z    O::: :       : :::O       A:: :: :: ::           ",
"    : :PP   P ::  P   R:::  RRR  :: ::  O: ::       O:: ::O          :  :T         : :: O     O ::::O        :::  Z       : : O     O:: ::        : : :A A: :::          ",
"  P : :   : ::::PP     :  ::: :::: :RR   :::::O      : :::O        T ::::         O ::::      O: :::        : :::Z      O  :::      O: : :O      :::  A      :::A        ",
"  P::  PPP  PPP R :  RRRRRR : ::R       O:  ::O     O : ::O        T :  :T        O  :::       :: ::O     Z::  :Z       O:::::        ::::O    A: :::A     A:::: A       ",
"  P :::                :: :R      :::::RO  :: O     O ::::O        T: :::T          :   O     O:  ::O     : :  Z         :  ::O      : :::O     ::: A A A AA :: ::A      ",
"   : : P               :: :      R: :::  :: ::      O: : :          :  ::         O:::::O     O::   O   Z  :::Z         O ::  O     O::: :O   : :::: ::::: ::: : : A     ",
"  P   :P              R:   R      :  : R ::  ::O   O :: ::O        T:::::T        O    ::O   O  ::::O Z :: ::Z     ZZ ZZO::  ::    O::::  O  ::: : A   A  A  A : :::A    ",
"P  :: ::PP           R:  ::R     R:: ::RO:::: ::OO ::: : :O      TT:: ::  TT      O  :: ::OO :: : : OZ : ::  ZZ Z ZZ:::Z : :::: OO ::  :::O ::   A             A ::      ",
"P:: : :::P          R : : :       :: ::R OO: : :::::: ::OO        : :::::::T       OO:: :::: ::  :OO Z:: ::: ::::   :: Z O : : :::::::: O A: :::A                 ::::   ",
"P     ::            R  : ::R     R:::::    OO: ::: :::OO         T :: : :: T         O :: : : : OO     ::  ::::: ::::::Z   O :::: : ::OO A : : A                 A :: :  ",
"P P   P  P            RR RR      RR  RR      O OO OOOO           T T T  TT T           O O OO OO     ZZ Z Z Z ZZ Z Z Z Z     O O  OOO   A  A A                          A" };

const array<string, 16> logo4 = { 
"P  P  P  P P  PP    R R R RR  RR R RR        OO  OO OO     TT T TT T TT T T TT T T     O   OO O      Z   Z Z Z  Z Z Z ZZ     O O O O O                 AAA               ",
"P: : :  : :  : :    R : :  : : :  : :R         :: : : O      ::  ::   :  : :: : :T   O ::  :  : O     : : :: :  : :  ::      :: : : :  O              A :                ",
" : ::  P    P:  :   R :  :: R   R:  ::R    ::: :  :   ::     : :  :   :  :::   ::T     : :  : : :  O   ::   ::   : : ::Z  O:: :  : : :                 :                 ",
"PP :  :        :: :  R: :         : : : O:  :     O: : : :  : : :  :  :: :T :: ::  : ::  :  O::  : :O   :   Z  Z  :  :  O :  :::     :  : O         A:  :: :             ",
"  P :  P      : : :P    ::       R : ::  ::   :O   O ::  :O    T   T   : T     T  O:: :::    O : :  O    Z      :::: Z    :  : O   O  :: :          :: ::  : A           ",
"    :::       :  ::   R   :R      : :  R   ::        :: ::          :  ::          : :::       :   :         Z:  : Z    O: : :       : :: O       A:  :  :: :            ",
"    : : P      :  P   R: :  R R  :: ::  O: ::       O : ::           :  :T         :  : O       ::: O        ::   Z       : :       O:  ::        : : :A  : :::          ",
"  P : :   : : :  P     :  ::: : :: : R   : : :O      : :: O        T :: :         O :: :      O: :::        : :::Z      O  :::       : : :O      ::          : :A        ",
"  P :   P   P     :  R R    : ::R       O:  ::      O :  :           :  :         O  :::       :: :        ::  :        O::  :        ::::O    A: : :      A:::          ",
"    :::                 : :       ::: :R   :          :: :O        T: :: T          :   O      :  ::O     : :  Z         :  ::O      : :::O     ::  A   A  A :   :A      ",
"   : : P               :: :      R: :::  :  ::      O: : :          :   :         O::  :       ::   O      :::          O ::         ::: :    :  ::  ::  : : : :         ",
"  P   :               R:   R      :  :   :   :     O :: ::O        T :: :T             ::    O   : :O Z :   :Z      Z ZZ ::  ::    O::::  O  : :   A      A  A :  ::A    ",
"P  :: ::P            R   ::      R : ::R  : : ::   :   :  O      TT : :   T       O  :: :: O :: : :  Z : ::  Z    Z :::  : :: : O  ::  :::O ::   A             A :       ",
"P : : : :P          R : : :       ::  :R O   : : : :: ::O         : :: : ::         O:  :  : ::  :O  Z:: ::  :: :   :: Z O : : ::: :::  O  : : :A                 : ::   ",
"P     :             R  : : R     R: :::      :  :: :: OO         T :: : :: T              : : : O      ::   : :: :: ::     O :: : : ::O  A : :                     :: :  ",
"P     P                R  R      RR  R       O  O O                T T  T  T           O O O  O      Z  Z   Z  Z Z   Z Z       O   O    A    A                          A" };

const array<string, 16> logo5 = { 
"P     P  P     P    R   R R   R  R R         O    O  O      T T T  T  T T    T T       O    O            Z   Z  Z   Z Z      O O   O                   AAA               ",
"P: : :  : :    :    R : :  :   :  : :          :  :   O               :  : :  : :    O :   :    O       :       : :   :      :    : :                 A                  ",
" :  :           :     :     R       :        :    :    :     :    :   :  :       T     :    :   :            :   : : :        :  :   :                 :                 ",
"P  :  :           :   : :         :   :  :  :     O    : :  :   :  :  :      :     :     :         :    :      Z  :  :  O    : :     :  : O         A   :  :             ",
"    :  P      : : :     ::       R :  :  :                                     T   :   :     O   :       Z      :  :      :           :  :           : :   : A           ",
"     ::       :            R      : :      :            :           :  :              :        :   :          :  :       :   :       : :          A   :   : :            ",
"      : P      :       : :              O:  :       O :  :           :             :  : O           O        :            : :       O:   :        : : :   : : :          ",
"  P : :   :   :        :    :    : : R   : :              O        T    :              :       :   :        : :  Z          :        : :  O      :           : :A        ",
"    :       P     :  R        :          :   :      O    :           :  :         O  : :        : :         :  :        O :  :         :       A  : :         :          ",
"    :                   : :       :        :          :               :  T          :   O      :   :      : :            :  ::O      :   :      :   A      A     :A      ",
"   : : P               :  :              :  :          : :          :   :          :            :   O      :              :              :    :  :   :   : : : :         ",
"  P   :                :   R      :  :   :            : :          T :   T             :     O     :    :   :         Z   :  :     O : :  O  : :   A         A :  :      ",
"   :  :              R    :      R   :    :    :   :      O      T    :           O   : :     :   :    :  :         : :  : :  :     :  : :  :                  A :       ",
"P :   :               :   :       :      O   :   : :  :           :  :    :          :  :  : :       Z :  :  :  :   :  Z     : :   :           :                  : :    ",
"      :             R      R      :   :      :   : :   O           :  :                     : :        :    : :  :   :       :  : : :    A : :                      : :  ",
"P                      R             R          O                          T                  O         Z      Z       Z       O   O    A    A                          A" };

const array<string, 16> logo6 = { 
"P        P                R      R                   O      T                  T            O            Z            Z        O                       A                 ",
"     :         :        :           :          :                           :  :      O :                              :      :    :                   A                  ",
" :  :           :     :             :        :    :    :     :           :                                   :       :        :                                          ",
"P  :  :                                                            :  :      :                          :                            :  : O             :                ",
"    :                   :                :                                                       :           :  :                                          : A           ",
"              :                     :      :            :           :  :                           :          :  :       :                                               ",
"      :                                     :                        :             :                                                                 :                   ",
"              :        :    :              :                            :                      :              :             :        : :                                 ",
"    :       P        R                       :           :           :  :                       : :                                    :          : :         :          ",
"                                  :        :          :                                 O          :      : :            :  :                                            ",
"   :                                                   : :          :   :                                                                     :  :                       ",
"      :                :          :      :            :                  T                         :    :                 :                 : :               :  :       ",
"   :                                 :    :        :      O      T    :                       :   :                 :               :  :                         :       ",
"P :                   :   :       :      O   :   :    :                   :                                        :                          :                          ",
"      :                           :   :                            :  :                                :         :   :                                              : :  ",
"P                                                                          T                  O                                         A                                " };