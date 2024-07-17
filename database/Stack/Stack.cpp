#include <iostream>
#include <string>
#include <stack>
#include <cstring> // Para usar strlen y strcpy
#include <fstream>
#include <unistd.h> // Para usar getcwd()

using namespace std;

template<class T>
class Stack : public stack<T> {
public:
    T pop() {
        T tmp = this->top();
        stack<T>::pop();
        return tmp;
    }
};

class Cell {
public:
    Cell(int i = 0, int j = 0) : x(i), y(j) {}
    bool operator==(const Cell &c) const {
        return x == c.x && y == c.y;
    }
private:
    int x, y;
    friend class Maze;
};

class Maze {
public:
    Maze();
    void exitMaze();
private:
    Cell currentCell, exitCell, entryCell;
    const char exitMarker, entryMarker, visited, passage, wall;
    Stack<Cell> mazeStack;
    char **store; // array of strings
    void pushUnvisited(int, int);
    friend ostream &operator<<(ostream &, const Maze &);
    int rows, cols;
};

Maze::Maze() : exitMarker('e'), entryMarker('m'), visited('.'), passage('0'), wall('1') {
    Stack<char *> mazeRows;
    char str[80], *s;
    int col, row = 0;
    cout << "Reading maze from input.txt" << endl;

    ifstream infile("input.txt");
    if (!infile) {
        cerr << "Error opening input.txt" << endl;
        exit(1);
    }

    while (infile >> str) {
        row++;
        cols = strlen(str);
        s = new char[cols + 3]; // two more cells for borderline columns
        mazeRows.push(s);
        strcpy(s + 1, str);
        s[0] = s[cols + 1] = wall; // fill the borderline cells with walls
        s[cols + 2] = '\0';
        if (strchr(s, exitMarker) != nullptr) {
            exitCell = Cell(row, strchr(s, exitMarker) - s);
        }
        if (strchr(s, entryMarker) != nullptr) {
            entryCell = Cell(row, strchr(s, entryMarker) - s);
        }
    }

    rows = row;
    store = new char *[rows + 2]; // create a 1D array of pointers
    store[0] = new char[cols + 3]; // a borderline row
    for (; !mazeRows.empty(); row--) {
        store[row] = mazeRows.pop();
    }
    store[rows + 1] = new char[cols + 3]; // another borderline row
    store[0][cols + 2] = store[rows + 1][cols + 2] = '\0';
    for (col = 0; col <= cols + 1; col++) {
        store[0][col] = wall; // fill the borderline rows with walls
        store[rows + 1][col] = wall;
    }
}

void Maze::pushUnvisited(int row, int col) {
    if (store[row][col] == passage || store[row][col] == exitMarker) {
        mazeStack.push(Cell(row, col));
    }
}

void Maze::exitMaze() {
    int row, col;
    currentCell = entryCell;
    while (!(currentCell == exitCell)) {
        row = currentCell.x;
        col = currentCell.y;
        cout << *this; // print a snapshot
        if (!(currentCell == entryCell)) {
            store[row][col] = visited;
        }
        pushUnvisited(row - 1, col);
        pushUnvisited(row + 1, col);
        pushUnvisited(row, col - 1);
        pushUnvisited(row, col + 1);
        if (mazeStack.empty()) {
            cout << *this;
            cout << "Failure\n";
            return;
        } else {
            currentCell = mazeStack.pop();
        }
    }
    cout << *this;
    cout << "Success\n";
}

ostream &operator<<(ostream &out, const Maze &maze) {
    for (int row = 0; row <= maze.rows + 1; row++) {
        out << maze.store[row] << endl;
    }
    out << endl;
    return out;
}

int main() {
    Maze().exitMaze();
    return 0;
}
