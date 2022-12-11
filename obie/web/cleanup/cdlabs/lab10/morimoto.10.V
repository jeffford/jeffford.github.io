Script started on Thu 04 May 2006 05:23:45 PM EDT
]0;Student@localhost:~[Student@localhost ~]$ echo --- 1 ---
--- 1 ---
]0;Student@localhost:~[Student@localhost ~]$ vi Ch10S5F1
[?1049h[?1h=[1;24r[?12;25h[?12l[?25h[27m[m[H[2J[?25l[24;1H"Ch10S5F1" 10L, 500C[1;1H* This is a line with only one asterisk.
* This is a line that starts with asterisk, *but* has more.*
*** Tgus us a line with three asterisks in a row.
This line has no asterisk.
* This is another line with only one asterisk.
This line has two asterisks * separeted by other characters. *
*** The start and end have three asterisks. ***
This line has towo asterisks with *a* character between them.
*** The start has three, but tge ebd has four asterisks. ****
*The start and end have one asterisk.*
[1m[34m~                                                                               [12;1H~                                                                               [13;1H~                                                                               [14;1H~                                                                               [15;1H~                                                                               [16;1H~                                                                               [17;1H~                                                                               [18;1H~                                                                               [19;1H~                                                                               [20;1H~                                                                               [21;1H~                                                                               [22;1H~                                                                               [23;1H~                                                                               [m[24;63H1,1[11CAll[1;1H[?12l[?25h[?25l[24;1H[K[24;1H:[?12l[?25hw[?25l[?12l[?25hq[?25l[?12l[?25h[?25l"Ch10S5F1" 10L, 500C written
[?1l>[?12l[?25h[?1049l]0;Student@localhost:~[Student@localhost ~]$ echo --- 2 ---
--- 2 ---
]0;Student@localhost:~[Student@localhost ~]$ grep "^\8[^\*[K[K[K[K[K*[^\*]" Ch10S5F1
* This is a line with only one asterisk.
* This is a line that starts with asterisk, *but* has more.*
* This is another line with only one asterisk.
*The start and end have one asterisk.*
]0;Student@localhost:~[Student@localhost ~]$ echo --- 3 ---
--- 3 ---
]0;Student@localhost:~[Student@localhost ~]$ grep '\*[^\*]\*' Ch10S5F1
This line has towo asterisks with *a* character between them.
]0;Student@localhost:~[Student@localhost ~]$ echo --- 4 ---
--- 4 ---
]0;Student@localhost:~[Student@localhost ~]$ grep -v "\9[K(\*\).*\1.*\1.8|1[K[K[K*\1.*\1.*\1.*\1" Ch10S5F1
* This is a line with only one asterisk.
* This is a line that starts with asterisk, *but* has more.*
*** Tgus us a line with three asterisks in a row.
This line has no asterisk.
* This is another line with only one asterisk.
This line has two asterisks * separeted by other characters. *
*** The start and end have three asterisks. ***
This line has towo asterisks with *a* character between them.
*The start and end have one asterisk.*
]0;Student@localhost:~[Student@localhost ~]$ ecjh[K[Kho --- 5 ---
--- 5 ---
]0;Student@localhost:~[Student@localhost ~]$ grep '\(\*\*8[K*\).*[^\*]\1$'^\(\*\**\).*[^\*]\1$'[Student@localhost ~]$ grep '^\[Student@localhost ~]$ grep '^\([Student@localhost ~]$ grep '^\(\[Student@localhost ~]$ grep '^\(\*[Student@localhost ~]$ grep '^\(\*\[Student@localhost ~]$ grep '^\(\*\*[Student@localhost ~]$ grep '^\(\*\**[Student@localhost ~]$ grep '^\(\*\**\[Student@localhost ~]$ grep '^\(\*\**\)[Student@localhost ~]$ grep '^\(\*\**\).[Student@localhost ~]$ grep '^\(\*\**\).*[Student@localhost ~]$ grep '^\(\*\**\).*[[Student@localhost ~]$ grep '^\(\*\**\).*[^[Student@localhost ~]$ grep '^\(\*\**\).*[^\[Student@localhost ~]$ grep '^\(\*\**\).*[^\*[Student@localhost ~]$ grep '^\(\*\**\).*[^\*][Student@localhost ~]$ grep '^\(\*\**\).*[^\*]\[Student@localhost ~]$ grep '^\(\*\**\).*[^\*]\1[Student@localhost ~]$ grep '^\(\*\**\).*[^\*]\1$[Student@localhost ~]$ grep '^\(\*\**\).*[^\*]\1$' Ch10S5F1
* This is a line that starts with asterisk, *but* has more.*
*** The start and end have three asterisks. ***
*The start and end have one asterisk.*
]0;Student@localhost:~[Student@localhost ~]$ exit

Script done on Thu 04 May 2006 05:27:37 PM EDT
Script started on Fri 05 May 2006 08:18:52 AM EDT
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ echo --- add cat commnad to si[K[Kdisplay all[K[K[Kfiles ---
--- add cat commnad to display files ---
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ ca [Kt Ch10S5F1
* This is a line with only one asterisk.
* This is a line that starts with asterisk, *but* has more.*
*** Tgus us a line with three asterisks in a row.
This line has no asterisk.
* This is another line with only one asterisk.
This line has two asterisks * separeted by other characters. *
*** The start and end have three asterisks. ***
This line has towo asterisks with *a* character between them.
*** The start has three, but tge ebd has four asterisks. ****
*The start and end have one asterisk.*
]0;Student@localhost:~[Student@localhost ~]$ 
]0;Student@localhost:~[Student@localhost ~]$ exit

Script done on Fri 05 May 2006 08:19:21 AM EDT
