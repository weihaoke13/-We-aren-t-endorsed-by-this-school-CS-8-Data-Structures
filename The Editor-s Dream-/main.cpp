#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
#include<algorithm>

using namespace std;

/** structure to define a word **/
struct Word
{
    string word;
    int count;
    vector<int> lineNumbers;

    //helper functions for comparison
    bool operator<(const Word &w) const { return word < w.word; }
    bool operator<=(const Word &w) const { return word <= w.word; }
    bool operator>(const Word &w) const { return word > w.word; }
    bool operator>=(const Word &w) const { return word >= w.word; }
    bool operator==(const Word &w) const { return word == w.word; }
    bool operator!=(const Word &w) const { return word != w.word; }

    Word operator=(const Word &w)
    {
        if (*this != w)
        {
            word = w.word;
            count = w.count;
            lineNumbers = w.lineNumbers;
        }

        return *this;
    }
};

/*
 * Node Declaration
 */
struct avl_node
{
    Word data;
    struct avl_node *left;
    struct avl_node *right;
};

/*
 * Class Declaration
 */
class avlTree
{
public:
    /*
     * Function to calculate the height of AVL Tree
     * return the calculated height.
     */
    int height(avl_node *);

    /*
     * Function to compute the Height Difference
     */
    int diff(avl_node *);

    /*
     * Function to perform Right- Right Rotation to help balance
     * the AVL Tree.
     */
    avl_node *rr_rotation(avl_node *);

    /*
     * Function to perform LEFT-LEFT Rotation to help balance
     * the AVL Tree.
     */
    avl_node *ll_rotation(avl_node *);

    /*
     * Function to perform LEFT- Right Rotation to help balance
     * the AVL Tree.
     */
    avl_node *lr_rotation(avl_node *);

    /*
     * Function to perform Right- Left Rotation to help balance
     * the AVL Tree.
     */
    avl_node *rl_rotation(avl_node *);

    /*
     * Function to balance the AVL Tree, to ensure the balance is
     * maintained as per avl tree properties.
     */
    avl_node* balance(avl_node *);

    /*
     * Insert Element into the tree, and maintain the balance
     * if necessary.
     */
    avl_node* insert(avl_node *, Word);

    /*
     void display(avl_node *, int);


     void preorder(avl_node *);

     void postorder(avl_node *);
     */

    void inorder(avl_node *, ostream &);


    /*
     * Check if the word is already in the avl tree, if so return
     * true otherwise return false
     */
    bool exists(avl_node *, string);

    /*
     * Function to update an existing word, its count and its also
     * also line number where it appears
     */
    void update(avl_node *, string, int);
    avlTree()
    {
        root = NULL;
        ncount = 0;
    }

    avl_node * root;
    int ncount;
};


const char * FILE_NAME = "output.txt";

//helper function to normalize a given word, remove all numeric
//and punctuations and even the case (make lower case and return it
string normalize(string);

//function to write to output file the words and the frequency
void writeFile(avlTree, ofstream &);

int main()
{
    avlTree tree;					/* Heap to store the words */
    int lineCount = 0;			/* Number lines in the file */
    int paraCount = 0;			/* Number of Paragraphs in the file */
    int wordCount = 0;			/* Number of Words int the file */
    char name[100] = "novel1.txt";				//name of input file
    string curWord;				//Current Word read from file
    string curLine;				//Current line in the file

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    //Prompt the user to enter the file name
    cout << "Enter File name to check? ";
    cin >> name;

    clock_t begin = clock();

    //Open the file to read
    ifstream in(name);

    //output file
    ofstream out(FILE_NAME, ios::out);

    cout << "Processing Please Wait...." << endl;

    //Read file word by word
    while (!in.eof())
    {
        //read line
        getline(in, curLine, '\n');

        //cout << "Line: " << curLine << endl;
        //if read successfully
        if (in)
        {
            //Increase line count
            lineCount++;

            if (curLine != "" && curLine.length() > 0)
            {
                //Create string stream
                stringstream ss;
                ss.str(curLine);

                while (!ss.eof())
                {
                    ss >> curWord;
                    wordCount++;
                    curWord = normalize(curWord);
                    //cout << "Current Word: " << curWord << endl;
                    //Create Word Object
                    Word cw;					//Current Word
                    cw.count = 1;
                    cw.lineNumbers.push_back(lineCount);
                    cw.word = curWord;

                    //check if it is already in the Tree
                    bool exist = tree.exists(tree.root, cw.word);

                    if (exist)
                    {
                        //cout << "HERE" << endl;
                        tree.update(tree.root, cw.word, lineCount);
                    }
                    else
                    {
                        //cout << "HERE" << endl;
                        tree.root = tree.insert(tree.root, cw);
                    }
                }
                //cout << "HERE" << endl;
            }
            else
            {
                paraCount += 1;
            }
        }
    }


    //Output Statistics
    writeFile(tree, out);
    cout << endl << endl;
    cout << "Statistics for File Read: " << name << endl;
    cout << "Total number of Paragraphs: " << paraCount << endl;
    cout << "Total Number of Lines: " << lineCount << endl;
    cout << "Total number of Words: " << wordCount << endl;
    cout << "Output Also written to " << FILE_NAME << endl;
    cout << endl;

    //output file
    out << endl << endl;
    out << "Statistics for File Read: " << name << endl;
    out << "Total number of Paragraphs: " << paraCount << endl;
    out << "Total Number of Lines: " << lineCount << endl;
    out << "Total number of Words: " << wordCount << endl;
    out << endl;

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << elapsed_secs << " Second(s) taken to process the file." << endl;
    cout << endl;
    out << elapsed_secs << " Second(s) taken to process the file." << endl;
    out << endl;

    out.close();
    system("pause");
    return 0;
}

