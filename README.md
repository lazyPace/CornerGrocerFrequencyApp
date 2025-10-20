# Corner Grocer - Frequency App

A small C++ console app that reads a grocery transactions file and reports item frequencies. Built in Visual Studio as part of CS-210.

## Build & Run

- **Requirements:** Visual Studio (MSVC toolchain), C++14 or later
- **Open:** `CornerGroceryFrequencyApp.sln` in Visual Studio
- **Set startup project:** `CornerGroceryFrequencyApp`
- **Input file:** `CS210_Project_Three_Input_File.txt`
- **Run:** `Ctrl+F5`


---

## Reflection

### 1) Project Summary and problem solved

This program ingest a plain-text list of purchased grocery items and outputs: 
- The frequency of a specific item queried by the user. 
- A full frequency report of all items (sorted)
- A histogram-style view of frequencies using '*' characters.

It solves the need to quickly analyze item popularity from a raw, line-delimited input file, allowing clearer insights into which items in the produce section are popular, and which are not.


### 2) What I did particularly well

- Clear, modular class design using FrequencyTracker to encapsulate all logic for file handling, counting and printing.
- Robust input handling: Guards against missing files and invalid user input
- Readable, consistent naming and comment style

### 3) Where I could enhance the code
- **Error handling:** Add richer diagnostics to improve supportability.
- **Data validation:** Implement data validation to functions handling file I/O to ensure data validity from the start.
- **Case:** Extend support for case-insensitive matching.

### 4) Hardest pieces & how I overcame them
- **Parameter passing:** Deciding when to use references versus values. 
- **File Loading:** Loading and retrieving data from the input file required careful attention to file handling and trimming the stray carriage returns. 
- **Incremental Testing:** Developing a bit and testing early and often helped identify these quirks so a solution could be found swiftly.


### 5) Transferable skills
- Working with C++ STL containers
- Modular class design and header/source file separation
- Exception-based handling
- Input validation and iterative debugging

### 6) Making the program maintainable, readable, and adaptable

Each function has a clear responsibility. The class encapsulation prevents global variable misuse and improves readability.

Consistent naming conventions, inline comments, and separated headers make it easy for another developer to extend or reuse `FrequencyTracker` in other C++ applications.
