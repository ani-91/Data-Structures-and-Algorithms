# Problem statement
## 1. Simple Web Browser Navigation using one Stack and one Queue
Create a simplified web browser navigation system that allows users to visit web pages, go back to previously
visited pages, go forward to pages they have previously visited and display top of the navigation stack.\
To achieve this, implement a program that uses following:\
&nbsp; - Stack-To track the user's navigation history\
&nbsp; - Queue-To track forward navigation history
- The program should start with an initial web page URL, e.g., "https://www.google.com".
- The user should be presented with the following menu options:
  - Visit a New URL - Allows the user to enter a new URL and visit that page.
  - Go Back - Allows the user to navigate back to the previously visited page.
  - Go Forward - Allows the user to navigate forward to a previously visited page
  - Display Top of Stack - Allows the user to see the top web page of the navigation stack
  - Exit - Allows the user to exit the web browser simulation.
- The program should display the current page's URL and the front URL in the forward navigation queue after each navigation action.
- Proper error handling should be implemented for scenarios like trying to go back when there is no backward history or trying to go forward when there is no forward history.
## 2. Tree
In the magical town of Queensland, there are many families. Each family consist of an ancestor and all other
family members are residents of the ancestor. Each famiy maintains a structure called the “Family Tree” which is
basically a tree-like representation of the family where the nodes of the tree represent the family members and
edges represent parent-child relationship. A parent can have multiple children in the town. Each family member
has certain information which is to be stored in the tree like name, age, income and occupation.

Implement these operations on the Family Tree!

Each family wants to know the member having unique occupation. Write the code to find the member having
unique occupation, if exists for each family.

The next task is to compute the average income by age group for each family. For each family, print the average
income for the age groups: <=20, 21-40, >=41.

Each family wants to know the richest individual in each generation. Help them determine the richest individual in
each generation. Think of it as of finding node with highest income in each level of the family tree.

Lastly, the families of Queensland want to know the most diverse family which is the family with highest count of
distinct occupations.

![Screenshot 2024-05-23 144623](https://github.com/ani-91/Data-Structures-and-Algorithms/assets/141425684/77be7a89-2f00-4de6-8ecb-934b52f99a71)
