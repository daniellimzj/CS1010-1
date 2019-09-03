import math

########################  tagging ########################
def attach_tag(type_tag, contents):
    return (type_tag, contents)

def type_tag(datum):
    if type(datum) == tuple and len(datum) == 2:
        return datum[0]
    else:
        raise Exception('Bad tagged datum --\
                         type_tag' + str(datum))

def contents(datum):
    if type(datum) == tuple and len(datum) == 2:
        return datum[1]
    else:
        raise Exception('Bad tagged datum --\
                         contents' + str(datum))


########################  Table ########################
procs = {}

# installs <value> in table, indexed by <op> and <type>
def put(op, type, value):
    if op not in procs:
        procs[op] = {} # empty dictionary
    procs[op][type] = value

# looks up <op>, <type> entry in table and 
# returns the value found there
def get(op, type):
    return procs[op][type]


########################  Rect rep. ########################
def install_rectangular_package():
    def make_from_real_imag(x, y):
        return attach_tag('rectangular', (x, y))
    def real_part(z):
        return z[0]
    def imag_part(z):
        return z[1]
    def magnitude(z):
        return math.hypot(real_part(z), imag_part(z))
    def angle(z):
        return math.atan(image_part(z) / real_part(z))
    def make_from_mag_ang(r, a):
        return make_from_real_imag(r * math.cos(a), r * math.sin(a))
    
    put('real_part', ('rectangular',), real_part)
    put('imag_part', ('rectangular',), imag_part)
    put('magnitude', ('rectangular',), magnitude)
    put('angle', ('rectangular',), angle)
    put('make_from_real_imag', 'rectangular', make_from_real_imag)
    put('make_from_mag_ang', 'rectangular', make_from_mag_ang)
    return 'done'


########################  Polar rep. ########################
def install_polar_package():
    def make_from_mag_ang(r, a):
        return attach_tag('polar', (r, a))
    def magnitude(z):
        return z[0]
    def angle(z):
        return z[1]
    def real_part(z):
        return magnitude(z) * math.cos(angle(z))
    def imag_part(z):
        return magnitude(z) * math.sin(angle(z))
    def make_from_real_imag(x, y):
        return make_from_mag_ang(math.hypot(x, y), math.atan(y/x))

    
    put('real_part', ('polar',), real_part)
    put('imag_part', ('polar',), imag_part)
    put('magnitude', ('polar',), magnitude)
    put('angle', ('polar',), angle)
    put('make_from_real_imag', 'polar', make_from_real_imag)
    put('make_from_mag_ang', 'polar', make_from_mag_ang)
    return 'done'


########################  Generic Ops ########################
def make_from_real_imag_rectangular(x, y):
    return get('make_from_real_imag', 'rectangular')(x, y)
def make_from_mag_ang_rectangular(x, y):
    return get('make_from_mag_ang', 'rectangular')(x, y)
def make_from_real_imag_polar(x, y):
    return get('make_from_real_imag', 'polar')(x, y)
def make_from_mag_ang_polar(x, y):
    return get('make_from_mag_ang', 'polar')(x, y)

def apply_generic(op, *args):
    type_tags = tuple( map(type_tag, args) )
    proc = get(op, type_tags)
    return proc( *map(contents, args) )

def real_part(z):
    return apply_generic('real_part', z)
def imag_part(z):
    return apply_generic('imag_part', z)
def magnitude(z):
    return apply_generic('magnitude', z)
def angle(z):
    return apply_generic('angle', z)


install_rectangular_package()
install_polar_package()


########################  Example user code ########################
z1 = make_from_real_imag_rectangular(1, 2)
z2 = make_from_real_imag_rectangular(2, 3)

def add_complex(z1, z2):
    return make_from_real_imag_rectangular(
               real_part(z1) + real_part(z2),
               imag_part(z1) + imag_part(z2))

def print_complex(z): # print a+bi
    print(str(real_part(z)) + '+' + str(imag_part(z)) + 'i')

print_complex(add_complex(z1, z2))
