from logic import *

AKnight = Symbol("A is a Knight")
AKnave = Symbol("A is a Knave")

BKnight = Symbol("B is a Knight")
BKnave = Symbol("B is a Knave")

CKnight = Symbol("C is a Knight")
CKnave = Symbol("C is a Knave")

# Puzzle 0
# A says "I am both a knight and a knave."
knowledge0 = And(
    Or(AKnave, AKnight),
    Not(And(AKnave, AKnight)),

    Biconditional(AKnight, And(AKnight, AKnave))
)

# Puzzle 1
# A says "We are both knaves."
# B says nothing.
knowledge1 = And(
    #A says they're both knaves, meaning that what they said can't be true
    Not(And(BKnave, AKnave)),
    #A or B could be knave, but not both
    Or(AKnave, BKnave),
    #Both of them could be knights
    Or(BKnight, AKnight),
    #If B is a knight, A could be either a knight or a knave
    Implication(BKnight, Or(AKnight, AKnave)),
    #If A is a knight, then A has to be a knave and so does B
    Implication(AKnight, And(AKnave, BKnave))

)

# Puzzle 2
# A says "We are the same kind."
# B says "We are of different kinds."
knowledge2 = And(
    #If A is knave, that means that they can't be the same which makes B a knight
    Implication(AKnave, BKnight),
    #If B is a knave, then A has to be lying which makes them a knave
    Implication(BKnave, AKnave),
    #Only one of them can be a knave since if they were both knaves A would be telling the truth which would make them a knight
    Or(BKnave, AKnave)

)

# Puzzle 3
# A says either "I am a knight." or "I am a knave.", but you don't know which.
# B says "A said 'I am a knave'."
# B says "C is a knave."
# C says "A is a knight."
knowledge3 = And(
    #A can either be a knight or a knave
    Or(AKnave, AKnight),
    #If A is a knave, that means that A has to both a knight and knave
    Biconditional(AKnave, And(AKnight, AKnave)),
    #If A is a knight, that means A can be a knight or a knave, but not both
    Biconditional(AKnight, Or(AKnave, AKnight)),
    #If B is knave then A and C are not knaves
    Biconditional(BKnave, And(Not(AKnave), Not(CKnave))),
    #If B is a knight, then A and C are both knaves
    Biconditional(BKnight, And(AKnave, CKnave)),
    #If C is a knave, then A can't be a knight
    Biconditional(CKnave, Not(AKnight)),
    #If C is a knight, then A has to be a knight and B can't be a knight since they lied
    Biconditional(CKnight, And(AKnight, Not(BKnight))),
    #If A is a knight, then B has to be a knave
    Implication(AKnight, BKnave),
    #If B is a knave, then C has to a be a knight
    Implication(BKnave, CKnight)
)


def main():
    symbols = [AKnight, AKnave, BKnight, BKnave, CKnight, CKnave]
    puzzles = [
        ("Puzzle 0", knowledge0),
        ("Puzzle 1", knowledge1),
        ("Puzzle 2", knowledge2),
        ("Puzzle 3", knowledge3)
    ]
    for puzzle, knowledge in puzzles:
        print(puzzle)
        if len(knowledge.conjuncts) == 0:
            print("    Not yet implemented.")
        else:
            for symbol in symbols:
                if model_check(knowledge, symbol):
                    print(f"    {symbol}")


if __name__ == "__main__":
    main()
