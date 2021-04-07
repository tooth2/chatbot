#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{

    _id = id;
}

GraphNode::~GraphNode()
{
    std::cout << "GraphNode Destructor: NaN \n" ;
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    std::cout << "GraphNode: Move Chatbot here \n " ;
    TAG; 
  
    _chatBot = std::move(chatbot); // move semantics
    _chatBot.SetCurrentNode(this);

}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    std::cout << "GraphNode:Move Chatbot to New Node \n " ;
    TAG;
    
    newNode->MoveChatbotHere(std::move(_chatBot));  // move semantics
   //_chatBot = nullptr; // invalidate pointer at source->not needed any more since moving chatbot around
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    std::cout << "GetChildEdgeAt specific Index \n" << std::endl;
    TAG;
    
    return _childEdges[index].get();
}
