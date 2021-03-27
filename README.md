# chatbot

## Intro
The ChatBot creates a dialogue where users can ask questions about some aspects of memory management in C++. After the knowledge base of the chatbot has been loaded from a text file, a knowledge graph representation is created in computer memory, where chatbot answers represent the graph nodes and user queries represent the graph edges. After a user query has been sent to the chatbot, the Levenshtein distance is used to identify the most probable answer. 

### Code structure
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
* [wxWidgets](https://wiki.wxwidgets.org/Install) >= 3.0
