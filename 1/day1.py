#!/usr/bin/env python
# Advent of code 2015, Day 1
#
# Copyright 2015, 2016, 2017, 2018 by Jillian A. Bolton, All Rights Reserved.
#

intervals = { '(' : 1, ')' : -1 }

def traverse(instructions):
    floor = 0
    i = 0
    baspos = 0

    for c in instructions:
        floor += intervals[c]
        i += 1

        if baspos == 0 and floor < 0:
            baspos = i

    return (floor, baspos)

if __name__ == "__main__":

    file = open('input')
    instructions = file.read().strip()
    file.close()
    (floor, step) = traverse(instructions)
    print('The instructions take Santa to floor', floor, '.  step ', step, ' is when he first enters the basement')
