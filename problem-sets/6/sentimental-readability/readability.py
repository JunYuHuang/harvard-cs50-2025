from cs50 import get_string

def main():
    text = get_string("Text: ")
    N = len(text)
    words_count = 1
    letters_count = 0
    sentences_count = 0
    reading_level = 0

    for i in range(N):
        if text[i] == ' ':
            words_count += 1
        elif is_alphabetical_char(text[i]):
            letters_count += 1
        elif is_ending_punctuation_char(text[i]):
            sentences_count += 1
    
    reading_level = int(
        round(
            coleman_liau_index(
                letters_count, sentences_count, words_count
            )
        )
    )

    if reading_level < 0:
        print("Before Grade 1")
    elif reading_level >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {reading_level}")

def coleman_liau_index(letters_count, sentences_count, words_count):
    average_letters_per_100_words = letters_count / words_count * 100
    average_sentences_per_100_words = sentences_count / words_count * 100
    return (
        (0.0588 * average_letters_per_100_words) -
        (0.296 * average_sentences_per_100_words) -
        15.8
    )

def is_alphabetical_char(ch):
    ch = ch.lower()
    return True if 'a' <= ch and ch <= 'z' else False

def is_ending_punctuation_char(ch):
    return ch in ["!", "?", "."]

main()
