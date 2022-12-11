Script started on Tue 09 May 2006 08:03:01 AM EDT
]0;Student@localhost:~[Student@localhost ~]$ echo --- make script ---
--- make script ---
]0;Student@localhost:~[Student@localhost ~]$ vi HMbackup
[?1049h[?1h=[1;24r[?12;25h[?12l[?25h[27m[m[H[2J[?25l[24;1H"HMbackup" 30L, 412C[1;9H[33mexit
fi

if[m [35m[[[m [33m![m [33m-f[m [35m$1[m [35m]][m
[33mthen[6;9Hecho[m[31m [m[33m"[m[31mNo such file: [m[35m$1[m[33m"
fi

if[m [35m[[[m [33m![m [33m-d[m [35m$[m[43m2[m [35m]][m
[33mthen[11;9Hecho[m[31m [m[33m"[m[31mNo such directory: [m[35m$[m[43m2[m[33m"[12;9Hexit
fi[m

[36mdir[m=[35m$[m[43m2[m
cat [35m$1[m [33m|[m [33mwhile read filename
do[18;9Hif[m [35m[[[m [33m-f[m [35m$filename[m [35m]][m[19;9H[33mthen[m[20;17Hcp [35m$filename[m [35m$dir[m/[35m$filename[m.bak[21;17H[33mecho[m[31m [m[33m"[m[35m$filename[m[31m is backed up to [m[35m$[m[43m2[m[33m"[22;9Hfi
done[m[24;63H30,1[10CBot[23;1H[?12l[?25h[?25l[24;1H[K[24;1H:[?12l[?25hw[?25l[?12l[?25hq[?25l[?12l[?25h[?25l"HMbackup" 30L, 412C written
[?1l>[?12l[?25h[?1049l]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ echo ==[K[K--- praparation for excute[Kion ---
--- praparation for excution ---
]0;Student@localhost:~[Student@localhost ~]$ chmod u+x HMbackup
]0;Student@localhost:~[Student@localhost ~]$ PATH =[K[K=$PATH:.
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ echo --- 1 ---
--- 1 ---
]0;Student@localhost:~[Student@localhost ~]$ HMbackup
Usarge: ./HMbackup [filename of list] [directory]
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ echo --- 2 ---
--- 2 ---
]0;Student@localhost:~[Student@localhost ~]$ echo --- 2 ---[6PHMbackup myscript
Usarge: ./HMbackup [filename of list] [directory]
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ echo --- 3 ---
--- 3 ---
]0;Student@localhost:~[Student@localhost ~]$ echo --- 3 ---HMbackup myscript backupsd s[K[K[K something
Usarge: ./HMbackup [filename of list] [directory]
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ echo --- 4 ---
--- 4 ---
]0;Student@localhost:~[Student@localhost ~]$ echo --- 4 ---HMbackup myscript backups something[Student@localhost ~]$ HMbackup myscript [Student@localhost ~]$ HMbackup myscript b[Student@localhost ~]$ HMbackup myscript ba[Student@localhost ~]$ HMbackup myscript bac[Student@localhost ~]$ HMbackup myscript back[Student@localhost ~]$ HMbackup myscript backu[Student@localhost ~]$ HMbackup myscript backup[Student@localhost ~]$ HMbackup myscript backups[Student@localhost ~]$ HMbackup myscript backups [Student@localhost ~]$ HMbackup myscript backups s[Student@localhost ~]$ HMbackup myscript backups so[Student@localhost ~]$ HMbackup myscript backups som[Student@localhost ~]$ HMbackup myscript backups some[Student@localhost ~]$ HMbackup myscript backups somet[Student@localhost ~]$ HMbackup myscript backups someth[Student@localhost ~]$ HMbackup myscript backups somethi[Student@localhost ~]$ HMbackup myscript backups somethin[Student@localhost ~]$ HMbackup myscript backups something[K[K[K[K[K[K[K[K[K[K[1P backups[1P backups[1P backups[1P backups[1P backups[1P backups[1P backups[1P backupsb backupsa backupsc backupsk backupsu backupsp backupss backups
No such file: backups
cat: backups: Is a directory
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ echo --- 5 ---
--- 5 ---
]0;Student@localhost:~[Student@localhost ~]$ echo --- 5 ---HMbackup backups backups[10Pecho --- 4 ---HMbackup myscript backups something[Student@localhost ~]$ [21Pecho --- 3 ---HMbackup myscript[3Pecho --- 2 ---HMbackup myscript myscript
No such directory: myscript
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ echo --- 6 ---
--- 6 ---
]0;Student@localhost:~[Student@localhost ~]$ ls backups
[00m[m]0;Student@localhost:~[Student@localhost ~]$ HM[K[Kcat myscript
morimoto.11.I
morimoto.11.II
]0;Student@localhost:~[Student@localhost ~]$ HMbackuo[Kp myscript backuop[K[Kps
morimoto.11.I is backed up to backups
morimoto.11.II is backed up to backups
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ ls HMbackup myscript backups[Student@localhost ~]$ [13Pcat myscript[2Pls backups
[00m[00mmorimoto.11.I.bak[00m  [00mmorimoto.11.II.bak[00m
[m]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ echo --- cat command ---
--- cat command ---
]0;Student@localhost:~[Student@localhost ~]$ cat HMbackup
#! /bin/bash
# Script: HMbackup
# purpose: backup a list of files

if (( $# != 2))
then 
	echo "Usarge: $0 [filename of list] [directory]"
	exit
fi

if [[ ! -f $1 ]]
then
	echo "No such file: $1"
fi

if [[ ! -d $2 ]]
then
	echo "No such directory: $2"
	exit
fi

dir=$2
cat $1 | while read filename
do 
	if [[ -f $filename ]]
	then
		cp $filename $dir/$filename.bak
		echo "$filename is backed up to $2"
	fi
done
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ cat myscript
morimoto.11.I
morimoto.11.II
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ ca[K[Kexit

Script done on Tue 09 May 2006 08:06:49 AM EDT
