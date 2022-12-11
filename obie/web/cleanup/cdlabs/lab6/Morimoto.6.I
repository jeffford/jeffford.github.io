Script started on Thu 27 Apr 2006 04:34:31 PM EDT
]0;Student@localhost:~[Student@localhost ~]$ cat Ch6S1F1>Ch6S1F1 Ch6S1F1
12 425	Ja uan	14.3 25
4321	George	21.11
6781	Anna	16.77
1451	Ben	21.77
2277	Tuan	18.77
]0;Student@localhost:~[Student@localhost ~]$ cat Ch6S1F1
1425	Juan	14.25
4321	George	21.11
6781	Anna	16.77
1451	Ben	21.77
2277	Tuan	18.77
]0;Student@localhost:~[Student@localhost ~]$ cat Ch6S1F1[Kvi Ch6S1F1
[?1049h[?1h=[1;24r[?12;25h[?12l[?25h[27m[m[H[2J[?25l[24;1H"Ch6S1F1" 5L, 81C[1;1H1425    Juan    14.25
4321    George  21.11
6781    Anna    16.77
1451    Ben     21.77
2277    Tuan    18.77
[1m[34m~                                                                               [7;1H~                                                                               [8;1H~                                                                               [9;1H~                                                                               [10;1H~                                                                               [11;1H~                                                                               [12;1H~                                                                               [13;1H~                                                                               [14;1H~                                                                               [15;1H~                                                                               [16;1H~                                                                               [17;1H~                                                                               [18;1H~                                                                               [19;1H~                                                                               [20;1H~                                                                               [21;1H~                                                                               [22;1H~                                                                               [23;1H~                                                                               [m[24;63H2,1[11CAll[2;1H[?12l[?25h[?25l[24;1H[K[24;1H:[?12l[?25hw[?25l[?12l[?25hq[?25l[?12l[?25h[?25l"Ch6S1F1" 5L, 81C written
[?1l>[?12l[?25h[?1049l]0;Student@localhost:~[Student@localhost ~]$ sort -k1 Ch6S1F1 example
1425	Juan	14.25
1451	Ben	21.77
2277	Tuan	18.77
4321	George	21.11
6781	Anna	16.77
]0;Student@localhost:~[Student@localhost ~]$ sort -k1 Ch6S1F1 example > [K[K[K[Ksort -k1 Ch6S1F1 > example
]0;Student@localhost:~[Student@localhost ~]$ sort -k1 Ch6S1F1 > example[Student@localhost ~]$ [Kcp example Ch6S1F1
]0;Student@localhost:~[Student@localhost ~]$ paste Ch6S1F1 Ch6S1F1 | cut -f1,3,5 > example
]0;Student@localhost:~[Student@localhost ~]$ cp example Ch6S1F1
]0;Student@localhost:~[Student@localhost ~]$ cat Ch6S1F1
1425	14.25	Juan
1451	21.77	Ben
2277	18.77	Tuan
4321	21.11	George
6781	16.77	Anna
]0;Student@localhost:~[Student@localhost ~]$ exit

Script done on Thu 27 Apr 2006 04:38:16 PM EDT
