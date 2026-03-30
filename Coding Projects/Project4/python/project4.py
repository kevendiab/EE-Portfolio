from sample_p3 import *

class P4_COURSE(P3_COURSE):
    def __init__(self, c_name, x, y):
        super().__init__(c_name, x, y)
        output_file.write(f"++++++++++ P4 CONSTRUCTOR INSTANTIATED AN OBJECT NAMED {c_name} \n")
        output_file.write("===============================================================\n")

    def __gt__(self, input_var):
        output_file.write("++++++++++ P4 ====== START =====================\n")
        output_file.write(f"++++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > FOR OBJECT {self.courseName}:\n")

        if isinstance(input_var, int):
            result = self.n > input_var
        else:
            result = self.n > input_var.n

        output_file.write(f"++++++++++ P4 EVALUATED {'TRUE' if result else 'FALSE'}.\n")
        output_file.write("++++++++++ P4 ====== END =======================\n")
        return result

    def __iadd__(self, obj2):
        output_file.write("++++++++++ P4 ====== START =====================\n")
        output_file.write(f"++++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR += FOR OBJECT {self.courseName}:\n")

        for i in range(obj2.n):
            index = self.P3_INSERT(obj2.id[i], obj2.pin[i], obj2.firstNames[i], obj2.lastNames[i])
            if index != -1 and index != -2:
                for j in range(self.noof_exams):
                    self.examGrades[index][j] = obj2.examGrades[i][j]

        output_file.write("++++++++++ P4 ====== END =====================\n")
        return self

    def __isub__(self, x):
        output_file.write("++++++++++ P4 ====== START =====================\n")
        output_file.write(f"++++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR -= FOR OBJECT {self.courseName}:\n")

        index = -1
        for i in range(self.n):
            if self.id[i] == x:
                index = i

        if index != -1:
            output_file.write(f"++++++++++ P4 STUDENT WITH ID {x} IS DELETED FROM THIS OBJECT.\n")
            for i in range(index, self.n - 1):
                self.firstNames[i] = self.firstNames[i + 1]
                self.lastNames[i] = self.lastNames[i + 1]
                self.id[i] = self.id[i + 1]
                self.pin[i] = self.pin[i + 1]
                for j in range(self.noof_exams):
                    self.examGrades[i][j] = self.examGrades[i + 1][j]
            self.n -= 1
            output_file.write(f"++++++++++ P4 NOW THERE ARE {self.n} STUDENTS IN OBJECT {self.courseName}.\n")
        else:
            output_file.write(f"++++++++++ P4 NO SUCH STUDENT WITH ID {x}.\n")

        output_file.write("++++++++++ P4 ====== END =======================\n")
        return self

    def INSERT_STUDENT(self, F, L, x, y):
        output_file.write("++++++++++ P4 ====== START =====================\n")
        output_file.write("++++++++++ P4 OUTPUT FROM P3_INSERT METHOD:\n")
        r_v = self.P3_INSERT(x, y, F, L)
        output_file.write("++++++++++ P4 ====== END =======================\n")
        return r_v

    def P4_SORT(self):
        output_file.write("++++++++++ P4 ====== START =====================\n")
        output_file.write("++++++++++ P4 OUTPUT FROM P4_SORT METHOD:\n")
        self.P3_ALPHABETIZE()
        output_file.write("++++++++++ P4 ====== END =======================\n")
