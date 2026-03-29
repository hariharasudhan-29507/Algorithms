# Heap Sort

## Description
Heap Sort is a comparison-based sorting algorithm that uses a binary max-heap data structure. It works in two phases: first it builds a max-heap from the input array, then it repeatedly extracts the maximum element (root) and places it at the end of the array, shrinking the heap each time until the array is fully sorted.

---

## Algorithm: Heapify

Heapify(arr[0..n-1], n, i)  
//Input: Array arr[], heap size n, root index i  
//Output: arr[] with subtree rooted at i satisfying the max-heap property

largest ← i  
left ← 2 × i + 1  
right ← 2 × i + 2

IF left < n AND arr[left] > arr[largest] THEN  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;largest ← left  
END IF

IF right < n AND arr[right] > arr[largest] THEN  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;largest ← right  
END IF

IF largest ≠ i THEN  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Swap arr[i] and arr[largest]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i ← largest  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;WHILE true DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;largest ← i  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;left ← 2 × i + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;right ← 2 × i + 2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF left < n AND arr[left] > arr[largest] THEN  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;largest ← left  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END IF  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF right < n AND arr[right] > arr[largest] THEN  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;largest ← right  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END IF  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF largest == i THEN break  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Swap arr[i] and arr[largest]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i ← largest  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END WHILE  
END IF

---

## Algorithm: HeapSort

HeapSort(arr[0..n-1])  
//Input: Array arr[] of n elements  
//Output: arr[] sorted in non-decreasing order

// Phase 1 — Build max-heap  
FOR i ← ⌊n/2⌋ − 1 DOWNTO 0 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Heapify(arr, n, i)  
END FOR

// Phase 2 — Extract elements from heap one by one  
FOR i ← n − 1 DOWNTO 1 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Swap arr[0] and arr[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Heapify(arr, i, 0)  
END FOR

Return arr[]

---

## Time Complexity

| Case        | Complexity   | Explanation |
|-------------|--------------|-------------|
| **Best**    | Θ(n log n)   | Even on an already sorted array, HeapSort builds the heap and performs n extractions, each calling Heapify at O(log n) cost. |
| **Average** | Θ(n log n)   | Building the heap takes O(n); each of the n−1 extractions triggers a Heapify of O(log n), giving n log n total. |
| **Worst**   | Θ(n log n)   | HeapSort always performs the same two-phase structure regardless of input order, guaranteeing n log n in all cases. |

## Space Complexity

| Type          | Complexity | Explanation |
|---------------|------------|-------------|
| **Input**     | O(n)       | The array of n elements is sorted in-place; no separate copy is made. |
| **Auxiliary** | O(1)       | Heapify uses only scalar variables (largest, left, right, temp, i) — the iterative loop avoids any recursion stack overhead. |
