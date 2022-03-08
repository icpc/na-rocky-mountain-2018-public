import random, sys, math

caseno = dict()

PROBID = "treasurespotting"

MAXL = 1000
MAXQ = 1000
MAXC = 1000000000

def on_line(p, w):
    d1 = (w[0]-p[0], w[1]-p[1])
    d2 = (w[2]-p[0], w[3]-p[1])

    return d1[0]*d2[1] == d1[1]*d2[0] and d1[0]*d2[0]+d1[1]*d2[1] <= 0


# The first argument is a short string describing the "type" of data
# (eg. sample, hand, random), the rest have the test case data.
#
# This will generate the file in the data directory, putting type "sample" in
# sample and the rest in secret.
#
# Subsequent calls with the same type will increase the number following the
# type. Example: consecutive calls with type=="random" will create files
# PROBID-random-01.in, PROBID-random-02.in, ... in ../data/secret
def genfile(tp, treasure, walls, people):
    global caseno

    caseno[tp] = caseno.get(tp, 0)+1

    #path = "."
    if tp == "sample":
        filename = "../data/sample/{0}.in".format(caseno[tp])
    else:
        filename = "../data/secret/{0}-{1}-{2:02d}.in".format(PROBID, tp, caseno[tp])

    outfile = open(filename, "w")

    #####################################################
    # validate data, raise an error if bad
    #

    def check_int(x, lo, hi):
        if type(x) != int or x < lo or x > hi:
            raise ValueError("Bad int", x, lo, hi)

    def check_tuple(p):
        if type(p) != tuple or len(p) != 4 or p[:2] == p[2:]:
            raise ValueError("Bad point", p)
        for x in p: check_int(x, -MAXC, MAXC)

    # check that data is of the proper type and range
    if type(treasure) != tuple or len(treasure) != 2:
        raise ValueError("Bad treasure", treasure)
    for x in treasure: check_int(x, -MAXC, MAXC)

    if type(walls) != list or type(people) != list:
        raise ValueError("Bad lists")

    check_int(len(walls), 0, MAXL)
    for x in walls: check_tuple(x)

    check_int(len(people), 1, MAXQ)
    for x in people:
        check_tuple(x)
        if x[:2] == treasure:
            raise("On treasure", x, treasure)

    if len(people) != len(set(people)):
        raise ValueError("Duplicate points")

    for w in walls:
        for p in people:
            if on_line(p, w):
                raise ValueError("On Wall", w, p)

    #
    # end data validation
    #####################################################


    #####################################################
    # output test case with print(..., file=outfile) here
    #

    print(len(walls), len(people), file=outfile)
    print(*treasure, file=outfile)
    for x in walls: print(*x, file=outfile)
    for x in people: print(*x, file=outfile)

    #
    # end of test case output
    #####################################################

    outfile.close()

    print("Generated", filename)

def gensample():
    treasure = (2, 3)
    walls = [(1, 2, 2, 0), (0, 0, 3, 1)]
    people = [(0, 1, 3, 4), (5, 0, 5, 5), (2, 6, 2, 5)]

    genfile("sample", treasure, walls, people)

    treasure = (0, 0)
    walls = []
    people = [(1, 0, 1, 1), (3, 0, -4, 0), (-2, 0, -5, 0)]

    genfile("sample", treasure, walls, people)

