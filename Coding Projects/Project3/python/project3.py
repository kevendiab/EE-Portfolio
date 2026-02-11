//////////////////////////////////////////////////// PROJECT 3 PYTHON //////////////////////////////////////////////////////////////////////////////////////////

from sample_p2 import *

class P3_COURSE(P2_COURSE):
	def __init__(self,course_name, x, y):
		super().__init__(course_name, x, y)
		self.firstNames = [0 for _ in range(15)] 
		self.lastNames = [0 for _ in range(15)] 
		i = 0
		with open('studentNames.txt','r') as i_f_3:
			for line in i_f_3: 
				self.firstNames[i] = line.split()[0] # read first word from the line and put it into id array
				self.lastNames[i] = line.split()[1] # read first word from the line and put it into id array
				i += 1
		output_file.write("++++++++ P3 ++ START ++++\n")
		output_file.write(f"++++++++ P3 THERE ARE {x} STUDENTS IN THIS P3_COURSE OBJECT.\n" )
		output_file.write(f"++++++++ P3 THERE ARE {y} EXAMS FOR EACH STUDENT.\n")
		output_file.write("++++++++ P3 ++ END  ++++\n")
	
	def P3_LIST_ALL(self):

		output_file.write("++++++++ P3 ++ START OUTPUT FROM P3_LIST_ALL METHOD:\n")
		
		for i in range(self.n):
			output_file.write (f"++++++++ P3 {self.firstNames[i]}\t{self.lastNames[i]}\t")
			for j in range(self.noof_exams):
				output_file.write (f"{self.examGrades[i][j]} ")
			output_file.write ("\n")

		output_file.write ("++++++++ P3 ++ END OUTPUT FROM P3_LIST_ALL METHOD\n")

	def P3_ALPHABETIZE(self):
		output_file.write("++++++++ P3 ++ START OUTPUT FROM P3_ALPHABETIZE METHOD:\n ") 

		minindex = 0
		for i in range(self.n-1):
			for j in range(i+1,self.n):
				if(self.lastNames[j]< self.lastNames[i]): #if a smaller last name is found
					minindex = j #update the minimum index
			
			self.lastNames[i], self.lastNames[minindex] = self.lastNames[minindex], self.lastNames[i] # swap student last names
			self.firstNames[i],self.firstNames[minindex] = self.firstNames[minindex], self.firstNames[i]  # swap student first names
			self.id[i], self.id[minindex] = self.id[minindex], self.id[i]  # swap ID's
			self.pin[i],self.pin[minindex] = self.pin[minindex],self.pin[i] # swap pins 
			for k in range(self.noof_exams):
				self.examGrades[i][k], self.examGrades[minindex][k] = self.examGrades[minindex][k] , self.examGrades[i][k]  # swap exam grades
		output_file.write("++++++++ P3 ++ END OUTPUT FROM P3_ALPHABETIZE METHOD\n")


	def P3_INSERT(self, x, y, F, L):
	    output_file.write("++++++++ P3 ++ START OUTPUT FROM P3_INSERT METHOD:\n")
	    output_file.write(f"++++++++ P3 P3_INSERT IS CALLED WITH x: {x}, y: {y}, first name: {F}, last name: {L}\n")

	    if x < 0 or y > 99999 or y<0 or not F or not L:
	        output_file.write("++++++++ P3 INPUT ERROR.\n")
	        output_file.write("++++++++ P3 ++ END OUTPUT FROM P3_INSERT METHOD\n")
	        return -2

	    output_file.write(f"++++++++ P3 INVOKING P1_FIND({x},{y}):\n")
	    find = self.P1_FIND(x, y)

	    if find != -1:
	        output_file.write("++++++++ P3 STUDENT IS ALREADY IN THIS OBJECT:\n")
	        output_file.write(f"++++++++ P3 LAST NAME: {self.lastNames[find]} FIRST NAME: {self.firstNames[find]} ID: {x}\n")
	        output_file.write(f"++++++++ P3 THERE ARE STILL {self.n} STUDENTS IN THIS OBJECT\n")
	        output_file.write("++++++++ P3 ++ END OUTPUT FROM P3_INSERT METHOD\n")
	        return -1

	    elif find == -1:
		    self.id[self.n] = x
		    self.pin[self.n] = y
		    self.firstNames[self.n] = F
		    self.lastNames[self.n] = L
	    for j in range(self.noof_exams):
	        self.examGrades[self.n][j] = 0
	    self.n += 1
	    updatednos = self.n

	    output_file.write("++++++++ P3 NEW STUDENT ADDED TO THIS OBJECT:\n")
	    output_file.write(f"++++++++ P3 LAST NAME: {L} FIRST NAME: {F} ID: {x}\n")
	    output_file.write(f"++++++++ P3 NOW THERE ARE {self.n} STUDENTS IN THIS OBJECT.\n")
	    output_file.write("++++++++ P3 ++ END OUTPUT FROM P3_INSERT METHOD\n")
	    return updatednos

	def P3_UPDATE(self, x, y, z, w):

	    output_file.write("++++++++ P3 ++ START OUTPUT FROM P3_UPDATE METHOD:\n")
	    output_file.write(f"++++++++ P3 P3_UPDATE IS CALLED WITH x: {x}, y: {y}, z: {z}, w: {w}\n")

	    if x < 0 or y > 99999 or y < 0 or z >= self.noof_exams or z < 0 or w < 0 or w > 100:
	        output_file.write("++++++++ P3 INPUT ERROR.\n")
	        output_file.write("++++++++ P3 ++ END OUTPUT FROM P3_UPDATE METHOD\n")
	        return -2

	    output_file.write(f"++++++++ P3 INVOKING P1_FIND({x},{y}):\n")
	    find = self.P1_FIND(x, y)

	    if find == -1:
	        output_file.write(f"++++++++ P3 NO SUCH STUDENT WITH ID {x} AND PIN {y}.\n")
	        output_file.write("++++++++ P3 ++ END OUTPUT FROM P3_UPDATE METHOD\n")
	        return -1

	    elif find !=-1:
		    self.examGrades[find][z] = w
		    output_file.write(f"++++++++ P3 FOR STUDENT ID {x} EXAM {z} GRADE IS SET TO {w}.\n")
		    output_file.write("++++++++ P3 ++ END OUTPUT FROM P3_UPDATE METHOD\n")
		    return find