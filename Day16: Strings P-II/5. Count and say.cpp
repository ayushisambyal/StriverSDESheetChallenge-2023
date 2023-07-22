#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	std::string sequence = "1";
    for (int i = 1; i < n; i++) {
        std::string new_sequence = "";
        char current_char = sequence[0];
        int count = 1;
        
        for (int j = 1; j < sequence.length(); j++) {
            if (sequence[j] == current_char) {
                count++;
            } else {
                new_sequence += std::to_string(count) + current_char;
                current_char = sequence[j];
                count = 1;
            }
        }
        new_sequence += std::to_string(count) + current_char;
        sequence = new_sequence;
    }
    return sequence;
}
