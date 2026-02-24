
""" Write a Python program to test whether a passed letter is a vowel or not. """


def is_vowel( Char ):
    return True if Char in 'aeiouAEIOU' else False


print(is_vowel('a'))
print(is_vowel('b'))