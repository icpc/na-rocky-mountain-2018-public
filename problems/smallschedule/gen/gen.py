import random, sys, math

caseno = dict()

PROBID = "smallschedule"

MAXQ = 1000
MAXL = MAXS = MAXM = 1000000

# The first argument is a short string describing the "type" of data
# (eg. sample, hand, random), the rest have the test case data.
#
# This will generate the file in the data directory, putting type "sample" in
# sample and the rest in secret.
#
# Subsequent calls with the same type will increase the number following the
# type. Example: consecutive calls with type=="random" will create files
# PROBID-random-01.in, PROBID-random-02.in, ... in ../data/secret
def genfile(tp, Q, M, S, L):
    global caseno

    caseno[tp] = caseno.get(tp, 0)+1

    #path = "."
    path = "../data/{0}".format("sample" if tp == "sample" else "secret")
    filename = "{0}/{1}-{2}-{3:02d}.in".format(path, PROBID, tp, caseno[tp])

    outfile = open(filename, "w")

    #####################################################
    # validate data, raise an error if bad
    #

    def check_range(a, lo, hi):
        if type(a) != int or a < lo or a > hi:
            raise ValueError("Bad int or range", a, lo, hi)
    check_range(Q, 2, MAXQ)
    check_range(M, 1, MAXM)
    check_range(S, 0, MAXS)
    check_range(L, 0, MAXL)

    #
    # end data validation
    #####################################################


    #####################################################
    # output test case with print(..., file=outfile) here
    #

    print(Q, M, S, L, file=outfile)

    #
    # end of test case output
    #####################################################

    outfile.close()

    print("Generated", filename)

def gensample():
    genfile("sample", 2, 4, 3, 6)
    genfile("sample", 3, 4, 3, 5)
    genfile("sample", 10, 2, 0, 1)

def genhand():
    for Q in [2, MAXQ]:
        for M in [1, MAXM]:
            for S in [0, MAXS]:
                for L in [0, MAXL]:
                    genfile("hand", Q, M, S, L)
    genfile("hand", MAXQ-713, MAXM-1, 0, MAXL)
    genfile("hand", MAXQ-713, MAXM-1, MAXS, MAXL)
    genfile("hand", 100, 21, 2000, 22)
    genfile("hand", 100, 21, 2001, 22)
    genfile("hand", 100, 21, 1999, 22)
    genfile("hand", 100, 21, 99, 22)
    genfile("hand", 100, 21, 100, 22)
    genfile("hand", 100, 21, 101, 22)

def genrandom():
    for _ in range(25):
        Q = random.randint(2, MAXQ)
        M = random.randint(1, MAXM)
        S = random.randint(0, MAXS)
        L = random.randint(0, MAXL)
        genfile("random", Q, M, S, L)

if __name__ == "__main__":
    random.seed(0)

    gensample()
    genhand()
    genrandom()

    print("Done!")
