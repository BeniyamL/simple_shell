# simple_shell project

## Description

This project is designed to write a simple UNIX command interpreter. The project covers all topics that we have learnt in low level programming. The project is mainly developed using C programming language.
---
## Requirements:

   * Allowed editors: vi, vim, emacs
   * All your files will be compiled on Ubuntu 14.04 LTS
   * Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
   * All your files should end with a new line
   * A README.md file, at the root of the folder of the project is mandatory
   * Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
   * Your shell should not have any memory leaks
   * No more than 5 functions per file
   * All your header files should be include guarded
   * Use system calls only when you need to
   * There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score
---

## List of allowed functions and system calls

  * access (man 2 access)
  * chdir (man 2 chdir)
  * close (man 2 close)
  * closedir (man 3 closedir)
  * execve (man 2 execve)
  * exit (man 3 exit)
  * _exit (man 2 _exit)
  * fflush (man 3 fflush)
  * fork (man 2 fork)
  * free (man 3 free)
  * getcwd (man 3 getcwd)
  * getline (man 3 getline)
  * getpid (man 2 getpid)
  * isatty (man 3 isatty)
  * kill (man 2 kill)
  * malloc (man 3 malloc)
  * open (man 2 open)
  * opendir (man 3 opendir)
  * perror (man 3 perror)
  * read (man 2 read)
  * readdir (man 3 readdir)
  * signal (man 2 signal)
  * stat (__xstat) (man 2 stat)
  * lstat (__lxstat) (man 2 lstat)
  * fstat (__fxstat) (man 2 fstat)
  * strtok (man 3 strtok)
  * wait (man 2 wait)
  * waitpid (man 2 waitpid)
  * wait3 (man 2 wait3)
  * wait4 (man 2 wait4)
  * write (man 2 write)

---

## How the project works

  * First it displays a prompt: `./hsh` and wait the user to write a command
  * The project accepts the user input, analyze it and display the correct out put the user
  * if the user command is not correct or if some errors occurs, it will display an error message
  * It will then display a prompt to accept another command from the user

---

## Usage

  * Compile all created source code .c along with ``` holnerton.h ``` using gcc -Wall -Werror -Wextra -pedantic *.c
  * launch the executable file using ./hsh

---
## Available commands

| commands | Description |
---  | --- |
ls   | used to list all files and directories in the current workind directory
pwd  | shows the current working directory
which| locate a command
cd   | used to change the directory
exit | used to exit the shel
env  | used to show the current environment
---

## Examples

``` ls ```:
```
./hsh$ ls
AUTHORS  func8.c	 hi	      man_1_simple_shell
func2.c  func_execute.c  holberton.h  README.md
func4.c  func_split.c	 hsh	      str_helpers.c
func6.c  get_builtin.c	 main.c       variable_rplcmt.c
./hsh$ 


```

---

``` ls -l ```:
```
./hsh$ ls -l
total 84
-rw-rw-r-- 1 beniyaml beniyaml   215 Apr 15 07:38 AUTHORS
-rw-rw-r-- 1 beniyaml beniyaml  2486 Apr 20 05:16 func2.c
-rw-rw-r-- 1 beniyaml beniyaml  2304 Apr 20 05:25 func4.c
-rw-rw-r-- 1 beniyaml beniyaml  1382 Apr 15 07:38 func6.c
-rw-rw-r-- 1 beniyaml beniyaml  1695 Apr 15 07:38 func8.c
-rw-rw-r-- 1 beniyaml beniyaml  3417 Apr 20 05:30 func_execute.c
-rw-rw-r-- 1 beniyaml beniyaml  2562 Apr 19 08:12 func_split.c
-rw-rw-r-- 1 beniyaml beniyaml  3154 Apr 19 08:14 get_builtin.c
drwxrwxr-x 2 beniyaml beniyaml  4096 Apr 15 07:38 hi
-rw-rw-r-- 1 beniyaml beniyaml  2919 Apr 20 05:26 holberton.h
-rwxrwxr-x 1 beniyaml beniyaml 23872 Apr 20 05:31 hsh
-rw-rw-r-- 1 beniyaml beniyaml  3122 Apr 15 07:38 main.c
-rw-rw-r-- 1 beniyaml beniyaml  1975 Apr 15 07:38 man_1_simple_shell
-rw-rw-r-- 1 beniyaml beniyaml  3229 Apr 15 07:38 README.md
-rw-rw-r-- 1 beniyaml beniyaml  1706 Apr 15 07:38 str_helpers.c
-rw-rw-r-- 1 beniyaml beniyaml  2346 Apr 15 07:38 variable_rplcmt.c
./hsh$ 


```
---

