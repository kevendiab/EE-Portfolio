//////////////////////////////////////////////////// PROJECT 0 python //////////////////////////////////////////////////////////////////////////////////////////


output_file = open("python_Output.txt",'w')
class P0_COURSE:

	def __init__(self,course_name, x):
		self.courseName = course_name # name of the course
		self.n = x # number of customers
		print(f"x = {self.n}\n")
		print(f"courseName = {self.courseName}\n")

        # creating a Python array of a specific length and initializing all elements to 0 
		# Note that these arrays are not static, we can append to or pop from these lists:
		self.id = [0 for _ in range(x)] # same as int id[x] = {0, 0, 0, 0, 0, ... etc.} in C++
		self.pin = [0 for _ in range(x)] # same as int pin[x] = {0, 0, 0, 0, 0, ... etc.} in C++

        # not as conventional way in Python but closer to the original sample_p0.h 
		i = 0 
		with open('studentInfo.txt','r') as i_f:
			for line in i_f: 
				self.id[i] = line.split()[0] # read first word from the line and put it into id array
				self.pin[i] = line.split()[1] # read second word from the line and put it in pin array
				i += 1
				print(i)

		output_file.write (f"++ P0 ++ START ++++\n")
		output_file.write (f"++ P0  CONSTRUCTOR SUCCESSFULLY INSTANTIATED A P0_COURSE OBJECT.\n");
		output_file.write (f"++ P0  NAME OF THE COURSE IS {self.courseName}.\n")
		output_file.write (f"++ P0  THERE ARE {self.n} STUDENTS IN THIS P0_COURSE OBJECT.\n")
		output_file.write (f"++ P0 ++ END ++++ \n")
    
	def P0_LIST(self, x):
		print(f"x is {x}\n")
		output_file.write ("++ P0 ++ START OUTPUT FROM P0_LIST METHOD:\n")
		if (x == 0):
			output_file.write (f"++ P0 THE COURSE IS {self.courseName} WITH {self.n} STUDENTS.\n")
			output_file.write ("++ P0 ++ END OUTPUT FROM P0_LIST METHOD.\n")
		elif (x == 1):
			output_file.write (f"++ P0 THE COURSE IS {self.courseName} WITH {self.n} STUDENTS.\n")
			print(f"x is {x}\n")
			for i in range (self.n):
				output_file.write(f"++ P0 {self.id[i]}\n")
		else:
			print(f"x is {x}\n")
			output_file.write(f"++ P0 SINCE P0_LIST IS CALLED WITH {x}, INPUT ERROR.\n")
		output_file.write("++ P0 ++ END OUTPUT FROM P0_LIST METHOD.\n")
