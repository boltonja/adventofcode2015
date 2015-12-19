#!/usr/bin/env python

intervals = { '(' : 1, ')' : -1 }

def traverse(instructions):
    floor = 0
    for c in instructions:
        floor += intervals[c]
    return floor

if __name__ == "__main__":

    file = open('input', encoding='utf-8')
    instructions = file.read().strip()
    file.close()
    floor = traverse(instructions)
    print('The instructions take Santa to floor', floor)
