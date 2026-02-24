
""" Count number of 4 in a given list """


my_list = [1,3,4,6,6,4,3,4,6,4,3,2,3,3,4,6,5,43,2,345,6,54,323,45,6,54,3,4]

count = 0 

for i in my_list:
    if i ==4 :
        count+=1
print(count)

####################################### Another solution ########################################################################


count = len([i for i in my_list if i ==4])
print(count)