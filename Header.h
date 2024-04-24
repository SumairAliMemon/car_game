#pragma once
#include<iostream>
#include<string>
#include <conio.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <random>
#include<fstream>
#include<sstream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
using namespace std;
using namespace chrono;
const int x = 17;
const int y = 17;
class QueueNode 
{
public:
    int x_axis;
    int y_axis;

    QueueNode* next;

    QueueNode(int a, int b) {
        x_axis = a;
        y_axis = b;
        next = nullptr;
    }
};
template<class t >
class Queue {
public:
    t * front, * rear;
    Queue() {
        front = rear = nullptr;
    }
    void push(t  *node) {
        t * temp = node;
        temp->next = nullptr;
        if (front == nullptr && rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    t * first()
    {
        return front;
    }
    void pop() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        t* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete (temp);
    }
    bool empty() {
        return (front == nullptr);
    }
    void display() {
        t * temp = front;
        while (temp != nullptr) {
            cout << temp->x_axis << " " << temp->y_axis << endl;
            temp = temp->next;
        }
    }
};

template <typename T>
class Nod
{
public:
    T data;
    Nod* next;
    Nod()
    {
        next = nullptr;
   }

    Nod(T da) :data(da), next(nullptr){}
  
};

template <typename t >
class queue
{
public:
    Nod<t>* top;
    Nod<t>* last;

    queue()
    {
        top = nullptr;
        last = nullptr;
    }

