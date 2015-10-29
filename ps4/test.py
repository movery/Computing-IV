import sys

i = 0

with open (sys.argv[1]) as f:
    for line in f:
        i += int(line[4])

    print i
