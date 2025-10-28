// Simple To-Do List Application for Beginners
// This program demonstrates arrays, objects, and basic CRUD operations

// Array to store all todo items
let todoList = [];

// Variable to track unique IDs for each todo item
let nextId = 1;

/**
 * Add a new task to the todo list
 * @param {string} task - The task description
 */
function addTask(task) {
    // Create a new todo object with id, task, and completion status
    const newTodo = {
        id: nextId++,
        task: task,
        completed: false
    };
    
    // Add the new todo to the array
    todoList.push(newTodo);
    console.log(`✓ Task added: "${task}"`);
}

/**
 * Remove a task from the todo list by its ID
 * @param {number} id - The ID of the task to remove
 */
function removeTask(id) {
    // Find the index of the task with the given ID
    const index = todoList.findIndex(todo => todo.id === id);
    
    // Check if the task was found
    if (index !== -1) {
        const removedTask = todoList[index].task;
        // Remove the task from the array
        todoList.splice(index, 1);
        console.log(`✓ Task removed: "${removedTask}"`);
    } else {
        console.log(`✗ Task with ID ${id} not found.`);
    }
}

/**
 * Mark a task as completed or uncompleted
 * @param {number} id - The ID of the task to toggle
 */
function toggleComplete(id) {
    // Find the task with the given ID
    const todo = todoList.find(todo => todo.id === id);
    
    // Check if the task was found
    if (todo) {
        // Toggle the completed status
        todo.completed = !todo.completed;
        const status = todo.completed ? "completed" : "incomplete";
        console.log(`✓ Task "${todo.task}" marked as ${status}`);
    } else {
        console.log(`✗ Task with ID ${id} not found.`);
    }
}

/**
 * Display all tasks in the todo list
 */
function displayTasks() {
    console.log("\n=== TO-DO LIST ===");
    
    // Check if the list is empty
    if (todoList.length === 0) {
        console.log("No tasks yet. Add some tasks to get started!");
        return;
    }
    
    // Loop through all tasks and display them
    todoList.forEach(todo => {
        // Use a checkbox symbol to show completion status
        const status = todo.completed ? "[✓]" : "[ ]";
        // Add strikethrough for completed tasks
        const taskText = todo.completed ? `~~${todo.task}~~` : todo.task;
        console.log(`${status} ID: ${todo.id} - ${taskText}`);
    });
    console.log("==================\n");
}

/**
 * Get all incomplete tasks
 * @returns {Array} Array of incomplete tasks
 */
function getIncompleteTasks() {
    return todoList.filter(todo => !todo.completed);
}

/**
 * Get all completed tasks
 * @returns {Array} Array of completed tasks
 */
function getCompletedTasks() {
    return todoList.filter(todo => todo.completed);
}

// ========== DEMO USAGE ==========
// The following code demonstrates how to use the todo list functions

console.log("\n🎯 Simple To-Do List Demo\n");

// Adding tasks
addTask("Learn JavaScript basics");
addTask("Build a simple project");
addTask("Read programming book");
addTask("Practice coding daily");

// Display all tasks
displayTasks();

// Mark some tasks as completed
toggleComplete(1);
toggleComplete(3);

// Display updated list
displayTasks();

// Show statistics
console.log(`Total tasks: ${todoList.length}`);
console.log(`Completed: ${getCompletedTasks().length}`);
console.log(`Incomplete: ${getIncompleteTasks().length}`);

// Remove a task
removeTask(2);

// Display final list
displayTasks();

console.log("\n✨ Demo completed! Try modifying the code to add your own tasks.\n");

// Export functions for use in other modules (Node.js)
if (typeof module !== 'undefined' && module.exports) {
    module.exports = {
        addTask,
        removeTask,
        toggleComplete,
        displayTasks,
        getIncompleteTasks,
        getCompletedTasks,
        todoList
    };
}
