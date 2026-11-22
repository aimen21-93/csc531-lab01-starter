# CSC-531 Lab 01 — Student Report

**Roll No.:*44*
**Student name:*AIMEN ASIF KHAN*  
**Section (A/B):*A*  
**GitHub username:*aimen21-93*  

## 1. Aim and input assumptions

Describe the task and state the relationship among capacity, logical size and active indices.
relationship
capacity=8
logical size=4
active indices=4

## 2. Task A — Array diagram and address calculations

Draw **8 slots with logical size 4**. Label indices, active items, free slots and the next append index.
Capacity = 8
Logical size = 4


Index	  0    1	    2	    3	    4	    5	    6	     7
Value	  70	 80   	90  	85	  -     -     -      -
Capacity = 8
Logical size = 4

**1D address worksheet:** Given `B=4000`, `w=4`, calculate `A[0]`, `A[3]`, `A[7]`. Show steps.
D Address Worksheet
Given:

Base address (B) = 4000
Element width (w) = 4 bytes
Formula:

Address(A[i]) = B + (i × w)

A[0]:

= 4000 + (0 × 4)
= 4000

A[3]:

= 4000 + (3 × 4)
= 4012

A[7]:

= 4000 + (7 × 4)
= 4028


**2D row-major worksheet:** Given `M[4][5]`, `B=2000`, `w=4`, calculate `M[2][3]`. Show the linear offset and explain why it is multiplied by element width.
Given:

Matrix = M[4][5]
Base address (B) = 2000
Element width (w) = 4 bytes
Required element = M[2][3]
Number of columns = 5
Formula:

Address(M[i][j]) = B + [(i × columns) + j] × w

Linear offset:

= (2 × 5) + 3
= 10 + 3
= 13

Address:

= 2000 + (13 × 4)
= 2000 + 52
= 2052

Answer: M[2][3] = 2052

The offset is multiplied by the element width because each element occupies 4 bytes in memory. The multiplication converts the element position into a byte offset.



## 3. Task B — Insertion/deletion trace

Using initial active values `[70, 80, 90, 85]`, `size=4`, `capacity=8`, trace insertion of `75` at index `2`. Show **each shift**, the new element and final logical size.

Insertion process
To insert 75 at index 2, elements are shifted one position to the right, starting from the last active element.


Step	                  Operation	                          Array
Initial	             Original  array              	       [70, 80, 90, 85]
1	                   Shift 85 from index 3 to 4            [70, 80, 90, 85, 85]
2	                   Shift 90 from index 2 to 3	           [70, 80, 90, 90, 85]
3	                   Insert 75 at index 2	                 [70, 80, 75, 90, 85]
Final active array:

[70, 80, 75, 90, 85]

New logical size = 5

Then trace deletion of the element at **index 1** from the updated array. Describe which indices move and the resulting active values

Deletion process
Now delete the element at index 1.

The element at index 1 is 80.


Step	                  Operation	                       Array
Initial	                Before deletion	                 [70, 80, 75, 90, 85]
1	                      Shift 75 from index 2 to 1     	 [70, 75, 75, 90, 85]
2	                      Shift 90 from index 3 to 2       [70, 75, 90, 90, 85]
3                      	Shift 85 from index 4 to 3	   [70, 75, 90, 85, 85]
The last duplicate is no longer considered active.

Final active array:

[70, 75, 90, 85]

New logical size = 4

## 4. Task C — Menu demonstration

Describe how to use your four menu options. Show a sample run or a concise input/output log. Include one failed insertion at full capacity and one failed deletion from an empty list.
he program provides four menu options:

Display: Shows all active elements of the array.
Insert: Adds a new element at a specified valid index.
Delete: Removes an element from a specified valid index.
Exit: Terminates the program.
Capacity: 8

1. Display
2. Insert
3. Delete
4. Exit

Enter choice: 1
Array: 70 80 90 85

Enter choice: 2
Enter index: 2
Enter value: 75
Element inserted successfully.

Enter choice: 1
Array: 70 80 75 90 85

Enter choice: 3
Enter index: 1
Element deleted successfully.

