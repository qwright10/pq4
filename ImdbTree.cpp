#include <iostream>
#include <string>
#include <vector>
#include "Bridges.h"
#include "DataSource.h"
#include "BSTElement.h"
#include <queue>
#include "stdlib.h"

using namespace std;
using namespace bridges;

BSTElement<string, string>* insertIntoBST(string actor, string movie, BSTElement<string, string> *root)
{
    if (root == nullptr)
    {
        root = new BSTElement<string, string>(actor);
        root->setLabel(movie);
        return root;
    }

    if (actor > root->getKey())
    {
        root->setRight(insertIntoBST(actor, movie, root->getRight()));
    }
    else
    {
        root->setLeft(insertIntoBST(actor, movie, root->getLeft()));
    }

    return root;
}

const char* colors[3] = { "red", "green", "blue" };

void colorNodes(BSTElement<string, string>* root, int color) {
    if (root == nullptr) {
        return;
    }

    root->setColor(colors[color % 3]);
    auto *left = root->getLeft();
    auto *right = root->getRight();

    if (left != nullptr) {
        colorNodes(left, color + 1);
    }
}

int main(int argc, char **argv)
{

    // Step 3: Test if the following print statement is being run
    cout << "Bridges: IMDB Data in a BST\n";

    // Step 4: Add your User ID and API Key as secrets on Replit

    /* Step 5: Print your User ID and API Key from secrets to the console
       to test if secrets were properly loaded
    */

    /*
     Step 6: Create a Bridges object by uncommenting the next line
     and inserting the values from steps 1 and 2
    */

    char *userId = getenv("username");
    char *apiKey = getenv("api_key");
    Bridges bridges(1, userId, apiKey);

    /*
       Step 7: Import IMDB data into a vector<ActorMovieIMDB> by
               referring to the Bridges IMDB documentation:
               https://bridgesuncc.github.io/tutorials/Data_IMDB.html
    */

    bridges.setTitle("Accessing IMDB Data");

    DataSource ds (&bridges);

    vector<ActorMovieIMDB> actor_list = ds.getActorMovieIMDBData(1814);

    cout << "Actor-Movie Data:" << endl
    << "\tActor: " << actor_list[0].getActor() << endl
    << "\tMovie: " << actor_list[0].getMovie() << endl;

    /*
       Step 9: Use the insertion function from the previous step to insert
               any 100 actor/movie pairs into a Bridges BST. Refer to the
               Bridges IMDB documentation:
               https://bridgesuncc.github.io/tutorials/Data_IMDB.html
    */

//COMMENT THIS BACK


  BSTElement<string, string> *root = insertIntoBST(actor_list[0].getActor(), actor_list[0].getMovie(), nullptr);

  root -> setLabel("root");

  for(int i = 1; i < 100; i++){
    insertIntoBST(actor_list[i].getActor(), actor_list[i].getMovie(), root);
  }


    /*
       Step 10: Visualize this tree by referring to the Bridges BST documentation:
               https://bridgesuncc.github.io/tutorials/BinarySearchTree.html
    */


    /*
       Step 11: Color each level of the tree using a level-order traversal.
               Every node in a given level should have the same color.
               Do not use the same color in two consecutive levels. A starter
               queue has been provided in case you wish to use an iterative
               implementation of BFS.

               Refer to the Bridges BST Styling documentation:
               https://bridgesuncc.github.io/tutorials/BinarySearchTree.html

    */

    queue<BSTElement<string, string> *> q;

    /*
      Step 12: Visualize the updated tree. Comment out or remove the old
               visualization code from Step 10
    */

      bridges.setDataStructure(root);
      bridges.visualize();

    return 0;
}