string normalize(string w)
{
    string nw = "";
    for (unsigned i = 0; i < w.length(); i++)
    {
        //only take alphabetic letter
        if (isalpha(w[i]))
        {
            nw.insert(nw.end(), 1, w[i]);
        }
    }
    return nw;
}

//function to write to output file the words and the frequency
void writeFile(avlTree tree, ofstream & out)
{
    cout << "\nFirst 100 Words Printed Here - Output File has all words Printed\n\n" << endl;
    cout << left << setw(25) << "Word" << setw(10) << "Frequency" << "Line Numbers" << endl;
    out << left << setw(25) << "Word" << setw(10) << "Frequency" << "Line Numbers" << endl;
    tree.inorder(tree.root, out);

    /*while (!heap.isEmpty())
     {
     Word w = heap.remove();
     cout << left << setw(25) << w.word << setw(10) << w.count;
     out << left << setw(25) << w.word << setw(10) << w.count;
     for (unsigned j = 0; j < w.lineNumbers.size(); j++)
     {
     //restrict output to five line numbers on screen
     if (j < 5)
     cout << w.lineNumbers[j] << " ";

     //upto 10 lines
     if (j < 10)
     out << w.lineNumbers[j] << " ";
     else break;
     }

     cout << endl;
     out << endl;
     }*/
}

/*
 * Function to calculate the height of AVL Tree
 * return the calculated height.
 */
int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

/*
 * Function to compute the Height Difference
 */
int avlTree::diff(avl_node *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

/*
 * Function to perform Right- Right Rotation to help balance
 * the AVL Tree.
 */
avl_node *avlTree::rr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

/*
 * Function to perform Left-Left Rotation to help balance
 * the AVL Tree.
 */
avl_node *avlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

/*
 * Function to perform Left- Right Rotation to help balance
 * the AVL Tree.
 */
avl_node *avlTree::lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

/*
 * Function to perform Right- Left Rotation to help balance
 * the AVL Tree.
 */
avl_node *avlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

/*
 * Function to balance the AVL Tree, to ensure the balance is
 * maintained as per avl tree properties.
 */
avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}

/*
 * Insert Element into the tree, and maintain the balance
 * if necessary.
 */
avl_node *avlTree::insert(avl_node *root, Word value)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance(root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance(root);
    }
    return root;
}



/*
 * Inorder Traversal of AVL Tree
 */
void avlTree::inorder(avl_node *tree, ostream & out)
{
    if (tree != NULL)
    {
        inorder(tree->left, out);
        //cout << tree->data << "  ";

        //cout << left << setw(25) << "Word" << setw(10) << "Frequency" << "Line Numbers" << endl;
        //out << left << setw(25) << "Word" << setw(10) << "Frequency" << "Line Numbers" << endl;
        Word w = tree->data;

        if(ncount < 100)
            cout << left << setw(25) << w.word << setw(10) << w.count;
        out << left << setw(25) << w.word << setw(10) << w.count;
        for (unsigned j = 0; j < w.lineNumbers.size(); j++)
        {
            //restrict output to five line numbers on screen
            if (j < 5 && ncount < 100)
                cout << w.lineNumbers[j] << " ";

            //upto 10 lines
            if (j < 10)
                out << w.lineNumbers[j] << " ";
            else break;
        }

        if(ncount < 100)
            cout << endl;
        out << endl;

        ncount += 1;

        inorder(tree->right, out);
    }
}


/*
 * Check if the word is already in the avl tree, if so return
 * true otherwise return false
 */
bool avlTree::exists(avl_node *tree, string w)
{
    if (tree != NULL)
    {
        if (tree->data.word > w) return exists(tree->left, w);
        if (tree->data.word == w) return true;
        if (tree->data.word < w) return exists(tree->right, w);
    }
    return false;
}

/*
 * Function to update an existing word, its count and its also
 * also line number where it appears
 */
void avlTree::update(avl_node * tree, string w, int lineNumber)
{
    if (tree != NULL)
    {
        if (tree->data.word > w)
            update(tree->left, w, lineNumber);

        if (tree->data.word == w)
        {
            tree->data.count += 1;
            tree->data.lineNumbers.push_back(lineNumber);
            return;
        }

        if (tree->data.word < w)
            update(tree->right, w, lineNumber);
    }
}

