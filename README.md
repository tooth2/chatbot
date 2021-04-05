# ChatBot

## Intro
The ChatBot creates a dialogue where users can ask questions about some aspects of memory management in C++. After the knowledge base of the chatbot has been loaded from a text file, a knowledge graph representation is created in computer memory, where chatbot answers represent the graph nodes and user queries represent the graph edges. After a user query has been sent to the chatbot, the Levenshtein distance is used to identify the most probable answer. The code is fully functional as-is and uses raw pointers to represent the knowledge graph and interconnections between objects throughout the project.

### Basic Build Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./membot`.

### Project Details
1. Exclusive Ownership 1
- In file `chatgui.h` / `chatgui.cpp`, make `_chatLogic` an exclusive resource to class `ChatbotPanelDialog` using an appropriate smart pointer. Where required, make changes to the code such that data structures and function parameters reflect the new structure. 

2. The Rule Of Five
- In file `chatbot.h` / `chatbot.cpp`, make changes to the class `ChatBot` such that it complies with the Rule of Five. Make sure to properly allocate / deallocate memory resources on the heap and also copy member data where it makes sense to you.  In each of the methods (e.g. the copy constructor), print a string of the type "ChatBot Copy Constructor" to the console so that you can see which method is called in later examples. 

3. Exclusive Ownership
- In file `chatlogic.h` / `chatlogic.cpp`, adapt the vector `_nodes` in a way that the instances of `GraphNodes` to which the vector elements refer are exclusively owned by the class `ChatLogic`. Use an appropriate type of smart pointer to achieve this. Where required, make changes to the code such that data structures and function parameters reflect the changes. When passing the `GraphNode` instances to functions, make sure to not transfer ownership and try to contain the changes to class `ChatLogic` where possible. 

4. Moving Smart Pointers
- In files `chatlogic.h` / `chatlogic.cpp` and `graphnodes.h` / `graphnodes.cpp` change the ownership of all instances of `GraphEdge` in a way such that each instance of `GraphNode` exclusively owns the outgoing `GraphEdges` and holds non-owning references to incoming `GraphEdges`. Use appropriate smart pointers and where required, make changes to the code such that data structures and function parameters reflect the changes. When transferring ownership from class `ChatLogic`, where all instances of `GraphEdge` are created, into instances of `GraphNode`, make sure to use move semantics. 

5. Moving the ChatBot
In file `chatlogic.cpp`, create a local `ChatBot` instance on the stack at the bottom of function `LoadAnswerGraphFromFile`. Then, use move semantics to pass the `ChatBot` instance into the root node. Make sure that `ChatLogic` has no ownership relation to the `ChatBot` instance and thus is no longer responsible for memory allocation and deallocation. Note that the member `_chatBot` of `ChatLogic` remains so it can be used as a communication handle between GUI and `ChatBot` instance. Make all required changes in files `chatlogic.h` / `chatlogic.cpp` and `graphnode.h` / `graphnode.cpp`. When the program is executed, messages on which part of the Rule of Five components of `ChatBot` is called should be printed to the console. When sending a query to the `ChatBot`, the output should look like the following: 


### Code structure
```
ChatBot Constructor
ChatBot Move Constructor
ChatBot Move Assignment Operator
ChatBot Destructor
ChatBot Destructor 
```
* `chatgui.h` / `chatgui.cpp`: make `_chatLogic` an exclusive resource to class `ChatbotPanelDialog` using an appropriate smart pointer
* `chatbot.h` / `chatbot.cpp`:  In each of the methods (e.g. the copy constructor), print a string of the type "ChatBot Copy Constructor" to the console
* `chatlogic.h` / `chatlogic.cpp`: adapt the vector `_nodes` in a way that the instances of `GraphNodes` to which the vector elements refer are exclusively owned by the class `ChatLogic`. create a local `ChatBot` instance on the stack at the bottom of function `LoadAnswerGraphFromFile`. pass the `ChatBot` instance into the root node. the `ChatBot` instance (`_chatBot`) is used as a communication handle between GUI and ChatBot instance
* `graphnodes.h` / `graphnodes.cpp`: change the ownership of all instances of `GraphEdge` in a way such that each instance of `GraphNode` exclusively owns the outgoing `GraphEdges` and holds non-owning references to incoming `GraphEdges`
* Console output: When sending a query to the ChatBot, the output should look like the following:
    * ChatBot Constructor
    * ChatBot Move Constructor
    * ChatBot Move Assignment Operator
    * ChatBot Destructor
    * ChatBot Destructor 

### Run-time Environment Dependency
* cmake >= 3.11
* make >= 4.1
* gcc/g++ >= 5.4
* [wxWidgets](https://wiki.wxwidgets.org/Install) >= 3.0, [wxWidgets Binary](https://wiki.codelite.org/pmwiki.php/Main/WxWidgets30Binaries#toc2)
