# Insertion Sort

## Description
Insertion Sort is a simple, comparison-based, in-place sorting algorithm. It builds the final sorted array one item at a time by repeatedly taking the next element and inserting it into the correct position among the previously sorted elements.

---

## Basic steps (high-level)
- Iterate from the second element to the last.
- Save the current element as the "key".
- Shift elements of the sorted portion that are greater than the key one position to the right.
- Insert the key into the position vacated by the shifts.

---

## Algorithm (pseudocode)

InsertionSort(arr[0..n-1])
//Output: arr[] sorted in non-decreasing order

FOR i ← 1 TO n − 1 DO
&nbsp;&nbsp;&nbsp;&nbsp;key ← arr[i]

&nbsp;&nbsp;&nbsp;&nbsp;j ← i − 1

&nbsp;&nbsp;&nbsp;&nbsp;WHILE j ≥ 0 AND arr[j] > key DO

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arr[j + 1] ← arr[j]

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j ← j − 1

&nbsp;&nbsp;&nbsp;&nbsp;END WHILE

&nbsp;&nbsp;&nbsp;&nbsp;arr[j + 1] ← key

END FOR

Return arr[]

---

## Time Complexity

| Case        | Complexity | Explanation |
|-------------|------------|-------------|
| **Best**    | Θ(n)       | Array already sorted; inner loop never shifts, only one comparison per element. |
| **Average** | Θ(n^2)     | Elements are partially ordered; on average each insertion shifts O(i) elements. |
| **Worst**   | Θ(n^2)     | Array sorted in reverse; each insertion shifts all previously sorted elements. |

## Space Complexity

| Type          | Complexity | Explanation |
|---------------|------------|-------------|
| **Input**     | O(n)       | The array of n elements being sorted in-place. |
| **Auxiliary** | O(1)       | Only a constant number of scalar variables (key, i, j) are used. |

