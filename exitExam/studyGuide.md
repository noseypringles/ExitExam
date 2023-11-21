# BA Exit Exam Study Guide

## Procedural Programming
- Static Casting
	- To have one data type changed to another data type
	- You can change int to double, double to int, int to char, char to int. ex(static_cast<int>('A') is 65 and static_cast<char>(65) is 'A')
- [Arrays](https://www.geeksforgeeks.org/cpp-arrays/)
   - an array is a data structure that is used to store multiple values of similar data types in a contiguous memory location
- [Structs](https://www.geeksforgeeks.org/structures-in-cpp/)
   - A structure is a user-defined data type in C/C++. A structure creates a data type that can be used to group items of possibly different types into a single type.
      - **Data Member**: These members are normal C++ variables. We can create a structure with variables of different data types in C++.
	  - **Member Functions**: These members are normal C++ functions. Along with variables, we can also include functions inside a structure declaration.
- [Modulus operator](https://www.geeksforgeeks.org/modulo-operator-in-c-cpp-with-examples/)
   - denoted by %, is an arithmetic operator. The modulo division operator produces the remainder of an integer division which is also called the modulus of the operation.
   - ex: num % 6 + 5
- Enums
	- is defined as a list of things.

	Correct
	```cpp
	enum Colors { BROWN, BLUE, RED, GREEN, YELLOW };
	```

	Incorrect
	```cpp
	enum Grade { 'A', 'B', 'C', 'D', 'F' }; // illegal enumeration type
	enum Place { 1ST, 2ND, 3RD, 4TH}; // illegal enumeration type

	// cannot define value, APPLE in multiple types (as shown below)
	enum Fruit { APPLE, ORANGE, PEACH };
	enum Food { MILKSHAKE, BURGER, EGGS, APPLE };
	```
	- Enumeration types are stored internally as integers, which means they can be compared with each other. You have to explicitly cast the integer back to the enm type after the operator.
	```cpp
	fav = static_cast<Sport>(mySport + 1);
	```
	- Relational Operators
	```cpp
	FOOTBALL <= SOCCER;  // true
	HOCKEY > BASKETBALL; // true
	FOOTBALL == SOCCER;  // false
	```
	- Counter in a Counter-Controlled Loop
	```cpp
	for (Sport mySport = BASKETBALL; mySport <= SOCCER;
		mySport = static_cast<Sport>(mySport + 1))
	{
		// Do stuff with mySport. Each iteration it is a different sport.
	}
	```
	- Enumeration types are stored internally as integers and therefore, will output numbers (not words) when displayed. However, we can write a function to convert the enumerated value into a string.
	
## Object-Oriented Programming
[Object-Oriented Programming](https://www.geeksforgeeks.org/object-oriented-programming-oops-concept-in-java/?ref=shm)
- [Abstract Classes:](https://www.geeksforgeeks.org/abstract-classes-in-java/)
   - An abstract class is a class that can not be instantiated by itself, it needs to be subclassed by another class to use its properties.
   - An abstract class can be created using “abstract” keywords.
   - We can have an abstract class without any abstract method.
- [Generic classes](https://www.geeksforgeeks.org/generic-class-in-java/)
   - Generics methods and classes, enables programmer with a single method declaration, a set of related methods, a set of related types. 
   - Generics also provide compile-time type safety which allows programmers to catch invalid types at compile time.
   - Generic means parameterized types. Using generics, the idea is to allow any data type to be it Integer, String, or any user-defined Datatype and it is possible to create classes that work with different data types.
   - the items or functions in that class can be generalized with the parameter(example `<T>`) to specify that we can add any type as a parameter in place of T like Integer, Character, String, Double or any other user-defined type.
- [Template arguments](https://www.geeksforgeeks.org/templates-cpp/)
   - to pass the data type as a parameter so that we don’t need to write the same code for different data types.
- [Interfaces in Java](https://www.geeksforgeeks.org/interfaces-in-java/)
   - Is 100% abstract class and has only abstract methods.
   - Can NOT have instances.
   - All variables are final (constants), public, and static.

## Data Structures
- **Linked Lists** - store data in nodes, where each node contains the data and pointer to the next node. Best for linear data structure.
	- Uses: stack, queue, or where elements need to be efficiently added or removed from middle of the structure.
	- Advantages
		- Efficient insertion and deletion of elements, dynamic size, easy to implement
		- A variable size; memory is allocated and released as needed.
		- Some algorithms are faster with linked lists compared to arrays.
		- Expandable to nonlinear data structures (nodes with multiple pointers) ex: trees and graphs.

- **Binary Tree** - is either empty or has these properties: root node and two sets of nodes( left subtree and right subtree). Best for hierarchical data.
	- Uses: file systems, organizational charts, or searching and sorting algorithms like binary search tree
	- Advantages
		- Efficient searching, insertion, and deletion (especially when balanced)

- **HashTable** - map keys to values. Best for fast access to data using keys and avoid collisions efficiently.
	- Uses: dictionary, symbol table, or when to retrieve values based on a key quickly.
	- Advantages
		- Fast lookup, efficient for associative arrays, maps and caches.

- [Big-O](https://flexiple.com/algorithms/big-o-notation-cheat-sheet) notation for various data structures
   - Constant: O(1)
   - Linear time: O(n)
   - Logarithmic time: O(n log n)
   - Quadratic time: O(n^2)
   - Exponential time: 2 ^(n)
   - Factorial time: O(n!)

## Scripting Languages
- [Scripting Language](https://www.geeksforgeeks.org/introduction-to-scripting-languages/)
   - Designed for gluing together more task-focused components that may be written using systems programming languages
   - Each line of code is interpreted at runtime instead of beforehand like compiled programs.
   - Can process a string as a snippet of code
   - Can not Function overload
   - Faster to write scripting code but has slower execution speed
- What does it mean for an object to be [Immutable?](https://www.interviewcake.com/concept/java/mutable)
   - Can't be changed after it is created.
   - In Java, strings are immutable, but can be mutable depending on the language.
   - You can make objects immutable by making all fields final and private.
- [Shallow vs Deep Copy](https://www.geeksforgeeks.org/difference-between-shallow-and-deep-copy-of-a-class/)
   - **Shallow Copy**: Shallow repetition is quicker. However, it’s “lazy” it handles pointers and references. Rather than creating a contemporary copy of the particular knowledge the pointer points to, it simply copies over the pointer price. So, each of the first and therefore the copy can have pointers that reference constant underlying knowledge.
   - **Deep Copy**: Deep repetition truly clones the underlying data. It is not shared between the first and therefore the copy.

## [Perl](https://www.geeksforgeeks.org/perl-basic-syntax-of-a-perl-program/?ref=lbp)
- Scalar Variables: an individual unit of data. Defined with `$` preceding their name
- Three types
   1) Numbers
   2) Strings
   3) References
- Array Variables: defined with the `@` preceding the name

## [Python](https://www.geeksforgeeks.org/python-3-basics/?ref=lbp)
- No braces or semicolons. Just indentation for blocks
- If...elif...else
- No auto-increment `i++` or auto-decrement `i--`
- The “is” operator compares objects by reference (do they point to the same memory location)
- Uses ‘and’, ‘or’, ‘not’ for boolean logic, instead of symbolic operators `&&`, `||`, `!`

## [Shell](https://www.geeksforgeeks.org/how-to-create-a-shell-script-in-linux/?ref=lbp)
- A user interface to the operating system’s services
- Mostly CLIs (Command Line Interfaces)

## [Bash](https://www.geeksforgeeks.org/bash-scripting-introduction-to-bash-and-bash-scripting/)
- Bourne Again Shell

## Applied Networking
- Protocol: defines the format and the order of messages exchanged between two or more communicating entities, as well as the actions taken on the transmission and/or receipt of a message or other event.
- [7 OSI Protocol Layers:](https://www.checkpoint.com/cyber-hub/network-security/what-is-the-osi-model-understanding-the-7-layers/)
   1) Application:
      - Responsible for initiating or servicing the request
      - DNS, HTTP, HTTPS, FTP, Telnet, SIP
   2) Presentation
      - Formats the information so that it is understood by the receiving system
      - Compression and encryption depending on the implementation
   3) Session
      - Responsible for establishing. Managing, and terminating the session
   4) Transport
      - Breaks information into segments and is responsible for connection and connectionless communication
      - TCP, UDP
   5) Network
      - Responsible for logical addressing and routing
   6) Data Link
      - Responsible for physical addressing, error correction, and preparing the information for the media
      - ARP
   7) Physical
      - Deals with the electrical signal

- [5-Layer Internet Protocol Stack](https://www.educative.io/answers/what-is-the-five-layer-internet-protocol-stack)
   - **Application**
      - responsible for communication between applications running on two different end systems.
   - **Transport**
      -  responsible for collecting the application layer message from the relevant end-point and transferring it to the network layer to be communicated over the network.
   - **Network**
      - responsible for transferring data from one system to another on the network. The transport layer passes a segment and the destination address to the network layer. Main use is for Internet Protocol (IP).
   - **Link**
      - responsible for communication between one device and its immediate neighbor.
   - **Physical**
      -responsible for breaking the data frame into bits, converting it into a form that can be transmitted over the physical communication line, and transferring it.

## System Analysis
- Software Development Life Cycle (SDLC) Types:
   - Basic stages of SDLC:
      1) Planning and requirements analysis
      2) Designing project architecture
      3) Development and programming
      4) Testing
      5) Deployment

	- **Agile**
	- Ongoing release cycles, each featuring small, incremental changes from the previous release.
	- At each iteration, the product is tested

	- **Lean**
	- Work only on what must be worked on at the time
	- 7 Lean principles
		1) Eliminate waste
		2) Amplify learning
		3) Decide as late possible
		4) Deliver as fast as possible
		5) Empower the team
		6) Build integrity in
		7) See the whole

	- **Waterfall model:** results of each phase are called deliverables, which flow into the next phase
		- Pros
			- Simple to use and understand
			- Every phase has a defined result and process review
			- Development stages go one by one
			- Perfect for small/mid-sized projects
			- Easy to determine the key points in the development cycle
			- Easy to classify and prioritize tasks

		- Cons
			- Software is ready only after the last stage
			- High risks and uncertainty
			- Not the best for complex and object-oriented projects
			- Inappropriate for long-term projects
			- Progress of the stage is hard to measure while still in development

	- **Iterative model:** the process is repetitive, allowing the creation of new versions of the product for every cycle
		- Pros
			- Some functions can be quickly developed at the beginning of the development lifecycle
			- Paralleled development can be applied
			- Progress is easy to measure
			- The shorter the iteration is, the easier testing and debugging stages are
			- Easy to control the risks as high-risk tasks are completed first
			- Problems and risks defined within one iteration can be prevented in the next sprints
			- Flexibility and readiness to changes in the requirements

		- Cons
			- Iterative model requires more resources than the waterfall model
			- Constant management is required
			- Issues with architecture or design may occur because not all the requirements are foreseen during the short planning stage
			- Bad choice for small projects
			- The process is difficult to manage
			- The risks may not be completely determined even at the final stage of the project
			- Risks analysis requires involvement of highly-qualified specialists

	- **Spiral model**
		- Pros
			- Lifecycle is divided into small parts
			- The development process is precisely documented yet scalable to the changes
			- The scalability allows making changes and adding new functionality even at the relatively late stages
			- The earlier working prototype is done, the sooner users can point out the flaws

		- Cons
			- Can be quite expensive
			- Risk control demands involvement of highly-skilled professionals
			- Can be ineffective for small projects
			- A big number of intermediate stages requires excessive documentation

	- **V-Shaped model:** an expansion of the waterfall model and it’s based on an associated test stage for every development stage
		- Pros
			- Every stage has strict results, so it’s easy to control
			- Testing and verification take place in the early stages
			- Good for small projects, where requirements are static and clear

		- Cons
			- Lack of flexibility
			- Relatively big risks

	- SWOT analysis (Strengths, weaknesses, opportunities, and threats): is a study undertaken by an organization to identify its internal strengths and weaknesses, as well as external opportunities and threats

