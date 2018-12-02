#!/usr/bin/env python

intervals = { '(' : 1, ')' : -1 }

def paper_and_ribbon(packages):
    area = 0
    ribbon = 0
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

        # ribbon length is the perimeter of the smallest side
        perimeter = 2 * (sides[0] + sides[1])

        # bows require an additional ribbon length equal to the volume
        volume = sides[0] * sides[1] * sides[2]

        ribbon += volume + perimeter

    return (area, ribbon)

if __name__ == "__main__":

    file = open('input')
    packages = file.read().strip()
    file.close()
    (area, ribbon) = paper_and_ribbon(packages)
    print('The elves require {0} square feet of wrapping paper'.format(area) +
          ' and {0} feet of ribbon'.format(ribbon))
