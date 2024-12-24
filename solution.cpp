#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

void interface()
{
    cout << string(80, '-') << endl
         << string(10, ' ') << "Generalized node solution" << endl
         << string(80, '-') << endl
         << endl;
}
// get the no_of nodes
int first_step()
{
    cout << "First step: enter the number of nodes: ";
    int n;
    cin >> n;
    return n;
}

// second step, form the conductance matrix
void scan_conductance(double matrix_g[][11], int &state, int no_nodes)
{
    cout << endl
         << string(80, '-') << endl
         << endl;
    int no_resistance;
    cout << "For node number " << state << endl
         << "Enter the number of resistances that are directly connected to that node" << endl;
    cin >> no_resistance;
    for (int i = 1; i <= no_resistance; i++)
    {
        cout << "Enter the values of resistance connected to the " << state << " node directly" << endl;
        double resistance;
        cin >> resistance;
        matrix_g[state - 1][state - 1] += 1 / resistance;
    }
    for (int i = 1; i <= no_nodes; i++)
    {
        if (i == state)
            continue;
        cout << "Enter the value of resistance that is directly between node " << state << " and node " << i << endl;
        cin >> matrix_g[state - 1][i - 1];
        if (matrix_g[state - 1][i - 1] != 0)
            matrix_g[state - 1][i - 1] = -1 / matrix_g[state - 1][i - 1];
    }
    cout << "Enter the number of current sources connected to node " << state << endl;
    int no_current;
    cin >> no_current;
    for (int i = 1; i <= no_current; i++)
    {
        double current;
        cout << "Enter the value of current entering the " << state << " node. +ve if the current enters the node and -ve otherwise" << endl;
        cin >> current;
        matrix_g[state - 1][no_nodes] += current;
    }
    state++;
}

// third step solve the matrix
void solve_equations(double mat[][11], int n, double solutions[11])
{
    // Forward Elimination
    for (int i = 0; i < n; i++)
    {
        // Partial Pivoting
        int max_row = i;
        for (int j = i + 1; j < n; j++)
        {
            if (abs(mat[j][i]) > abs(mat[max_row][i]))
                max_row = j;
        }
        // Swap the rows
        for (int k = i; k < n + 1; k++)
        {
            double temp = mat[max_row][k];
            mat[max_row][k] = mat[i][k];
            mat[i][k] = temp;
        }
        // Make all elements below the diagonal in this column zero
        for (int j = i + 1; j < n; j++)
        {
            double f = (mat[i][j]) ? mat[j][i] / mat[i][i] : 0;
            for (int k = i; k < n + 1; k++)
            {
                mat[j][k] -= f * mat[i][k];
            }
        }
    }
    // backward substitution
    for (int i = n - 1; i >= 0; i--)
    {
        solutions[i] = mat[i][n];
        for (int j = i + 1; j < n; j++)
        {
            solutions[i] -= mat[i][j] * solutions[j];
        }
        solutions[i] /= mat[i][i];
    }
}

// fourth step display the result
void display(double solutions[11], int no_nodes)
{
    cout << string(80, '-') << endl
         << string(10, ' ') << "Solutions" << endl
         << string(80, '-') << endl
         << endl;
    for (int i = 0; i < no_nodes; i++)
    {
        cout << "The voltage at node " << i + 1 << " is " << solutions[i] << " V" << endl
             << endl;
    }
}
int main()
{
    interface();
    int no_nodes, state = 1;
    no_nodes = first_step();
    double matrix_g[10][11] = {{0}}, solutions[11], first_volt;

    // char reference;
    // int flag = 0;
    // cout << "Is there a voltage source connecting between the reference node and node number 1? (y/n)";
    // cin >> reference;
    // switch (reference)
    // {
    // case 'n':
    //     break;
    // case 'y':
    //     cout << "Enter the value of the voltage source: ";
    //     cin >> first_volt;
    //     flag = 1;
    // }

    // Form conductance matrix
    for (int i = 1; i <= no_nodes; i++)
    {
        scan_conductance(matrix_g, state, no_nodes);
    }

    // Solve the matrix
    solve_equations(matrix_g, no_nodes, solutions);

    // Print the conductance matrix
    cout << endl
         << string(' ', 10) << "Conductance matrix" << endl
         << endl;
    for (int i = 0; i < no_nodes; i++)
    {
        for (int j = 0; j < no_nodes; j++)
        {
            cout << matrix_g[i][j] << '\t';
        }
        cout << endl
             << endl;
    }

    // Display result
    display(solutions, no_nodes);
    char a;
    cin >> a;
}
