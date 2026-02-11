//////////////////////////////////////////////////// PROJECT 1 PYTHON //////////////////////////////////////////////////////////////////////////////////////////

from sample_p0 import *

class P1_COURSE(P0_COURSE):
	def __init__(self,course_name, x, y):
		super().__init__(course_name,x)
		self.courseName = course_name # name of the course
		self.n = x # number of students
		self.noof_exams = y # number of exams

        # creating a Python array of a specific length and initializing all elements to 0 
		# Note that these arrays are not static, we can append to or pop from these lists:
		self.id = [0 for _ in range(x)] # same as int id[x] = {0, 0, 0, 0, 0, ... etc.} in C++
		self.pin = [0 for _ in range(x)] # same as int pin[x] = {0, 0, 0, 0, 0, ... etc.} in C++
		self.examGrades = [0 for _ in range(y)] 

        # not as conventional way in Python but closer to the original sample_p0.h 
		i = 0 
		with open('studentInfo.txt','r') as i_f, open('studentGrades.txt','r') as i_f2:
			for line in i_f: 
				self.id[i] = line.split()[0] # read first word from the line and put it into id array
				self.pin[i] = line.split()[1] # read second word from the line and put it in pin array
				i += 1
			self.examGrades = [row.split() for row in i_f2]

		output_file.write ("++++ P1 ++ START ++++\n")
		output_file.write ("++++ P1  CONSTRUCTOR INSTANTIATED A P1_COURSE OBJECT.\n");
		output_file.write (f"++++ P1  THERE ARE {self.noof_exams} EXAMS.\n")
		output_file.write ("++++ P1 ++ END ++++ \n")

######## python code starts here ############################
	def P1_LIST(self, x):
		output_file.write("++++ P1 ++ START OUTPUT FROM P1_LIST METHOD:\n")
		if(x == 0 or x == 1):
			print("here in if\n")
			output_file.write(f"++++ P1 ++ INHERITING FROM P0_LIST({x}):\n")
			self.P0_LIST(x)
		elif (x == 2):
			output_file.write(f"++++ P1 ++ INFORMATION FOR {self.courseName}:\n")
			for i in range(self.n):
				output_file.write(f"STUDENT ID: {self.id[i]} GRADES:")
				for j in range(self.noof_exams):
					output_file.write(f"{self.examGrades[i][j]} ")
				output_file.write("\n")
		else:
			print("input error\n")
			output_file.write(f"++++ P1 ++ SINCE P1_LIST IS CALLED WITH {x}, INPUT ERROR.\n")
		output_file.write("++++ P1 ++ END OUTPUT FROM P1_LIST METHOD\n")
######## python code ends here ############################

########################### FIND MIN ##############################################
	def P1_MIN(self, x):
		#print(f"++++ P1 ++ P1_MIN: x ==== {x} P1_LIST METHOD: \n")
		output_file.write("++++ P1 ++ START OUTPUT FROM P1_MIN METHOD: \n")
		if (x < 0) or (x >= self.noof_exams):
			output_file.write(f"++++ P1 INPUT ERROR\n");
			return -2
		else:
			min = self.examGrades[0][x]
			min_pos = -1
			for i in range(self.n):
				if (min > self.examGrades[i][x]):
					min = self.examGrades[i][x]
					min_pos = i;
		output_file.write(f"++++ P1 THE LOWEST GRADE FOR EXAM {x} IS {min}.\n") 

		output_file.write("++++ P1 ++ END OUTPUT FROM P1_MIN METHOD\n")
  ########################### FIND MIN ##############################################
	def P1_FIND(self, x,y):   # x = id and y = pin
		#print(f"++++ P1 ++ P1_MIN: x ==== {x} P1_FIND METHOD: \n")
		output_file.write("++++ P1 ++ START OUTPUT FROM P1_FIND METHOD: \n")
		if (x <= 0) or (x >= 9999) or (y <= 0) or (y> 999):
			output_file.write(f"++++ P1 INPUT ERROR.\n")
			output_file.write ("++++ P1 ++ END OUTPUT FROM P1_FIND METHOD \n") 
			return -2
		else:
			FOUND = -1
			for i in range(self.n):
				#print(f"id[{i}] is {self.id[i]} and x is {x}\t")
				#print(f"pin[{i}] is {self.pin[i]} and y is {y}\n")
				if (int(self.id[i]) == x) and (int(self.pin[i]) == y):
					output_file.write(f"++++ P1 STUDENT {x}  IS IN THIS CLASS.\n") 
					output_file.write ("++++ P1 ++ END OUTPUT FROM P1_FIND METHOD \n") 
					FOUND = 1
					return i
				else:
					pass
		
		################### if we reach at this point studend is not found 		
		output_file.write(f"++++ P1 NO SUCH STUDENT WITH ID {x} AND PIN {y}.\n")
		output_file.write ("++++ P1 ++ END OUTPUT FROM P1_FIND METHOD \n") 
		return FOUND


