import socket

SERVER_IP = '127.0.0.1'  # Change to server IP when running on another machine
PORT = 9990

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((SERVER_IP, PORT))

print("=== TCP Calculator Client ===")
expr = input("Enter operation (e.g. 5 + 3): ")

client.send(expr.encode())
result = client.recv(1024).decode()

print(f"Result from server: {result}")

client.close()
