#!/usr/bin/env python

intervals = { '(' : 1, ')' : -1 }

def area_with_margin(packages):
    area = 0
    for dimensions in packages.splitlines():
        # a robust application might validate the number of sides
        # it might also handle floating point
        sides = [int(d) for d in dimensions.split('x')]
        sides.sort()

        # the elves requires the sa of the package + a margin equal to the
        # smallest side. if a and b are the smallest dimensions, and c is
        # largest, the formula is ab + 2(ab + ac + bc) which simplifies
        # to 3ab + 2(ac + bc)
        area += 3 * sides[0] * sides[1] + 2 * (sides[0] * sides[2] + sides[1] * sides[2])

    return area

if __name__ == "__main__":

    file = open('input', encoding='utf-8')
    packages = file.read().strip()
    file.close()
    area = area_with_margin(packages)
    print('The elves require {0} square feet of wrapping paper'.format(area))