    void enqueue(t  data)
    {
            Nod<t>* temp = new Nod<t>;
        temp->data = data;
        temp->next = nullptr;

        if (top == nullptr)
        {
            top = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

    Nod<t>* dequeue()
    {
         Nod<t> * old = top;
        Nod<t>* temp = top;

        if (top == last)
        {
            last = nullptr;
        }

        top = top->next;
        delete temp;

        return old;
    }

    t showFirst()
    {
        if (top == nullptr)
        {
            cout << "Queue is empty";
        }
        else
        {
            return top->data;
        }
    }

    bool isempty()
    {
        if (top->data == nullptr)
        {
            return 1;
       }
        return 0;
    }
};
class NodeBinary {
public:
    int data;
    string Name;
    NodeBinary* left;
    NodeBinary* right;
    NodeBinary()
    {
        data = 0;
        Name = "\0";
        left = nullptr;
        right = nullptr;
    }
    NodeBinary(int value , string NA) : Name(NA), data(value), left(nullptr), right(nullptr) {}
};
// BST Node 
class NodeBST
{
public:
    int data;
    string name;
    NodeBST* left;
    NodeBST* right;
    NodeBST(string n, int d)
    {
        name = n;
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
// BINARY Search Tree 
class BST
{
public:
    NodeBST* root;

    BST()
    {
        root = nullptr;
    }

    void InsertNode(string name, int newdat)
    {
        NodeBST* newdata = new NodeBST(name, newdat);

        if (root == nullptr)
        {
            root = newdata;
        }
        else
        {
            NodeBST* temp = root;
            while (temp != nullptr)
            {
                if (newdat < temp->data)
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = newdata;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                else if (newdat > temp->data)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = newdata;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    cout << "Duplicate found, cannot add this\n";
                    break;
                }
            }
        }
    }
    void display(NodeBST* r)
    {
        NodeBST* Temp = r;
        if (Temp == nullptr)
        {
            return;
        }
        display(Temp->left);
        cout << YELLOW << "\t\t\t\t\t\t\t" << Temp->name << "      " << Temp->data << " " << RESET;
        cout << endl;
        display(Temp->right);

    }
    NodeBST* searchRecursive(NodeBST* current, string& name) {
        if (current == nullptr) {
            return NULL;
        }
        if (current->name == name)
        {
            name = current->name;
            return current;
        }
        return  searchRecursive(current->left, name);
        return  searchRecursive(current->right, name);



        return nullptr;
    }

};

NodeBinary* searchRecursive(NodeBinary* current, string& name) {
    if (current == nullptr) {
        return NULL;
    }
    if (current->Name == name)
    {
        name = current->Name;
        return current;
    }
    return  searchRecursive(current->left, name);
    return  searchRecursive(current->right, name);



    return nullptr;
}


double randomGenerator() {
    
    unsigned generate = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine generator(generate);
    std::uniform_real_distribution<double> distribution(1.0, 16.0);

   
    return distribution(generator);
}
class Node {

    Node* left;
    Node* right;
    Node* up;
    Node* down;
    int cost;
    char data;
    int x_axis;
    int y_axis;
public:
    int vertex;
    Node() : left(nullptr), right(nullptr), up(nullptr), down(nullptr), cost(2), data('.'), x_axis(0), y_axis(0) {}
   Node(Node& copy)
    {
        cost = copy.cost;
        data = copy.data;
        x_axis = copy.x_axis;
        y_axis = copy.y_axis;
        up = new Node;
        up = copy.up;
        down = new Node;
        down = copy.down;
        left = new Node;
        left = copy.left;
        right = new Node;
        right = copy.right;
        vertex = 0;
        
    }
   
    Node* getLeft() const {
        return left;
    }


    void setLeft(Node* newLeft) {
        left = newLeft;
    }

    Node* getRight() const {
        return right;
    }

    void setRight(Node* newRight) {
        right = newRight;
    }

   

    Node* getDown() const {
        return down;
    }

    void setDown(Node* newDown) {
        down = newDown;
    }

    Node* getUp() const {
        return up;
    }

    void setUp(Node* newUp) {
        up = newUp;
    }

    char getData() const {
        return data;
    }

    void setData(char newData) {
        data = newData;
    }

    int getCost() const {
        return cost;
    }

    void setCost(int newCost) {
        cost = newCost;
    }

    int getXAxis() const {
        return x_axis;
    }

    void setXAxis(int newXAxis) {
        x_axis = newXAxis;
    }

    int getYAxis() const {
        return y_axis;
    }

    void setYAxis(int newYAxis) {
        y_axis = newYAxis;
    }
}; 

class ListNode
{
public :
    int x_axis;
    int  y_axis;
    int vertex;
    int cost;

    ListNode* next;
    ListNode()
    {
        x_axis = 0;
        y_axis = 0;
        vertex = 0;
        cost = 0;
        next = nullptr;
    }
    ListNode(int a , int b , int verte , int co )
    {
        x_axis = a;
        y_axis = b;
        vertex = verte;
        cost = co;
        next = nullptr;
    }
};


class LinkedList
{
public:
    ListNode* Head;

    LinkedList()
    {
        Head = nullptr;
    }

    void Insert(int dat)
    {
        ListNode * add = new ListNode;
        add->vertex = dat;
        add->next = nullptr;

        if (Head == nullptr)
        {
            Head = add;
            return;
        }

        ListNode * temp = Head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = add;
    }

    void Display()
    {
        ListNode* temp = Head;
        while (temp != nullptr)
        {
            cout << temp->vertex << "->";
            temp = temp->next;
        }
        cout << "\n";
    }

    int RemoveFront()
    {
        if (Head == nullptr)
        {
            return -1;
        }

        int data = Head->vertex;
        ListNode* temp = Head;
        Head = Head->next;
        delete temp;
        return data;
    }
    bool IsEmpty()
    {
        return Head == nullptr;
    }
};


class linkedlistForGraph
{
public:
ListNode * head;
    linkedlistForGraph()
    {
        head = nullptr;
    }

    int & getX()
    {
        return head->x_axis;
    }

    int& getY()
    {
        return head->y_axis;
    }

    int& getVertex()
    {
        return head->vertex;
    }
    void insertAtFront(ListNode* value) {

        ListNode* newNode = value;
        if (head == nullptr) {
            head = newNode;    
        }
        else
        {
            newNode->next = head;
            head = newNode; 
        }
    }
    void Delete()
    {
        ListNode * temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }

    void display() {
        ListNode * current = head;
        while (current != nullptr) {
            
            cout << "->" << current->x_axis << " "<< current->y_axis << " ";
            current = current->next;
        }
        cout << endl;
    }

};


class GridGraph
{
public:
    int Vertex;

    linkedlistForGraph* adjList;
    Node** Grid;
    BST* scoreStored;


    GridGraph()
    {
        Vertex = 0;
        adjList = new linkedlistForGraph[x * y];
        scoreStored = new BST;
        Grid = new Node * [x];
        for (int j = 0; j < y; j++)
        {
            Grid[j] = new Node[y];
        }
        MakeGrid();
        connect_UpDown();
        connect_LeftRight();
        ConvertAdjList();
    }
    void MakeGrid()
    {
        int ver = 0;
        for (int i = 0; i < x; i++)
        {

            for (int j = 0; j < y; j++)
            {
                Grid[i][j].setXAxis(i);
                Grid[i][j].setYAxis(j);
                Grid[i][j].vertex = ver;
                ver++;
            }
        }

    }
    void ConvertAdjList()
    {
        int a = 0;
        for (int i = 0; i < x; i++)
        {

            for (int j = 0; j < y; j++)
            {
                if (Grid[i][j].getData() != 'x')
                {
                    if (Grid[i][j].getLeft() != nullptr)
                    {
                        ListNode* temp = new ListNode(Grid[i][j].getLeft()->getXAxis(), Grid[i][j].getLeft()->getYAxis(),a,2);
                        temp->cost = Grid[i][j].getCost();
                        adjList[a].insertAtFront(temp);
                    }
                    if (Grid[i][j].getRight() != nullptr)
                    {
                        ListNode* temp = new ListNode(Grid[i][j].getRight()->getXAxis(), Grid[i][j].getRight()->getYAxis(),a,2);
                        adjList[a].insertAtFront(temp);
                        temp->cost = Grid[i][j].getCost();
                    }
                    if (Grid[i][j].getUp() != nullptr)
                    {
                        ListNode* temp = new ListNode(Grid[i][j].getUp()->getXAxis(), Grid[i][j].getUp()->getYAxis(),a,2);
                        adjList[a].insertAtFront(temp);
                        temp->cost = Grid[i][j].getCost();
                    }
                    if (Grid[i][j].getDown() != nullptr)
                    {
                        ListNode* temp = new ListNode(Grid[i][j].getDown()->getXAxis(), Grid[i][j].getDown()->getYAxis(),a,2);
                        adjList[a].insertAtFront(temp);
                        temp->cost = Grid[i][j].getCost();
                    }
                    a++;
                }
            }
        }

    }

    void DisplayAdj()
    {
        for (int i = 0; i < x * y; i++)
        {
            cout << i << " ";
            adjList[i].display();
        }

    }
    void displayVertex()
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cout << Grid[i][j].vertex;
            }
        }

    }
    void connect_LeftRight()
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y - 1; j++)
            {

                Grid[i][j].setRight(&Grid[i][j + 1]);
                Grid[i][j + 1].setLeft(&Grid[i][j]);
            }
        }

    }

    void connect_UpDown()
    {
        for (int i = 0; i < x - 1; i++)
        {
            for (int j = 0; j < y; j++)
            {

                Grid[i][j].setDown(&Grid[i + 1][j]);
                Grid[i + 1][j].setUp(&Grid[i][j]);
                // cout << i << "|" << j << endl;
            }
        }

    }

    void Display()
    {
        cout << " ";
        for (int i = 0; i < x; i++)
        {
            cout << YELLOW << "___" << RESET;
        }
        cout << endl;
        for (int i = 0; i < x; i++)
        {
            cout << YELLOW << "| " << RESET;
            
            for (int j = 0; j < y; j++)
            {
                if (Grid[i][j].getData() == '.')
                {
                    cout << WHITE << Grid[i][j].getData() << "  " << RESET;
                  
                }
                else if (Grid[i][j].getData() == 'x')
                {
                    cout << RED << Grid[i][j].getData() << "  " << RESET;
    
                }
                else if (Grid[i][j].getData() == 'c')
                {
                    cout << BLUE << Grid[i][j].getData() << "  " << RESET;
                }
                else if (Grid[i][j].getData() == 'W')
                {
                    cout << BLUE << Grid[i][j].getData() << "  " << RESET;
                }
                else if (Grid[i][j].getData() == '0')
                {
                    cout << YELLOW << Grid[i][j].getData() << "  " << RESET;
                }
                else if (Grid[i][j].getData() == '#')
                {
                    cout << CYAN << Grid[i][j].getData() << "  " << RESET;
                }
                else
                {
                    cout << Grid[i][j].getData() << "  ";
                }

            }
            cout << YELLOW << "|" << RESET;
            cout << endl;
        }

        for (int i = 0; i < x; i++)
        {
            cout << YELLOW << "---" << RESET;
        }
        cout << endl;
    }

    Node* Move(Node*& control, char key, Node*& finish, int& Steps, int& collision, int& Coin, int& PowerUp, bool Obs) {


        switch (key) {
        case 75: 
            if (control->getLeft() != nullptr && control->getLeft()->getData() == '.') {
                control->setData('.');
                control = control->getLeft();
                control->setData('c');
            }
            else   if (control->getLeft() != nullptr && control->getLeft()->getData() == 'x')
            {
                if (Obs == 0)
                {
                    collision--;
                }
            }
            else if (control->getLeft() != nullptr && control->getLeft()->getData() == '#')
            {
                Steps -= 50;
                control->setData('.');
                control = control->getLeft();
                control->setData('c');
            }
            else    if (control->getLeft() != nullptr && control->getLeft()->getData() == 'P')
            {
                PowerUp++;
                control->setData('.');
                control = control->getLeft();
                control->setData('c');
            }
            else    if (control->getLeft() != nullptr && control->getLeft()->getData() == '0')
            {
                Coin++;
                control->setData('.');
                control = control->getLeft();
                control->setData('c');
            }
            else if (control->getLeft() != nullptr && control->getLeft()->getData() == 'W')
            {
                control = finish;
            }
            break;
        case 77: // right 
            if (control->getRight() != nullptr && control->getRight()->getData() == '.') {

                control->setData('.');
                control = control->getRight();
                control->setData('c');
            }
            else  if (control->getRight() != nullptr && control->getRight()->getData() == 'x')
            {
                if (Obs == 0)
                {
                    collision--;
                }
            }
            else  if (control->getRight() != nullptr && control->getRight()->getData() == '#')
            {
                Steps -= 50;
                control->setData('.');
                control = control->getDown();
                control->setData('c');
            }
            else   if (control->getRight() != nullptr && control->getRight()->getData() == 'P')
            {
                PowerUp++;
                control->setData('.');
                control = control->getRight();
                control->setData('c');
            }
            else  if (control->getRight() != nullptr && control->getRight()->getData() == '0')
            {
                Coin++;
                control->setData('.');
                control = control->getRight();
                control->setData('c');
            }
            else if (control->getRight() != nullptr && control->getRight()->getData() == 'W')
            {
                control->setData('.');
                control = finish;
            }
            break;
        case 72:
            if (control->getUp() != nullptr && control->getUp()->getData() == '.') {

                control->setData('.');
                control = control->getUp();
                control->setData('c');
            }
            else if (control->getUp() != nullptr && control->getUp()->getData() == 'x')
            {
                if (Obs == 0)
                {
                    collision--;
                }
            }
            else if (control->getUp() != nullptr && control->getUp()->getData() == '#')
            {
                Steps -= 50;
                control->setData('.');
                control = control->getUp();
                control->setData('c');
            }
            else   if (control->getUp() != nullptr && control->getUp()->getData() == 'P')
            {
                PowerUp++;
                control->setData('.');
                control = control->getUp();
                control->setData('c');
            }
            else if (control->getUp() != nullptr && control->getUp()->getData() == '0')
            {
                Coin++;
                control->setData('.');
                control = control->getUp();
                control->setData('c');
            }
            else if (control->getUp() != nullptr && control->getUp()->getData() == 'W')
            {
                control->setData('.');
                control = finish;
            }
            break;
        case 80: // down 
            if (control->getDown() != nullptr && control->getDown()->getData() == '.') {
                control->setData('.');
                control = control->getDown();
                control->setData('c');
            }

            else   if (control->getDown() != nullptr && control->getDown()->getData() == 'x')
            {
                if (Obs == 0)
                {
                    collision--;
                }
            }
            else  if (control->getDown() != nullptr && control->getDown()->getData() == '#')
            {
                Steps -= 50;
                control->setData('.');
                control = control->getDown();
                control->setData('c');
            }
            else   if (control->getDown() != nullptr && control->getDown()->getData() == 'P')
            {
                PowerUp++;
                control->setData('.');
                control = control->getDown();
                control->setData('c');
            }
            else   if (control->getDown() != nullptr && control->getDown()->getData() == '0')
            {
                Coin++;
                control->setData('.');
                control = control->getDown();
                control->setData('c');
            }
            else if (control->getDown() != nullptr && control->getDown()->getData() == 'W')
            {
                control->setData('.');
                control = finish;
            }
            break;
        }
        return control;
    } 
    double randomGenerator(double a, double b) {

        unsigned generate = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
        default_random_engine generator(generate);
        uniform_real_distribution<> distribution(a, b);
        return distribution(generator);
    }
    int  WallsRandomGenerator(linkedlistForGraph& walls)
    {
        int temp = randomGenerator(80, 90);
        for (int i = 0; i < temp; i++)
        {
            int a = randomGenerator(1, x - 1); 
            int b = randomGenerator(1, y - 1); 
            ListNode* temp = new ListNode(a, b, Grid[a][b].vertex, 100 ); 
            walls.insertAtFront(temp);
            Grid[a][b].setCost(100);
            Grid[a][b].setData('x');
        }
        return temp;
    }

    int  CoinRandomGenerator(linkedlistForGraph& walls)
    {
        int temp = randomGenerator(5, 10);
        for (int i = 0; i < temp; i++)
        {
            int a = randomGenerator(1, x - 1); 
            int b = randomGenerator(1, y - 1);
            ListNode* temp = new ListNode(a, b ,Grid[a][b].vertex, 1);
            walls.insertAtFront(temp);
            Grid[a][b].setCost(randomGenerator(1, 2));
            Grid[a][b].setData('0');
        }
        return temp;
    }

    int  PowerUpsRandomGenerator(linkedlistForGraph& walls)
    {
        int temp = randomGenerator(1, 2);
        for (int i = 0; i < temp; i++)
        {
            int a = randomGenerator(1, x - 1);
            int b = randomGenerator(1, y - 1);
            ListNode* temp = new ListNode(a, b , Grid[a][b].vertex, 100);
            cout << a << b << endl;
            walls.insertAtFront(temp);
            Grid[a][b].setCost(randomGenerator(0, 1));
            Grid[a][b].setData('P');
        }
        return temp;
    }

    void setStartAndWinner(Node*& start, Node*& winner)
    {
        int rx = randomGenerator(0, x / 2), ry = randomGenerator(0, y - 1);
        start = &Grid[rx][ry];
        int a = randomGenerator(x / 2, y - 1), b = randomGenerator(0, y - 1);
        winner = &Grid[a][b];
        winner->setData('W');
    }

    void RecoverNodes(linkedlistForGraph& walls, int count)
    {
        for (int i = 0; i < count; i++)
        {
            Grid[walls.getX()][walls.getY()].setData('.');
            walls.Delete();
        }
    }
    void Export()
    {
        ofstream file("Project.csv");
        queue<NodeBST*>* q = new  queue<NodeBST*>;
        NodeBST* temp = scoreStored->root;
        q->enqueue(temp);
        while (!q->isempty())
        {
            NodeBST* temp = q->showFirst();
            if (temp->left)
            {
                q->enqueue(temp->left);
            }
            if (temp->right)
            {
                q->enqueue(temp->right);
            }
            file << temp->name << "," << temp->data << endl;
            q->dequeue();
        }
    }
    void importScore()
    {
        ifstream file("Project.csv");
        string line;
        while (getline(file, line))
        {
            size_t  comma = line.find(',');
            string name = line.substr(0, comma);
            int score = stoi(line.substr(comma + 1));
            NodeBinary* temp = new NodeBinary;
            temp->data = score;
            temp->Name = name;
            scoreStored->InsertNode(name, score);
        }
    }
    int  ObsRandomGenerator(Queue<QueueNode>& Obstacles)
    {
        int temp = randomGenerator(6, 11);
        for (int i = 0; i < temp; i++)
        {
            int a = randomGenerator(0, x - 1); 
            int b = randomGenerator(0, y - 1);
            QueueNode* temp = new QueueNode(a, b);
            cout << a << b << endl;
            Obstacles.push(temp);
            Grid[a][b].setCost(randomGenerator(300, 600));
            Grid[a][b].setData('#');
        }
        return temp;
    }

    void RecoverObs(Queue<QueueNode>& Obs, int count)
    {
        for (int i = 0; i < count; i++)
        {
            Grid[Obs.first()->x_axis][Obs.first()->y_axis].setData('.');
            Obs.pop();
        }
    }
  /*  */
    void ScoreBoard(int coinsCollected, int  PowerUpCollected, int  CountCollision, int  Steps, int sec, string name)
    {
        int Score = 0;
        Score += Steps;
        Score += coinsCollected * 10;
        Score += CountCollision * 20;
        Score -= sec;
        NodeBST* User = scoreStored->searchRecursive(scoreStored->root, name);
        if (User == nullptr)
        {
            system("cls");
            while (true)
            {
                cout << "\n\n\n\n\n";
                cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                cout << YELLOW << "\t\t\t\t\t\t   New High Score \n" << RESET;
                cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                cout << "\t\t\t\t\t\tFuel       " << Steps << " \n";
                cout << "\t\t\t\t\t\tCoins      " << coinsCollected << " x 10 \n";
                cout << "\t\t\t\t\t\tcollision  " << CountCollision << " x 20 \n";
                cout << "\t\t\t\t\t\tTime (sec) " << sec << "*.1 \n";
                cout << "\t\t\t\t\t\tPower Up   " << PowerUpCollected << "\n";
                cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                cout << CYAN << "\t\t\t\t\t\tScore      " << RESET << Score << endl;
                cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                int a = 0;
                scoreStored->InsertNode(name, Score);
                if (cin >> a)
                {
                    break;
                }
            }
        }
        else
        {

            system("cls");
            while (true)
            {

                if (User->data > Score)
                {
                    cout << "\n\n\n\n\n";
                    cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                    cout << YELLOW << "\t\t\t\t\t\t   New High Score \n" << RESET;
                    cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                    cout << "\t\t\t\t\t\tFuel       " << Steps << " \n";
                    cout << "\t\t\t\t\t\tCoins      " << coinsCollected << " x 10 \n";
                    cout << "\t\t\t\t\t\tcollision  " << CountCollision << " x 20 \n";
                    cout << "\t\t\t\t\t\tTime (sec) " << sec << "*.1 \n";
                    cout << "\t\t\t\t\t\tPower Up   " << PowerUpCollected << "\n";
                    cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                    cout << CYAN << "\t\t\t\t\t\tScore      " << RESET << Score << endl;
                    cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                    int a = 0;
                    if (cin >> a)
                    {
                        break;
                    }
                    scoreStored->InsertNode(name, Score);
                }
                else
                {
                    cout << "\n\n\n\n\n";
                    cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                    cout << YELLOW << "\t\t\t\t\t\t   Your Score   \n" << RESET;
                    cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                    cout << "\t\t\t\t\t\tFuel       " << Steps << " \n";
                    cout << "\t\t\t\t\t\tCoins      " << coinsCollected << " x 10 \n";
                    cout << "\t\t\t\t\t\tcollision  " << CountCollision << " x 20 \n";
                    cout << "\t\t\t\t\t\tTime (sec) " << sec << "*.1 \n";
                    cout << "\t\t\t\t\t\tPower Up   " << PowerUpCollected << "\n";
                    cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                    cout << CYAN << "\t\t\t\t\t\tScore      " << RESET << Score << endl;
                    cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
                    int a = 0;
                    if (cin >> a)
                    {
                        break;
                    }



                }



            }
            
        }

    }
    string NamePage()
    {
        string name;
        while (true)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n";
            cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
            cout << "\t\t\t\t\t\t" << CYAN << "Enter Your Name " << RESET << "\n\n";
            cout << BLUE << "\t\t\t\t\t-------------------------------------" << RESET << endl;
            cout << "\t\t\t\t\t\t";
            if (cin >> name)
            {
                break;
            }
        }
        return name;
    }
    void  YouLose()
    {
        int a ;
        while (true){
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n";
            cout << YELLOW << "\t\t\t\t\t-------------------------------------" << RESET << endl;
            cout << "\t\t\t\t\t\t" << RED << " You Lose " << RESET << "\n\n";
            cout << YELLOW << "\t\t\t\t\t-------------------------------------" << RESET << endl;
            cout << "\t\t\t\t\t\t";
            if (cin >> a)
            {
                break;
            }
        }
        return;
    }
    void GamePlay()
    {
        ConvertAdjList();
        string name = NamePage();
        Node* control = new Node;
        Node* finish = new Node;
        linkedlistForGraph  Coins;
        linkedlistForGraph  PowerUp;
        Queue<QueueNode> obstacle;
        linkedlistForGraph walls;
        int totalWalls = WallsRandomGenerator(walls);
        int totalObs = ObsRandomGenerator(obstacle);
        int TotalPowerups = PowerUpsRandomGenerator(PowerUp);
        int TotalCoins = CoinRandomGenerator(Coins);
        int coinsCollected = 0, PowerUpCollected = 0, CountCollision = 3, Steps = randomGenerator(300, 450);
        bool Check = 0;
        auto start_time = std::chrono::high_resolution_clock::now();
        chrono::seconds duration(100);
        setStartAndWinner(control, finish);
        control->setData('c');
        finish->setData('W');
        while (true) {
            system("cls");
            cout << endl << endl;
            cout << YELLOW << "        Coins " << RESET << coinsCollected << CYAN << "                  PowerUps   " << RESET << PowerUpCollected << endl;
            cout << RED << "        Fuel " << RESET << Steps << BLUE << "                Collisions   " << RESET << CountCollision << endl;
            Display();
            this_thread::sleep_for(std::chrono::milliseconds(1));
            cout << BLUE << "Start point  C" << RESET << endl;
            cout << BLUE << "End point W" << RESET << endl;
            cout << "Powerups  P" << endl;
            cout << YELLOW << "Coins 0" << RESET << endl;
            cout << BLUE "Obstacles #" << RESET << endl;
            cout << RED << "Wall x" << RESET << endl;
            char directions = _getch();
            if (directions == 72 || directions == 80 || directions == 77 || directions == 75)
            {
                Steps = Steps - 10;
                control = Move(control, directions, finish, Steps, CountCollision, coinsCollected, PowerUpCollected, 0);
                if (control == finish)
                {
                    auto end_time = std::chrono::high_resolution_clock::now();
                    auto TotalTime = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
                    int seconds = static_cast<int>(TotalTime.count());
                    ScoreBoard(coinsCollected, PowerUpCollected, CountCollision, Steps, seconds, name);
                    break;
                }
                else if (CountCollision == 0)
                {
                    YouLose();
                    break;
                }
                else if (Steps <= 0)
                {
                    YouLose();
                    break;
                }
            }
            else
            {
                cout << "Wrong Key \n ";
            }
        }
        control->setData('.');
        finish->setData('.');
        RecoverNodes(walls, totalWalls);
        RecoverNodes(PowerUp, TotalPowerups);
        RecoverNodes(Coins, TotalCoins);
        RecoverObs(obstacle, totalObs);
        ConvertAdjList();
        return;
    }
    void GamePlayAutomatic()
    {
        string name = NamePage();

        Node* control = new Node;
        Node* finish = new Node;
        // = new BinaryTree;
        linkedlistForGraph  Coins;
        linkedlistForGraph  PowerUp;
        Queue<QueueNode> obstacle;
        linkedlistForGraph walls;
        int totalWalls = WallsRandomGenerator(walls);
        int totalObs = ObsRandomGenerator(obstacle);
        int TotalPowerups = PowerUpsRandomGenerator(PowerUp);
        int TotalCoins = CoinRandomGenerator(Coins);
        int coinsCollected = 0, PowerUpCollected = 0, CountCollision = 3, Steps = randomGenerator(2000, 2450);
        bool Check = 0;
        auto start_time = std::chrono::high_resolution_clock::now();
        chrono::seconds duration(100);
        setStartAndWinner(control, finish);
        control->setData('c');
        finish->setData('W');
        while (true) {
            system("cls");
            cout << endl << endl;
            cout << YELLOW << "        Coins " << RESET << coinsCollected << CYAN << "                  PowerUps   " << RESET << PowerUpCollected << endl;
            cout << RED << "        Fuel " << RESET << Steps << BLUE << "                Collisions   " << RESET << CountCollision << endl;
            Display();
            this_thread::sleep_for(std::chrono::microseconds(1));
            cout << BLUE << "Start point  C" << RESET << endl;
            cout << BLUE << "End point W" << RESET << endl;
            cout << "Powerups  P" << endl;
            cout << YELLOW << "Coins 0" << RESET << endl;
            cout << BLUE "Obstacles #" << RESET << endl;
            cout << RED << "Wall x" << RESET << endl;

            char directions = ' ';
            int Automatic = randomGenerator(0, 3);
            if (Automatic == 0)
            {
                directions = 72;
            }
            else if (Automatic == 1)
            {
                directions = 75;
            }
            else if (Automatic == 2)
            {
                directions = 77;
            }
            else if (Automatic == 3)
            {
                directions = 80;
            }

            if (directions == 72 || directions == 80 || directions == 77 || directions == 75)
            {
                Steps = Steps - 10;
                control = Move(control, directions, finish, Steps, CountCollision, coinsCollected, PowerUpCollected, 1);


                if (control == finish)
                {
                    auto end_time = std::chrono::high_resolution_clock::now();

                    // Calculate the duration in seconds and print it as an integer
                    auto TotalTime = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
                    int seconds = static_cast<int>(TotalTime.count());
                    ScoreBoard(coinsCollected, PowerUpCollected, CountCollision, Steps, seconds, name);

                    break;
                }

                else if (CountCollision == 0)
                {
                    YouLose();
                    break;
                }
                else if (Steps <= 0)
                {
                    YouLose();
                    break;
                }
            }
            else
            {
                cout << "Wrong Key \n ";
            }

        }
        control->setData('.');
        finish->setData('.');
        RecoverNodes(walls, totalWalls);
        RecoverNodes(PowerUp, TotalPowerups);
        RecoverNodes(Coins, TotalCoins);
        RecoverObs(obstacle, totalObs);
        return;
    }

    void  SearchNode(int a ,int &x, int &y  )
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
                  if (Grid[i][j].vertex == a)
                {
                    x = i; y = j ;
                }
        }
            
    }
  
    LinkedList *Dijkstra_Zalim(int start, int end)
    {
        int* distance = new int[x*y];
        int* parent = new int[x*y];
        bool* visited = new bool[x*y];

        for (int i = 0; i < x*y; ++i)
        {
            distance[i] = INT_MAX;
            parent[i] = -1;
            visited[i] = false;
        }

        distance[start] = 0;

        LinkedList queue;

        queue.Insert(start);

        while (!queue.IsEmpty())
        {
            int u = queue.RemoveFront();

            visited[u] = true;

            ListNode* current = adjList[u].head;
            while (current != nullptr)
            {
                if (Grid[current->x_axis][current->y_axis].getData() != 'x')
                {
                    int v = current->vertex;
                    int weight = current->cost;

                    if (!visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v])
                    {
                        distance[v] = distance[u] + weight;
                        parent[v] = u;
                        queue.Insert(v);
                    }
                }
                    current = current->next;
                
            }
        }
        LinkedList path;
        int current = end;
        while (current != -1)
        {
            path.Insert(current);
            current = parent[current];
        }
        delete[] distance;
        delete[] parent;
        delete[] visited;
        return &path;
    }
    void AutomaticGame()
    {
        Node* control = new Node;
        Node* finish = new Node;
        linkedlistForGraph  Coins;
        linkedlistForGraph  PowerUp;
        Queue<QueueNode> obstacle;
        linkedlistForGraph walls;
        int totalWalls = WallsRandomGenerator(walls);
        int totalObs = ObsRandomGenerator(obstacle);
        int TotalPowerups = PowerUpsRandomGenerator(PowerUp);
        int TotalCoins = CoinRandomGenerator(Coins);
        int coinsCollected = 0, PowerUpCollected = 0, CountCollision = 3, Steps = randomGenerator(2000, 2450);
        bool Check = 0;
        auto start_time = std::chrono::high_resolution_clock::now();
        chrono::seconds duration(100);
        int start = 0 , end = 0 , startx = 0,starty = 0,endx = 0,endy = 0;
        system("cls");
        cout <<RED<< "Enter Start Vertex (0 to " << x * y << ")" <<RESET <<endl;
        cin >> start;
        cout << RED << "Enter End Vertex (0 to " << x * y << ")" << RESET << endl;
        cin >> end;

        if (start == end)
        {
            cout << "Start == end \n";
            return;
        }
        SearchNode(start, startx, starty);
        SearchNode(end, endx, endy);
        control = &Grid[startx][starty];
        finish = &Grid[endx][endy];
        control->setData('c');
        finish->setData('W');

        LinkedList* Path = new LinkedList;
      Path =  Dijkstra_Zalim(start, end);

      while (!Path->IsEmpty())
      {
          int xNode = 0, yNode = 0;
          SearchNode(Path->RemoveFront(), xNode, yNode);
          Grid[xNode][yNode].setData('^');
      }
      Path->Display();
      int a = 0;
      cin >> a;
      Path = Dijkstra_Zalim(3, 110);
      while (!Path->IsEmpty())
      {
          int xNode = 0, yNode = 0;
          SearchNode(Path->RemoveFront(), xNode, yNode);
          Grid[xNode][yNode].setData('.');
      }
      control->setData('.');
      finish->setData('.');
      RecoverNodes(walls, totalWalls);
      RecoverNodes(PowerUp, TotalPowerups);
      RecoverNodes(Coins, TotalCoins);
      RecoverObs(obstacle, totalObs);
    }
};
