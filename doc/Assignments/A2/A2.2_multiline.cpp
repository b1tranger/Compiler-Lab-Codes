#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Assignment 2.2 Extension: Multi-Line Comment Detector
 * 
 * Problem:
 * Standard getline(cin, line) stops at every newline character ('\n').
 * To detect multi-line comments (slash-star ... star-slash) that span across multiple lines,
 * we maintain a state variable (`inside_block`) across loop iterations.
 * 
 * When slash-star is encountered, `inside_block` becomes true.
 * All subsequent lines are recognized as comment lines until star-slash is found.
 */

int main()
{
    int n;
    cout << "How many lines of code to input?\n>> ";
    if (!(cin >> n) || n <= 0)
    {
        cerr << "Invalid line count." << endl;
        return 1;
    }

    cin.ignore(); // Clear remaining newline character from input buffer
    cout << "\nInput your code line by line (press Enter after each line):\n>>\n";

    vector<string> lines(n);
    bool inside_block = false;

    int single_line_comments = 0;
    int multi_line_blocks = 0;
    int total_comment_lines = 0;
    vector<int> comment_line_numbers;

    for (int i = 0; i < n; i++)
    {
        getline(cin, lines[i]);
        int current_line_num = i + 1;
        bool is_comment_line = false;

        if (inside_block)
        {
            is_comment_line = true;
            // Search if block comment closes on this line
            size_t end_pos = lines[i].find("*/");
            if (end_pos != string::npos)
            {
                inside_block = false; // Block comment closed
            }
        }
        else
        {
            size_t single_pos = lines[i].find("//");
            size_t block_start_pos = lines[i].find("/*");

            // Case 1: Single-line comment '//' appears first or standalone
            if (single_pos != string::npos && (block_start_pos == string::npos || single_pos < block_start_pos))
            {
                single_line_comments++;
                is_comment_line = true;
            }
            // Case 2: Multi-line comment '/*' begins on this line
            else if (block_start_pos != string::npos)
            {
                multi_line_blocks++;
                is_comment_line = true;

                // Check if the block comment closes on the SAME line (e.g., /* comment */)
                size_t end_pos = lines[i].find("*/", block_start_pos + 2);
                if (end_pos == string::npos)
                {
                    inside_block = true; // Spans across newline to subsequent lines
                }
            }
        }

        if (is_comment_line)
        {
            total_comment_lines++;
            comment_line_numbers.push_back(current_line_num);
        }
    }

    // Output Statistics
    cout << "\n================ Comment Analysis ================\n";
    cout << "Single-line comments (//)       : " << single_line_comments << endl;
    cout << "Multi-line comment blocks (/* */): " << multi_line_blocks << endl;
    cout << "Total lines containing comments  : " << total_comment_lines << endl;

    cout << "Commented line numbers           : ";
    for (size_t i = 0; i < comment_line_numbers.size(); i++)
    {
        cout << comment_line_numbers[i] << (i + 1 < comment_line_numbers.size() ? ", " : "");
    }
    cout << endl;

    if (inside_block)
    {
        cout << "\n[Warning] Syntax error: Multi-line comment was not closed with '*/' before EOF.\n";
    }

    return 0;
}