```exit ```:
```
./hsh$ exit 98
exit
==5191== 
==5191== HEAP SUMMARY:
==5191==     in use at exit: 0 bytes in 0 blocks
==5191==   total heap usage: 85 allocs, 85 frees, 4,245 bytes allocated
==5191== 
==5191== All heap blocks were freed -- no leaks are possible
==5191== 
==5191== For counts of detected and suppressed errors, rerun with: -v
==5191== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
beniyaml@ubuntu:~/ALX/simple_shell$ 


```
---

```env ```:
```
./hsh$ env
XDG_VTNR=7
XDG_SESSION_ID=c2
CLUTTER_IM_MODULE=xim
XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/beniyaml
SESSION=ubuntu
GPG_AGENT_INFO=/home/beniyaml/.gnupg/S.gpg-agent:0:1
TERM=xterm-256color
SHELL=/bin/bash
XDG_MENU_PREFIX=gnome-
VTE_VERSION=4205
QT_LINUX_ACCESSIBILITY_ALWAYS_ON=1
WINDOWID=52428894
UPSTART_SESSION=unix:abstract=/com/ubuntu/upstart-session/1000/1785
GNOME_KEYRING_CONTROL=
GTK_MODULES=gail:atk-bridge:unity-gtk-module
USER=beniyaml
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
QT_ACCESSIBILITY=1
XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
SESSION_MANAGER=local/ubuntu:@/tmp/.ICE-unix/2016,unix/ubuntu:/tmp/.ICE-unix/2016
DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/usr/share/upstart/xdg:/etc/xdg
PATH=/home/beniyaml/bin:/home/beniyaml/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DESKTOP_SESSION=ubuntu
QT_IM_MODULE=ibus
QT_QPA_PLATFORMTHEME=appmenu-qt5
XDG_SESSION_TYPE=x11
JOB=dbus
PWD=/home/beniyaml/ALX/simple_shell
XMODIFIERS=@im=ibus
GNOME_KEYRING_PID=
LANG=en_US.UTF-8
GDM_LANG=en_US
MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
IM_CONFIG_PHASE=1
COMPIZ_CONFIG_PROFILE=ubuntu
GDMSESSION=ubuntu
SESSIONTYPE=gnome-session
GTK2_MODULES=overlay-scrollbar
XDG_SEAT=seat0
HOME=/home/beniyaml
SHLVL=1
LANGUAGE=en_US
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
XDG_SESSION_DESKTOP=ubuntu
LOGNAME=beniyaml
QT4_IM_MODULE=xim
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/usr/local/share:/usr/share:/var/lib/snapd/desktop:/var/lib/snapd/desktop
DBUS_SESSION_BUS_ADDRESS=unix:abstract=/tmp/dbus-g2mpTIY4wb
LESSOPEN=| /usr/bin/lesspipe %s
INSTANCE=
XDG_RUNTIME_DIR=/run/user/1000
DISPLAY=:0
XDG_CURRENT_DESKTOP=Unity
GTK_IM_MODULE=ibus
LESSCLOSE=/usr/bin/lesspipe %s %s
XAUTHORITY=/home/beniyaml/.Xauthority
OLDPWD=/home/beniyaml
_=./hsh
./hsh$ 


```
---

## Authors
* **Bereket Abera** - [bereket5042] from github account https://github.com/bereket5042
* **Beniyam Legesse** - [beniyaml] from github account  https://github.com/beniyaml
