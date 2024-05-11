#!/bin/bash

set -euo pipefail

gcc -c -g main.c -o main.o
gcc -no-pie -o linkbomb"$1" main.o phase"$1".o

