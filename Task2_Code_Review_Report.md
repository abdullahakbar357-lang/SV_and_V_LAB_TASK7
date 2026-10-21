# Task 2: Code Review Report

**Project:** Static Verification of C++ Code  
**File Reviewed:** game.cpp

| Line Number | Defect Type | Why It Is a Problem | Proposed Solution | Severity |
|---:|---|---|---|---|
| 27 | Array Size | The array can store only 5 monsters, but the program creates 6. | Increase the capacity or use a dynamic container. | High |
| 41 | Array Overflow | Adding a monster after the array is full writes outside the array. | Check capacity before adding a monster. | Critical |
| 47 | Assignment Instead of Comparison | The ID is overwritten instead of being compared, so the wrong monster may be found. | Replace `=` with `==`. | High |
| 54 | Null Pointer | `findMonster()` can return `nullptr` when the requested monster does not exist. | Check whether `m` is null before accessing it. | Critical |
| 55 | Incorrect Data Type | Negative damage becomes a large unsigned value. | Validate damage and use a suitable signed type. | High |
| 56 | Arithmetic Error | The unsigned damage and health comparison do not reliably detect negative health. | Use signed arithmetic and check the resulting health. | High |
| 64 | Loop Boundary | The loop uses `i <= monsterCount`, which accesses one element beyond the valid range. | Use `i < monsterCount`. | Critical |
| 65 | Null or Invalid Pointer Access | An invalid array element may be accessed during total health calculation. | Correct the loop boundary and validate elements. | Critical |
| 70 | Dangling Reference | The function returns a reference to a local string that is destroyed when the function ends. | Return `std::string` by value. | High |
| 72 | Null Pointer | The monster pointer may be null before its members are accessed. | Check the pointer before using it. | High |
| 73 | Dangling Reference | Returning `label` by reference creates an invalid reference. | Return `label` by value. | High |
| 77 | Uninitialized Variable | `sum` has no initial value, so calculations use an indeterminate value. | Initialize `sum` to `0`. | High |
| 80 | Division by Zero | If there are no monsters, `monsterCount` is zero. | Check for an empty collection before dividing. | High |
| 85 | Unsafe Deletion | The pointer may be null or may not refer to a currently stored monster. | Validate the monster and remove it safely. | High |
| 86 | Use After Free | The program accesses `m->name` after deleting `m`. | Print the name before deletion. | Critical |
| 91 | Integer Arithmetic | Integer division can discard the fractional part of the calculated damage. | Use `100.0` or cast to `double`. | Medium |
| 94 to 99 | Missing Return Value | The function has no return statement when the score is 100 or lower. | Add a default return value. | High |
| 102 | Buffer Size | The boss name buffer has space for only 10 characters, including the null terminator. | Use `std::string` or safely limit input. | High |
| 105 | Buffer Overflow | Input longer than the allocated buffer can overwrite memory. | Use `std::string` with `std::cin`. | Critical |
| 108 | Type Conversion | A character pointer is passed where a `std::string` is expected. This may compile, but it depends on the buffer containing a valid null-terminated string. | Use a `std::string` variable for the boss name. | Medium |
| 109 | Incorrect Deallocation | Memory allocated with `new[]` is released using `delete`. | Use `delete[]` or avoid manual allocation. | High |
| 121 | Memory Leak | The dynamically allocated bonus monster is never deleted. | Use automatic storage or a smart pointer. | Medium |
| 133 | Unsafe Object Copying | The default copy operation duplicates raw pointers, which can lead to double deletion and invalid memory access. | Implement safe copying or use value-based containers. | Critical |

## Conclusion

The code review identified defects related to array bounds, pointer safety, arithmetic, initialization, control flow, function return values, and class memory management. The proposed solutions should be applied and tested to prevent crashes, undefined behavior, and incorrect results.
