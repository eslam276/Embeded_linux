
""" Write a Python program which accepts the radius of a circle from the user and compute the area."""

def Clac_Area(radius: float):
    return 3.14 * (radius **2)

radius = float(input("Enter the radius : "))
Area = Clac_Area(radius)
print(f'The Area = {Area} ')