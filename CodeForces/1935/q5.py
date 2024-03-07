import pandas as pd
import numpy as np

def class_grades(students):
    """
    :param students: (list) Each element of the list is another list with the 
      following elements: Student name (string), class name (string), student grade (int).
    :returns: (list) Each element is a list with the following 
      elements: Class name (string), median grade for students in the class (float).
    """
    df = pd.DataFrame(students, columns=["student", "class", "grade"])
    df = df.groupby("class").mean()
    return df.reset_index().values.tolist()

students = [["Ana Stevens", "1a", 5], ["Mark Stevens", "1a", 4], ["Jon Jones", "1a", 2], ["Bob Kent", "1b", 4]]
print(class_grades(students))
