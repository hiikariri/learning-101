import random
import string


def generate_password(min_length, numbers=True, special_chars=True):
    letters = string.ascii_letters
    digits = string.digits
    special = string.punctuation

    characters = letters
    password = ""
    meets_criteria = True
    has_numbers = False
    has_special = False

    if numbers and not has_numbers:
        characters += digits
        meets_criteria = False
    if special_chars and not has_special:
        characters += special
        meets_criteria = False

    while not meets_criteria or len(password) < min_length:
        new_char = random.choice(characters)
        password += new_char

        if new_char in digits:
            has_numbers = True
        elif new_char in special:
            has_special = True

        if has_numbers and has_special:
            meets_criteria = True

    return password


print("Welcome to the Password Generator!")
print("Your password is: " + generate_password(5, False, False))
