import socket

HOST = '0.0.0.0'   
PORT = 9990       

def calculate(op, a, b):
    if op == '+': return a + b
    elif op == '-': return a - b
    elif op == '*': return a * b
    elif op == '/':
        return "Error: Division by zero" if b == 0 else a / b
    else:
        return "Error: Invalid operator"

# Create socket
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)

print(f"[SERVER] Listening on {HOST}:{PORT} ...")

while True:
    conn, addr = server.accept()
    print(f"[SERVER] Connection from {addr}")

    data = conn.recv(1024).decode()
    if not data:
        conn.close()
        continue

    # Expecting format like: "5 + 3"
    try:
        a, op, b = data.split()
        a = float(a)
        b = float(b)
        result = calculate(op, a, b)
    except Exception as e:
        result = f"Error: {str(e)}"

    conn.send(str(result).encode())
    print(f"[SERVER] Sent result: {result}")
    conn.close()
