#include <bits/stdc++.h>
using namespace std;

class FamilyNode {
public:
    vector<FamilyNode*> children;
    string name;
    int age;
    double income;
    string occupation;

    FamilyNode(string n, int a, double inc, string occ)
        : name(n), age(a), income(inc), occupation(occ) {}
};

FamilyNode* buildTree() {
    string name;
    cout << "Enter name of member: ";
    cin >> name;

    int age;
    cout << "Enter age: ";
    cin >> age;

    double income;
    cout << "Enter income: ";
    cin >> income;

    string occupation;
    cout << "Enter occupation: ";
    cin >> occupation;

    int numOfChildren;
    cout << "Enter number of children: ";
    cin >> numOfChildren;

    FamilyNode* node = new FamilyNode(name, age, income, occupation);

    for (int i = 0; i < numOfChildren; i++) {
        node->children.push_back(buildTree());
    }

    return node;
}

void printUniqueOccupationMember(vector<FamilyNode*>& familyTrees) {
    for (int i = 0; i < familyTrees.size(); i++) {
        map<string, int> occupationToCount;
        queue<FamilyNode*> q;
        q.push(familyTrees[i]);

        while (!q.empty()) {
            FamilyNode* currentNode = q.front();
            q.pop();

            // Increment the count of this occupation
            occupationToCount[currentNode->occupation]++;

            // Add all children to the queue for further traversal
            for (FamilyNode* child : currentNode->children) {
                q.push(child);
            }
        }

        // Print family tree ancestor's name
        cout << "Ancestor: " << familyTrees[i]->name << endl;
        cout << "Family Members with Unique Occupations:" << endl;

        // Iterate over all descendants and print those with unique occupations
        if (occupationToCount[familyTrees[i]->occupation] == 1)
            {
                cout << "Name: " << familyTrees[i]->name << ", Occupation: " << familyTrees[i]->occupation << endl;
            }
        q.push(familyTrees[i]);
        while (!q.empty()) {
            FamilyNode* currentNode = q.front();
            q.pop();
            

            for (FamilyNode* descendant : currentNode->children) {
                q.push(descendant);

                if (occupationToCount[descendant->occupation] == 1) {
                    cout << "Name: " << descendant->name << ", Occupation: " << descendant->occupation << endl;
                }
            }
        }

        cout << endl;
    }
}
void printAverageIncomePerAgeGroup(vector<FamilyNode *> &familyTrees)
{
    int sum1=0, count1=0, sum2=0, count2=0, sum3=0 , count3=0;
    for (int i = 0; i < familyTrees.size(); i++)
    {
        queue<FamilyNode *> q;
        q.push(familyTrees[i]);

        while (!q.empty())
        {
            FamilyNode *currentNode = q.front();
            q.pop();
            
            if (currentNode->age <= 20)
            {
                sum1 += currentNode->income;
                count1++;
            }
            else if (currentNode->age >= 21 && currentNode->age <= 40 )
            {
                sum2 += currentNode->income;
                count2++;
            }
            else if (currentNode->age >= 41)
            {
                sum3 += currentNode->income;
                count3++;
            }

            for (FamilyNode *child : currentNode->children)
            {
                q.push(child);
            }
        }
        cout << "Ancestor: " << familyTrees[i]->name << endl;
        cout << "average income for the age group <=20:" << float(sum1)/count1 << endl;
        cout << "average income for the age group 21-40:" << float(sum2)/count2 << endl;
        cout << "average income for the age group >=41:" << float(sum3)/count3 << endl;
    
    sum1=0;
    count1=0;
    sum2=0;
    count2=0;
    sum3=0;
    count3=0;
    }
}

void levelOrderTraversal(FamilyNode *node)
{
    queue<FamilyNode *> q;
    q.push(node);

    int level = 0;
    while (!q.empty())
    {
        int currentLevelSize = q.size();
        double maxIncome = 0;
        string richestName;

        for (int j = 0; j < currentLevelSize; j++)
        {
            FamilyNode *currentNode = q.front();
            q.pop();

            if (currentNode->income > maxIncome)
            {
                maxIncome = currentNode->income;
                richestName = currentNode->name;
            }

            for (FamilyNode *child : currentNode->children)
            {
                q.push(child);
            }
        }
        cout << "Generation " << level << " - Richest Individual's Name: " << richestName << ", Income: " << maxIncome << endl;
        level++;
    }
}

void printRichestIndividualEachGeneration(vector<FamilyNode *> &familyTrees)
{
    for (int i = 0; i < familyTrees.size(); i++)
    {
        cout << "Ancestor: " << familyTrees[i]->name << endl;
        levelOrderTraversal(familyTrees[i]);
        cout << endl;
    }
}


FamilyNode* getDiverseFamily(vector<FamilyNode*>& familyTrees)
{
    FamilyNode* result = nullptr;
    double maxratio = 0;

    for (int i = 0; i < familyTrees.size(); i++)
    {
        double incomesum = 0;
        double agesum = 0;
        queue<FamilyNode*> q;
        q.push(familyTrees[i]);

        while (!q.empty())
        {
            FamilyNode* currentNode = q.front();
            q.pop();

            incomesum += currentNode->income;
            agesum += currentNode->age;

            for (FamilyNode* child : currentNode->children)
            {
                q.push(child);
            }
        }

        double currentRatio =  double(incomesum) / agesum;

        if (currentRatio > maxratio)
        {
            maxratio = currentRatio;
            result = familyTrees[i];
        }
    }

    return result;
}

int main() {
    int numOfFamilies;
    cout << "Enter the number of families: ";
    cin >> numOfFamilies;

    vector<FamilyNode*> familyTrees;

    for (int i = 0; i < numOfFamilies; i++) {
        familyTrees.push_back(buildTree());
    }

    while (true) {
        int choice;
        cout << "1. Find Member with Unique Occupation" << endl;
        cout << "2. Find Average income per Age group" << endl;
        cout << "3. Find Richest Individual of Each Generation" << endl;
        cout << "4. Print Family(Ancestor) Name which is most diverse" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printUniqueOccupationMember(familyTrees);
                break;
            case 2:
                printAverageIncomePerAgeGroup(familyTrees);
                break;
            case 3:
                printRichestIndividualEachGeneration(familyTrees);
                break;
            case 4:
            {
                FamilyNode *result = getDiverseFamily(familyTrees);
                cout << "Family of ancestor named " << result->name << " is most diverse" << endl;
                break;
            }
            case 5:
                return 0;
                break;
            default:
            {
                cout << "Incorrect choice!!!" << endl;
                break;
            }
        }
    }

    return 0;
}
