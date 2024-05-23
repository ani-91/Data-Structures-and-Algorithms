#include <iostream>
#include <stack>
#include <queue>
#include <string>

int main() {
    std::stack<std::string> backwardStack;
    std::queue<std::string> forwardQueue;
    std::stack<std::string> backwardStack_copy;
    std::queue<std::string> forwardQueue_copy;
    std::string CurrentPage = "https://www.google.com";

    while (true) {
        std::cout << "Simple Web Browser Simulation" << std::endl;
        std::cout << "1. Visit a New URL" << std::endl;
        std::cout << "2. Go Back" << std::endl;
        std::cout << "3. Go Forward" << std::endl;
        std::cout << "4. Display Top of Stack" << std::endl;
        std::cout << "5. Exit" << std::endl;

        std::cout << "Current Page: " << CurrentPage << std::endl;
        backwardStack_copy = backwardStack;
        forwardQueue_copy = forwardQueue;
        std::cout << "Elements in Stack:\n";
        while (!backwardStack_copy.empty()) {
            std::cout << backwardStack_copy.top() << " ";
            backwardStack_copy.pop();
        }
        std::cout << "\nElements in Queue:\n";
        while (!forwardQueue_copy.empty()) {
            std::cout << forwardQueue_copy.front() << " ";
            forwardQueue_copy.pop();
        }
        std::cout << std::endl;

        if (!backwardStack.empty()) {
            std::cout << "Top of Stack (Backward): " << backwardStack.top() << std::endl;
        } else {
            std::cout << "Top of Stack (Backward): None" << std::endl;
        }

        if (!forwardQueue.empty()) {
            std::cout << "Front of Queue (Forward): " << forwardQueue.front() << std::endl;
        } else {
            std::cout << "Front of Queue (Forward): None" << std::endl;
        }

        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: // Visit a New Page
            {
                std::string newUrl;
                std::cout << "Enter the URL of the page you want to visit: ";
                std::cin.ignore(); // Clear input buffer
                std::getline(std::cin, newUrl);

                forwardQueue = std::queue<std::string>(); // Clear the forward queue
                backwardStack.push(CurrentPage); // Push the current page onto the backward stack
                CurrentPage = newUrl;
                std::cout << "Visited " << newUrl << std::endl;
            }
            break;

            case 2: // Go Back
                if (!backwardStack.empty()) {
                    forwardQueue.push(CurrentPage);
                    CurrentPage = backwardStack.top();
                    backwardStack.pop();
                    std::cout << "Went back to " << CurrentPage << std::endl;
                } else {
                    std::cout << "No previous pages to go back to." << std::endl;
                }
                break;

            case 3: // Go Forward
                if (!forwardQueue.empty()) {
                    backwardStack.push(CurrentPage);
                    CurrentPage = forwardQueue.back();
                    for (int i = 0; i < forwardQueue.size() - 1; i++)
                    {
                        forwardQueue.push(forwardQueue.front());
                        forwardQueue.pop();
                    }
                    forwardQueue.pop();
                    std::cout << "Went forward to " << CurrentPage << std::endl;
                } else {
                    std::cout << "No forward pages to go to." << std::endl;
                }
                break;

            case 4: // Display Top of Stack
                if (!backwardStack.empty()) {
                    std::cout << "Top of Stack (Backward): " << backwardStack.top() << std::endl;
                } else {
                    std::cout << "Top of Stack (Backward): None" << std::endl;
                }
                break;

            case 5: // Exit
                std::cout << "Exiting, Goodbye!" << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
