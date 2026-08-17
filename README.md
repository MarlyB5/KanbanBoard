## Technical Overview

The Kanban Board is a command-line application written in **C** that allows users to create, modify, save, and load a Kanban-style task board.

The project was developed with a focus on applying fundamental programming and data structure concepts in a practical application.

### Data Structures

The board is primarily implemented using **doubly linked lists**. Each Kanban list is connected to the previous and next lists using pointers, allowing the program to dynamically add, remove, and navigate between lists.

Items are also dynamically associated with their respective lists, allowing each list to contain its own collection of tasks.

This implementation demonstrates concepts including:

* Doubly linked lists
* Pointer manipulation
* Dynamic memory allocation
* Linked-list traversal
* Insertion and deletion operations

### Memory Management

As the program uses dynamically allocated data structures, memory management is an important part of the implementation.

When lists or items are removed, the associated dynamically allocated memory is freed appropriately. This helps prevent memory leaks and ensures that the program manages its resources correctly.

### File Handling and Persistence

The application supports **saving and loading Kanban boards** using file I/O.

When a board is saved, the program traverses the linked-list structure and writes the board's lists and items to a file in a structured format.

When the board is loaded again, the file is read line by line and the linked-list structure is reconstructed. A helper function, `parseLine`, is used to interpret the saved data and determine whether each line represents a list or an item.

This allows users to maintain their board between different program sessions.

### Program Structure

The project separates different responsibilities into dedicated functions rather than placing all functionality inside the main program.

Functions are used for operations such as:

* Displaying the board
* Adding and deleting lists
* Renaming lists
* Adding and deleting items
* Saving the board
* Loading a saved board
* Parsing saved board data
* Managing user menu selections

This modular structure makes the program easier to understand, test, debug, and maintain.

---

## How to Run

### Requirements

To compile and run the project, you will need:

* A C compiler such as **GCC**
* A terminal or command-line environment
* The project source files

Alternatively, the project can be opened and run using a C/C++ development environment such as **CLion**.

### Running with CLion

1. Clone or download the repository.
2. Open **CLion**.
3. Select **Open** and choose the project folder.
4. Allow CLion to load the project and configure CMake.
5. Build the project using the **Build** option.
6. Select the appropriate executable configuration.
7. Click **Run** to start the program.
8. Follow the options displayed in the terminal to interact with the Kanban board.

### Running from the Terminal

First, clone the repository:

```bash
git clone https://github.com/MarlyB5/KanbanBoard.git
```

Move into the project directory:

```bash
cd KanbanBoard
```

If the project includes a `CMakeLists.txt` file, it can be built using CMake:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

The generated executable can then be run from the build directory.

For example:

```bash
./kanban
```

> **Note:** The exact executable name may depend on the target name specified in `CMakeLists.txt`.

### Using the Application

Once the program starts, the main menu will display the available Kanban board operations.

The user can select menu options to perform actions such as:

* Display the current board
* Edit lists
* Edit items
* Save the board
* Load a previously saved board
* Exit the application

The program will continue displaying the appropriate menus until the user chooses to exit.


## Key Functions and Features

### Save Board

The `saveBoard` function allows the user to save the current state of the Kanban board to a file so that it can be accessed again later.

The function opens a file for writing and traverses the linked-list structure used to represent the board. For each list, it writes the list name followed by its associated items in a structured format.

This provides persistence between program sessions, allowing users to close the application without losing their current Kanban board.

---

### Load Board

The `loadBoard` function reconstructs a previously saved Kanban board from a file.

A helper function called `parseLine` is used to analyse each line of the saved file. It determines whether the current line represents a list or an item based on the formatting of the line, including the presence of a colon (`:`).

`loadBoard` reads the saved file line by line and passes each line to `parseLine`, which rebuilds the appropriate linked-list structures.

Separating the parsing logic into its own helper function keeps the loading process organised and modular while making the code easier to maintain.

---

### Main Menu

The main menu provides the primary interface for navigating the Kanban board application.

It displays the available options to the user and processes their selection using a `switch` statement. Depending on the user's choice, the appropriate function is called.

This provides a simple command-line interface through which the user can access the main features of the program.

---

### Board Editing

The board editing functionality allows users to modify the overall structure of their Kanban board.

The edit board menu provides options to:

- Rename an existing list
- Add a new list
- Delete an existing list
- Return to the main menu

A `switch` statement is used to process the user's selection and call the corresponding function.

#### Editing a List Name

The `edit_list_name` function traverses the linked list until it finds the list matching the name provided by the user. Once the correct list has been found, its name is updated.

#### Adding and Deleting Lists

The add and delete functions modify the linked-list structure of the board.

When a list is added or removed, the program correctly updates the `prev` and `next` pointers to maintain the integrity of the doubly linked list.

When deleting a list, the program also frees the memory associated with its items before removing the list itself. This helps prevent memory leaks and ensures that dynamically allocated memory is managed correctly.

---

### Item Editing

The item editing functionality works similarly to the board editing system but operates on the items contained within a specific list.

The user first selects a list and is then presented with an item-editing menu. From here, they can perform operations such as:

- Adding a new item
- Editing an existing item
- Deleting an item
- Returning to the previous menu

These operations update the linked-list structure associated with the selected Kanban list.

---

### Display Board

The display function traverses the board and prints each list along with its associated items.

This gives the user a clear overview of the current Kanban board and allows them to see the changes made through the editing functions.

---

### ASCII Art

The program includes custom ASCII art that is displayed as part of the command-line interface.

The design depicts a female figure, similar to the symbol commonly used on public signs. We chose this design because both members of our development team are women, making it a small personalised element of the project.
