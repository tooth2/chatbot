#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <memory>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define TAG printf("                                 [INFO]  %s  at  %s : %d \n\n", \
               __FUNCTION__, __FILENAME__, __LINE__);

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                      // constructor WITHOUT memory allocation
    ChatBot(std::string filename);  // constructor WITH memory allocation
    ~ChatBot();                                // [rule1] destructor

    ChatBot(const ChatBot &source);            // [rule2] copy constructor
    ChatBot &operator=(const ChatBot &source); // [rule3] copy assignment constructor
    ChatBot(ChatBot &&source);                 // [rule 4] move constructor
    ChatBot &operator=(ChatBot &&source);      // [rule 5] move assignment constructor

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
