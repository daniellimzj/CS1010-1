def print_move(src, dest):
    print("move top disk from ", src, " to ", dest)

def move_tower(size, src, dest, aux):
    if size == 0:
        return None
    else:
        move_tower(size-1, src, aux, dest)
        print_move(src, dest)
        move_tower(size-1, aux, dest, src)

move_tower(3, 'A', 'C', 'B')
