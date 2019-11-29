#!/bin/bash

# HACK
shopt -s expand_aliases
source ~/.bash_aliases

cd "Build/"
premake5 gmake
cd ..
cd "_project_"
make "$1"
cd ..
