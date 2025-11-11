1. List the user commands and redirect the output to /tmp/commands.list

   echo $PATH | tr ':' '\n' | while read dir; do ls "$dir"; done > /tmp/commands.list

2. Edit in your profile to display date at login and change your prompt permanently.

   vim ~/.profile

   date

   export PS1="[\u@\h \W]: "



3. What is the command to count the word in a file or number of file in directory.

   wc -w filename

   ls | wc -l

   a. Count the number of user commands    --->  wc -w /tmp/commands.list     ---->  4075 

4. What happens if you execute:
   a. cat filename1 | cat filename2  ----> filename2 : command not found
   b. ls | rm   --------->  rm: missing operand
   c. ls /etc/passwd | wc –l   ----> wc: –l: No such file or directory

5. Write a command to search for all files on the system that, its name is “.profile”.

   locate  .profile

6. List the inode numbers of /, /etc, /etc/hosts.   -------> ls -ilh / /etc /etc/hosts

7. Create a symbolic link of /etc/passwd in /boot. --> sudo ln -s /etc/passwd /boot/passwd_link

8. Create a hard link of /etc/passwd in /boot. Could you? Why? yes . on the same partition .

9. PS2=": "