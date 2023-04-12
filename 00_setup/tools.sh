#!/usr/bin/bash

# Download needed programs from package manager
sudo apt install build-essential gdb git wget clang clangd clang-format;

# Get the latest release of bazelisk since package manager versions can be out of date
wget 'https://github.com/bazelbuild/bazelisk/releases/download/v1.16.0/bazelisk-linux-amd64';

# Make the Home/bin dir and copy bazelisk
mkdir $HOME/bin;
mv ./bazelisk-linux-amd64 $HOME/bin/bazelisk;

# Make sure bazelisk is executable
chmod +x $HOME/bin/bazelisk;

# Add to path
echo "" >> $HOME/.bashrc;
echo "# Adding /bin in home directory to PATH" >> $HOME/.bashrc;
echo 'export PATH=$PATH:$HOME/bin' >> $HOME/.bashrc;
source $HOME/.bashrc;

