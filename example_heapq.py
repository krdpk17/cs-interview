import heapq

# Define a custom comparison function
def compare_entry(entry):
    return entry[0]  # Assuming the first element of each entry is used for comparison

# Example list of 2D entries
entries = [[3, 'foo'], [1, 'bar'], [5, 'baz'], [2, 'qux']]

# Convert the list into a heap using heapq.heapify()
heapq.heapify(entries)

print("Heap:", entries)  # Output: [[1, 'bar'], [2, 'qux'], [5, 'baz'], [3, 'foo']]
