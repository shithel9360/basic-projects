# Simple Calculator Program for Beginners
# This program demonstrates basic arithmetic operations and user input handling

# Function to perform addition
def add(x, y):
    """Add two numbers and return the result"""
    return x + y

# Function to perform subtraction
def subtract(x, y):
    """Subtract y from x and return the result"""
    return x - y

# Function to perform multiplication
def multiply(x, y):
    """Multiply two numbers and return the result"""
    return x * y

# Function to perform division
def divide(x, y):
    """Divide x by y and return the result"""
    # Check if the divisor is zero to avoid division by zero error
    if y == 0:
        return "Error: Cannot divide by zero!"
    return x / y

# Main program
def calculator():
    """Main calculator function that handles user interaction"""
    print("\n=== Simple Calculator ===")
    print("Select an operation:")
    print("1. Add")
    print("2. Subtract")
    print("3. Multiply")
    print("4. Divide")
    print("5. Exit")
    
    while True:
        # Get user's choice
        choice = input("\nEnter your choice (1-5): ")
        
        # Exit if user chooses option 5
        if choice == '5':
            print("Thank you for using the calculator. Goodbye!")
            break
        
        # Validate the choice
        if choice not in ['1', '2', '3', '4']:
            print("Invalid choice! Please enter a number between 1 and 5.")
            continue
        
        # Get numbers from user
        try:
            num1 = float(input("Enter first number: "))
            num2 = float(input("Enter second number: "))
        except ValueError:
            print("Invalid input! Please enter numeric values.")
            continue
        
        # Perform calculation based on user's choice
        if choice == '1':
            result = add(num1, num2)
            operation = "+"
        elif choice == '2':
            result = subtract(num1, num2)
            operation = "-"
        elif choice == '3':
            result = multiply(num1, num2)
            operation = "*"
        elif choice == '4':
            result = divide(num1, num2)
            operation = "/"
        
        # Display the result
        print(f"\nResult: {num1} {operation} {num2} = {result}")

# Run the calculator when the script is executed
if __name__ == "__main__":
    calculator()
