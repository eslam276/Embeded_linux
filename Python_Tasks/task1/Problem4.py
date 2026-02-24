
""" 
Sum 1 … n — Compute and display the running total.
Input: 5 → Output: 15

"""

def Acc_Func(num:int):
    sum = 0 
    for i in range(num+1):
        sum+=i
        print(f"add {i} sum = {sum}")
    
    return sum

num = int(input("Enter the number : "))

print(f"The sum = {Acc_Func(num)}")



    
    