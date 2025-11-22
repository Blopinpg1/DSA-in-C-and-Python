# Radix Sort implementation

def counting_sort_by_digit(array, digit_place):
    array_length = len(array)
    sorted_array = [0] * array_length       # Output array
    digit_count = [0] * 10                  # Count array for digits 0-9

    print(f"\nSorting by digit place: {digit_place}")

    # Count occurrences of each digit at current place
    for number_index in range(array_length):
        digit_value = (array[number_index] // digit_place) % 10
        digit_count[digit_value] += 1
    print("Digit counts (frequency of each digit):", digit_count)

    # Digit count
     
    for i in range(1, 10):
        digit_count[i] += digit_count[i - 1]
    print("Cumulative count:", digit_count)

    # Build the output array (process from end for stability)
    
    for number_index in range(array_length - 1, -1, -1):
        digit_value = (array[number_index] // digit_place) % 10
        sorted_position = digit_count[digit_value] - 1
        sorted_array[sorted_position] = array[number_index]
        digit_count[digit_value] -= 1
        print(f"Placing {array[number_index]} at sorted_array[{sorted_position}]:", sorted_array)

    # Copy sorted values back to original array
    
    for index in range(array_length):
        array[index] = sorted_array[index]

    print("Array after sorting by this digit place:", array)

def radix_sort(array):
    maximum_number = max(array)
    digit_place = 1

    # Process each digit place (units, tens, hundreds, ...)
    while maximum_number // digit_place > 0:
        counting_sort_by_digit(array, digit_place)
        digit_place *= 10


if __name__ == "__main__":
    numbers_to_sort = [170, 45, 75, 90, 802, 24, 2, 66]
    print("Original array:", numbers_to_sort)
    radix_sort(numbers_to_sort)
    print("\nSorted array:", numbers_to_sort)
