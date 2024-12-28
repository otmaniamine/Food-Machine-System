# Generate user data
user_data = "\n".join([
    f"user{i} pass{i} {'Customer' if i % 2 != 0 else 'Admin'}" for i in range(0, 5000)
])

# Save the data to a file
file_name = "users.txt"
with open(file_name, "w") as file:
    file.write(user_data)

print(f"User data has been saved to '{file_name}'.")
