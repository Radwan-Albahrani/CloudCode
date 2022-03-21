# Student Information
from traceback import print_tb


Student = ["Radwan Ali Albahrani", 2200003819, "SM23", "Introduction to Programming", 100.0]

# Part A
print(f"""
The datatype of the Student variable is: {type(Student)}
Student Name:       {Student[0]}
Student ID:         {Student[1]}
Section No:         {Student[2]}
Subject:            {Student[3]}
Marks:              {Student[4]}
""")

# Part B
print(f"Complete list before adding Grade: {Student}")
Student.append("A+")

print(f"Complete List after Adding Grade: {Student}")