#!/bin/bash
while true; do
echo "============================"
echo " File Operations Menu"
echo "============================"
echo "1. Create a file"
echo "2. Delete a file"
echo "3. Copy a file"
echo "4. List files"
echo "5. Exit"
echo -n "Choose an option [1-5]: "

read choice
case $choice in
1)
echo -n "Enter filename to create: "
read filename
if [ -e "$filename" ]; then
echo "File already exists."
else
touch "$filename" && echo "File created successfully."
fi
;;
2)
echo -n "Enter filename to delete: "
read filename
if [ -e "$filename" ]; then
rm "$filename" && echo "File deleted successfully."
else
echo "File does not exist."
fi
;;
3)
echo -n "Enter source filename: "
read src
echo -n "Enter destination filename: "
read dest
if [ -e "$src" ]; then
cp "$src" "$dest" && echo "File copied successfully."
else
echo "Source file does not exist."
fi
;;
4)
echo "Files in current directory:"
ls -l
;;
5)
echo "Exiting..."
break
;;
*)
echo "Invalid option. Please choose 1–5."
;;
esac
echo
done