# Task 1: Code Review Checklist

**Project:** Static Verification of C++ Code  
**File Reviewed:** game.cpp

| No. | Review Checklist | Category | Result |
|---:|---|---|---|
| 1 | Are all variables initialized before use? | Initialization | Fail |
| 2 | Are pointers checked for null before use? | Pointer (Null Detection) | Fail |
| 3 | Are arrays and buffers accessed within their limits? | Arrays/Buffers | Fail |
| 4 | Are loop conditions and boundaries correct? | Loops | Fail |
| 5 | Are arithmetic operations and data types handled correctly? | Arithmetic | Fail |
| 6 | Does every control flow path behave correctly? | Control Flow | Fail |
| 7 | Are function calls and return values handled safely? | Function Call | Fail |
| 8 | Are class objects, constructors, destructors, and copying handled safely? | Classes | Fail |

## Conclusion

The review found multiple defects in the original C++ program, including uninitialized variables, unsafe pointer access, array boundary errors, incorrect arithmetic, missing return values, and memory management problems. These defects should be corrected and the program tested before it is considered safe to run.
