Script started on Thu 04 May 2006 04:08:30 PM EDT
]0;Student@localhost:~[Student@localhost ~]$ echo --- 1 ---
--- 1 ---
]0;Student@localhost:~[Student@localhost ~]$ cat > Ch10S1F1
1425	Juan	18	14.25
4321	George	22	21.11
6781	Anne	44	16.77
1451	21.77     Ben	36	1 21.77
2277	Tuan	16	18.77
]0;Student@localhost:~[Student@localhost ~]$ echoi [K[K --- 3[K2 ---
--- 2 ---
]0;Student@localhost:~[Student@localhost ~]$ grep 'Anne' Ch10S1F1 | cut -g[Kf4
16.77
]0;Student@localhost:~[Student@localhost ~]$ echo --- 3 ---
--- 3 ---
]0;Student@localhost:~[Student@localhost ~]$ grep ""`"[1P"1"4"5"1"[Student@localhost ~]$ grep "1451" Ch10S1F1 | cut -f2
Ben
]0;Student@localhost:~[Student@localhost ~]$ echo --- 4 ---
--- 4 ---
]0;Student@localhost:~[Student@localhost ~]$ cut -f2,3 Ch10S1F1 | grep ""{"}"[1P"[1P"["]"["]"0][]"-][]"9][]"[1P][]"[1P][]"[1P][]"2][]"-][]"9][]"[Student@localhost ~]$ cut -f2,3 Ch10S1F1 | grep "[2-9][Student@localhost ~]$ cut -f2,3 Ch10S1F1 | grep "[2-9][0]"-]"9]"
George	22
Anne	44
Ben	36
]0;Student@localhost:~[Student@localhost ~]$ echo --- 5 ---
--- 5 ---
]0;Student@localhost:~[Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep ""["]"["]"."["]"["]"[Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[][]\.[][]"2][]\.[][]"-][]\.[][]"9][]\.[][]"[Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[2-9][Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[2-9][0]\.[][]"-]\.[][]"9]\.[][]"[Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[2-9][0-9][Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[2-9][0-9]\[Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[2-9][0-9]\.[Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[2-9][0-9]\.[0][]"-][]"9][]"[Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[2-9][0-9]\.[0-9][Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[2-9][0-9]\.[0-9][0]"-]"9]"[Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[2-9][0-9]\.[0-9][0-9][Student@localhost ~]$ cut -f1,3,4 Ch10S1F1 | grep "[2-9][0-9]\.[0-9][0-9]" | cu t -f1,2
4321	22
1451	36
]0;Student@localhost:~[Student@localhost ~]$ echo ---6[K 6 ---
--- 6 ---
]0;Student@localhost:~[Student@localhost ~]$ c[Kgrep "'[Student@localhost ~]$ grep "'[K"\"<"["]"["]"0][]"-][]"9][]"[Student@localhost ~]$ grep "\<[0-9][Student@localhost ~]$ grep "\<[0-9][^]" ]"[1P]",]"[1P]".]"0]"-]"9]"[Student@localhost ~]$ grep "\<[0-9][^.0-9][Student@localhost ~]$ grep "\<[0-9][^.0-9]" Ch10S1F1 | cut -f1,2,4[Student@localhost ~]$ grep "\<[[4h[[4l[4h][4l[4h1[4l[4h-[4l[4h9[4l[4h-[4l[4hv[4l[4h [4l[Student@localhost ~]$ grep -v "[Student@localhost ~]$ grep -v "\[Student@localhost ~]$ grep -v "\<[Student@localhost ~]$ grep -v "\<[[Student@localhost ~]$ grep -v "\<[1[Student@localhost ~]$ grep -v "\<[1-[Student@localhost ~]$ grep -v "\<[1-9[Student@localhost ~]$ grep -v "\<[1-9][Student@localhost ~]$ grep -v "\<[1-9][[Student@localhost ~]$ grep -v "\<[1-9][0[Student@localhost ~]$ grep -v "\<[1-9][0-[Student@localhost ~]$ grep -v "\<[1-9][0-9[Student@localhost ~]$ grep -v "\<[1-9][0-9][Student@localhost ~]$ grep -v "\<[1-9][0-9][[Student@localhost ~]$ grep -v "\<[1-9][0-9][^[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9][Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]"[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" [Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" C[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch1[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 [Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 |[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | [Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | c[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | cu[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | cut[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | cut [Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | cut -[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | cut -f[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | cut -f1[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | cut -f1,[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | cut -f1,2[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | cut -f1,2,[Student@localhost ~]$ grep -v "\<[1-9][0-9][^.0-9]" Ch10S1F1 | cut -f1,2,4
]0;Student@localhost:~[Student@localhost ~]$ exit

Script done on Thu 04 May 2006 04:18:22 PM EDT
Script started on Fri 05 May 2006 08:13:48 AM EDT
]0;Student@localhost:~[Student@localhost ~]$ echo --[K[K-- add cat commnad to display files ---
-- add cat commnad to display files ---
]0;Student@localhost:~[Student@localhost ~]$ cat Ch11[K0S1F1
1425	Juan	18	14.25
4321	George	22	21.11
6781	Anne	44	16.77
1451	Ben	36	21.77
2277	Tuan	16	18.77
]0;Student@localhost:~[Student@localhost ~]$ exit

Script done on Fri 05 May 2006 08:14:24 AM EDT
