# By Jonathan Chen Yisheng

from turtle import *
from time import sleep
from random import randrange

########################################################
# HELPFUL BINARY OPERATIONS FOR AI TO OWN HUMAN PLAYER #
########################################################

def to_bin(n):
    if (n//2) == 0:
        return n
    else:
        return n%2 + 10*to_bin(n//2)

def to_dec(binary):
    if binary//10:
        return binary%10 + 2*to_dec(binary//10)
    else:
        return binary%10

def xor(bit1, bit2):
    if not bit1 or not bit2:
        return bit1 + bit2
    else:
        bit1, r1 = divmod(bit1, 10)
        bit2, r2 = divmod(bit2, 10)
        return (r1+r2)%2 + 10*xor(bit1, bit2)

#def complement(bit):
#    if bit:
#        bit, r = divmod(bit, 10)
#        return (r+1)%2 + 10*complement(bit)
#    else:
#        return 0

##########################
# CODE FOR GAME GRAPHICS #
##########################

class Message(Turtle):
    def __init__(self, color="black", x=0, y=0):
        Turtle.__init__(self, visible=False)
        self.pu()
        self.speed(0)
        self.color(color)
        self.goto(x,y)
    def print(self, msg):
        self.write(msg, align='center', font=("Courier", 16, "bold"))

class Block(Turtle):
    def __init__(self):
        Turtle.__init__(self, shape="square", visible=False)
        self.pu()
        self.speed(0)
        self.shapesize(1.5, 1.5, 2) # square-->rectangle
        self.fillcolor("black")
        self.st()
    def col(self):
        return self.color()[1]
    def delete(self):
        if self.col() == "black":
            self.fillcolor("red")
        elif self.col() == "red":
            self.ht()
    def restore(self):
        self.fillcolor("black")
        self.st()
    def x(self):
        return self.pos()[0]
    def y(self):
        return self.pos()[1]
    def glow_r(self):
        self.fillcolor("red")
    def unglow(self):
        self.fillcolor("black")

class Pile(list):
    def __init__(self, x):
        "create an shelf. y is y-position of first block"
        self.y = -150
        self.x = x
    def height(self):
        height = self.y + 34*self.length()
        return height
    def push(self, d):
        width, _, _ = d.shapesize()
        xoffset = width/2 * 20 # to align the blocks by it's left edge
        d.setx(self.x + xoffset)
        d.sety(self.y+34*len(self))
        self.append(d)
    def length(self):
        count = 0
        for b in self:
            if b.isvisible():
                count += 1
        return count
    def restore(self, i):
        restored = 0
        for b in self:
            if restored < i:
                b.restore()
                restored += 1
            else: break

#####################
# CODE FOR GAMEPLAY #
#####################

def init_pile(pile_num, val=5):
    s = Pile(-180 + pile_num*60)
    for i in range(val):
        b = Block()
        s.push(b)
    return s

def select(x,y,turn="human"):
    saved = False
    for p in piles:
        if (x <= (p.x+30)) and (x >= p.x) and (y <= p.height()):
            valid = True
            for block in p:
                if (block.y()+17) < y:
                    if block.col() == "red":
                        block.unglow()
                        valid = False
                else:
                    if block.col() == "black":
                        block.glow_r()
                        valid = False
                    else:
                        if valid:
                            if not saved and turn == "human":
                                state = get_coins(piles)
                                push_save(state, saved_steps)
                                saved = True
                            block.delete()
            if valid:
                if game_over():
                    end_game(turn)
                    return quit()
                else:
                    if turn == "human":
                        state = get_coins(piles)
                        computer_move(state)
        else:
            for block in p:
                block.unglow()

def get_coins(piles):
    coins = []
    for p in piles:
        coins.append(p.length())
    return coins

def game_over():
    coins = 0
    for p in piles:
        if p.length():
            return False
    return True

def end_game(turn):
    clearscreen()
    m1 = Message("Green")
    m1.print("You win. Congratulations." if turn == "human" \
        else "You lose. Better luck next time.")
    timer = Message("Black", 0, -100)
    for time in range(5, 0, -1):
        timer.print("Game ending in " + str(time))
        sleep(1)
        timer.clear()
    bye()

###############
# CODE FOR AI #
###############

def computer_move(state):
    pile_index, remaining = find_move(state)
    current_coins = state[pile_index]
    computer_select(piles[pile_index], current_coins - remaining)

def find_move(state):
    bin_coins = list(map(to_bin, state))
    
    def nim_sum(bin_coins):
        total, i = 0, 0
        def simplify(n):
            if n < 10:
                return n%2
            else:
                return n%2 + 10*simplify(n//10)
        for c in bin_coins:
            total += c
            i += 1
            if i == 9:
                total = simplify(total)
        return simplify(total)
    
    nimsum = nim_sum(bin_coins)
    for pos, bc in enumerate(bin_coins):
        diff = xor(nimsum, bc)
        if diff < bc:
            return (pos, to_dec(diff))
    else:
        pile_index = any_non_empty_pile(state)
        return (pile_index, randrange(state[pile_index]))

def any_non_empty_pile(state):
    piles_with_coins = []
    for pos, c in enumerate(state):
        if c != 0:
            piles_with_coins.append(pos)
    return piles_with_coins[randrange(len(piles_with_coins))]

def computer_select(pile, coins):
    onscreenclick(None)
    select(pile.x, pile.height() - coins*34, turn="com")
    sleep(.5)
    select(pile.x, pile.height() - coins*34, turn="com")
    onscreenclick(select)

#################
# CODE FOR UNDO #
#################

def make_save():
    return []

def peek(stack):
    return stack[-1]

def is_empty(stack):
    return stack == []

def push_save(state, stack):
    if is_empty(stack):
        stack.append(state)
    elif state != peek(stack):
        stack.append(state)

def pop_save(stack):
    return stack.pop()

def riffle(list1, list2):
    output = []
    for i in range(len(list1)):
        output.append((list1[i],list2[i]))
    return output

def undo():
    global count
    if is_empty(saved_steps):
        m3 = Message("Black",0,200)
        if count < 3:
            m3.print("No more undos left.")
        elif count < 7:
            m3.print(("Hey stop it.","That's irritating.","Bugger off.")[randrange(3)])
        elif count < 10:
            m3.print(("Great tenacity there.","You won't stop, wontcha?","Stop that already.","Play the game and leave me alone.")[randrange(4)])
        elif count < 15:
            m3.print(("You must be so bored.","I'm running out of things to say, y'know.","Have you won the game yet?")[randrange(3)])
        else:
            m3.print("I mean, you could have just looked at the code.")
            count = 0
        count += 1
        sleep(1)
        m3.clear()
    else:
        previous_state = pop_save(saved_steps)
        restoring = riffle(piles, previous_state)
        for p, coins in restoring:
            p.restore(coins)
        count = 0

#################################
# USER INPUT TO INITIALIZE GAME #
#################################

userinput = input("How many piles of coins shall we have? (1-6): ")
try:
    num_of_piles = int(userinput)
    if num_of_piles > 6:
        num_of_piles = 6
        print("\tNumber of piles of coins is set to the maximum 6.\n")
    else:
        print("\tNumber of piles of coins is set to "+str(num_of_piles)+".\n")
except ValueError:
    num_of_piles = 2
    print("\tInvalid input.\n\tNumber of piles of coins is set to 2.\n")
piles = []
for i in range(num_of_piles):
    userinput = input("How many coins will be in pile " + str(i+1) + " ? (1-9): ")
    try:
        userinput = int(userinput)
        if userinput < 1:
            piles.append(1)
            print("\tOut of range.\n\tNumber of coins in this pile is set to 1.")
        elif userinput > 9:
            piles.append(9)
            print("\tOut of range.\n\tNumber of coins in this pile is set to 9.")
        else:
            piles.append(userinput)
    except ValueError:
            piles.append(5)
            print("\tInvalid input.\n\tNumber of coins in this pile is set to 5.")
for i in range(num_of_piles):
    piles[i] = init_pile(i, piles[i])

saved_steps = make_save()
count=0
m4 = Message("Black",0,-250)
m4.print("Press the LEFT arrow for undo")

Screen().onkey(undo, "Left")
Screen().listen()
onscreenclick(select)
Screen().mainloop()
