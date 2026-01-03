import csv
from sys import exit, argv

def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Usage: python dna.py database.csv sample.txt")
        exit(1)

    # TODO: Read database file into a variable
    strs = []
    str_tuples_to_names = {}
    with open(argv[1]) as database_file:
        reader = csv.DictReader(database_file)
        strs = list(reader.fieldnames)

        # remove the first value `name` of the CSV table header 
        strs.pop(0)

        # build the `str_tuples_to_names` hashmap
        for row_dict in reader:
            name = ""
            str_counts = []

            for key in row_dict.keys():
                if key == 'name':
                    name = row_dict[key]
                    continue
                str_counts.append(int(row_dict[key]))

            # add the (int tuple, string) key-value pair to the hashmap
            str_tuples_to_names[tuple(str_counts)] = name

    # TODO: Read DNA sequence file into a variable
    sample = ""
    with open(argv[2], "r") as sample_file:
        sample = sample_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    sample_str_counts = []
    for str in strs:
        sample_str_counts.append(longest_match(sample, str))

    # TODO: Check database for matching profiles
    sample_str_counts = tuple(sample_str_counts)
    if (str_tuples_to_names.get(sample_str_counts)):
        print(str_tuples_to_names[sample_str_counts])
    else:
        print("No match")

    exit(0)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
