#Write a Bash script that checks IF the .bashrc file exists in the user's home
#directory. If it does, append new environment variables to the file: one called
#HELLO with the value of HOSTNAME, and another local variable called LOCAL
#with the value of the whoami command. Additionally, the script should include a
#command to open another terminal at the end

#!/bin/bash
BASHRC="$HOME/.bashrc"
if [ -f "$BASHRC" ]; then
    echo "export HELLO=\$HOSTNAME" >> "$BASHRC"
    echo "LOCAL=\$(whoami)" >> "$BASHRC"
    echo "New environment variables added to $BASHRC"
else
    echo "$BASHRC does not exist."
fi
# Open a new terminal
gnome-terminal &  # For GNOME Terminal; change as needed for other terminal emulators
