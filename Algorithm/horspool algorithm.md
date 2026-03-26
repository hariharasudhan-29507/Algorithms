# Horspool's Algorithm

## Description

Horspool's algorithm is a simplified version of the Boyer-Moore algorithm for string pattern matching. It preprocesses the pattern to build a shift table, then aligns the pattern against the text and compares right-to-left, using the shift table to skip characters efficiently on a mismatch.



## Algorithm: ShiftTable

ShiftTable(pattern[0..m-1])

//Input: Pattern of length m  
//Output: Shift table of size 256 (for all ASCII characters)

FOR each character c in alphabet DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;shift[c] ← m  
END FOR
FOR i ← 0 TO m - 2 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;shift[pattern[i]] ← m - 1 - i  
END FOR
Return shift table

## Algorithm: Horspool

Horspool(text[0..n-1], pattern[0..m-1])

//Input: Text of length n, Pattern of length m  
//Output: Starting index of first match, or "Pattern not found"

i ← m − 1 &nbsp;&nbsp;// Align pattern's last character with text[m-1]
WHILE i < n DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;k ← 0  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;WHILE k < m AND pattern[m - 1 - k] == text[i - k] DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;k ← k + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END WHILE  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF k == m THEN  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Print "Pattern found at position", i − m + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Stop  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i ← i + shift[text[i]]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END IF  
END WHILE

Print "Pattern not found"  
Stop

---

## Time Complexity

| Case        | Complexity | Explanation |
|-------------|------------|-------------|
| **Best**    | Θ(n / m)   | The last character of the pattern rarely appears in the text, causing large shifts. The algorithm skips roughly `m` characters at a time, resulting in only `n / m` comparisons. |
| **Average** | Θ(n)       | Shifts are typically a few characters wide, so the algorithm scans the text in roughly linear time across most real-world inputs. |
| **Worst**   | Θ(n × m)   | Occurs when every alignment requires a full pattern comparison before a mismatch — common with highly repetitive patterns and text (e.g., pattern `aab` in text `aaaa...a`), producing minimal shifts each time. | 