Enter choice: 1
Array: 70 75 90 85

Enter choice: 2
Enter index: 8
Array is full. Insertion failed.

Enter choice: 3
Enter index: 0
List is empty. Deletion failed.

Enter choice: 4
Program terminated.


## 5. Validation test table

| Test case | Initial state / input | Expected result | Actual result | Pass/Fail |
|---|---|---|---|---|
| Insert in middle | | | | |
| Delete first | | | | |
| Delete middle | | | | |
| Delete last | | | | |
| Insert when full | | | | |
| Delete when empty | | | | |
| Invalid negative index | | | | |
| Invalid index == size | | | | |
|Test case	              | Initial state / input	   |  Expected result        	|  Actual result                    Pass/Fail|
|Insert in middle	        |[10,20,30],               |insert 25 at 2	          |[10,20,25,30]	[10,20,25,30]	     |Pass|
|Delete first   	        |[10,20,30],               |index 0	                  |[20,30]	[20,30]	                 |Pass|
|Delete middle	          |[10,20,30],               |index 1	                  |[10,30]	[10,30]	                 |Pass|
|Delete last	            |[10,20,30],               |index 2	                  |[10,20]	[10,20]	                 |Pass|
|Insert when full         |	Capacity 3, size 3	     |Insertion rejected	      |Insertion rejected	               |Pass|
|Delete when empty        |	Size 0	                 |Deletion rejected       	|Deletion rejected	               |Pass|
|Invalid negative index   |	Insert at -1             |Invalid index             |message	Invalid index message    |Pass|
|Invalid index == size	  |Delete at index 3,size 3	 |Invalid index             |message	Invalid index message    |Pass|

Insert at beginning	[20,30], insert 10 at 0	[10,20,30]	[10,20,30]	Pass
Append element	[10,20], insert 30 at 2	[10,20,30]	[10,20,30]	Pass
Add other tests you used.

## 6. Complexity and limitations

Define `n` as the number of active elements before the operation and `p` as the target position. State the number of element shifts for insertion and deletion. Explain worst-case time and auxiliary-space complexity. State any assumptions and restrictions.

Let:

n = number of active elements before the operation.
p = target position.
capacity = maximum array size.
Insertion
To insert an element at position p, elements from index p to n-1 are shifted one position to the right.

Number of shifts:

n - p

Best case: O(1), when inserting at the end.
Worst case: O(n), when inserting at the beginning.
Auxiliary space: O(1).
Deletion
To delete an element at position p, elements from index p+1 to n-1 are shifted one position to the left.

Number of shifts:

n - p - 1

Best case: O(1), when deleting the last element.
Worst case: O(n), when deleting the first element.
Auxiliary space: O(1).
Limitations and assumptions
The array has a fixed capacity of 8.
Insertion is not allowed when the array is full.
Deletion is not allowed when the array is empty.
Valid insertion indices are from 0 to size.
Valid deletion indices are from 0 to size - 1.
Elements must be shifted during middle insertion and deletion.
The implementation does not automatically increase array capacity.

## 7. Reflection and viva preparation

1. How many shifts are required to insert at position `p` into an active list of `n` elements?

   n - p shifts are required because all elements from position p to n-1 must move one position to the right.
   
3. Why does insertion shift backward while deletion shifts forward?

   insertion shifts backward from the last active element to avoid overwriting existing values. Deletion shifts forward from the next element to fill the empty position.
   
5. Which workload favors arrays: frequent indexed access or frequent front insertion? Explain.

   Arrays favor frequent indexed access because accessing an element by index takes O(1) time. Front insertion is less efficient because all existing elements must be shifted one position to the right, taking O(n) time. 

**One bug I encountered:*Incorrect shifting of elements during insertion, which caused an existing element to be overwritten.*  
**How I detected it:*I tested insertion at the middle of the array and noticed that one of the original values was missing.*  
**What I changed:*I corrected the shifting loop to start from the last active element and move backward before inserting the new value.*  
**External/AI assistance disclosed, if applicable:*AI assistance was used to understand array operations, address calculations, insertion and deletion traces, and report organization. I will verify the explanations and sample outputs against my own program.*  