def genhand():
    treasure = (0, 0)
    walls = []
    people = [(1, 0, 0, 0), (3, 4, -2, 4), (4, 4, -1, 4), (-1, 0, -1, 1)]
    genfile("hand", treasure, walls, people)

    treasure = (MAXC, MAXC)
    walls = []
    people = [(-MAXC, -MAXC, MAXC, MAXC), (-MAXC+1, -MAXC, MAXC-1, MAXC),
              (MAXC, -MAXC, -MAXC+1, -MAXC), (-MAXC, MAXC, -MAXC, -MAXC)]
    genfile("hand", treasure, walls, people)

    treasure = (MAXC, MAXC)
    walls = [(-MAXC, -MAXC+1, MAXC-1, MAXC), (-MAXC+1, -MAXC, MAXC, MAXC-1)]
    people = [(-MAXC, -MAXC, MAXC, MAXC)]
    genfile("hand", treasure, walls, people)

    treasure = (MAXC, MAXC)
    walls = []
    people = [(-MAXC, -MAXC, MAXC, MAXC), (0, 1, 0, 0)]
    genfile("hand", treasure, walls, people)

    treasure = (MAXC, MAXC)
    walls = [(-MAXC+1, -MAXC+1, MAXC-1, MAXC-1)]
    people = [(-MAXC, -MAXC, MAXC, MAXC)]
    genfile("hand", treasure, walls, people)

    treasure = (MAXC, MAXC)
    walls = [(-1, -1, 1, 1)]
    people = [(-MAXC, -MAXC, MAXC, MAXC), (0, 1, MAXC, MAXC), (1, 0, MAXC, MAXC),
              (0, -1, MAXC, MAXC), (-1, 0, MAXC, MAXC),
              (1, -1, MAXC, MAXC), (-1, 1, MAXC, MAXC),
              (-MAXC+1, -MAXC, MAXC, MAXC), (-MAXC, -MAXC+1, MAXC, MAXC),
              (-MAXC, MAXC, MAXC, MAXC), (MAXC, -MAXC, MAXC, MAXC)]
    genfile("hand", treasure, walls, people)

    treasure = (MAXC, MAXC)
    walls = []
    people = [(0, 1, 0, 0), (-MAXC, -MAXC, MAXC, MAXC)]
    genfile("hand", treasure, walls, people)

    treasure = (MAXC, MAXC-1)
    walls = [(MAXC-1, MAXC, MAXC-1, MAXC-1)]
    people = [(-MAXC, MAXC-1, MAXC, MAXC-1), (-MAXC, MAXC-2, MAXC, MAXC-1)]
    genfile("hand", treasure, walls, people)

    treasure = (MAXC, 0)
    walls = [(0, 1, 0, -1)]
    people = [(-MAXC, i, MAXC, 0) for i in range(-2, 3)]
    genfile("hand", treasure, walls, people)

    treasure = (MAXC//2 + 1534, MAXC//2 - 8713)
    walls = []
    people = []
    for i in range(-16, 16):
        for j in range(-16, 16):
            if i != 0 and j != 0:
                people.append((treasure[0]+i, treasure[1]+j, treasure[0], treasure[1]))
    genfile("hand", treasure, walls, people)

def randloc(rng):
    return tuple(random.randint(-rng, rng) for _ in range(2))

def randwall(len):
    step = (0, 0)
    while step == (0, 0):
        start, step = randloc(MAXC-len), randloc(len)
    return start + tuple(start[i]+step[i] for i in range(2))

def scatter(treasure, walls, num_ppl):
    people = []
    pts = set([treasure])

    while len(people) < num_ppl:
        pt = randloc(MAXC)+randloc(MAXC)
        if pt[:2] == pt[2:]: continue
        if pt[:2] in pts: continue

        ok = True
        for w in walls:
            if on_line(pt, w):
                ok = False
                break
        if ok:
            people.append(pt)
            pts.add(pt[:2])

    return people

def genrandom():
    # no walls
    walls = []
    treasure = randloc(MAXC//3)
    people = scatter(treasure, walls, MAXQ)
    genfile("random", treasure, walls, people)

    walls = [randwall(MAXC//10) for _ in range(MAXL)]
    treasure = (0, 0)
    people = scatter(treasure, walls, MAXQ)
    genfile("random", treasure, walls, people)

    walls = [randwall(MAXC//100) for _ in range(MAXL)]
    treasure = (0, 0)
    people = scatter(treasure, walls, MAXQ)
    genfile("random", treasure, walls, people)

    walls = [randwall(MAXC) for _ in range(MAXL)]
    treasure = (0, 0)
    people = scatter(treasure, walls, MAXQ)
    genfile("random", treasure, walls, people)

    walls = [randwall(2*MAXC//3) for _ in range(5)]
    treasure = (0, 0)
    people = scatter(treasure, walls, MAXQ)
    genfile("random", treasure, walls, people)

if __name__ == "__main__":
    random.seed(0)

    gensample()
    genhand()
    genrandom()

    print("Done!")
