# Basic File Operations in Python
# This program demonstrates reading, writing, and manipulating files

import os

# ========== FILE WRITING OPERATIONS ==========

def write_to_file(filename, content):
    """
    Write content to a file (overwrites existing content)
    
    Args:
        filename (str): Name of the file to write to
        content (str): Content to write to the file
    """
    try:
        # Open file in write mode ('w')
        # This will create a new file or overwrite an existing one
        with open(filename, 'w') as file:
            file.write(content)
        print(f"✓ Successfully wrote to {filename}")
    except Exception as e:
        print(f"✗ Error writing to file: {e}")


def append_to_file(filename, content):
    """
    Append content to the end of a file
    
    Args:
        filename (str): Name of the file to append to
        content (str): Content to append to the file
    """
    try:
        # Open file in append mode ('a')
        # This adds content to the end without deleting existing data
        with open(filename, 'a') as file:
            file.write(content)
        print(f"✓ Successfully appended to {filename}")
    except Exception as e:
        print(f"✗ Error appending to file: {e}")


# ========== FILE READING OPERATIONS ==========

def read_entire_file(filename):
    """
    Read and return the entire contents of a file
    
    Args:
        filename (str): Name of the file to read
    
    Returns:
        str: Contents of the file, or None if error occurs
    """
    try:
        # Open file in read mode ('r')
        with open(filename, 'r') as file:
            content = file.read()
        print(f"✓ Successfully read {filename}")
        return content
    except FileNotFoundError:
        print(f"✗ Error: File '{filename}' not found")
        return None
    except Exception as e:
        print(f"✗ Error reading file: {e}")
        return None


def read_file_lines(filename):
    """
    Read a file line by line and return as a list
    
    Args:
        filename (str): Name of the file to read
    
    Returns:
        list: List of lines from the file, or None if error occurs
    """
    try:
        # Open file and read all lines into a list
        with open(filename, 'r') as file:
            lines = file.readlines()
        print(f"✓ Successfully read {len(lines)} lines from {filename}")
        return lines
    except FileNotFoundError:
        print(f"✗ Error: File '{filename}' not found")
        return None
    except Exception as e:
        print(f"✗ Error reading file: {e}")
        return None


# ========== FILE UTILITY OPERATIONS ==========

def file_exists(filename):
    """
    Check if a file exists
    
    Args:
        filename (str): Name of the file to check
    
    Returns:
        bool: True if file exists, False otherwise
    """
    return os.path.exists(filename)


def get_file_size(filename):
    """
    Get the size of a file in bytes
    
    Args:
        filename (str): Name of the file
    
    Returns:
        int: Size of file in bytes, or None if file doesn't exist
    """
    try:
        size = os.path.getsize(filename)
        print(f"File size: {size} bytes")
        return size
    except FileNotFoundError:
        print(f"✗ Error: File '{filename}' not found")
        return None


def delete_file(filename):
    """
    Delete a file
    
    Args:
        filename (str): Name of the file to delete
    """
    try:
        if file_exists(filename):
            os.remove(filename)
            print(f"✓ Successfully deleted {filename}")
        else:
            print(f"✗ Error: File '{filename}' not found")
    except Exception as e:
        print(f"✗ Error deleting file: {e}")


# ========== DEMO USAGE ==========
# The following code demonstrates how to use the file operation functions

def demo():
    """
    Demonstrate all file operations with a sample file
    """
    print("\n📁 Basic File Operations Demo\n")
    
    # Demo filename
    demo_file = "demo_file.txt"
    
    # 1. Write to a new file
    print("1. Writing to file...")
    write_to_file(demo_file, "Hello, World!\n")
    write_to_file(demo_file, "This is a test file.\n")
    
    # 2. Append to the file
    print("\n2. Appending to file...")
    append_to_file(demo_file, "This line was appended.\n")
    append_to_file(demo_file, "Another appended line.\n")
    
    # 3. Read the entire file
    print("\n3. Reading entire file...")
    content = read_entire_file(demo_file)
    if content:
        print("File contents:")
        print("-" * 40)
        print(content)
        print("-" * 40)
    
    # 4. Read file line by line
    print("\n4. Reading file line by line...")
    lines = read_file_lines(demo_file)
    if lines:
        print("Lines in file:")
        for i, line in enumerate(lines, 1):
            print(f"  Line {i}: {line.strip()}")
    
    # 5. Check file existence and get size
    print("\n5. File utilities...")
    print(f"File exists: {file_exists(demo_file)}")
    get_file_size(demo_file)
    
    # 6. Clean up - delete the demo file
    print("\n6. Cleaning up...")
    delete_file(demo_file)
    print(f"File exists after deletion: {file_exists(demo_file)}")
    
    print("\n✨ Demo completed!\n")


# Run the demo when the script is executed
if __name__ == "__main__":
    demo()
    print("💡 Tip: Modify this code to practice file operations with your own files!\n")
