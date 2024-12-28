# Generate product data
product_data = "\n".join([
    f"{i+1} Product{i+1} {round((i+1)*10.5, 2)} {i%100 + 1}" for i in range(5000)
])

# Save the data to a file
file_name = "products.txt"
with open(file_name, "w") as file:
    file.write(product_data)

print(f"Database of 5,000 products has been saved to '{file_name}'.")
