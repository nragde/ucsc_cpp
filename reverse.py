def reverse(number):
    is_overflow = check_over(number)
    if is_overflow == 0:
        return 0
    mod_num = number
    reversed = 0
    while mod_num > 0:
        rem = mod_num % 10 # Get the last digit
        mod_num = int(mod_num/10) # Drop the last digit (and round down)
        reversed = (reversed*10)+rem

    return reversed


def check_over(number):
    if number > 900000000:
        return 0
    return number

def main():
    number_to_reverse = input("Number to reverse:")
    reversed_number = reverse(number_to_reverse)
    print("Reversed number: {}".format(reversed_number))

if __name__ == "__main__":
    main()