## Prob & Stats MATH 213
   - [Intervals](https://www.scribbr.com/statistics/confidence-interval/)
      - ME: z-score * standard error(SE) aka Z(SE)
	  - SE: standard deviation(s) of sampling distribution
	  - The interval is created by adding/subtracting the ME to the statistic.

      - **95% confidence interval: x̄ ± Z(SE)**
	     - statistic ± z-score(Margin of Error)
		 - z-score: **1.960**
	   	 - The interpretation is: I am 95% confident that the true proportion is between this% and that%

	  - **90%: x̄ ± Z(SE)**
	     - sample mean ± z-score(standard deviation/√sample size)
		 - z-score: **1.645**
		 - The interpretation is: I am 90% confident that the true proportion is between this% and that%
		 
	  - **99%: x̄ ± Z(SE)**
	     - sample mean ± z-score(standard deviation/√sample size)
		 - z-score: **2.576**
		 - The interpretation is: I am 90% confident that the true proportion is between this% and that%

   - [Correlation](https://www.scribbr.com/statistics/correlation-coefficient/)
      - symbol of correlation is r.
	  -The value of the correlation coefficient always ranges between 1 and -1, and you treat it as a general indicator of the strength of the relationship between variables.

| Correlation coefficient | Correlation strength | Correlation type |
|-------------------------|----------------------|------------------|
| -.7 to -1               | Very strong          | Negative         |
| -.5 to -.7              | Strong               | Negative         |
| -.3 to -.5              | Moderate             | Negative         |
| 0 to -.3                | Weak                 | Negative         |
| 0                       | None                 | Zero             |
| 0 to .3                 | Weak                 | Positive         |
| .3 to .5                | Moderate             | Positive         |
| .5 to .7                | Strong               | Positive         |
| .7 to 1                 | Very strong          | Positive         |



