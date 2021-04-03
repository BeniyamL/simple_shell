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

  * First it displays a prompt: `$` and wait the user to write a command
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
write sample example for ls here

```

---

``` ls -l ```:
```
write sample example for ls -l here

```
---

```exit ```:
```
write sample example for exit here

```
---

```env ```:
```
write sample example for env here

```
---

## Authors
* **Bereket Abera** - [bereket5042] from github account https://github.com/bereket5042
* **Beniyam Legesse** - [beniyaml] from github account  https://github.com/beniyaml
