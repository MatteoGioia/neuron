# Solution to nebula challenges

### Level 02

The program makes use of the variable `$USER` fetched from the shell environment and passes it to a `system()` call without sanitizing the input first. 

Simply changing the username with something like `export USER = something && bash_code` allows to execute wathever code you want after the `&&` with superuser rights, i.e. a script in `/tmp` that gives you access to a shell.

### Level 03