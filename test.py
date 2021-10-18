#!/usr/bin/env python3

from argparse import ArgumentParser
from random import shuffle
from os import system

parser = ArgumentParser()
parser.add_argument('length', type=int)
args = parser.parse_args()

numbers = list(range(args.length))
shuffle(numbers)
print(*numbers)

system(f'ARG="{" ".join(map(str, numbers))}"; ./push_swap $ARG | wc -l')
# system(f'ARG="{" ".join(map(str, numbers))}"; ./push_swap $ARG | ./checker $ARG')