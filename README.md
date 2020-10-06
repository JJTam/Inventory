COMP 2012 Object-Oriented Programming and Data Structures

Assignment 1 Inventory


Introduction
In this assignment, through the implementation of a custom-made data structure called Inventory, you will have practices on various C++/OOP fundamentals, e.g., classes, objects, constructors, destructors, pointers, etc.

We value academic integrity very highly. Please read the Honor Code section on our course webpage to make sure you understand what is considered as plagiarism and what the penalties are. The following are some of the highlights:

Do NOT try your "luck" - we use sophisticated plagiarism detection software to find cheaters. We also review codes for potential cases manually.
The penalty (for BOTH the copier and the copiee) is not just getting a zero in your assignment. Please read the Honor Code thoroughly.
Serious offenders will fail the course immediately, and there may be additional disciplinary actions from the department and university, upto and including expulsion.
Overview
There are 2 classes.



Inventory: It is a flexible container of items. It is backed by a dynamic array of Item pointers that point to Item objects. It supports some set-like operations like union.
Item: It is a representation of an item in an inventory. It has two properites: name and quantity.
Your solution to this assignment must be based on the given skeleton code provided in the Download section.

Your task is to complete the following:

Inventory implementation in Inventory.cpp
Item implementation in Item.cpp
These are the only 2 files you are supposed to modify, zip, and then submit to Zinc.

Comments in the corresponding header files list out the detailed requirements. The description below supplements only the missing information. You need to read both the source/header files and the webpage description carefully to get the whole picture.

While you probably will jump back and forth as you read the materials as they reference each others, we recommend the following reading order:

Item.h
Inventory.h
The remaining of this webpage
main10.cpp
main1.cpp - main9.cpp
Read the FAQ page for some common clarifications. You should check that a day before the deadline to make sure you don't miss any clarification, even if you have already submitted your work then.

If you need clarification of the requirements, please feel free to post your question on Piazza with the pa1 tag. However, to avoid cluttering the forum with repeated/trivial questions, please do read all the source code comments, webpage description, sample output, and the latest FAQ (refresh this page regularly) carefully before you post your questions. You should also check if your question has been asked before posting one. Please note that we won't debug for any student's assignment for fairness.

Submission details are in the Submission and Deadline section.

Download
Skeleton code: skeleton0928.zip
Minor update on Sep 28th: changed #include "inventory.h" to #include "Inventory.h" in all mainN.cpp files. You don't need to re-download the skeleton if the old one can compile for you, e.g., on Windows at least, the include filename is case-insensitive anyway. You can also edit the old files yourself.
This is a Makefile project. Just do what you did in lab 1 to put that in your VS Code / Eclipse / other IDEs.

In VS Code terminal, running make will create 10 excuteables: test1.exe, test2.exe, ..., test10.exe for the 10 given test cases which are compiled from their corresponding mainN.cpp file, where N is the test case number, together with Inventory.cpp and Item.cpp. Run ./testN.exe to run the program.

See the Sample Output and Grading Scheme section for more information about the test cases.
Output format
In Inventory::print(), you need to follow this format exactly for printing the inventory and the items in it. You should not have any other console output in any other functions that you implement. If you are not sure about the format, check the sample output, or simply try your implementation on the online autograder (feel free to try as the number of submissions is not limited; we only use your last submission for grading at the end).

The format is as follows:

{"[FIRST ITEM NAME]":[FIRST ITEM QUANTITY],"[SECOND ITEM NAME]":[SECOND ITEM QUANTITY],"[THIRD ITEM NAME]":[THIRD ITEM QUANTITY],"[FORTH ITEM NAME]":[FORTH ITEM QUANTITY] AND SO ON...}
Basically, use { and } to contain all items which are separated by a single comma. Each item is represented by a quoted name, followed by a colon, followed by its quantity.

At the very end after }, there is a single endl.

For example, if we have 10 apples, 20 bananas, and 15 oranges, the print function should print the following line:

{"Apple":10,"Banana":20,"Orange":15}
Tips: the double quote character in C++ has to be escaped, i.e., "\"" represents a double quote string while """ is incorrect.

Sample Output and Grading Scheme
Test 10 is actually the overall test, while tests 1 to 9 are simply pieces of it. Tests 1 to 9 are there to give you partial credits. You can test all these 10 given test cases on Zinc anytime.

Your finished program should produce the exact same output as our sample output. Please note that sample output, naturally, does not show all possible cases. It is part of the assessment for you to design your own test cases to test your program. Be reminded to remove any debugging message that you might have added before submitting your code.

Your program should terminate without any memory leak. We will have 2 test cases (test case 9 and test case 10) to check for it. Your program will need to have 0 memory leak as well as correct output in order to get credits for test 9 and test 10. We don't care about memory leak in other test cases.

Each of the test cases is worth 4 marks, and there is no partial credit for each case. We will have other additional 15 test cases which are not released to you before the deadline. In total, all 25 test cases (10 given + 15 hidden) will contribute to the 100 total marks of the assignment.

Submission and Deadline
Deadline: 23:59:00 on Oct 9, 2020 (Friday) Oct 13, 2020 (Tuesday)


Notice: Zinc submission for assignment 1 will be open at a later time, as the Zinc team is doing some adjustments. If you want to check your program output, you may do so with our provided sample output yourself meanwhile.


Please zip two cpp files only: Item.cpp and Inventory.cpp. Zip only these 2 files, NOT a folder containing them. Submit the zip file to Zinc. Zinc usage instructions can be found here.

Notes:

You may submit your file multiple times, but only the latest version will be graded.
Submit early to avoid any last-minute problem. Only ZINC submissions will be accepted.

Compilation Requirement
It is required that your submissions can be compiled and run successfully in our online autograder Zinc. If we cannot even compile your work, it won't be graded. Therefore, for parts that you cannot finish, just put in dummy implementation so that your whole program can be compiled for Zinc to grade the other parts that you have done. Empty implementations can be like:

int SomeClass::SomeFunctionThatIsTooDifficultToImplementForMe()
{
    return 0;
}

void SomeClass::AnotherFunctionThatIsTooDifficultToImplementForMeOhNo()
{
}

Late submission policy
There will be a penalty of -1 point (out of a maximum 100 points) for every minute you are late. For instance, since the deadline of the assignment is 23:59:00 on Oct 13th, if you submit your solution at 1:00:00 on Oct 14th, there will be a penalty of -61 points for your assignment. However, the lowest grade you may get from an assignment is zero: any negative score after the deduction due to late penalty (and any other penalties) will be reset to zero.

FAQ
Frequently Asked Questions

Q: My code doesn't work / there is an error, here is the code, can you help me fix it?

A: As the assignment is a major course assessment, to be fair, you are supposed to work on it on your own and we should not finish the tasks for you. We might provide some very general hints to you, but we shall not fix the problem or debug for you.


Q: Can I add extra helper functions?

A: You may do so in the files that you are allowed to modify and submit.


Q: Can I include additional libraries?

A: No. Everything you need is already included - there is no need for you to add any include statement (under our official environment).


Q: Can I use global variable or static variable such as "static int x"?

A: No.


Q: Can I use "auto"?

A: No.
