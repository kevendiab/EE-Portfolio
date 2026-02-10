//////////////////////////////////////////////////// PROJECT 2 PYTHON //////////////////////////////////////////////////////////////////////////////////////////

from sample_p1 import *

class P2_COURSE(P1_COURSE):
    def __init__(self, course_name, x, y):
        super().__init__(course_name, x, y)
        self.courseName = course_name  # name of the course
        self.n = x  # number of students
        self.noof_exams = y  # number of exams

        output_file.write("++++++ P2 ++ START ++++\n")
        output_file.write("++++++ P2 CONSTRUCTOR INSTANTIATED A P2_COURSE OBJECT.\n")
        output_file.write("++++++ P2 ++ END ++++\n")

######## python code starts here ############################
    def P2_REPORT(self, x, y, z):
        print("++++++ P2 ++ START OUTPUT FROM P2_REPORT METHOD:")
        print(f"++++++ P2 P2_REPORT IS CALLED WITH x: {x}, y: {y}, z: {z}")

        output_file.write("++++++ P2 ++ START OUTPUT FROM P2_REPORT METHOD:\n")
        output_file.write(f"++++++ P2 P2_REPORT IS CALLED WITH x: {x}, y: {y}, z: {z}\n")

        if x == -1:  # List all students
            if y < 0 or y > self.noof_exams:
                print("++++++ P2 INPUT ERROR.")
                output_file.write("++++++ P2 INPUT ERROR.\n")
            else:
                print(f"++++++ P2 INHERITING FROM P1_LIST({y}):")
                output_file.write(f"++++++ P2 INHERITING FROM P1_LIST({y}):\n")
                self.P1_LIST(y)
        else:  # Report student grade
            if x < 0 or x >= 9999 or y <= 0 or y > 9999 or z < 0 or z > self.noof_exams:
                print("++++++ P2 INPUT ERROR.")
                output_file.write("++++++ P2 INPUT ERROR.\n")
            else:
                student_index = self.P1_FIND(x, y)
                if student_index == -1:
                    print(f"++++++ P2 NO SUCH STUDENT WITH ID {x} AND PIN {y}.")
                    output_file.write(f"++++++ P2 NO SUCH STUDENT WITH ID {x} AND PIN {y}.\n")
                else:
                    print(f"++++++ P2 THE GRADE OF STUDENT {self.id[student_index]} FOR EXAM {z} IS {self.examGrades[student_index][z]}.")
                    output_file.write(f"++++++ P2 THE GRADE OF STUDENT {self.id[student_index]} FOR EXAM {z} IS {self.examGrades[student_index][z]}.\n")
        
        print("++++++ P2 ++ END OUTPUT FROM P2_REPORT METHOD")
        output_file.write("++++++ P2 ++ END OUTPUT FROM P2_REPORT METHOD\n")

######## python code ends here ############################

######## python code starts here ############################

    def P2_SORT(self):
        print("++++++ P2 ++ START OUTPUT FROM P2_SORT METHOD:")
        print("++++++ P2 OUTPUT FROM P2_SORT METHOD:")

        output_file.write("++++++ P2 ++ START OUTPUT FROM P2_SORT METHOD:\n")
        output_file.write("++++++ P2 OUTPUT FROM P2_SORT METHOD:\n")

        for i in range(self.n):
            min_pos = i
            for j in range(i, self.n):
                if self.id[j] < self.id[min_pos]:
                    min_pos = j

            # Swap student IDs
            self.id[i], self.id[min_pos] = self.id[min_pos], self.id[i]
            # Swap student PINs
            self.pin[i], self.pin[min_pos] = self.pin[min_pos], self.pin[i]
            # Swap student grades
            self.examGrades[i], self.examGrades[min_pos] = self.examGrades[min_pos], self.examGrades[i]

        print("++++++ P2 ++ END OUTPUT FROM P2_SORT METHOD")
        output_file.write("++++++ P2 ++ END OUTPUT FROM P2_SORT METHOD\n")

######## python code ends here ############################

######## python code starts here ############################

    def P2_MINMAX(self, x, y):
        print("++++++ P2 ++ START OUTPUT FROM P2_MINMAX METHOD:")
        print(f"++++++ P2 P2_MINMAX IS CALLED WITH x: {x}, y: {y}")

        output_file.write("++++++ P2 ++ START OUTPUT FROM P2_MINMAX METHOD:\n")
        output_file.write(f"++++++ P2 P2_MINMAX IS CALLED WITH x: {x}, y: {y}\n")

        if x == 0:  # Find minimum grade (inherits from P1_MIN)
            print(f"++++++ P2 INHERITING FROM P1_MIN({y}):")
            output_file.write(f"++++++ P2 INHERITING FROM P1_MIN({y}):\n")
            self.P1_MIN(y)
        elif x == 1:  # Find maximum grade
            max_grade = max(int(self.examGrades[i][y]) for i in range(self.n))
            print(f"++++++ P2 THE HIGHEST GRADE FOR EXAM {y} IS {max_grade}.")
            output_file.write(f"++++++ P2 THE HIGHEST GRADE FOR EXAM {y} IS {max_grade}.\n")
        else:
            print("++++++ P2 INPUT ERROR.")
            output_file.write("++++++ P2 INPUT ERROR.\n")

        print("++++++ P2 ++ END OUTPUT FROM P2_MINMAX METHOD")
        output_file.write("++++++ P2 ++ END OUTPUT FROM P2_MINMAX METHOD\n")

######## python code ends here ############################