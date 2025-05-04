class student:
    def __init__(self, major, gpa):
        self.major = major
        self.gpa = gpa
    
    def print_student(self):
        print(f"Major: {self.major}, GPA: {self.gpa}")
        if self.gpa >= 3.6:
            print("Dean's List")
        
        
        
    
s = student("Robo", 3.8)
s2 = student("MI", 3.9)