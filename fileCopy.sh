#!/bin/bash

echo "Enter Folder Name: "
read folderName

mkdir -p "$folderName"

echo "Enter fileName: "
read fileName

if mv "$fileName" "$folderName/"; then
echo "File is moved"
else 
echo "File is not moved"
fi



