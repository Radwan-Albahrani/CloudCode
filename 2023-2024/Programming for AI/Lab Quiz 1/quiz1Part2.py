def check_grades(students: list) -> dict:
    # Using Max function, we can create a lambda function to check the max grade by selecting the second element of each tuple and comparing them
    maxStudent = max(students, key=lambda nameGrade: nameGrade[1])

    # Returning it as dict
    return {"name": maxStudent[0], "grade": maxStudent[1]}
