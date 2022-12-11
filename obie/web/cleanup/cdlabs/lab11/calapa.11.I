Script started on Tue 09 May 2006 08:06:28 AM EDT
]0;Student@localhost:~[Student@localhost ~]$ exit./ncbackup file1 backups[13Pvi ncbackup./ncbackup file1 backups[2P[Student@localhost ~]$ ncbackup file1 backups[4Pchmod 755 ncbackupncbackup file1 backups[4h./[4l[Student@localhost ~]$ ./ncbackup file1 backups[13Pvi ncbackup./ncbackup file1 backupsexit[K[Kmore Ch11s1f1
John  Adams   55
George Bull 77
Anne Blue   99
Janet  Blue 67
Ben Benjamin    78
Ted White 32
]0;Student@localhost:~[Student@localhost ~]$ more Ch11s1f1exit[K./ncbackup file1 backups[13Pvi ncbackup./ncbackup file1 backupsexit[Kmore Ch11s1f1[Ksed 's/\(^[A-Za-s][K[Kz]*\)[ ]*\([A-Za][K-z]*\)[ ]*\([0-9][0-9]\)/ \2, \1 \1/' Ch11s1f1
Adams, John John
Bull, George George
Blue, Anne Anne
Blue, Janet Janet
Benjamin, Ben Ben
White, Ted Ted
]0;Student@localhost:~[Student@localhost ~]$ sed 's/\(^[A-Za-z]*\)[ ]*\([A-Za-z]*\)[ ]*\([0-9][0-9]\)/\\2, \1 \1/' Ch11s1f1[1P[4h3[4l
Adams, John 55
Bull, George 77
Blue, Anne 99
Blue, Janet 67
Benjamin, Ben 78
White, Ted 32
]0;Student@localhost:~[Student@localhost ~]$ sort -f1,3 Ch[K[Ked 's/\(^[A-Za-z]*\)[ ]*\([A-Za-z]*\)[ ]*\([0-9][0-9]\)/\\2, \1 \3/' Ch11s1f1\2, \1 \1\2, \1 \1/' Ch11s1f1\2, \1 \3\2, \1 \3/' Ch11s1f1[A[Student@localhost ~]$ sort -f1,3 [K
[K[A[Student@localhost ~]$ sort -f1,3 [K[K[K[K[K[K[K[K[K[K[Ksed 's/\(^[A-Za-z]*\)[ ]*\([A-Za-z]*\)[ ]*\([0-9][0-9]\)/\\2, \1 \3/' Ch11s1f1 .[K> temp
]0;Student@localhost:~[Student@localhost ~]$ more temp
Adams, John 55
Bull, George 77
Blue, Anne 99
Blue, Janet 67
Benjamin, Ben 78
White, Ted 32
]0;Student@localhost:~[Student@localhost ~]$ temp[K[K[K[Ksort -f1,3 temp > Ch11s1f1
sort: invalid option -- 1
Try `sort --help' for more information.
]0;Student@localhost:~[Student@localhost ~]$ sort -f1,3 temp > Ch11s1f1[1P[1P[4h+[4l
sort: open failed: +1,3: No such file or directory
]0;Student@localhost:~[Student@localhost ~]$ sort +1,3 temp > Ch11s1f1[1P[4h-[4l[4hf[4l[Student@localhost ~]$ sort -f1[1P[1P[1P[4h2[4l[Student@localhost ~]$ sort -f2 [Student@localhost ~]$ sort -f2 t[Student@localhost ~]$ sort -f2 te[Student@localhost ~]$ sort -f2 tem[Student@localhost ~]$ sort -f2 temp[Student@localhost ~]$ sort -f2 temp [1P Ch11s1f1[1PCh11s1f1[1Ph11s1f1[1P11s1f1[Student@localhost ~]$ sort -f2 temp 1[1Ps1f1[1Ps1f1[1P1f1[1Pf1[1P1[K
sort: invalid option -- 2
Try `sort --help' for more information.
]0;Student@localhost:~[Student@localhost ~]$ sort -f2 temp [Student@localhost ~]$ sort -f2[1P[4h1[4l[4h,[4l[4h3[4l[1P[1P[4h+[4l[Student@localhost ~]$ sort +1[1P[4h [4l[4h-[4l
Blue, Anne 99
Benjamin, Ben 78
Bull, George 77
Blue, Janet 67
Adams, John 55
White, Ted 32
]0;Student@localhost:~[Student@localhost ~]$ sort +1 -3 temp [1P[4h-[4l[Student@localhost ~]$ sort -1[Student@localhost ~]$ sort -1 [1P[4h+[4l
sort: invalid option -- 1
Try `sort --help' for more information.
]0;Student@localhost:~[Student@localhost ~]$ sort -1 +3 temp [1P[4h+[4l[Student@localhost ~]$ sort +1[Student@localhost ~]$ sort +1 [1P[4h-[4l[Student@localhost ~]$ sort +[1P[4h0[4l
Adams, John 55
Benjamin, Ben 78
Blue, Anne 99
Blue, Janet 67
Bull, George 77
White, Ted 32
]0;Student@localhost:~[Student@localhost ~]$ sort +0 -3 temp [1P[4h2[4l[1P[4h-[4l
Adams, John 55
Benjamin, Ben 78
Blue, Anne 99
Blue, Janet 67
Bull, George 77
White, Ted 32
]0;Student@localhost:~[Student@localhost ~]$ sort +0 -2 temp [1P[4h+[4l[1P[4h-[4l[Student@localhost ~]$ sort +0 -2[4h-[4l[4hn[4l[4hr[4l[4h [4l
White, Ted 32
Bull, George 77
Blue, Janet 67
Blue, Anne 99
Benjamin, Ben 78
Adams, John 55
]0;Student@localhost:~[Student@localhost ~]$ exit
exit

Script done on Tue 09 May 2006 08:14:45 AM EDT
