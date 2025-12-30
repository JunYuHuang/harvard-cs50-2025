from cs50 import get_int

def main():
    height = 0

    while is_invalid_height(height):
        height = get_int("Height: ")

    print_pyramids(height)
    
def is_invalid_height(height):
    return True if (height < 1 or height > 8) else False

def print_pyramids(height):
    for row in range(height):
        print_l_pyramid_row(row, height)
        print("  ", end="")
        print_r_pyramid_row(row, height)
        print()

def print_l_pyramid_row(row, height):
    pyramid_hash_count = row + 1
    pyramid_space_count = height - pyramid_hash_count
    print(" " * pyramid_space_count + "#" * pyramid_hash_count, end="")

def print_r_pyramid_row(row, height):
    pyramid_hash_count = row + 1
    pyramid_space_count = height - pyramid_hash_count
    print("#" * pyramid_hash_count + " " * pyramid_space_count, end="")

main()