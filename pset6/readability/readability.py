from cs50 import get_string

# Main


def main():
    x = get_string("Text: ")
    grdlvl = gradelvl(count_letters(x), count_words(x), count_sentences(x))
    
    # Gives a specififed message based on grade level
    
    if grdlvl < 1:
        print("Before Grade 1")
    elif grdlvl > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grdlvl}")
        
# Counts the number of letters


def count_letters(s):
    l = len(s)
    for c in s:
        if c == ' ' or c == '!' or c == '?' or c == '.' or c == "'" or c == '"' or c == ";" or c == ",":
            l -= 1
    return l
    
# Counts the number of words


def count_words(s):
    w = 1
    for c in s:
        if c == ' ':
            w += 1
    return w
    
# Counts the number of sentences


def count_sentences(sen):
    s = 0
    for c in sen:
        if c == '.' or c == '?' or c == '!':
            s += 1
    return s
    
# Calculates the grade level


def gradelvl(l, w, s):
    L = (l * 100) / w
    S = (s * 100) / w
    grdlvl = round(0.0588 * L - 0.296 * S - 15.8)
    return grdlvl

    
main()