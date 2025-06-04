#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int movieID;
    string title;
    string genre;
    int ratings;
    Node* left;
    Node* right;

    Node(int movieID, string title, string genre, int ratings)
        : movieID(movieID), title(title), genre(genre), ratings(ratings), left(nullptr), right(nullptr) {}
};

class MovieRecommendationSystem {
public:
    Node* root;


    MovieRecommendationSystem() : root(nullptr) {}

    void insertMovie(Node*& node, int movieID, string title, string genre, int ratings) {
        if (node == nullptr) {
            node = new Node(movieID, title, genre, ratings);
        } else if (movieID < node->movieID) {
            insertMovie(node->left, movieID, title, genre, ratings);
        } else {
            insertMovie(node->right, movieID, title, genre, ratings);
        }
    }

   void recommendMoviesByGenre(Node* node, string genre) {
        if (node == nullptr) {
            return;
        }

        recommendMoviesByGenre(node->left, genre);

        if (node->genre == genre) {
            cout << "Movie ID: " << node->movieID << ", Title: " << node->title << ", Ratings: " << node->ratings << endl;
        }

        recommendMoviesByGenre(node->right, genre);
    }
    Node* deleteMovieByID(Node* root, int movieID) {
        if (root == nullptr) {
            return root;
        }

        if (movieID < root->movieID) {
            root->left = deleteMovieByID(root->left, movieID);
        } else if (movieID > root->movieID) {
            root->right = deleteMovieByID(root->right, movieID);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            root->movieID = temp->movieID;
            root->right = deleteMovieByID(root->right, temp->movieID);
        }
        return root;
    }
    //due to time issu i left that i was using bubble sorting and then in order displaying
	void display()
	{
		
	}
};

int main() {
    MovieRecommendationSystem engine;
    int choice;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a Movie\n";
        cout << "2. Delete a Movie by ID\n";
        cout << "3. Recommend Movies by Genre\n";
        cout << "4. Display Movies Sorted by Ratings\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int movieID;
                string title, genre;
                int ratings;
                cout << "Enter Movie ID: ";
                cin >> movieID;
                cin.ignore(); 
                cout << "Enter Movie Title: ";
                getline(cin, title);
                cout << "Enter Movie Genre: ";
                getline(cin, genre);
                cout << "Enter Ratings: ";
                cin >> ratings;

                engine.insertMovie(engine.root, movieID, title, genre, ratings);
                cout << "Movie added successfully!" << endl;
                break;
            }
            case 2: {
                int deleteID;
                cout << "Enter Movie ID to delete: ";
                cin >> deleteID;
                engine.root = engine.deleteMovieByID(engine.root, deleteID);
                cout << "Movie with ID " << deleteID << " deleted successfully!" << endl;
                break;
            }
                     case 3: {
                string genre;
                cout << "Enter your favorite genre: ";
                cin.ignore(); 
                getline(cin, genre);
                cout << "Recommended Movies in Genre " << genre << ":\n";
                engine.recommendMoviesByGenre(engine.root, genre);
                break;
            }

            case 4:
               
            break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}
