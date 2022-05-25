import sys
from inspect import currentframe, getframeinfo

def trans2c_synt_sug(instruction_line):
    # single-step addition
    # single-step subtraction
    synt_sug_decl = {
        "+=": "",
        "-=": ""
    }
    instruction_iter = dict()
    instruction_args = instruction_line.split(";")
    if len(instruction_args) == 1:
        return None
    for rule in synt_sug_decl:
        for frag in instruction_args:
            synt_sug_decl
            instruction_args[instruction_args.index(frag)] = instruction_args

class this_point:
    def __init__(self):
        self.crrframe = currentframe()

    def getfilename(self):
        __file__ = str(getframeinfo(self.crrframe).filename)
        return __file__
        
    def getlineno(self):
        __line__ = int(self.crrframe.f_lineno)
        return __line__

class Eval:
    def __init__(self, retries):
        self.retries = retries
        self.a = 4
        self.b = 3
        self.c = int(-1)
        self.d = int(-1)
        self.e = int(-1)
        self.f = float(2)
        self.g = float(5)
        self.h = float(-1)
        self.i = float(-1)
        self.j = float(-1)
        self.k = float(-1)
        self.method = {
            1: "self.c = self.f / self.b * self.f",
            2: "self.h = self.a / float(self.b); self.a += 1",
            3: "self.j = float(self.c) / self.h; self.h -= 1",
            4: "self.d = self.b * self.h / self.c",
            5: "self.i = self.d * self.f + self.h; self.h -= 1",
            6: "self.e = self.a * self.d / self.i; self.d += 1",
            7: "self.k = int(self.i) * self.d / float(self.a)"
        }
        self.result = {
            1: [None, None],
            2: [None, None],
            3: [None, None],
            4: [None, None],
            5: [None, None],
            6: [None, None],
            7: [None, None],
            # 8: "checking error raising"
        }

    def start(self):
        this_doc = this_point()
        if len(self.method) - len(self.result):
            # line = sys._getframe(1).f_lineno
            sys.stderr.write("\
\033[1m{:s}:{:d}: \033[1;31mSourceError\033[0;39m\n\
Something went wrong.\n".format(this_doc.getfilename().split("/")[-1], this_doc.getlineno())) # , inspect.getsourcelines(__doc__)))
            exit(1)
        self_num = len(self.method)

        self.loop = input("o_time? [ 1=YES | 0=no ]: ")
        if not self.loop:
            self.loop = 1
        else:
            self.loop = len(self.result)

        done = 0
        i = 1
        j = 1

        while not done:
            for eiei in range(0, self.loop):
                to_print = self.method[i].replace("self.", "")
                turns_left = self.retries
                while turns_left:
                    self.result[i][0] = input("{:30s}    \033[1;33m{:s}:\033[0;39m ".format(to_print, to_print[0]))
                    eval(self.method[i])
                    eval_result_type = type(self.method)
                    if type(self.result[i][0]) == eval_result_type:
                        break
                    turns_left -= 1
                i += 1
            for eiei in range(0, self.loop):
                eval_res = exec(self.method[i])
                if self.result[i][0] == eval_res:
                    self.result[i][1] = 1
                else:
                    self.result[i][1] = 0
                j += 1
            if i == self_num and j == i:
                done = 1
        
        def get_res(self):
            return self.result

self = Eval(3)
self.start()
print(self.get_res())