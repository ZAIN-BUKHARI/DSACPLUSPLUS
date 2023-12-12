#include <iostream>
#include <stack>
#include <string>
using namespace std;
class TextEditor {
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:

    void type(string newText) {
        // Save the current text to the undo stack before making changes
        undoStack.push(text);

        // Update the text with the new input
        text += newText;
        cout << "Text: " << text << endl;

        // Clear the redo stack since we are making a new change
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    void undo() {
        if (!undoStack.empty()) {
            // Save the current text to the redo stack before undoing
            redoStack.push(text);

            // Restore the previous text from the undo stack
            text = undoStack.top();
            undoStack.pop();

            cout << "Undo. Text: " << text << endl;
        } else {
            cout << "Nothing to undo." << endl;
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            // Save the current text to the undo stack before redoing
            undoStack.push(text);

            // Restore the next text from the redo stack
            text = redoStack.top();
            redoStack.pop();

            cout << "Redo. Text: " << text << endl;
        } else {
            cout << "Nothing to redo." << endl;
        }
    }
};

int main() {
    TextEditor textEditor;

    textEditor.type("1, ");
    textEditor.type("2");

    textEditor.undo();
    textEditor.redo();

    textEditor.type(" 3");

    textEditor.undo();
    textEditor.redo();

    return 0;
}
