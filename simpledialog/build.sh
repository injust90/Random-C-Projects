#!/bin/sh
# set -ex
# gcc main.c -Wall -Wextra -lraylib

#!/bin/sh
set -ex
cc -o game main.c -lraylib -pthread
